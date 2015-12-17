#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[505][505], sum[505], a[505];

int main() {
  int t, n, m, i, j, x, v, cas;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d%d", &n, &m);
    memset(sum, 0, sizeof(sum));
    memset(dp, -1, sizeof(dp));
    for (i = 1; i <= n; i++) {
      scanf("%d", &x);
      sum[i] = sum[i - 1] + x;
    }
    dp[0][0] = 0;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= i && j <= m; j++) {
        if (j == 1)
          dp[i][j] = sum[i];
        else {
          for (v = j - 1; v <= i - 1; v++)  //
          {
            int t = max(dp[v][j - 1], sum[i] - sum[v]);
            if (dp[i][j] == -1 || t < dp[i][j]) dp[i][j] = t;
          }
        }
      }
    }
    j = m - 1;
    x = 0;
    for (i = n; i >= 1; i--) {
      x += sum[i] - sum[i - 1];
      if (x > dp[n][m] || i <= j) {
        a[j--] = i + 1;
        x = sum[i] - sum[i - 1];
      }
    }
    int cnt = 1;
    for (i = 1; i <= n; i++) {
      if (i > 1) printf(" ");
      if (cnt < m && a[cnt] == i) {
        printf("/ ");
        cnt++;
      }
      printf("%d", sum[i] - sum[i - 1]);
    }
    printf("\n");
  }

  return 0;
}