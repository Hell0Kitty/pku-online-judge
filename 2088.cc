#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int dp[1 << 20];
int a[22], b[22][22];
int n;
int ans;
void floyd() {
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
}
int cal(int x) {
  int ans = 0;
  while (x) {
    ans++;
    x &= (x - 1);
  }
  return ans;
}

void dfs(int i, int cnt, int s) {
  if (ans == n) return;
  if (ans < cnt) ans = cnt;
  for (int j = 0; j < n; j++) {
    if (!(s & (1 << j))) {
      if (dp[s | (1 << j)] < dp[s] - a[j] - b[i][j]) {
        dp[s | (1 << j)] = dp[s] - a[j] - b[i][j];
        dfs(j, cnt + 1, s | (1 << j));
      }
    }
  }
}
int main() {
  while (scanf("%d", &n) && n) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) scanf("%d", &b[i][j]);
    floyd();
    memset(dp, -1, sizeof(dp));
    ans = 0;
    for (int i = 0; i < n; i++)
      if (a[i] <= 420) {
        dp[1 << i] = 420 - a[i];
        dfs(i, 1, 1 << i);
      }
    printf("%d\n", ans);
  }
  return 0;
}
