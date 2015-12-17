#include <cstdio>
#include <string>
#include <cmath>
int cost[305][305], dp[35][305], n, m;
int DP() {
  int tem, i, j, k;
  for (i = 1; i <= n; i++) {
    dp[1][i] = cost[1][i];
  }
  for (i = 2; i <= m; i++)
    for (j = 2; j <= n; j++) {
      dp[i][j] = 0x7fffffff;
      for (k = i - 1; k <= j; k++)
        if (dp[i][j] > dp[i - 1][k] + cost[k + 1][j])
          dp[i][j] = dp[i - 1][k] + cost[k + 1][j];
    }
  return dp[m][n];
}
int main() {
  int i, j, k, s[305];
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
  }
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) {
      for (k = i; k <= j; k++)
        cost[i][j] += (int)fabs((float)(s[k] - s[(i + j) / 2]));
    }
  printf("%d\n", DP());
  return 0;
}