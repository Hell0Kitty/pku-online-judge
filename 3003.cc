#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[50][1050], pr[50][1050];
const int inf = 0x3f3f3f3f;
void dfs(int k, int d) {
  if (pr[k][d] != -1) {
    dfs(k - 1, pr[k][d]);
    printf("%c", (pr[k][d] > d) ? 'D' : 'U');
  }
}
int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    int n;
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof(dp));
    memset(pr, -1, sizeof(pr));
    dp[0][0] = 0;
    for (int i = 1, d; i <= n; i++) {
      scanf("%d", &d);
      for (int j = 0; j <= 1000; j++) {
        if (j - d >= 0 && dp[i - 1][j - d] != inf &&
            dp[i][j] > max(dp[i - 1][j - d], j)) {
          dp[i][j] = max(dp[i - 1][j - d], j);
          pr[i][j] = j - d;
        }
        if (j + d <= 1000 && dp[i - 1][j + d] != inf &&
            dp[i][j] > dp[i - 1][j + d]) {
          dp[i][j] = dp[i - 1][j + d];
          pr[i][j] = j + d;
        }
      }
    }
    if (dp[n][0] == inf)
      printf("IMPOSSIBLE");
    else
      dfs(n, 0);
    printf("\n");
  }
  return 0;
}
