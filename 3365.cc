#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
double w, h;
const double pi = acos(-1.0);
int main() {
  ;
  while (scanf("%lf%lf", &h, &w), w + h) {
    double ans = 0, r;
    r = min(h / 2, w / (2 * (pi + 1)));
    ans = max(ans, pi * r * r * h);
    r = h / 2 / pi;
    ans = max(ans, pi * r * r * (w - 2 * r));
    printf("%.3f\n", ans);
  }
  return 0;
}
