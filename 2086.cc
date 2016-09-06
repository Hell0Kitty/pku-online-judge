#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[410][410], val[410], s[410], INF = 1e9;
int main() {
  int n, N, i, j, k, len, ans;
  double p;
  while (~scanf("%d%lf", &n, &p) && n) {
    for (i = 1; i <= n; i++) {
      scanf("%d", &val[i]);
      val[i + n] = val[i];
    }
    N = n * 2;
    for (i = 1; i <= N; i++) {
      dp[i][i] = 0;
      s[i] = s[i - 1] + val[i];
    }
    for (len = 1; len < n; len++)
      for (i = 1; i + len <= N; i++) {
        j = i + len;
        dp[i][j] = INF;
        for (k = i; k < j; k++)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] +
                                       max(s[k] - s[i - 1], s[j] - s[k]));
      }
    ans = INF;
    for (i = 1; i <= n; i++) ans = min(ans, dp[i][i + n - 1]);
    printf("%.2f\n", ans * p);
  }
}
