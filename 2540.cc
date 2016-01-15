#include <stdio.h>
#include <string.h>
#define MAXD 210
#define INF 10
#define zero 1e-8
struct point {
  double x, y;
} wa[MAXD], wb[MAXD], *a, *b;
int N, na, nb;
double px, py, cx, cy;
char st[10];
double fabs(double x) { return x < 0 ? -x : x; }
int dcmp(double x) { return fabs(x) < zero ? 0 : (x < 0 ? -1 : 1); }
double det(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}
void init() {
  int i, j, k;
  a = wa, b = wb;
  a[0].x = 0, a[0].y = 0, a[1].x = INF, a[1].y = 0, a[2].x = INF, a[2].y = INF,
  a[3].x = 0, a[3].y = INF;
  a[na = 4] = a[0];
  px = py = 0;
}
void add(double x, double y) {
  b[nb].x = x, b[nb].y = y;
  ++nb;
}
void cut(double x0, double y0, double nx, double ny) {
  int i, j, k;
  point *t;
  double t1, t2, x, y;
  nb = 0;
  for (i = 0; i < na; i++) {
    t1 = det(nx, ny, a[i].x - x0, a[i].y - y0);
    t2 = det(nx, ny, a[i + 1].x - x0, a[i + 1].y - y0);
    if (dcmp(t1) >= 0) add(a[i].x, a[i].y);
    if (dcmp(t1) * dcmp(t2) < 0) {
      x = (fabs(t2) * a[i].x + fabs(t1) * a[i + 1].x) / (fabs(t1) + fabs(t2));
      y = (fabs(t2) * a[i].y + fabs(t1) * a[i + 1].y) / (fabs(t1) + fabs(t2));
      add(x, y);
    }
  }
  t = a, a = b, b = t;
  a[na = nb] = a[0];
}
void calculate() {
  int i, j, k;
  double s = 0;
  for (i = 0; i < na; i++) s += det(a[i].x, a[i].y, a[i + 1].x, a[i + 1].y);
  printf("%.2lf\n", fabs(s) / 2);
}
void solve() {
  int i, j, k;
  if (st[0] == 'S')
    na = 0;
  else if (st[0] == 'H')
    cut((px + cx) / 2, (py + cy) / 2, cy - py, px - cx);
  else
    cut((px + cx) / 2, (py + cy) / 2, py - cy, cx - px);
  calculate();
}
int main() {
  init();
  while (scanf("%lf%lf%s", &cx, &cy, st) == 3) {
    solve();
    px = cx, py = cy;
  }
  return 0;
}
