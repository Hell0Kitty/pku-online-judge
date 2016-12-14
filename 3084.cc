#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define _Clr(x, y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;

const int N = 110;
int head[N], tot;
struct Edge {
  int to, next;
  int w;
  Edge(int u = 0, int v = 0, int w = 0) : to(v), next(head[u]), w(w) {}
} edge[2010];
int level[N];
int S, T;

inline void add_edge(int u, int v, int w1, int w2) {
  edge[tot] = Edge(u, v, w1);
  head[u] = tot++;

  edge[tot] = Edge(v, u, w2);
  head[v] = tot++;
}

bool bfs() {
  _Clr(level, -1);
  queue<int> Q;
  level[S] = 0;
  Q.push(S);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if (u == T) return true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (level[v] == -1 && edge[i].w > 0) {
        level[v] = level[u] + 1;
        Q.push(v);
      }
    }
  }
  return false;
}

int dfs(int u, int f) {
  int r = 0;
  if (u == T) return f;
  for (int i = head[u]; i != -1 && r < f; i = edge[i].next) {
    int v = edge[i].to;
    if (level[u] + 1 == level[v] && edge[i].w > 0) {
      int d = dfs(v, min(f - r, edge[i].w));
      r += d;
      edge[i].w -= d;
      edge[i ^ 1].w += d;
    }
  }
  if (r == 0) level[u] = -1;
  return r;
}

void Dinic() {
  int ans = 0;
  while (bfs()) ans += dfs(S, INF);
  if (ans >= INF)
    puts("PANIC ROOM BREACH");
  else
    printf("%d\n", ans);
}

void Print(int n) {
  for (int i = 0; i < S; i++) {
    for (int j = head[i]; j != -1; j = edge[j].next)
      printf("%d-%d; ", i, edge[j].to);
    puts("");
  }
}

int main() {
  int K, n, m;
  int a, d;
  char str[5];
  scanf("%d", &K);
  while (K--) {
    scanf("%d%d", &n, &m);
    S = n + 1;
    T = m;
    tot = 0;
    _Clr(head, -1);
    for (int i = 0; i < n; i++) {
      scanf("%s %d", str, &d);
      if (str[0] == 'I') add_edge(S, i, INF, 0);
      while (d--) {
        scanf("%d", &a);
        add_edge(i, a, INF, 1);
      }
    }
    Dinic();
  }
  return 0;
}
