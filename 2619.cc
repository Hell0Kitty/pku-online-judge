#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
  int temp, n, m, s, flag = 3, cn, cm, zb, yb, cc, k, sj;
  while (scanf("%d%d", &m, &n) == 2) {
    flag = 3;
    s = 0;
    k = 0;
    if (m > n) {
      temp = m;
      m = n;
      n = temp;
    }
    cn = ceil(sqrt(n));
    cm = ceil(sqrt(m));
    cc = abs(cn - cm);
    zb = m + (cn - 1) * (cn - 1) - (cm - 1) * (cm - 1);
    yb = zb + 2 * cc;

    if (n >= zb && n <= yb) {
      s = 2 * (cc);
      k = 1;
    } else {
      if (n < zb)
        s = 2 * (cc) + abs(n - zb);
      else
        s = 2 * (cc) + abs(n - yb);
    }
    sj = m - (cm - 1) * (cm - 1);
    if (abs(n - m) % 2 != (cc) % 2) {
      if (sj % 2 == 1)
        flag = 1;
      else
        flag = 0;
    }
    if (flag == 1 && k == 1) s = s - 1;
    if (flag == 0 && k == 1) s = s + 1;
    printf("%d\n", s);
  }
  return 0;
}
