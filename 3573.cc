#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[40][40][40];
char f[40][40][40][40];
char c[100];
char s[1000];
int t[1000];
int g[300];

int main() {
  memset(g, 0, sizeof(g));
  for (int k = 1; k <= 26; k++) {
    g['A' + k - 1] = k;
    g['a' + k - 1] = k;
  }
  for (int k = 0; k <= 9; k++) g[k + 48] = 100;
  memset(a, 0, sizeof(a));
  int cnt = 0;
  while (gets(s)) {
    int len = strlen(s);
    memset(t, 1, sizeof(t));
    for (int i = 0; s[i]; i++)
      if (t[i]) {
        if (g[s[i]]) {
          int num = len;
          for (int j = i; s[j]; j++) {
            if (g[s[j]])
              num = j;
            else
              break;
          }
          int m = 0;
          for (int j = i; j <= num; j++) c[m++] = s[j], t[j] = 0;
          if (m == 1) {
            printf("%c", c[0]);
            continue;
          }
          if (c[1] >= '0' && c[1] <= '9') {
            int temp = 0;
            for (int j = 1; j < m - 1; j++) temp = temp * 10 + c[j] - '0';
            if (a[g[c[0]]][g[c[m - 1]]][temp] != 1) {
              for (int j = 0; j < m; j++) printf("%c", c[j]);
            } else {
              int wh0 = 32;
              if (c[m - 1] >= 'A' && c[m - 1] <= 'Z') wh0 = 0;

              printf("%c", c[0]);
              for (int j = 1; j <= temp; j++)
                printf("%c", f[g[c[0]]][g[c[m - 1]]][temp][j] + wh0);
              printf("%c", c[m - 1]);
            }
          } else {
            for (int j = 0; j < m; j++) printf("%c", c[j]);
            int temp;
            temp = m - 2;
            int i1 = g[c[0]];
            int j1 = g[c[m - 1]];
            for (int j = 1; j <= temp; j++)
              if (c[j] > 96 && c[j] < 97 + 26) c[j] -= 32;
            if (a[i1][j1][temp] == 0) {
              a[i1][j1][temp]++;
              for (int j = 1; j <= temp; j++) f[i1][j1][temp][j] = c[j];
            } else if (a[i1][j1][temp] == 1) {
              int flag = 1;
              for (int j = 1; j <= temp; j++)
                if (f[i1][j1][temp][j] != c[j]) flag = 0;
              if (!flag) a[i1][j1][temp] = 2;
            }
          }
        } else {
          printf("%c", s[i]);
          t[i] = 0;
        }
      }
    printf("\n");
  }
  return 0;
}
