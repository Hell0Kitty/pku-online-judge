#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

double pi = acos(-1.0);

double bs(double V, double D) {
  double l = 0.0, r = D, d;
  while (r - l > 1e-5) {
    d = 0.5 * (l + r);
    if (pi * D * D * D - pi * d * d * d > 6.0 * V)
      l = d;
    else
      r = d;
  }
  return l;
}

int main() {
  double D, V;
  while (cin >> D >> V && D + V)
    printf("%.3lf\n", bs(V, D));

  return 0;
}