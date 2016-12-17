#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 555
#define inf 1 << 30

struct Edge {
  int v, w;
  Edge(int vv, int ww) : v(vv), w(ww) {}
};

int dfn[MAXN], low[MAXN], color[MAXN];
bool mark[MAXN];
int dist[MAXN];
int n, m, k, cnt, _count;

vector<vector<Edge> > map;
stack<int> S;

void Tarjan(int u) {
  dfn[u] = low[u] = ++cnt;
  mark[u] = true;
  S.push(u);
  for (int i = 0; i < map[u].size(); i++) {
    int v = map[u][i].v;
    if (dfn[v] == 0) {
      Tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (mark[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    int v;
    _count++;
    do {
      v = S.top();
      S.pop();
      mark[v] = false;
      color[v] = _count;
    } while (u != v);
  }
}

int SPFA(int st, int ed) {
  for (int i = 1; i <= n; i++) dist[i] = inf;
  dist[st] = 0;
  queue<int> Q;
  Q.push(st);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    mark[u] = false;
    for (int i = 0; i < map[u].size(); i++) {
      int v = map[u][i].v, w = map[u][i].w;
      if (color[u] == color[v]) w = 0;
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        if (!mark[v]) {
          mark[v] = true;
          Q.push(v);
        }
      }
    }
  }
  return dist[ed] < inf;
}

int main() {
  int u, v, w;
  while (~scanf("%d", &n) && n) {
    scanf("%d", &m);
    map.clear();
    map.resize(n + 2);
    while (m--) {
      scanf("%d%d%d", &u, &v, &w);
      map[u].push_back(Edge(v, w));
    }
    cnt = _count = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(mark, false, sizeof(mark));
    for (int i = 1; i <= n; i++) {
      if (dfn[i] == 0) Tarjan(i);
    }
    scanf("%d", &k);
    while (k--) {
      scanf("%d%d", &u, &v);
      if (SPFA(u, v))
        printf("%d\n", dist[v]);
      else
        puts("Nao e possivel entregar a carta");
    }
    puts("");
  }
  return 0;
}
