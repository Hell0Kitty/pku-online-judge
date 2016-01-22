#include <cstdio>
#include <cstring>
const int LMT = 10007;
bool dp[2][LMT];
int car[502], sum[502];
int pre[502][LMT];
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
void dfs(int x, int y) {
  if (x <= 0) return;
  if (!pre[x][y]) {
    dfs(x - 1, y - car[x]);
    printf("starboard\n");
  } else {
    dfs(x - 1, y);
    printf("port\n");
  }
}
int main(void) {
  int len, i, j, d, h, cnt = 0, ans = 0;
  scanf("%d", &len);
  len *= 100;
  memset(dp, 0, sizeof(dp));
  memset(pre, -1, sizeof(pre));
  dp[0][0] = 1;
  sum[0] = 0;
  for (i = 1;; i++) {
    scanf("%d", &car[i]);
    if (0 == car[i]) break;
    sum[i] = sum[i - 1] + car[i];
    cnt++;
  }
  for (i = 1; i <= cnt; i++) {
    memset(dp[i & 1], 0, sizeof(dp[i & 1]));
    for (j = len; j >= 0; j--) {
      if (sum[i] - j > len) break;
      if (j >= car[i] && dp[(i - 1) & 1][j - car[i]]) {
        dp[i & 1][j] |= dp[(i - 1) & 1][j - car[i]];
        if (dp[i & 1][j]) pre[i][j] = 0;
      } else if (sum[i] - j >= car[i]) {
        dp[i & 1][j] |= dp[(i - 1) & 1][j];
        if (dp[i & 1][j]) pre[i][j] = 1;
      }
      if (dp[i & 1][j]) {
        ans = d = i;
        h = j;
      }
    }
    if (ans != i) break;
  }
  printf("%d\n", ans);
  if (ans) dfs(d, h);
  return 0;
}
