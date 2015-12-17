#include <iostream>
#include <math.h>
#define PI 3.141592653589793
using namespace std;
int main() {
  double x0, x1, x2, y0, y1, y2, a, b, c, cosA;
  while (scanf("%lf%lf%lf%lf%lf%lf", &x0, &y0, &x1, &y1, &x2, &y2) != EOF) {
    a = sqrt((y0 - y1) * (y0 - y1) + (x0 - x1) * (x0 - x1));
    b = sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
    c = sqrt((y0 - y2) * (y0 - y2) + (x0 - x2) * (x0 - x2));
    cosA = (b * b + c * c - a * a) / (2 * b * c);
    printf("%.2lf\n", PI * a / sqrt(1 - cosA * cosA));
  }
  return 0;
}