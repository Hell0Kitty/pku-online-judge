#include <iostream>
#include <stdio.h>
using namespace std;
int n, a[150], b[150], c[150], f[35][150];
bool dog(int x, int y) {
  int i;
  for (i = 1; i <= n; i++)
    if (f[x][i] < f[y][i])
      return false;
    else if (f[x][i] > f[y][i])
      return true;
  return false;
}
void swap(int x, int y) {
  int i, g;
  for (i = 1; i <= n; i++) {
    g = f[x][i];
    f[x][i] = f[y][i];
    f[y][i] = g;
  }
}
bool issame(int x, int y) {
  int i;
  for (i = 1; i <= n; i++)
    if (f[x][i] != f[y][i]) return false;
  return true;
}
int main() {
  int t1, t2, t, i, j, k, g, p, m, x, max;
  bool d;
  scanf("%d%d", &n, &m);
  t1 = 0;
  while (1) {
    scanf("%d", &x);
    if (x == -1) break;
    t1++;
    a[t1] = x;
  }
  t2 = 0;
  while (1) {
    scanf("%d", &x);
    if (x == -1) break;
    b[++t2] = x;
  }
  t = 0;
  for (i = 0; i <= 1; i++)
    for (j = 0; j <= 1; j++)
      for (k = 0; k <= 1; k++)
        for (g = 0; g <= 1; g++) {
          if (i + j + k + g > m) {
            continue;
          }
          if ((i + j + k + g) % 2 != m % 2) {
            continue;
          }
          for (p = 1; p <= n; p++) c[p] = 1;
          if (i == 1) {
            for (p = 1; p <= n; p++) c[p] = (c[p] + 1) % 2;
          }
          if (j == 1) {
            for (p = 1; p <= n; p += 2) c[p] = (c[p] + 1) % 2;
          }
          if (k == 1) {
            for (p = 2; p <= n; p += 2) c[p] = (c[p] + 1) % 2;
          }
          if (g == 1) {
            for (p = 1; p <= n; p += 3) c[p] = (c[p] + 1) % 2;
          }
          d = true;
          for (p = 1; p <= t1; p++)
            if (c[a[p]] == 0) {
              d = false;
              break;
            }
          for (p = 1; p <= t2; p++)
            if (c[b[p]] == 1) {
              d = false;
              break;
            }
          if (d) {
            t++;
            for (p = 1; p <= n; p++) f[t][p] = c[p];
          }
        }
  for (i = 1; i <= n; i++) f[0][i] = 100000000;
  for (i = 1; i <= t - 1; i++) {
    max = i;
    for (j = i + 1; j <= t; j++)
      if (dog(max, j)) max = j;
    swap(max, i);
  }
  for (i = 1; i <= t; i++)
    if (!issame(i, i - 1)) {
      for (j = 1; j <= n; j++) printf("%d", f[i][j]);
      printf("\n");
    }
  cin >> i;
  return 0;
}
