#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;
double xx, yy, l, eps = 1e-7;
struct point {
  double x, y;
  bool operator<(const point &temp) const {
    if (fabs((y - yy) * (temp.x - xx) - (x - xx) * (temp.y - yy)) < eps)
      return fabs(x - xx) + fabs(y - yy) >
             fabs(temp.x - xx) + fabs(temp.y - yy);
    return (y - yy) * (temp.x - xx) - (x - xx) * (temp.y - yy) < 0;
  }
};
point a[101], stack[101], na[101];
int n, top, ans, cnt, dp[101][101];
double cross(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}
int main() {
  int i, j, s, p, q;
  scanf("%d", &n);
  a[0].x = a[0].y = xx = yy = 0;
  for (i = 1; i <= n; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
  n++;
  scanf("%lf", &l);
  ans = 0;
  na[0] = a[0];
  for (i = 1; i <= n; i++) {
    cnt = 1;
    dp[0][0] = 1;
    if (ans < 1) ans = 1;
    if (2 * (a[i].x + a[i].y) <= l) {
      na[cnt++] = a[i];
      if (ans < 2) ans = 2;
      for (j = 1; j < n; j++) {
        if (j == i) continue;
        if (a[j].x <= a[i].x && 2 * (a[j].y + a[i].x) <= l) na[cnt++] = a[j];
      }
      sort(na + 1, na + cnt);
      for (j = 1; j < cnt; j++) {
        dp[0][j] = 2;
        for (s = j + 1; s < cnt; s++) {
          if (fabs(cross(na[s].x, na[s].y, na[j].x, na[j].y)) < eps) dp[0][j]++;
        }
      }
      for (j = 1; j < cnt; j++)
        for (s = j + 1; s < cnt; s++) {
          dp[j][s] = 2;
          if (fabs(cross(na[s].x, na[s].y, na[j].x, na[j].y)) < eps) continue;
          for (p = 0; p < j; p++) {
            if (cross(na[s].x - na[p].x, na[s].y - na[p].y, na[j].x - na[p].x,
                      na[j].y - na[p].y) < eps) {
              if (dp[j][s] < dp[p][j] + 1) dp[j][s] = dp[p][j] + 1;
            }
          }
          int value;
          if (cross(na[0].x - na[j].x, na[0].y - na[j].y, na[s].x - na[j].x,
                    na[s].y - na[j].y) < eps) {
            value = dp[j][s];
            for (p = s + 1; p < cnt; p++) {
              if (fabs(cross(na[0].x - na[s].x, na[0].y - na[s].y,
                             na[p].x - na[s].x, na[p].y - na[s].y)) < eps)
                value++;
            }
            if (ans < value) ans = value;
          }
        }
    }
  }
  printf("%d\n", ans);
  return 0;
}
