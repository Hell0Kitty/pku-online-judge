#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[2005], dp[2005][2005];

int main() {
  int n, i, j, k, l, ans;
  while (~scanf("%d", &n)) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= n; i++) dp[i][i] = a[i] * n;
    for (l = 1; l < n; l++) {
      for (i = 1; i + l <= n; i++) {
        j = i + l;
        dp[i][j] =
            max(dp[i + 1][j] + (n - l) * a[i], dp[i][j - 1] + (n - l) * a[j]);
      }
    }
    printf("%d\n", dp[1][n]);
  }

  return 0;
}
