#include <cmath>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 100;
const double eps = 1e-8;
inline double min(double a, double b) { return a < b ? a : b; }
inline double sgn(double x) { return fabs(x) < eps ? 0 : (x > 0 ? 1 : -1); }
struct Point {
  double x, y;
  Point(double tx = 0, double ty = 0) {
    x = tx;
    y = ty;
  }
  bool operator==(const Point& t) const {
    return sgn(x - t.x) == 0 && sgn(y - t.y) == 0;
  }
} p[maxn], Set[maxn], st[maxn], tmp[maxn], pp[maxn];
struct Seg {
  Point s, e;
};
inline double dist(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline double cross(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
inline bool outside(Seg seg, Point p) { return cross(seg.s, seg.e, p) > eps; }
inline bool inside(Seg seg, Point p) { return cross(seg.s, seg.e, p) < -eps; }
Point Intersect(Point p1, Point p2, Point p3, Point p4, Point& p) {
  double a1, b1, c1, a2, b2, c2, d;
  a1 = p1.y - p2.y;
  b1 = p2.x - p1.x;
  c1 = p1.x * p2.y - p2.x * p1.y;
  a2 = p3.y - p4.y;
  b2 = p4.x - p3.x;
  c2 = p3.x * p4.y - p4.x * p3.y;
  d = a1 * b2 - a2 * b1;
  if (fabs(d) < eps) return false;
  p.x = (-c1 * b2 + c2 * b1) / d;
  p.y = (-a1 * c2 + a2 * c1) / d;
  return p;
}
double W, H;
int a[10], n, pn;
double CUT(Seg seg, Point p[]) {
  int i, j, tot = 0;
  Point A, B;
  A = B = Point(0, 0);
  bool s, e;
  for (i = 0; i < pn; i++) {
    if (!outside(seg, p[i]))
      pp[tot++] = p[i];
    else {
      if (i == 0 && !outside(seg, p[pn - 1])) {
        B = A;
        pp[tot++] = Intersect(seg.s, seg.e, p[i], p[pn - 1], A);
      }
      if (i != 0 && !outside(seg, p[i - 1])) {
        B = A;
        pp[tot++] = Intersect(seg.s, seg.e, p[i], p[i - 1], A);
      }
      if (!outside(seg, p[i + 1])) {
        B = A;
        pp[tot++] = Intersect(seg.s, seg.e, p[i], p[i + 1], A);
      }
    }
  }
  pp[tot] = pp[0];
  pn = tot;
  memcpy(st, pp, sizeof(pp));
  return dist(A, B);
}
int main() {
  int i;
  while (scanf("%lf%lf", &W, &H) != EOF) {
    double ans = 1e20;
    st[4] = st[0] = Point(0, 0);
    st[1] = Point(0, H);
    st[2] = Point(W, H);
    st[3] = Point(W, 0);
    memcpy(tmp, st, sizeof(st));
    scanf("%d", &n);
    Seg ts[100];
    for (i = 0; i < n; i++) {
      scanf("%lf%lf", &p[i].x, &p[i].y);
      a[i] = i;
    }
    p[n] = p[0];
    for (i = 0; i < n; i++) ts[i].s = p[i], ts[i].e = p[i + 1];
    do {
      double tlen = 0;
      memcpy(st, tmp, sizeof(tmp));
      pn = 4;
      for (i = 0; i < n; i++) {
        tlen += CUT(ts[a[i]], st);
      }
      ans = min(ans, tlen);
    } while (next_permutation(a, a + n));
    printf("Minimum total length = %.3lf\n", ans);
  }
  return 0;
}
