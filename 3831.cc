#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point { double x, y; } point;
point P[25];
double r[25];

double cxcarea(point a, point b, double r1, double r2) {
  double dc = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  double r = r1 < r2 ? r1 : r2;
  double R = r1 > r2 ? r1 : r2;

  if (dc - 1e-8 > r + R) return 0.0;
  if (dc + 1e-8 < R - r) return acos(-1.0) * r * r;

  double a1 = acos((r * r + dc * dc - R * R) / (2.0 * r * dc));
  double a2 = acos((R * R + dc * dc - r * r) / (2.0 * R * dc));

  return a1 * r * r + a2 * R * R - dc * r * sin(a1);
}

int cover(int n, double R) {
  for (int i = 1; i <= n; ++i) {
    int flag = 1;
    for (int j = 1; j <= n; ++j) {
      double s1 = cxcarea(P[i], P[j], R, r[j]);
      double s2 = acos(-1.0) * r[j] * r[j];
      if (s1 * 2.0 < s2) {
        flag = 0;
        break;
      }
    }
    if (flag) return 1;
  }
  return 0;
}

double b_search(int n) {
  double l = 0.0, r = 50000.0, m;
  while (r - l > 1e-8) {
    m = (l + r) / 2.0;
    if (cover(n, m))
      r = m;
    else
      l = m;
  }
  return r;
}

int main() {
  int T, N;
  while (scanf("%d", &T) != EOF)
    while (T--) {
      scanf("%d", &N);
      for (int i = 1; i <= N; ++i) scanf("%lf%lf%lf", &P[i].x, &P[i].y, &r[i]);

      printf("%.4lf\n", b_search(N));
    }
}
