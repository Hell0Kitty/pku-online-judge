#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

#define eps 1.0E-8

double xx1, xx2, yy1, yy2;

double dist(double x1, double y1, double x2, double y2) {
  double x = abs(x1 - x2);
  double y = abs(y1 - y2);
  return sqrt(x * x + y * y);
}

bool ok(double x, double y) {
  double d1 = dist(xx1, yy1, x, y);
  double d2 = dist(xx2, yy2, x, y);
  if (d1 * 2 + eps < d2) return true;
  return false;
}

int main() {
  scanf("%lf%lf%lf%lf", &xx1, &yy1, &xx2, &yy2);
  double x, y;
  while (scanf("%lf%lf", &x, &y) != EOF) {
    if (ok(x, y)) {
      printf("The gopher can escape through the hole at (%.3f,%.3f).\n", x, y);
      return 0;
    }
  }
  printf("The gopher cannot escape.\n");
  return 0;
}
