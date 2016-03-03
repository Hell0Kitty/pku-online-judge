#include <stdio.h>
#include <string.h>

#define MAXN 1089
int cnt, g[MAXN][MAXN];
int cx[MAXN], cy[MAXN], vis[MAXN];

int dfs(int& u) {
  for (int v = 1; v <= cnt; v++)
    if (g[u][v] && !vis[v]) {
      vis[v] = 1;
      if (!~cy[v] || dfs(cy[v])) {
        cx[u] = v;
        cy[v] = u;
        return 1;
      }
    }
  return 0;
}
int MaxMatch() {
  int res = 0;
  memset(cx, 0xff, sizeof(cx));
  memset(cy, 0xff, sizeof(cy));
  for (int u = 1; u <= cnt; u++)
    if (!~cx[u]) {
      memset(vis, 0, sizeof(vis));
      res += dfs(u);
    }
  return res;
}
int index[33][33];
int main() {
  int m, n, k, x, y;
  while (~scanf("%d%d%d", &m, &n, &k)) {
    int hole[33][33] = {0};
    memset(g, 0, sizeof(g));
    for (int i = 0; i < k; i++) scanf("%d%d", &x, &y), hole[y][x] = 1;
    if ((m * n - k) & 1) {
      puts("NO");
      continue;
    }
    cnt = 0;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (!hole[i][j]) index[i][j] = ++cnt;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (!hole[i][j]) {
          if (i - 1 >= 1 && !hole[i - 1][j])
            g[index[i][j]][index[i - 1][j]] = 1;
          if (j + 1 <= n && !hole[i][j + 1])
            g[index[i][j]][index[i][j + 1]] = 1;
          if (i + 1 <= m && !hole[i + 1][j])
            g[index[i][j]][index[i + 1][j]] = 1;
          if (j - 1 >= 1 && !hole[i][j - 1])
            g[index[i][j]][index[i][j - 1]] = 1;
        }
    puts(MaxMatch() == cnt ? "YES" : "NO");
  }
  return 0;
}
