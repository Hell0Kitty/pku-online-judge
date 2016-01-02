#include <stdio.h>
#include <string.h>
int max(int x, int y) { return x > y ? x : y; }
int cnt, ans, a[1020], dp[2][40], p;
int main() {
  int b, c, t, m;
  memset(dp, 0, sizeof dp);
  c = 1;
  cnt = 1;
  a[1] = 0;
  scanf("%d%d", &t, &m);
  while (t--) {
    scanf("%d", &b);
    if (b == c)
      a[cnt]++;
    else
      a[++cnt] = 1;
    c = b;
  }
  p = 0;
  dp[1][0] = 0;
  for (int i = 1; i <= cnt; i++) {
    dp[p][0] = dp[1 - p][0] + (i & 1) * a[i];
    for (int j = 1; j <= m; j++) {
      dp[1 - p][j] = max(dp[p][j - 1], dp[p][j]) + a[i] * ((j + i) & 1);
    }
    p = 1 - p;
  }
  b = 0;
  for (int j = 0; j <= m; j++) {
    b = max(b, dp[p][j]);
  }
  printf("%d\n", b);
  return 0;
}
