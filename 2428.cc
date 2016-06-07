#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
double xx, yy, zz, dp[2][211][211],
    inf = (double)1000000000 * (double)1000000000, ans;
double area(double x1, double y1, double z1, double x2, double y2, double z2,
            double x3, double y3, double z3) {
  double value1 = (x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2) +
                  (z1 - z2) * (z3 - z2),
         value2 = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) +
                   (z1 - z2) * (z1 - z2)) *
                  ((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) +
                   (z3 - z2) * (z3 - z2));
  value1 *= value1;
  if (value2 - value1 < 0) value2 = value1;
  return 0.5 * sqrt(value2 - value1);
}
struct poly {
  double x, y, z;
};
poly a[2][111];
int n, m;
int main() {
  int i, j, s, p, q, id;
  double in, x1, y1, x2, y2;
  scanf("%d", &n);
  ans = inf;
  in = 1000000000;
  for (i = 0; i < n; i++) {
    scanf("%lf%lf", &a[1][i].x, &a[1][i].y);
    if (a[1][i].y < in) {
      in = a[1][i].y;
      id = i;
    }
    a[1][i].z = 0;
  }
  x1 = a[1][id].x - a[1][(id + n - 1) % n].x;
  y1 = a[1][id].y - a[1][(id + n - 1) % n].y;
  x2 = a[1][(id + 1) % n].x - a[1][id].x;
  y2 = a[1][(id + 1) % n].y - a[1][id].y;
  if (y1 * x2 > y2 * x1) {
    for (i = 0; i < (n - 1) / 2; i++) swap(a[1][i + 1], a[1][n - 1 - i]);
  }
  scanf("%d", &m);
  in = 1000000000;
  for (i = 0; i < m; i++) {
    scanf("%lf%lf", &a[0][i].x, &a[0][i].y);
    if (a[0][i].y < in) {
      in = a[0][i].y;
      id = i;
    }
    a[0][i].z = 10;
  }
  x1 = a[0][id].x - a[0][(id + m - 1) % m].x;
  y1 = a[0][id].y - a[0][(id + m - 1) % m].y;
  x2 = a[0][(id + 1) % m].x - a[0][id].x;
  y2 = a[0][(id + 1) % m].y - a[0][id].y;
  if (y1 * x2 > y2 * x1) {
    for (i = 0; i < (m - 1) / 2; i++) swap(a[0][i + 1], a[0][m - 1 - i]);
  }
  for (i = 0; i < 1; i++) {
    for (j = i; j < n + i + 1; j++)
      for (s = 0; s <= m; s++) {
        if (j == i && s == 0) {
          dp[0][j][s] =
              area(a[1][j % n].x, a[1][j % n].y, a[1][j % n].z, a[0][s % m].x,
                   a[0][s % m].y, a[0][s % m].z, a[0][(s + 1) % m].x,
                   a[0][(s + 1) % m].y, a[0][(s + 1) % m].z);
          dp[1][j][s] = area(a[1][j % n].x, a[1][j % n].y, a[1][j % n].z,
                             a[1][(j + 1) % n].x, a[1][(j + 1) % n].y,
                             a[1][(j + 1) % n].z, a[0][s % m].x, a[0][s % m].y,
                             a[0][s % m].z);
        } else
          dp[0][j][s] = dp[1][j][s] = inf;
      }
    for (j = i; j < n + i + 1; j++)
      for (s = 0; s < m + 1; s++) {
        if (j != i || s != 0) {
          if (j > i) {
            dp[0][j][s] = min(dp[0][j][s], dp[1][j - 1][s]);
            dp[1][j][s] = min(dp[1][j][s], dp[1][j - 1][s]);
          }
          if (s > 0) {
            dp[0][j][s] = min(dp[0][j][s], dp[0][j][s - 1]);
            dp[1][j][s] = min(dp[1][j][s], dp[0][j][s - 1]);
          }
          dp[0][j][s] +=
              area(a[1][j % n].x, a[1][j % n].y, a[1][j % n].z, a[0][s % m].x,
                   a[0][s % m].y, a[0][s % m].z, a[0][(s + 1) % m].x,
                   a[0][(s + 1) % m].y, a[0][(s + 1) % m].z);
          dp[1][j][s] += area(a[1][j % n].x, a[1][j % n].y, a[1][j % n].z,
                              a[1][(j + 1) % n].x, a[1][(j + 1) % n].y,
                              a[1][(j + 1) % n].z, a[0][s % m].x, a[0][s % m].y,
                              a[0][s % m].z);
        }
      }
    if (ans > min(dp[0][n + i][m - 1], dp[1][n + i - 1][m]))
      ans = min(dp[0][n + i][m - 1], dp[1][n + i - 1][m]);
  }
  printf("%.0f\n", ans);
  return 0;
}
