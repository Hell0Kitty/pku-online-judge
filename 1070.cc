#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const double EPS = 1e-6;
const double MAX = 0x7fffffff;
const double pi = acos(-1.0);
int n;
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }
  Point operator-(Point a) { return Point(x - a.x, y - a.y); }
};
vector<Point> vp;
Point g, last;
struct Segment {
  double length;
  double slope;
  Point a, b;
  Segment(double length, double slope) {
    this->length = length;
    this->slope = slope;
  }
};
vector<Segment> vs;
int dblcmp(double d) {
  if (fabs(d) < EPS) return 0;
  return (d > 0) ? 1 : -1;
}
int dblcmp(double a, double b) { return dblcmp(a - b); }
double fix(double d) {
  if (fabs(d) < 1e-3) return 0;
  return d;
}
double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
int between(Point c, Point a, Point b) { return dblcmp(dot(a - c, b - c)); }
bool onSegment(Point a, Segment s) {
  return dblcmp(cross(s.b - s.a, a - s.a)) == 0 &&
         (between(a, s.a, s.b) == 0 || between(a, s.a, s.b) == -1);
}
double sqr(double x) { return x * x; }
double dist(const Point &a, const Point &b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
bool on_hill(Point p) {
  for (vector<Segment>::iterator it = vs.begin(); it != vs.end(); ++it) {
    if (onSegment(p, *it)) {
      return true;
    }
  }
  return false;
}
bool check(double angle, double x, double y) {
  Point vc, nvc;
  vc.x = g.x - x;
  vc.y = g.y - y;
  nvc.x = vc.x * cos(angle) - vc.y * sin(angle);
  nvc.y = vc.x * sin(angle) + vc.y * cos(angle);
  int d1 = dblcmp(cross(Point(0, 1), vc));
  int d2 = dblcmp(cross(Point(0, 1), nvc));
  int d3 = dblcmp(cross(vc, nvc));
  return dblcmp(nvc.y + y, g.y) == -1 &&
         (d1 >= 0 && d2 >= 0 && d3 > 0 || d1 <= 0 && d2 <= 0 && d3 < 0);
}

void update(double x, double y, double x1, double y1, double x2, double y2,
            double &left, double &right) {
  double angle;
  double D1, D2;
  Point V1, V2;
  V1.x = x1 - x;
  V1.y = y1 - y;
  V2.x = x2 - x;
  V2.y = y2 - y;
  D1 = dist(Point(x, y), Point(x1, y1));
  D2 = dist(Point(x, y), Point(x2, y2));
  double v = dot(V1, V2) / (D1 * D2);
  if (v > 1)
    v = 1;
  else if (v < -1)
    v = -1;
  angle = acos(v);
  int d1 = dblcmp(x2, x);
  int d2 = dblcmp(cross(Point(x1 - x, y1 - y), Point(x2 - x, y2 - y)));
  if (d1 == -1) {
    if (d2 == -1) angle = 2 * pi - angle;
    if (dblcmp(angle, left) == -1) left = angle;
  } else if (d1 == 1) {
    if (d2 == 1) angle = 2 * pi - angle;
    if (dblcmp(angle, right) == -1) right = angle;
  }
}

int solve(double x, double y, double r, const Segment &s, double x2[2],
          double y2[2]) {
  int ans_n = 0;
  double AB, BC, AC;
  AB = dist(Point(x, y), s.a);
  AC = dist(Point(x, y), s.b);
  BC = s.length;
  double a, b, c, delta;
  a = BC;
  b = -(sqr(AB) + sqr(BC) - sqr(AC));
  c = BC * (sqr(AB) - sqr(r));
  delta = sqr(b) - 4 * a * c;
  if (delta < 0) return 0;
  double m[2];
  m[0] = (-b + sqrt(delta)) / (2 * a);
  m[1] = (-b - sqrt(delta)) / (2 * a);
  for (int i = 0; i < 2; ++i) {
    if (dblcmp(m[i], 0) >= 0 && dblcmp(m[i], BC) <= 0) {
      x2[ans_n] = (s.a.x * (BC - m[i]) + m[i] * s.b.x) / BC;
      y2[ans_n] = (s.a.y * (BC - m[i]) + m[i] * s.b.y) / BC;
      ans_n++;
    }
  }
  return ans_n;
}

bool rotate(int Point_id) {
  double left = MAX;
  double right = MAX;
  double x, y, x1, y1, x2[2], y2[2];
  double r;
  x = vp[Point_id].x;
  y = vp[Point_id].y;
  for (int i = 0; i < n; ++i) {
    if (i != Point_id) {
      x1 = vp[i].x;
      y1 = vp[i].y;
      r = dist(vp[i], vp[Point_id]);
      for (vector<Segment>::iterator its = vs.begin(); its != vs.end(); ++its) {
        int ans_n = solve(x, y, r, *its, x2, y2);
        for (int j = 0; j < ans_n; ++j)
          update(x, y, x1, y1, x2[j], y2[j], left, right);
      }
    }
  }
  double angle = MAX;
  if (dblcmp(left, 0) != 0 && dblcmp(left, MAX) != 0 &&
      check(left, vp[Point_id].x, vp[Point_id].y))
    angle = left;
  else if (dblcmp(right, 0) != 0 && dblcmp(right, MAX) != 0 &&
           check(-right, vp[Point_id].x, vp[Point_id].y))
    angle = -right;
  if (dblcmp(angle, MAX) == 0) return false;
  Point vc, nvc;
  for (int i = 0; i < n; ++i) {
    if (i != Point_id) {
      vc.x = vp[i].x - vp[Point_id].x;
      vc.y = vp[i].y - vp[Point_id].y;
      nvc.x = vc.x * cos(angle) - vc.y * sin(angle);
      nvc.y = vc.x * sin(angle) + vc.y * cos(angle);
      vp[i].x = nvc.x + vp[Point_id].x;
      vp[i].y = nvc.y + vp[Point_id].y;
    }
  }
  vc.x = g.x - vp[Point_id].x;
  vc.y = g.y - vp[Point_id].y;
  nvc.x = vc.x * cos(angle) - vc.y * sin(angle);
  nvc.y = vc.x * sin(angle) + vc.y * cos(angle);
  g.x = nvc.x + vp[Point_id].x;
  g.y = nvc.y + vp[Point_id].y;
  return true;
}

bool rotate() {
  for (int i = 0; i < n; ++i) {
    if (on_hill(vp[i]) && rotate(i)) {
      return true;
    }
  }
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vp.clear();
    for (int i = 0; i < n; ++i) {
      double x, y;
      scanf("%lf %lf", &x, &y);
      vp.push_back(Point(x, y));
    }
    scanf("%lf %lf", &g.x, &g.y);
    vs.clear();
    double l, s;
    do {
      scanf("%lf %lf", &l, &s);
      vs.push_back(Segment(l, s));
    } while (dblcmp(s));
    scanf("%lf %lf", &last.x, &last.y);
    for (vector<Segment>::iterator it = vs.begin(); it != vs.end(); ++it) {
      it->b.x = last.x;
      it->b.y = last.y;

      it->a.x = last.x - it->length / sqrt(1 + sqr(it->slope));
      it->a.y = last.y - it->length * it->slope / sqrt(1 + sqr(it->slope));

      last.x = it->a.x;
      last.y = it->a.y;
    }
    while (rotate())
      ;
    printf("%.3lf %.3lf\n", fix(g.x), fix(g.y));
  }
}
