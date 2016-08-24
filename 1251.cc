#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int map[100][100];
int flag[200];
int main() {
  int n;
  char schar, echar;
  while (cin >> n && n != 0) {
    memset(flag, 0, sizeof(flag));
    int i, j, m, value;
    for (i = 0; i < 100; i++)
      for (j = 0; j < 100; j++) map[i][j] = 1000;
    for (i = 0; i < n - 1; i++) {
      cin >> schar;
      cin >> m;
      while (m--) {
        cin >> echar >> value;
        map[(int)schar][(int)echar] = value;
        map[(int)echar][(int)schar] = value;
      }
    }
    flag[65] = 1;
    int temp = 0;
    int fnub = 0;
    int sum = 0;
    int k;
    for (k = 1; k < n; k++) {
      int min = 1000;
      for (i = 65; i < 91; i++) {
        if (flag[i] == 1)
          for (j = 65; j < 91; j++) {
            if (flag[j] == 0 && map[i][j] != 1000 && map[i][j] < min) {
              min = map[i][j];
              temp = j;
            }
          }
      }
      sum += min;
      flag[temp] = 1;
    }
    cout << sum << endl;
  }
  return 0;
}
