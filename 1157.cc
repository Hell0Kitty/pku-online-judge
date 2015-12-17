
#include <stdio.h>
#include <memory.h>
/*
# 1 <= F <= 100 where F is the number of the bunches of flowers. The bunches are
numbered 1 through F.
# F <= V <= 100*/
int value[105][105];
int dp[105][105];
int flower, vases;
#define NInf -10000000;
int main() {
  scanf("%d%d", &flower, &vases);
  for (int i = 1; i <= flower; i++) {
    for (int j = 1; j <= vases; j++) {
      scanf("%d", &value[i][j]);
    }
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= flower + 1; i++) {
    dp[i][0] = NInf;
  }
  for (int i = 1; i <= flower; i++) {
    for (int j = 1; j <= vases; j++) {
      if (dp[i][j - 1] > dp[i - 1][j - 1] + value[i][j]) {
        dp[i][j] = dp[i][j - 1];
      } else
        dp[i][j] = dp[i - 1][j - 1] + value[i][j];
    }
  }

  printf("%d\n", dp[flower][vases]);

  return 0;
}