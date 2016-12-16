#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct point {
  double x, y;
} p[31];
int n;
const double pi = acos(-1.0);
const double eps = 1e-4;
double area(double a) { return a * a; }
double max(double a, double b) { return a > b ? a : b; }
double cal(double z) {
  int i;
  double x, y;
  double max_x = -10000.0, max_y = -10000.0, min_x = 10000.0, min_y = 10000.0;
  for (i = 0; i < n; i++) {
    x = p[i].x * cos(z) - p[i].y * sin(z);
    y = p[i].x * sin(z) + p[i].y * cos(z);
    if (max_x < x) max_x = x;
    if (max_y < y) max_y = y;
    if (min_x > x) min_x = x;
    if (min_y > y) min_y = y;
  }
  return max(area(max_x - min_x), area(max_y - min_y));
}
double div() {
  double left = 0, right = pi / 2.0;
  double ans1, ans2;
  double m, mm;
  do {
    m = (left + right) / 2.0;
    mm = (right + m) / 2.0;
    ans1 = cal(m);
    ans2 = cal(mm);
    if (ans1 < ans2)
      right = mm;
    else
      left = m;
  } while (fabs(ans1 - ans2) > eps);
  return ans1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
    printf("%.2lf\n", div());
  }
  return 0;
}
