#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int d[11][11], n, m, dp[1 << 11][11];
const int inf = 1 << 30;
void flody() {
  for (int k = 0; k < n + 1; k++)
    for (int i = 0; i < n + 1; i++)
      for (int j = 0; j < n + 1; j++) {
        if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
      }
}
void DP() {
  int ans = inf;
  for (int i = 0; i < (1 << n); i++)
    for (int j = 1; j < n + 1; j++)
      if (i == (1 << (j - 1)))
        dp[i][j] = d[0][j];
      else if (i & (1 << (j - 1))) {
        dp[i][j] = inf;
        for (int k = 1; k < n + 1; k++)
          if (k != j && (i & (1 << (k - 1))))
            dp[i][j] = min(dp[i ^ (1 << (j - 1))][k] + d[k][j], dp[i][j]);
      }
  for (int i = 1; i < n + 1; i++) {
    ans = min(ans, dp[(1 << n) - 1][i] + d[i][0]);
  }
  printf("%d\n", ans);
}
int main() {
  while (1) {
    scanf("%d", &n);
    if (n == 0) break;
    for (int i = 0; i < n + 1; i++)
      for (int j = 0; j < n + 1; j++) {
        scanf("%d", &d[i][j]);
      }
    flody();
    DP();
  }
  return 0;
}
