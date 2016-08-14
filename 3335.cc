#include <cstdio>
#define vector point
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
  point p[100];
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

double dot_product(vector v1, vector v2) { return v1.x * v2.x + v1.y * v2.y; }

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

polygon hpi(polygon& poly, line& ln) {
  int m = 0;
  polygon hull;
  point p1 = ln.first, p2 = ln.second;
  for (int i = 0; i < poly.size; i++) {
    double c = cross_product(p2 - p1, poly.p[i] - p1);
    double d = cross_product(p2 - p1, poly.p[(i + 1) % poly.size] - p1);
    if (c >= 0) hull.p[m++] = poly.p[i];
    if (c * d < 0) {
      hull.p[m++] =
          line_intersection(line(poly.p[(i + 1) % poly.size], poly.p[i]), ln);
    }
  }
  hull.size = m;
  return hull;
}

// poly的顶点顺时针
bool polygon_kernel(polygon& poly, polygon& knl) {
  //初始化核为无限大
  knl.p[0] = point(-1e18, -1e18);
  knl.p[1] = point(1e18, -1e18);
  knl.p[2] = point(1e18, 1e18);
  knl.p[3] = point(-1e18, 1e18);
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

int main() {
  int t, n, s;
  polygon poly, knl;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lf%lf", &poly.p[i].x, &poly.p[i].y);
    poly.size = n;
    if (polygon_kernel(poly, knl))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
