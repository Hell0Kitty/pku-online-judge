#include <stdio.h>
#include <memory.h>
#define N 50010
#define oo 1000000000000000LL
int n, m, num, cas, u, v, i, j;
long long ans, sum, w;
int head[N], nxt[N * 2], ev[N * 2], temp[N];
long long frequency[N], f[N], ew[N * 2], dp[N], dis[N];
void addedge(int u, int v, long long w) {
  nxt[++num] = head[u];
  head[u] = num;
  ev[num] = v;
  ew[num] = w;
}
void readin() {
  memset(head, -1, sizeof(head));
  memset(frequency, 0, sizeof(frequency));
  num = -1;
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d%lld", &u, &v, &w);
    addedge(u, v, w);
    addedge(v, u, w);
  }
  sum = 0;
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d%lld", &u, &w);
    frequency[u] = w;
    sum += frequency[u];
  }
}
void pre_dfs(int father, int u) {
  int i;
  f[u] = 0;
  dis[u] = 0;
  for (i = head[u]; i != -1; i = nxt[i])
    if (ev[i] != father) {
      pre_dfs(u, ev[i]);
      dis[u] += dis[ev[i]] + 2 * ew[i] * f[ev[i]];
      f[u] += f[ev[i]];
    }
  f[u] += frequency[u];
}
void dfs(int father, int u, long long dis) {
  int i;
  dp[u] = dis;
  if (dp[u] < ans) ans = dp[u];
  for (i = head[u]; i != -1; i = nxt[i])
    if (father != ev[i]) dfs(u, ev[i], dis + 2 * ew[i] * (sum - 2 * f[ev[i]]));
}
void solve() {
  pre_dfs(1, 1);
  ans = oo;
  dfs(1, 1, dis[1]);
  printf("%lld\n", ans);
  for (j = -1, i = 1; i <= n; i++)
    if (dp[i] == ans) temp[++j] = i;
  for (i = 0; i <= j; i++)
    if (i != j)
      printf("%d ", temp[i]);
    else
      printf("%d\n", temp[i]);
}
int main() {
  scanf("%d", &cas);
  while (cas--) {
    readin();
    solve();
  }
  return 0;
}
