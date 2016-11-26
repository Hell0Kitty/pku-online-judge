#include <stdio.h>
#include <string.h>
#define MAXD 110
#define MAXM 1010
int T, N, M, e, first[MAXD], next[MAXM], v[MAXM], d[MAXD], dfn[MAXD], low[MAXD],
    cnt;
void add(int x, int y) {
  v[e] = y;
  next[e] = first[x];
  first[x] = e;
  ++e;
}
void dfs(int x, int pre) {
  int i, j, k;
  low[x] = dfn[x] = ++cnt;
  for (i = first[x]; i != -1; i = next[i])
    if (v[i] != pre) {
      if (!dfn[v[i]]) {
        dfs(v[i], x);
        if (low[v[i]] < low[x]) low[x] = low[v[i]];
      } else if (dfn[v[i]] < low[x]) {
        low[x] = dfn[v[i]];
        d[v[i]] ^= (dfn[x] - dfn[v[i]]) % 2 ? 0 : 1;
      }
    }
}
int getsg(int x, int pre) {
  int i, j, k, h[MAXD], rear = 0, ans = d[x];
  for (i = first[x]; i != -1; i = next[i])
    if (v[i] != pre && low[v[i]] == dfn[v[i]]) h[rear++] = getsg(v[i], x) + 1;
  for (i = 0; i < rear; i++) ans ^= h[i];
  return ans;
}
void solve() {
  int i, j, k, t, x, y, z, ans = 0;
  for (t = 0; t < T; t++) {
    scanf("%d%d", &N, &M);
    memset(first, -1, sizeof(first[0]) * (N + 1));
    e = 0;
    for (i = 0; i < M; i++) {
      scanf("%d%d", &x, &y);
      add(x, y), add(y, x);
    }
    memset(d, 0, sizeof(d[0]) * (N + 1));
    memset(dfn, 0, sizeof(dfn[0]) * (N + 1));
    cnt = 0;
    dfs(1, -1);
    ans ^= getsg(1, -1);
  }
  if (ans)
    printf("Sally\n");
  else
    printf("Harry\n");
}
int main() {
  while (scanf("%d", &T) == 1) {
    solve();
  }
  return 0;
}
