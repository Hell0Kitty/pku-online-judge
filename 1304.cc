#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char start_end[15];
int routine[25][15];
char c[200];
int a, n;
const char ss[] = "ENDOFINPUT";
int arrivalTime;
int sum[25];
int size[25];

void input() {
  int i, j;
  a = 0;
  cin >> n;
  gets(c);
  for (i = 0; i < n; i++) {
    j = 0;
    gets(c);
    int k = 0;
    while (c[j] != '\0') {
      a = 0;

      while (c[j] != ' ' && c[j] != '\0') {
        a = a * 10 + (c[j] - '0');
        j++;
      }
      routine[i][k] = a;
      k++;
      a = 0;
      if (c[j] == ' ') j++;
    }
    size[i] = k;
  }
  cin >> arrivalTime;
}
void solve() {
  int i, j;
  memset(sum, 0, sizeof(sum));
  int mmin = 10000000;
  for (i = 0; i < n; i++) {
    j = 0;
    while (1) {
      if (sum[i] < arrivalTime) {
        sum[i] += (routine[i][j % size[i]]);
        j++;
      } else {
        sum[i] = sum[i] - arrivalTime;
        if (mmin > sum[i]) mmin = sum[i];
        break;
      }
    }
  }
  cout << mmin << endl;
}
int main() {
  while (1) {
    cin >> start_end;
    if (strcmp(start_end, ss) == 0) break;
    input();
    cin >> start_end;
    solve();
  }
  return 0;
}
