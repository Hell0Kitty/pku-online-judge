#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
const double eps = 1e-10;
const double PI = acos(-1.0);

using namespace std;

struct Point {
  double x;
  double y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  void operator<<(Point &A) { cout << A.x << ' ' << A.y << endl; }
};

int dcmp(double x) { return (x > eps) - (x < -eps); }
int sgn(double x) { return (x > eps) - (x < -eps); }
typedef Point Vector;

Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }

Vector operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }

Vector operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }

Vector operator/(Vector A, double p) { return Vector(A.x / p, A.y / p); }

ostream &operator<<(ostream &out, Point &P) {
  out << P.x << ' ' << P.y << endl;
  return out;
}
//
bool operator<(const Point &A, const Point &B) {
  return dcmp(A.x - B.x) < 0 || (dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) < 0);
}

bool operator==(const Point &A, const Point &B) {
  return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}

double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }

double Cross(Vector A, Vector B) { return A.x * B.y - B.x * A.y; }

double Length(Vector A) { return sqrt(Dot(A, A)); }

double Angle(Vector A, Vector B) {
  return acos(Dot(A, B) / Length(A) / Length(B));
}

double Area2(Point A, Point B, Point C) { return Cross(B - A, C - A); }

Vector Rotate(Vector A, double rad) {
  return Vector(A.x * cos(rad) - A.y * sin(rad),
                A.x * sin(rad) + A.y * cos(rad));
}
Vector Normal(Vector A) {
  double L = Length(A);
  return Vector(-A.y / L, A.x / L);
}

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
  Vector u = P - Q;
  double t = Cross(w, u) / Cross(v, w);
  return P + v * t;
}

double DistanceToLine(Point P, Point A, Point B) {
  Vector v1 = P - A;
  Vector v2 = B - A;
  return fabs(Cross(v1, v2)) / Length(v2);
}

double DistanceToSegment(Point P, Point A, Point B) {
  if (A == B) return Length(P - A);

  Vector v1 = B - A;
  Vector v2 = P - A;
  Vector v3 = P - B;

  if (dcmp(Dot(v1, v2)) == -1)
    return Length(v2);
  else if (Dot(v1, v3) > 0)
    return Length(v3);

  else
    return DistanceToLine(P, A, B);
}

Point GetLineProjection(Point P, Point A, Point B) {
  Vector v = B - A;
  Vector v1 = P - A;
  double t = Dot(v, v1) / Dot(v, v);

  return A + v * t;
}

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
  double c1 = Cross(b1 - a1, a2 - a1);
  double c2 = Cross(b2 - a1, a2 - a1);
  double c3 = Cross(a1 - b1, b2 - b1);
  double c4 = Cross(a2 - b1, b2 - b1);

  return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

bool OnSegment(Point P, Point A, Point B) {
  return dcmp(Cross(P - A, P - B)) == 0 && dcmp(Dot(P - A, P - B)) <= 0;
}

double PolygonArea(Point *p, int n) {
  double area = 0;

  for (int i = 1; i < n - 1; i++) {
    area += Cross(p[i] - p[0], p[i + 1] - p[0]);
  }
  return area / 2;
}

Point read_point() {
  Point P;
  scanf("%Lf%Lf", &P.x, &P.y);
  return P;
}

struct Circle {
  Point c;
  double r;

  Circle(Point c = Point(0, 0), double r = 0) : c(c), r(r) {}

  Point point(double a) { return Point(c.x + r * cos(a), c.y + r * sin(a)); }
};

struct Line {
  Point p;
  Vector v;
  Line(Point p = Point(0, 0), Vector v = Vector(0, 1)) : p(p), v(v) {}

  Point point(double t) { return Point(p + v * t); }
};

int getLineCircleIntersection(Line L, Circle C, double &t1, double &t2,
                              vector<Point> &sol) {
  double a = L.v.x;
  double b = L.p.x - C.c.x;
  double c = L.v.y;
  double d = L.p.y - C.c.y;

  double e = a * a + c * c;
  double f = 2 * (a * b + c * d);
  double g = b * b + d * d - C.r * C.r;

  double delta = f * f - 4 * e * g;

  if (dcmp(delta) < 0) return 0;

  if (dcmp(delta) == 0) {
    t1 = t2 = -f / (2 * e);
    sol.push_back(L.point(t1));
    return 1;
  }

  else {
    t1 = (-f - sqrt(delta)) / (2 * e);
    t2 = (-f + sqrt(delta)) / (2 * e);

    sol.push_back(L.point(t1));
    sol.push_back(L.point(t2));

    return 2;
  }
}

double angle(Vector v) { return atan2(v.y, v.x); }

