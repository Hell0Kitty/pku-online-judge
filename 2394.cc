#include <cstdio>
#include <cstring>
const int maxn(555);
int g[maxn][maxn];
int dist[maxn], vis[maxn];
int n, p, c, m;
const int inf(100000000);
int ans[maxn];
void dijk() {
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; i++) dist[i] = inf;
  dist[1] = 0;
  for (int i = 0; i < n; i++) {
    int min = inf, u;
    for (int j = 1; j <= n; j++) {
      if (!vis[j] && dist[j] < min) {
        min = dist[j];
        u = j;
      }
    }
    if (min == inf) break;
    vis[u] = 1;
    for (int j = 1; j <= n; j++) {
      if (!vis[j] && g[u][j] != inf)
        if (g[u][j] + dist[u] < dist[j]) dist[j] = dist[u] + g[u][j];
    }
  }
  int cnt = 0;
  for (int i = 1; i <= c; i++) {
    int k;
    scanf("%d", &k);
    if (dist[k] <= m) ans[cnt++] = i;
  }
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) printf("%d\n", ans[i]);
}
int main() {
  while (~scanf("%d%d%d%d", &n, &p, &c, &m)) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (i == j)
          g[i][j] = 0;
        else
          g[i][j] = inf;
    for (int i = 0; i < p; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      if (w < g[u][v]) {
        g[u][v] = g[v][u] = w;
      }
    }
    dijk();
  }
  return 0;
}
