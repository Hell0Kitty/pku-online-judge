#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

using namespace std;

const double eps = 1e-8;

const double pi = acos(-1.0);

struct Point {
  double x, y;

  Point operator-(const Point& t) const {
    Point tmp;

    tmp.x = x - t.x;

    tmp.y = y - t.y;

    return tmp;
  }

  Point operator+(const Point& t) const {
    Point tmp;

    tmp.x = x + t.x;

    tmp.y = y + t.y;

    return tmp;
  }

  bool operator==(const Point& t) const {
    return fabs(x - t.x) < eps && fabs(y - t.y) < eps;
  }

} GP;

double cir_area_inst(Point c1, double r1, Point c2, double r2) {
  double a1, a2, d, ret;

  d = sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));

  if (d > r1 + r2 - eps) return 0;

  if (d < r2 - r1 + eps) return pi * r1 * r1;

  if (d < r1 - r2 + eps) return pi * r2 * r2;

  a1 = acos((r1 * r1 + d * d - r2 * r2) / 2 / r1 / d);

  a2 = acos((r2 * r2 + d * d - r1 * r1) / 2 / r2 / d);

  ret = (a1 - 0.5 * sin(2 * a1)) * r1 * r1 + (a2 - 0.5 * sin(2 * a2)) * r2 * r2;

  return ret;
}

int main()

{
  Point a, b;

  double r1, r2;

  scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &r1, &b.x, &b.y, &r2);

  double area = cir_area_inst(a, r1, b, r2);

  printf("%.3lf\n", area);

  return 0;
}
