

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

bool found;
int map[30][30], n, m, col[30];

bool check(int d, int color) {
  int i;
  for (i = 1; i <= n; i++)
    if (map[i][d] == 1 && color == col[i]) return false;
  return true;
}

bool DFS(int d) {
  if (d > n) return true;
  int i;
  for (i = 1; i <= m; i++)
    if (check(d, i)) {
      col[d] = i;
      if (DFS(d + 1)) return true;
    }
  return false;
}

int main() {
  int i, j;
  char c;
  while (cin >> n && n) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) map[i][j] = 0;
    /*
        for(i = 1; i <= n; i++)
              for(j = 1; j <= n; j++)
                scanf("%d",&map[i][j]);*/
    for (i = 1; i <= n; i++) {
      char temp[100];
      scanf("%s", temp);
      for (int k = 2; k < strlen(temp); k++) {
        map[temp[0] - 'A' + 1][temp[k] - 'A' + 1] = 1;
      }
    }
    for (m = 1; m <= 10; m++) {
      for (i = 1; i <= n; i++) col[i] = 0;
      if (found = DFS(1)) break;
    }
    //    for(i = 1; i <= n; i++)
    //        printf("%d ",col[i]);
    //    printf("\n");
    if (m == 1)
      cout << "1 channel needed." << endl;
    else
      cout << m << " channels needed." << endl;
  }
  return 0;
}