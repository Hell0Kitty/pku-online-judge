#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <ctime>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;
double eps = 0;
double js(double k) { return k * k * 3 * sqrt(3.0) / 2; }
int main() {
  int n, m, k, cas = 1;
  double r, pi = acos(-1.0);
  while (cin >> n >> m >> k >> r && n) {
    int lk;
    if (n != k)
      lk = n;
    else
      lk = n - 1;

    if (m & 1) lk = k;

    int tot = (n * 2 - 1) * (m / 2);
    if (m & 1) tot += k;
    int a[3] = {0};
    a[0] += k + lk + (m + 1) * 2;
    a[2] = (m - 1) * 3 * (n + n - 3);
    a[1] = (6 * tot - a[0] - a[2]);
    double p[3];
    double x = sqrt(3.0) / 2;
    p[0] = js((x - r) / x);
    p[2] = pi * r * r + r * r * sqrt(3.0) * 2;

    p[1] = js(1) - p[0] - p[2];

    p[0] /= 6 * tot * js(1.0) / 100;
    p[1] /= 6 * tot * js(1.0) / 100;
    p[2] /= 6 * tot * js(1.0) / 100;
    printf("Case %d:\n", cas++);
    printf("Probability of covering 1 hexagon   = %.3lf percent.\n",
           a[2] * p[0] + a[1] * (p[0] + p[1] / 2) +
               a[0] * (p[0] + p[1] + p[2]) + eps);
    printf("Probability of covering 2 hexagons  = %.3lf percent.\n",
           a[2] * p[1] + a[1] * (p[2] + p[1] / 2) + eps);
    printf("Probability of covering 3 hexagons  = %.3lf percent.\n",
           a[2] * p[2] + eps);
    cout << endl;
  }
}
