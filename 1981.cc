#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#define PI acos(-1.0)
using namespace std;
const int N = 305;
int n;
struct Point {
  double x, y;
} p[N];
struct Angle {
  double ang;
  bool is;
} angle[N * 2];
int cmp(Angle M, Angle N) { return M.ang < N.ang; }
double dist(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double k(Point a, Point b) {
  double ki = atan(fabs((b.y - a.y) / (b.x - a.x)));
  if (b.y - a.y > 0) {
    if (b.x - a.x < 0) ki = PI - ki;
  } else {
    if (b.x < a.x)
      ki += PI;
    else
      ki = 2 * PI - ki;
  }
  return ki;
}
void solve() {
  int res = 1, top;
  double dis, now, tmp;
  for (int i = 0; i < n; i++) {
    top = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      dis = dist(p[i], p[j]);
      if (dis > 2.0) continue;
      now = k(p[i], p[j]);
      tmp = acos(dis / 2.0);
      angle[top].ang = now - tmp;
      angle[top++].is = 1;
      angle[top].ang = now + tmp;
      angle[top++].is = 0;
    }
    if (top < res) continue;
    sort(angle, angle + top, cmp);
    int count = 1;
    for (int j = 0; j < top; j++) {
      if (angle[j].is)
        count++;
      else
        count--;
      res = max(res, count);
    }
  }
  printf("%d\n", res);
}
int main() {
  while (scanf("%d", &n) != EOF && n) {
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    solve();
  }
}
