#include "stdio.h"
#include "iostream"
using namespace std;
int main() {
  int m, n, i, j, w, t;
  int a[30005];
  int dp[30005][4];
  while (scanf("%d", &t) != EOF) {
    while (t--) {
      scanf("%d", &n);
      for (i = 1; i <= n; i++)
        scanf("%d", &a[i]), dp[i][1] = 1, dp[i][2] = a[i];

      dp[1][0] = 1;
      if (a[1] > a[2]) {
        dp[2][1] = 2, dp[2][2] = a[2];
      }

      for (i = 2; i <= n; i++) {
        if (dp[i - 1][0]) {
          if (a[i] < dp[i - 1][2]) {
            dp[i][0] = 0;
            dp[i][1] = dp[i - 1][1] + 1;
          } else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
          }
          dp[i][2] = a[i];
        } else {
          if (a[i] > dp[i - 1][2]) {
            dp[i][0] = 1;
            dp[i][1] = dp[i - 1][1] + 1;
          } else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
          }
          dp[i][2] = a[i];
        }
      }
      printf("%d\n", dp[n][1]);
    }
  }
  return 0;
}
