#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, i, x[200005], y[200005], xx, yy, s1, s2;

int main() {
  while (1) {
    scanf("%d", &n);
    if (n == 0) break;
    for (i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
    xx = x[(n >> 1) + 1], yy = y[(n >> 1) + 1];
    s1 = s2 = 0;
    for (i = 1; i <= n; i++) {
      if (x[i] > xx && y[i] > yy) s1++;
      if (x[i] < xx && y[i] < yy) s1++;
      if (x[i] > xx && y[i] < yy) s2++;
      if (x[i] < xx && y[i] > yy) s2++;
    }

    printf("%d %d\n", s1, s2);
  }

  return 0;
}
