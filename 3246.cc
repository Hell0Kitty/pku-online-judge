#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <stdio.h>
using namespace std;

#define MAX_N 100000 + 16

typedef int type_xy;
typedef struct Point {
  int id;
  type_xy x, y;
  Point() {}
  Point(type_xy x, type_xy y) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) { return Point(x - p.x, y - p.y); }
  Point operator*(type_xy d) { return Point(x * d, y * d); }
  bool operator<(const Point& a) const {
    if (x != a.x)
      return x < a.x;
    else
      return y < a.y;
  }
  type_xy dot(Point p) { return x * p.x + y * p.y; }
  type_xy det(Point p) { return x * p.y - y * p.x; }
};

Point P[MAX_N], Q[MAX_N];

inline type_xy cross(Point A, Point B, Point C) { return (B - A).det(C - A); }

inline type_xy compute_area(Point A, Point B, Point C) {
  type_xy res = cross(A, B, C);
  if (res < 0) {
    return -res;
  }
  return res;
}

inline type_xy compute_area(const vector<Point>& ps) {
  type_xy total = 0;
  for (int i = 2; i < ps.size(); ++i) {
    total += compute_area(ps[0], ps[i - 1], ps[i]);
  }
  return total;
}

vector<Point> convex_hull(Point* ps, int N) {
  sort(ps, ps + N);
  int k = 0;
  vector<Point> qs(N * 2);

  for (int i = 0; i < N; ++i) {
    while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) --k;
    qs[k++] = ps[i];
  }

  for (int i = N - 2, t = k; i >= 0; --i) {
    while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) --k;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

int main(int argc, char* argv[]) {
  int N;
  while (~scanf("%d", &N) && N > 0) {
    for (int i = 0; i < N; ++i) {
      scanf("%d%d", &P[i].x, &P[i].y);
      P[i].id = i;
    }
    memcpy(Q, P, N * sizeof(Point));
    vector<Point> ps = convex_hull(P, N);
    type_xy ans = 0x3f3f3f3f;
    for (int i = 0; i < ps.size(); ++i) {
      memcpy(P, Q, N * sizeof(Point));
      swap(P[ps[i].id], P[N - 1]);
      ans = min(ans, compute_area(convex_hull(P, N - 1)));
    }

    printf("%d.%s\n", ans / 2, ans % 2 == 1 ? "50" : "00");
  }
  return 0;
}
