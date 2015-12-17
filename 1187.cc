
#include <cstdio>
#include <cstring>
#define MOD 11380
//#define LOCAL

int dp[15][15][15][35];
bool vis[15][15][15][35];

int dfs(int l1, int l2, int l3, int dd) {
  if (!l1 && !l2 && !l3) {
    vis[l1][l2][l3][dd] = true;
    return dp[l1][l2][l3][dd] = 1;
  }
  if (!dd) {
    vis[l1][l2][l3][dd] = true;
    return dp[l1][l2][l3][dd] = 0;
  }
  if (vis[l1][l2][l3][dd]) return dp[l1][l2][l3][dd];

  int ans = 0;
  for (int i = 0; i <= l3; i++) {
    if (i) {
      ans = (ans + dfs(0, 0, i - 1, dd - 1) * dfs(l1, l2, l3 - i, dd)) % MOD;
      ans %= MOD;
    }
    for (int j = 0; j <= l2; j++) {
      if (j) {
        ans = (ans + dfs(0, j - 1, i, dd - 1) * dfs(l1, l2 - j, l3 - i, dd)) %
              MOD;
        ans %= MOD;
      }
      for (int k = 1; k <= l1; k++) {
        ans =
            (ans + dfs(k - 1, j, i, dd - 1) * dfs(l1 - k, l2 - j, l3 - i, dd)) %
            MOD;
        ans %= MOD;
      }
    }
  }
  vis[l1][l2][l3][dd] = true;
  return dp[l1][l2][l3][dd] = ans;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int l1, l2, l3, dd;

  memset(vis, 0, sizeof(vis));
  scanf("%d%d%d%d", &l1, &l2, &l3, &dd);

  dp[l1][l2][l3][dd] = dfs(l1, l2, l3, dd);
  if (dd) dp[l1][l2][l3][dd - 1] = dfs(l1, l2, l3, dd - 1);
  // dp[l1][l2][l3][dd-1]=dfs(l1,l2,l3,dd-1);

  if (!dd) {
    printf("%d\n", dp[l1][l2][l3][dd]);
    return 0;
  }
  int a1 = dp[l1][l2][l3][dd], a2 = dp[l1][l2][l3][dd - 1];

  // printf("%d %d\n",a1,a2);
  printf("%d\n", ((a1 - a2) % MOD + MOD) % MOD);
  return 0;
}