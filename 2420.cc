#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct point {
  double x, y, d;
  point(double x = 0, double y = 0) : x(x), y(y) {}
};
double dis(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
point p[105];
main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  // srand((unsigned)time(NULL));
  double dt = 10000;
  point pp;
  pp.x = double(rand() % 1000 + 1) / 1000.000 * 10000;
  pp.y = double(rand() % 1000 + 1) / 1000.000 * 10000;
  pp.d = 0;
  for (int i = 1; i <= n; i++) pp.d += dis(pp, p[i]);
  while (dt > 1e-7) {
    double dx = double(rand() % 2000 + 1 - 1000) / 1000.000 * dt;
    double dy = double(rand() % 2000 + 1 - 1000) / 1000.000 * dt;
    point q;
    q.x = pp.x + dx;
    q.y = pp.y + dy;
    q.d = 0;
    for (int i = 1; i <= n; i++) q.d += dis(q, p[i]);
    if (q.d < pp.d) pp = q;
    dt *= 0.95;
  }
  printf("%lld\n", (long long)round(pp.d));
}
