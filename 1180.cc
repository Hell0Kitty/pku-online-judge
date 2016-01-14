#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
long long dp[10005];
int sumt[10005], sumf[10005];
long long G(int x, int y) { return dp[x] - dp[y]; }
long long S(int x, int y) { return sumt[x] - sumt[y]; }
int q[10005], r, f;
void init() { r = f = 0; }
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &sumt[i], &sumf[i]);
  for (int i = n - 1; i > 0; i--) {
    sumt[i] += sumt[i + 1];
    sumf[i] += sumf[i + 1];
  }
  init();
  q[++r] = n + 1;
  for (int i = n; i > 0; i--) {
    while (f + 1 < r &&
           G(q[f + 2], q[f + 1]) <= sumf[i] * S(q[f + 2], q[f + 1]))
      f++;
    int tem = q[f + 1];
    dp[i] = dp[tem] + (m + sumt[i] - sumt[tem]) * sumf[i];
    q[++r] = i;
    for (int j = r - 1; j - 1 > f; j--) {
      int x = q[j - 1], y = q[j], z = q[j + 1];
      if (!(G(y, x) * S(z, y) < G(z, y) * S(y, x)))
        q[j] = q[r--];
      else
        break;
    }
  }
  printf("%lld\n", dp[1]);
  return 0;
}
