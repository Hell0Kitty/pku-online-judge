#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-5
int main() {
  double x, y, c;
  while (~scanf("%lf%lf%lf", &x, &y, &c)) {
    double l = 0, mid;
    double r = x < y ? x : y;
    double xx, yy, tt;
    while (1) {
      mid = (l + r) / 2;
      xx = sqrt(x * x - mid * mid);
      yy = sqrt(y * y - mid * mid);
      tt = xx * yy / (xx + yy);
      if (fabs(tt - c) < EPS)
        break;
      if (tt < c)
        r = mid;
      else
        l = mid;
    }
    printf("%.3f\n", mid);
  }
  return 0;
}