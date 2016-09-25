#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
const double INF = 100000000;
const double PI = acos(-1.0);
int n;
struct Point {
  double x, y;
} a, b, c, o, q;
Point getOra(Point a, Point b, Point c) {
  double aa = 2 * (b.x - a.x);
  double bb = 2 * (b.y - a.y);
  double cc = b.x * b.x + b.y * b.y - a.x * a.x - a.y * a.y;
  double dd = 2 * (c.x - b.x);
  double ee = 2 * (c.y - b.y);
  double ff = c.x * c.x + c.y * c.y - b.x * b.x - b.y * b.y;
  Point ret;
  ret.x = (bb * ff - ee * cc) / (bb * dd - ee * aa);
  ret.y = (dd * cc - aa * ff) / (bb * dd - ee * aa);
  return ret;
}
int main() {
  int Case = 1;
  while (scanf("%d", &n) != EOF) {
    if (n == 0) return 0;
    scanf("%lf%lf", &a.x, &a.y);
    scanf("%lf%lf", &b.x, &b.y);
    scanf("%lf%lf", &c.x, &c.y);
    double co = cos(PI * 2.0 / (double)n);
    double si = sin(PI * 2.0 / (double)n);
    o = getOra(a, b, c);
    // printf("%lf %lf\n",o.x,o.y);
    q.x = a.x - o.x;
    q.y = a.y - o.y;
    double hx, hy, lx, ly;
    hx = hy = -INF;
    lx = ly = INF;
    for (int i = 0; i <= n; i++) {
      hx = max(hx, o.x + q.x);
      hy = max(hy, o.y + q.y);
      lx = min(lx, o.x + q.x);
      ly = min(ly, o.y + q.y);
      Point temp = q;
      q.x = temp.x * co - temp.y * si;
      q.y = temp.x * si + temp.y * co;
    }
    printf("Polygon %d: %.3lf\n", Case++, (hy - ly) * (hx - lx));
  }
  return 0;
}
