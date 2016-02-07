#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 50005;
pair<int, int> p[MAXN];
int a[MAXN], sum[MAXN];
double C[MAXN];
void init() {
  C[0] = 0;
  for (int i = 1; i < MAXN; i++) {
    C[i] = C[i - 1] + log(i * 1.0);
  }
}
double calc(int n, int m) { return C[n] - C[n - m] - C[m]; }
int main() {
  int n, m, x;
  init();
  while (cin >> n >> m && n + m) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum[i + 1] = sum[i] + a[i];
    }
    double ans = 0;
    for (int i = m; i <= n; i++) {
      double p = exp(calc(i - 2, m - 2) - calc(n, m));
      ans += p * (sum[n] - sum[i - 1] - sum[n - i + 1]);
    }
    printf("%.3f\n", ans);
  }
  return 0;
}
