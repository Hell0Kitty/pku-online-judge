#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXD 210
#define zero 1e-8
#define INF 2000
struct point {
  double x, y;
} p[MAXD], wa[MAXD], wb[MAXD], *a, *b;
int N, R, na, nb;
double det(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}
int dcmp(double x) { return fabs(x) < zero ? 0 : (x < 0 ? -1 : 1); }
double sqr(double x) { return x * x; }
void init() {
  int i, j, k;
  for (i = 0; i < N; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  p[N] = p[0];
}
void add(double x, double y) {
  b[nb].x = x, b[nb].y = y;
  ++nb;
}
void cut(int k) {
  int i, j;
  double x, y, t1, t2, dx, dy;
  t1 = sqrt(sqr(p[k + 1].x - p[k].x) + sqr(p[k + 1].y - p[k].y));
  dx = (p[k].y - p[k + 1].y) / t1 * R;
  dy = (p[k + 1].x - p[k].x) / t1 * R;
  point *t;
  nb = 0;
  for (i = 0; i < na; i++) {
    t1 = det(p[k + 1].x - p[k].x, p[k + 1].y - p[k].y, a[i].x + dx - p[k].x,
             a[i].y + dy - p[k].y);
    t2 = det(p[k + 1].x - p[k].x, p[k + 1].y - p[k].y, a[i + 1].x + dx - p[k].x,
             a[i + 1].y + dy - p[k].y);
    if (dcmp(t1) <= 0) add(a[i].x, a[i].y);
    if (dcmp(t1) * dcmp(t2) < 0) {
      x = (fabs(t2) * a[i].x + fabs(t1) * a[i + 1].x) / (fabs(t1) + fabs(t2));
      y = (fabs(t2) * a[i].y + fabs(t1) * a[i + 1].y) / (fabs(t1) + fabs(t2));
      add(x, y);
    }
  }
  t = a, a = b, b = t;
  na = nb;
  a[na] = a[0];
}
void solve() {
  int i, j, k;
  double t, max, x1, y1, x2, y2;
  a = wa, b = wb;
  na = 4;
  a[0].x = -INF, a[0].y = -INF, a[1].x = -INF, a[1].y = INF, a[2].x = INF,
  a[2].y = INF, a[3].x = INF, a[3].y = -INF;
  a[na] = a[0];
  for (i = 0; i < N; i++) cut(i);
  max = -1.0;
  for (i = 0; i < na; i++)
    for (j = i; j < na; j++) {
      t = sqrt(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y));
      if (dcmp(t - max) > 0) {
        x1 = a[i].x, y1 = a[i].y;
        x2 = a[j].x, y2 = a[j].y;
        max = t;
      }
    }
  printf("%.5lf %.5lf %.5lf %.5lf\n", x1, y1, x2, y2);
}
int main() {
  while (scanf("%d%d", &N, &R) == 2) {
    init();
    solve();
  }
  return 0;
}
