#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double EP = 1e-10;
int main() {
  int n, i, j, touch[1010], sum, tmax;
  bool flag[1010];
  double r[1010], x[1010], lmax;
  while (scanf("%d", &n) != EOF) {
    lmax = 0;
    sum = 0;
    tmax = n - 1;
    memset(touch, -1, sizeof(touch));
    memset(flag, 0, sizeof(flag));
    for (i = 0; i < n; i++) {
      scanf("%lf", &r[i]);
      x[i] = r[i];
    }
    for (i = 1; i < n; i++) {
      for (j = 0; j < i; j++) {
        if (x[j] + 2 * sqrt(r[i] * r[j]) - x[i] > EP) {
          x[i] = x[j] + 2 * sqrt(r[i] * r[j]);
          touch[i] = j;
        }
      }
      if (x[i] + r[i] - lmax > EP) {
        lmax = x[i] + r[i];
        tmax = i;
      }
    }
    for (i = 0; i < n; i++)
      for (j = touch[i] + 1; j < i; j++)
        if (!flag[j]) {
          flag[j] = 1;
          sum++;
        }
    for (i = tmax + 1; i < n; i++)
      if (!flag[i]) {
        flag[i] = 1;
        sum++;
      }
    printf("%d\n", sum);
    for (i = 0; i < n; i++)
      if (flag[i]) printf("%d\n", i + 1);
  }
  return 0;
}
