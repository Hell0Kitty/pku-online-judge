#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
long long dp[500005], sum[500005], a[500005];
long long G(long long x, long long y) {
  return dp[y] + sum[x] + y * a[y + 1] - sum[y] - dp[x] - x * a[x + 1];
}
long long S(long long x, long long y) { return a[y + 1] - a[x + 1]; }
long long q[500005];
int r, f;
void insert(int k, int t) {
  q[++r] = k;
  for (long long i = r - 1; i > f + 1; i--) {
    long long x = q[i - 1], y = q[i], z = q[i + 1];
    if (!(G(x, y) * S(y, z) < G(y, z) * S(x, y)))
      q[i] = q[r--];
    else
      break;
  }
}
void init() {
  r = f = 0;
  memset(q, 0, sizeof(q));
  memset(dp, 0, sizeof(dp));
}
int main() {
  int c, n, m;
  scanf("%d", &c);
  while (c--) {
    scanf("%d%d", &n, &m);
    sum[0] = 0;
    init();
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      sum[i] = sum[i - 1] + a[i];
    }
    for (long long i = 1; i <= n; i++) {
      while (f + 1 < r && G(q[f + 1], q[f + 2]) <= i * S(q[f + 1], q[f + 2]))
        f++;
      long long tem = f < r ? q[f + 1] : 0;
      dp[i] = dp[tem] + sum[i] - sum[tem] - (i - tem) * a[tem + 1];
      if (i >= 2 * m - 1) {
        insert(i - m + 1, i + 1);
      }
    }
    printf("%lld\n", dp[n]);
  }
  return 0;
}
