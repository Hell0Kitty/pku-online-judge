#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXM = 5e4 + 5;
const int INF = 2e5 + 5;
const double MINM = 1e-10;
double x[MAXM], y[MAXM];
int n;

double _distance(int i, double xx) {
  double re = y[i] * y[i] + (x[i] - xx) * (x[i] - xx);
  return sqrt(re);
}
double solve(double p) {
  double res = 0.0;
  for (int i = 0; i < n; i++) {
    double temp = _distance(i, p);
    if (res < temp) res = temp;
  }
  return res;
}
int main() {
  double l, r;
  while (scanf("%d", &n) != EOF) {
    if (n == 0) break;
    l = INF;
    r = -INF;
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &x[i], &y[i]);
      if (l > x[i]) l = x[i];
      if (r < x[i]) r = x[i];
    }
    while (r - l >= MINM) {
      double mid1 = (l + r) / 2;
      double mid2 = (l + mid1) / 2;
      double res1 = solve(mid1);
      double res2 = solve(mid2);
      if (res1 >= res2)
        r = mid1;
      else
        l = mid2;
    }
    printf("%.9lf %.9lf\n", l, solve(l));
  }
  return 0;
}
