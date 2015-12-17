#include <stdio.h>
#include <string.h>
#define zero 1e-8
#define MAXD 160
struct point {
  double x, y;
} p[MAXD];
int N;
double R, X, Y;
double fabs(double x) { return x < 0 ? -x : x; }
int dcmp(double x) { return fabs(x) < zero ? 0 : (x < 0 ? -1 : 1); }
double det(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}
double sqr(double x) { return x * x; }
void init() {
  int i, j, k, n;
  scanf("%d", &n);
  N = 0;
  while (n--) {
    scanf("%lf%lf", &p[N].x, &p[N].y);
    if (dcmp(sqr(p[N].x - X) + sqr(p[N].y - Y) - R * R) <= 0) ++N;
  }
}
void solve() {
  int i, j, k, t1, t2, cnt = 0;
  for (i = 0; i < N; i++)
    if (dcmp(p[i].x - X) == 0 && dcmp(p[i].y - Y) == 0) ++cnt;
  for (i = 0; i < N; i++)
    if (dcmp(p[i].x) - X != 0 || dcmp(p[i].y - Y) != 0) {
      t1 = t2 = 0;
      for (j = 0; j < N; j++) {
        if (dcmp(det(p[i].x - X, p[i].y - Y, p[j].x - X, p[j].y - Y)) <= 0)
          ++t1;
        if (dcmp(det(p[i].x - X, p[i].y - Y, p[j].x - X, p[j].y - Y)) >= 0)
          ++t2;
      }
      if (t1 > cnt) cnt = t1;
      if (t2 > cnt) cnt = t2;
    }
  printf("%d\n", cnt);
}
int main() {
  for (;;) {
    scanf("%lf%lf%lf", &X, &Y, &R);
    if (dcmp(R) < 0) break;
    init();
    solve();
  }
  return 0;
}