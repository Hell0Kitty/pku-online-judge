#include <stdio.h>
#include <string.h>

int n, m, vis[305], ar[20][305];

int match() {
  int i;
  for (i = 0; i < m; i++) {
    if (vis[i] != 1) return 0;
  }
  return 1;
}

int judge() {
  int i;
  for (i = 0; i < m; i++) {
    if (vis[i] > 1) return 0;
  }
  return 1;
}

int dfs(int i) {
  int j;
  if (match()) return 1;
  if (i < n) {
    for (j = 0; j < m; j++) {
      vis[j] += ar[i][j];
    }
    if (judge())
      if (dfs(i + 1)) return 1;
    for (j = 0; j < m; j++) {
      vis[j] -= ar[i][j];
    }
    if (dfs(i + 1)) return 1;
  }
  return 0;
}

int main() {
  int i, j;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) scanf("%d", &ar[i][j]);
    memset(vis, 0, sizeof(vis));
    if (dfs(0))
      printf("Yes, I found it\n");
    else
      printf("It is impossible\n");
  }
  return 0;
}
