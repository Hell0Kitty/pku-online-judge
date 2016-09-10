#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;
#define N 100010
#define M 200010

vector<int> ver[N];
int head[N], dfn[N], low[N], vis[N], fa[N], dcnt, bcnt;
struct edge {
  int u, v, used, next;
} e[2 * M];
bool isbridge[N];

inline void add(int u, int v, int &k) {
  e[k].v = v;
  e[k].used = 0;
  e[k].next = head[u];
  head[u] = k++;
}

void LCA(int u, int v) {
  if (dfn[u] < dfn[v]) swap(u, v);
  while (dfn[u] > dfn[v]) {
    if (isbridge[u]) bcnt--;
    isbridge[u] = false;
    u = fa[u];
  }
  while (u != v) {
    if (isbridge[u]) bcnt--;
    if (isbridge[v]) bcnt--;
    isbridge[u] = isbridge[v] = false;
    u = fa[u];
    v = fa[v];
  }
}

void dfs(int u) {
  vis[u] = 1;
  dfn[u] = low[u] = ++dcnt;
  for (int k = head[u]; k != -1; k = e[k].next)
    if (!e[k].used) {
      e[k].used = e[k ^ 1].used = 1;
      int v = e[k].v;
      if (!vis[v]) {
        fa[v] = u;
        dfs(v);
        low[u] = min(low[u], low[v]);
        if (dfn[u] < low[v]) {
          bcnt++;
          isbridge[v] = true;
        }
      } else if (vis[v] == 1)
        low[u] = min(low[u], dfn[v]);
    }
  vis[u] = 2;
}

int main() {
  int n, m, q, cas = 0;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (!n && !m) break;
    memset(head, -1, sizeof(head));
    int k = 0;
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(u, v, k);
      add(v, u, k);
    }
    memset(isbridge, false, sizeof(isbridge));
    memset(vis, 0, sizeof(vis));
    dcnt = bcnt = 0;
    fa[1] = 1;
    dfs(1);
    printf("Case %d:\n", ++cas);
    scanf("%d", &q);
    while (q--) {
      int u, v;
      scanf("%d%d", &u, &v);
      LCA(u, v);
      printf("%d\n", bcnt);
    }
    printf("\n");
  }
  return 0;
}
