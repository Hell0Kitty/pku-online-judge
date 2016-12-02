#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10010;

struct Edge {
  int to, nxt;
} edge[N << 2];

int head[N], vis[N], dfn[N], low[N], cut[N];  // cut[u] 表示u这个点割边数
int cnt, k, root;

void addedge(int cu, int cv) {
  edge[cnt].to = cv;
  edge[cnt].nxt = head[cu];
  head[cu] = cnt++;
}

void Tarjan(int u, int fa) {  //割点模板
  int son = 0;
  vis[u] = 1;
  dfn[u] = low[u] = ++k;
  for (int i = head[u]; i != -1; i = edge[i].nxt) {
    int v = edge[i].to;
    if (vis[v] == 1 && v != fa) low[u] = min(low[u], dfn[v]);
    if (!vis[v]) {
      Tarjan(v, u);
      son++;
      low[u] = min(low[u], low[v]);
      if ((u == root && son > 1) || (u != root && dfn[u] <= low[v]))
        cut[u]++;  // cut[u] 表示u这个点割边数
    }
  }
  vis[u] = 2;
}

int main() {
  // freopen("input.txt","r",stdin);

  int n, m;
  while (~scanf("%d%d", &n, &m) && n) {
    if (m == 0) {
      printf("%d\n", n - 1);
      continue;
    }
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(cut, 0, sizeof(cut));
    memset(dfn, 0, sizeof(dfn));
    cnt = 0;
    int u, v;
    while (m--) {
      scanf("%d%d", &u, &v);
      addedge(u, v);
      addedge(v, u);
    }
    int ans = 0;
    int MAX = 0;
    for (int i = 0; i < n; i++) {
      if (!dfn[i]) {
        ans++;
        k = 0;
        root = i;
        Tarjan(i, -1);
      }
      MAX = max(MAX, cut[i]);  //取最大的
    }
    printf("%d\n", ans + MAX);
  }
  return 0;
}
