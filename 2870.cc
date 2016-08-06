#include <stdio.h>
#include <string.h>

int n, m, ans;
int mp[11][11], vis[11][11], adj[11][11];

int min(int a, int b) { return a > b ? b : a; }

void jie(int x, int y, int val) {
  adj[x + 1][y] += val;
  adj[x - 1][y] += val;
  adj[x][y + 1] += val;
  adj[x][y - 1] += val;
  vis[x][y] += val;
  int i;
  for (i = x - 1; i >= 1; i--) {
    vis[i][y] += val;
    if (mp[i][y] >= 0) break;
  }
  for (i = x + 1; i <= n; i++) {
    vis[i][y] += val;
    if (mp[i][y] >= 0) break;
  }
  for (i = y - 1; i >= 1; i--) {
    vis[x][i] += val;
    if (mp[x][i] >= 0) break;
  }
  for (i = y + 1; i <= m; i++) {
    vis[x][i] += val;
    if (mp[x][i] >= 0) break;
  }
}

bool l[11][11];

void dfs(int x, int y, int tot) {
  int i, j;
  if (y > m) {
    if (x < n)
      dfs(x + 1, 1, tot);
    else {
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
          if (mp[i][j] == -1 && !vis[i][j]) return;
          if (mp[i][j] > 0 && adj[i][j] + 1 != mp[i][j]) return;
        }
      }
      ans = min(ans, tot);
    }
    return;
  }
  if (mp[x][y] == -1) {
    dfs(x, y + 1, tot);
    if (!vis[x][y]) {
      jie(x, y, 1);
      dfs(x, y + 1, tot + 1);
      jie(x, y, -1);
    }
  } else {
    for (i = x - 1; i >= 1; i--)
      if (mp[i][y] == -1 && !vis[i][y]) return;
    dfs(x, y + 1, tot);
  }
}

int main() {
  int i, b, k, x, y;
  while (scanf("%d%d", &n, &m) != -1 && n) {
    memset(mp, -1, sizeof(mp));
    scanf("%d", &b);
    for (i = 0; i < b; i++) scanf("%d%d%d", &x, &y, &k), mp[x][y] = k + 1;
    memset(vis, 0, sizeof(vis));
    memset(adj, 0, sizeof(adj));
    ans = 1111111;
    dfs(1, 1, 0);
    if (ans == 1111111)
      puts("No solution");
    else
      printf("%d\n", ans);
  }
  return 0;
}
