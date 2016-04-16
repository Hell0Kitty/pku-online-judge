#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define vector point
using std::swap;
struct point {
  double x, y;
  point(double xx = 0, double yy = 0) {
    x = xx;
    y = yy;
  }
  point operator-(const point& s) { return point(x - s.x, y - s.y); }
  point operator+(const point& s) { return point(x + s.x, y + s.y); }
};
struct polygon {
  point p[2000];
  int size;
};
struct line {
  point first, second;
  line(point p1 = point(), point p2 = point()) {
    first = p1;
    second = p2;
  }
};

double cross_product(vector v1, vector v2) { return v1.x * v2.y - v1.y * v2.x; }

//求两直线交点
point line_intersection(line ln1, line ln2) {
  double a1, b1, c1, a2, b2, c2;
  a1 = ln1.first.y - ln1.second.y;
  b1 = ln1.second.x - ln1.first.x;
  c1 = ln1.first.x * ln1.second.y - ln1.second.x * ln1.first.y;
  a2 = ln2.first.y - ln2.second.y;
  b2 = ln2.second.x - ln2.first.x;
  c2 = ln2.first.x * ln2.second.y - ln2.second.x * ln2.first.y;
  double d = a1 * b2 - a2 * b1;
  return point((b1 * c2 - b2 * c1) / d, (c1 * a2 - c2 * a1) / d);
}

//一个多边形与一个半平面的交集
polygon hpi(polygon& poly, line& ln) {
  int m = 0;
  polygon hull;
  point p1 = ln.first, p2 = ln.second;
  //穷举多边形的所有点，判断是否在半平面上
  //如果凸多边形hull与直线ln有交点就求交点
  for (int i = 0; i < poly.size; i++) {
    double c = cross_product(p2 - p1, poly.p[i] - p1);
    double d = cross_product(p2 - p1, poly.p[(i + 1) % poly.size] - p1);
    //点poly.p[i]在半平面上
    if (c >= 0) hull.p[m++] = poly.p[i];
    //有交点
    if (c * d < 0)
      hull.p[m++] =
          line_intersection(line(poly.p[(i + 1) % poly.size], poly.p[i]), ln);
  }
  hull.size = m;
  return hull;
}

// poly的顶点顺时针
bool polygon_kernel(polygon& poly, polygon& knl) {
  //初始化核为无限大
  knl.p[0] = point(-1e5, -1e5);
  knl.p[1] = point(1e5, -1e5);
  knl.p[2] = point(1e5, 1e5);
  knl.p[3] = point(-1e5, 1e5);
  knl.size = 4;
  line ln;
  point pre = poly.p[0];
  for (int i = 1; i <= poly.size; i++) {
    ln.first = poly.p[i % poly.size];
    ln.second = poly.p[i - 1];
    knl = hpi(knl, ln);
    if (knl.size == 0) return false;
  }
  return true;
}

double polygon_area(polygon& poly) {
  double s = 0;
  for (int i = 0; i < poly.size - 1; i++)
    s += cross_product(poly.p[i], poly.p[i + 1]);
  s += cross_product(poly.p[poly.size - 1], poly.p[0]);
  return s / 2;
}

int main() {
  int t, n;
  polygon gallery, kernel;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%lf%lf", &gallery.p[i].x, &gallery.p[i].y);
    gallery.size = n;
    if (!polygon_kernel(gallery, kernel)) {
      int left = 0, right = n - 1;
      while (left < right) swap(gallery.p[left++], gallery.p[right--]);
      polygon_kernel(gallery, kernel);
    }
    double s;
    s = polygon_area(kernel);
    printf("%.2lf\n", s);
  }
  return 0;
}
