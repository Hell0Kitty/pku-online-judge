#include <cstdio>

#include <cstring>

#include <algorithm>

#include <cmath>

using namespace std;

const double eps = 1e-8, PI = acos(-1.0);

int main()

{
  double r, h, l, p1, p2, th1, th2, dt;

  while (scanf("%lf%lf%lf%lf%lf%lf", &r, &h, &p1, &th1, &p2, &th2) != EOF)

  {
    dt = fabs((th1 - th2) / 180.0) * PI;

    while (dt > 2 * PI + eps) dt -= 2 * PI;

    if (dt > PI + eps) dt = 2 * PI - dt;

    l = sqrt(h * h + r * r);

    printf("%.2lf\n",
           sqrt(p1 * p1 + p2 * p2 - 2.0 * p1 * p2 * cos(dt * r / l)));
  }

  return 0;
}
