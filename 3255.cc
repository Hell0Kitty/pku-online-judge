#include <iostream>
#include <queue>
using namespace std;
#define MAXV 5010
#define MAXE 200100
#define INF 1 << 29

typedef struct { int t, w, next; } Edge;
Edge edge[MAXE];

int d[MAXV], dr[MAXV];
int n, m, edge_sum;
int head[MAXV];
bool vis[MAXV];

void init() {
  memset(head, -1, sizeof(head));
  edge_sum = 0;
  for (int i = 1; i <= n; i++) d[i] = dr[i] = INF;
}

void addedge(int s, int t, int w) {
  edge[edge_sum].t = t;
  edge[edge_sum].w = w;
  edge[edge_sum].next = head[s];
  head[s] = edge_sum++;
}

void spfa(int source, int dt[]) {
  int i, v, u;
  queue<int> q;
  memset(vis, 0, sizeof(vis));
  dt[source] = 0;
  vis[source] = 1;
  q.push(source);
  while (!q.empty()) {
    v = q.front();
    q.pop();
    vis[v] = 0;

    for (i = head[v]; i != -1; i = edge[i].next) {
      u = edge[i].t;
      if (dt[v] + edge[i].w < dt[u]) {
        dt[u] = dt[v] + edge[i].w;
        if (!vis[u]) {
          vis[u] = 1;
          q.push(u);
        }
      }
    }
  }
}

int main() {
  int a, b, c;
  int ans, tmp, i;
  while (~scanf("%d%d", &n, &m)) {
    init();
    while (m--) {
      scanf("%d%d%d", &a, &b, &c);
      addedge(a, b, c);
      addedge(b, a, c);
    }

    spfa(1, d);
    spfa(n, dr);

    ans = INF;
    for (i = 1; i <= n; i++) {
      for (int j = head[i]; j != -1; j = edge[j].next) {
        b = edge[j].t;
        c = edge[j].w;
        tmp = d[i] + dr[b] + c;
        if (tmp > d[n] && ans > tmp) {
          ans = tmp;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
