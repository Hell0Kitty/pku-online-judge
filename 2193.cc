#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long dp[11][2001];
long long sp[11][2001];
int main() {
  memset(dp, 0, sizeof(dp));
  memset(sp, 0, sizeof(sp));
  for (int i = 1; i <= 2000; i++) dp[1][i] = 1, sp[1][i] = i;
  for (int i = 2; i <= 10; i++) {
    for (int j = (1 << (i - 1)); j <= 2000; j++) {
      for (int k = (j >> 1), len = (1 << (i - 2)); k >= len; k--)
        dp[i][j] += dp[i - 1][k];
      sp[i][j] = sp[i][j - 1] + dp[i][j];
    }
  }
  int T, ca = 0;
  for (scanf("%d", &T); T; T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("Case %d: n = %d, m = %d, # lists = %lld\n", ++ca, n, m, sp[n][m]);
  }
  return 0;
}
