#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int v[105], c[105], MAX, n, sum;
int dp[33333], inf = 100000000;

void ZeroOnePack(int cost, int cnt) {
  int i;
  for (i = sum + MAX; i >= cost; i--) dp[i] = min(dp[i], dp[i - cost] + cnt);
}

void CompletePack(int cost, int cnt) {
  int i;
  for (i = sum + MAX + cost; i >= 0; i--)
    dp[i] = min(dp[i], dp[i - cost] + cnt);
}

int MultiplePack() {
  int i, j, k;
  for (i = 1; i <= sum + MAX; i++) dp[i] = inf;
  dp[0] = 0;
  for (i = 1; i <= 2 * n; i++) {
    if (i <= n) {
      k = 1;
      while (k < c[i]) {
        ZeroOnePack(k * v[i], k);
        c[i] -= k;
        k *= 2;
      }
      ZeroOnePack(c[i] * v[i], c[i]);
    } else
      CompletePack(-v[i - n], 1);
  }
  if (dp[sum] == inf)
    return -1;
  else
    return dp[sum];
}

int main() {
  int i;
  while (~scanf("%d%d", &n, &sum)) {
    MAX = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      MAX = max(MAX, v[i]);
    }
    MAX *= MAX;
    for (i = 1; i <= n; i++) scanf("%d", &c[i]);
    printf("%d\n", MultiplePack());
  }

  return 0;
}
