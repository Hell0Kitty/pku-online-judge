#include <iostream>
#include <cmath>

#define Pi acos(-1.0)
using namespace std;

int main() {
  int t, a, b;
  int i;
  double x[4], y[4];
  double p, q, ans, c1, c2, ang, l;

  while (scanf("%d%d%d", &t, &a, &b) && t) {
    for (i = 0; i < 3; i++) scanf("%lf%lf", &x[i], &y[i]);

    ang = atan2(y[0], x[0]) + a * 2.0 * Pi / t;
    l = sqrt(x[0] * x[0] + y[0] * y[0]);
    x[0] = l * cos(ang);
    y[0] = l * sin(ang);

    ang = atan2(y[2], x[2]) - b * 2.0 * Pi / t;
    l = sqrt(x[2] * x[2] + y[2] * y[2]);
    x[2] = l * cos(ang);
    y[2] = l * sin(ang);

    c1 = (x[0] * x[0] + y[0] * y[0] - x[1] * x[1] - y[1] * y[1]) / 2;
    c2 = (x[0] * x[0] + y[0] * y[0] - x[2] * x[2] - y[2] * y[2]) / 2;
    p = (c1 * (y[0] - y[2]) - c2 * (y[0] - y[1])) /
        ((x[0] - x[1]) * (y[0] - y[2]) - (x[0] - x[2]) * (y[0] - y[1]));
    q = (c1 * (x[0] - x[2]) - c2 * (x[0] - x[1])) /
        ((y[0] - y[1]) * (x[0] - x[2]) - (y[0] - y[2]) * (x[0] - x[1]));

    ans = sqrt(p * p + q * q);
    printf("%.0lf\n", ans);
  }

  return 0;
}
