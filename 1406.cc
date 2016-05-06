#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int x, cn, tn, n, m, xbs, xmin, flag, bmax;
int main() {
  while (cin >> x, x) {
    cn = (int)pow(x * 1.0, 1.0 / 3.0) + 1;
    tn = (int)pow(x * 6.0, 1.0 / 3.0) + 1;
    flag = 0;
    xmin = x;
    for (m = 0; m <= tn && !flag; ++m) {
      for (n = cn; n >= 0; --n) {
        xbs = x - (n * n * n + m * (m + 1) * (m + 2) / 6);
        if (xbs == 0) {
          flag = 1;
          bmax = x;
          break;
        }
        if (xbs > 0 && xbs < xmin) {
          xmin = xbs;
        }
      }
    }
    if (!flag) bmax = x - xmin;
    printf("%d\n", bmax);
  }
  return 0;
}
