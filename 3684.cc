#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n, h, r, t, T;
double ans[maxn];
double calc(int t) {
  if (t < 0) return h;
  double t2 = sqrt(2 * h / 10.0);
  int k = t / t2;
  double val;
  if (k & 1)
    val = k * t2 + t2 - t;
  else
    val = t - k * t2;
  return h - 10.0 * val * val / 2;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &n, &h, &r, &t);
    for (int i = 0; i < n; i++) ans[i] = calc(t - i);
    sort(ans, ans + n);
    printf("%.2f", ans[0]);
    for (int i = 1; i < n; i++) printf(" %.2f", ans[i] + 2 * r * i / 100.0);
    printf("\n");
  }
  return 0;
}
