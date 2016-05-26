#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int dp[4505][4505];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  dp[1][1] = 1;
  dp[0][1] = 0;
  dp[1][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i > j) dp[i][j] = dp[i - 1][j];
      if (i == j) dp[i][j] = dp[i - 1][j] + 1;
      if (i < j) dp[i][j] = dp[i - 1][j] + dp[i][j - i];
      if (dp[i][j] >= 1000000007) dp[i][j] -= 1000000007;
    }
  printf("%lld\n", dp[n][m]);
  return 0;
}
