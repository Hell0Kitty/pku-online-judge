#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define MAXN 1005
#define MAXM 100005
#define INF 1000000000
using namespace std;
struct Edge {
  int v, w, next;
} edge[MAXM];
struct Node {
  int v, cost, f;
  bool operator<(const Node &a) const { return a.cost < cost; }
};
int head[MAXN], e, n, m, cap;
int dp[MAXN][105], used[MAXN][105], p[MAXN];
int s, t, ask;
priority_queue<Node> q;
void init() {
  memset(head, -1, sizeof(head));
  e = 0;
}
void ready() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= 100; j++) dp[i][j] = INF;
  dp[s][0] = 0;
  memset(used, 0, sizeof(used));
  while (!q.empty()) q.pop();
}
void insert(int x, int y, int w) {
  edge[e].v = y;
  edge[e].w = w;
  edge[e].next = head[x];
  head[x] = e++;
}
int bfs() {
  Node a, b;
  a.v = s, a.cost = 0, a.f = 0;
  q.push(a);
  while (!q.empty()) {
    a = q.top();
    q.pop();
    int u = a.v;
    int cost = a.cost;
    int f = a.f;
    used[u][f] = 1;
    if (u == t) return cost;
    if (f + 1 <= cap && !used[u][f + 1] && dp[u][f + 1] > dp[u][f] + p[u]) {
      dp[u][f + 1] = dp[u][f] + p[u];
      b.v = u;
      b.f = f + 1;
      b.cost = dp[u][f + 1];
      q.push(b);
    }
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].v;
      int w = edge[i].w;
      if (f >= w && !used[v][f - w] && dp[v][f - w] > cost) {
        dp[v][f - w] = cost;
        b.v = v;
        b.f = f - w;
        b.cost = dp[v][f - w];
        q.push(b);
      }
    }
  }
  return -1;
}
int main() {
  int x, y, w;
  scanf("%d%d", &n, &m);
  init();
  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
  while (m--) {
    scanf("%d%d%d", &x, &y, &w);
    insert(x, y, w);
    insert(y, x, w);
  }
  scanf("%d", &ask);
  while (ask--) {
    scanf("%d%d%d", &cap, &s, &t);
    ready();
    int ans = bfs();
    if (ans != -1)
      printf("%d\n", ans);
    else
      printf("impossible\n");
  }
  return 0;
}