int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point> &sol) {
  double d = Length(C1.c - C2.c);

  if (dcmp(d) == 0) {
    if (dcmp(C1.r - C2.r) == 0)
      return -1;  // 重合
    else
      return 0;  //  内含  0 个公共点
  }

  if (dcmp(C1.r + C2.r - d) < 0) return 0;  // 外离
  if (dcmp(fabs(C1.r - C2.r) - d) > 0) return 0;

  double a = angle(C2.c - C1.c);
  double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));

  Point p1 = C1.point(a - da);
  Point p2 = C1.point(a + da);

  sol.push_back(p1);

  if (p1 == p2)
    return 1;
  else {
    sol.push_back(p2);
    return 2;
  }
}

int getTangents(Point p, Circle C, Vector *v) {
  Vector u = C.c - p;

  double dist = Length(u);

  if (dcmp(dist - C.r) < 0)
    return 0;

  else if (dcmp(dist - C.r) == 0) {
    v[0] = Rotate(u, PI / 2);
    return 1;
  }

  else {
    double ang = asin(C.r / dist);
    v[0] = Rotate(u, -ang);
    v[1] = Rotate(u, +ang);
    return 2;
  }
}

int getTangents(Circle A, Circle B, Point *a, Point *b) {
  int cnt = 0;

  if (A.r < B.r) {
    swap(A, B);
    swap(a, b);
  }

  double d = Length(A.c - B.c);

  double rdiff = A.r - B.r;
  double rsum = A.r + B.r;

  if (dcmp(d - rdiff) < 0) return 0;

  double base = angle(B.c - A.c);

  if (dcmp(d) == 0 && dcmp(rdiff) == 0) return -1;

  if (dcmp(d - rdiff) == 0) {
    a[cnt] = A.point(base);
    b[cnt] = B.point(base);
    cnt++;
    return 1;
  }

  double ang = acos(rdiff / d);
  a[cnt] = A.point(base + ang);
  b[cnt] = B.point(base + ang);
  cnt++;
  a[cnt] = A.point(base - ang);
  b[cnt] = B.point(base - ang);
  cnt++;

  if (dcmp(d - rsum) == 0) {
    a[cnt] = A.point(base);
    b[cnt] = B.point(base + PI);
    cnt++;
  }

  else if (dcmp(d - rsum) > 0) {
    double ang_in = acos(rsum / d);
    a[cnt] = A.point(base + ang_in);
    b[cnt] = B.point(base + ang_in + PI);
    cnt++;
    a[cnt] = A.point(base - ang_in);
    b[cnt] = B.point(base - ang_in + PI);
    cnt++;
  }

  return cnt;
}

Point Zero = Point(0, 0);

double common_area(Circle C, Point A, Point B) {
  if (A == C.c || B == C.c) return 0;

  double OA = Length(A - C.c), OB = Length(B - C.c);
  double d = DistanceToLine(Zero, A, B);

  int sg = sgn(Cross(A, B));
  if (sg == 0) return 0;

  double angle = Angle(A, B);

  if (dcmp(OA - C.r) <= 0 && dcmp(OB - C.r) <= 0) {
    return Cross(A, B) / 2;

  }

  else if (dcmp(OA - C.r) >= 0 && dcmp(OB - C.r) >= 0 && dcmp(d - C.r) >= 0) {
    return sg * C.r * C.r * angle / 2;

  } else if (dcmp(OA - C.r) >= 0 && dcmp(OB - C.r) >= 0 && dcmp(d - C.r) < 0) {
    Point prj = GetLineProjection(Zero, A, B);

    if (OnSegment(prj, A, B)) {
      vector<Point> p;
      Line L = Line(A, B - A);
      double t1, t2;
      getLineCircleIntersection(L, C, t1, t2, p);

      double s1 = 0;
      s1 = C.r * C.r * angle / 2;

      double s2 = 0;
      s2 = C.r * C.r * Angle(p[0], p[1]) / 2;
      s2 -= fabs(Cross(p[0], p[1]) / 2);
      s1 = s1 - s2;

      return sg * s1;
    }

    else {
      return sg * C.r * C.r * angle / 2;
    }

  } else {
    if (dcmp(OB - C.r) < 0) {
      Point temp = A;
      A = B;
      B = temp;
    }

    Point inter_point;

    double t1, t2;
    Line L = Line(A, B - A);
    vector<Point> inter;
    getLineCircleIntersection(L, C, t1, t2, inter);

    if (OnSegment(inter[0], A, B))
      inter_point = inter[0];
    else {
      inter_point = inter[1];
    }

    double s = fabs(Cross(inter_point, A) / 2);
    s += C.r * C.r * Angle(inter_point, B) / 2;

    return s * sg;
  }
}

int main() {
  Point p[60];
  double R;
  int n;
  Circle C(Zero, 0);
  while (cin >> R) {
    C.r = R;
    cin >> n;
    for (int i = 0; i < n; i++) p[i] = read_point();

    p[n] = p[0];
    double ans = 0;

    for (int i = 0; i < n; i++) ans += common_area(C, p[i], p[i + 1]);
    printf("%.2f\n", fabs(ans) + eps);
  }

  return 0;
}
