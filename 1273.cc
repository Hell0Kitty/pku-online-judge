#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define MAXN 210
#define INF 0x3f3f3f3f

struct Edge {
  int st, ed;
  int c;
  int next;
} edge[MAXN << 1];

int n, m;
int s, t;
int ans;
int e = 0;
int head[MAXN];
int d[MAXN];

int min(int a, int b) { return a < b ? a : b; }

void init() {
  int i, j;
  int a, b, c;
  s = 1;
  t = m;
  e = 0;
  ans = 0;
  memset(head, -1, sizeof(head));
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &a, &b, &c);
    edge[e].st = a;
    edge[e].ed = b;
    edge[e].c = c;
    edge[e].next = head[a];
    head[a] = e++;
    edge[e].st = b;
    edge[e].ed = a;
    edge[e].next = head[b];
    head[b] = e++;
  }
}

int bfs() {
  memset(d, -1, sizeof(d));
  queue<int> q;
  d[s] = 0;
  q.push(s);
  int i;
  int cur;
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    for (i = head[cur]; i != -1; i = edge[i].next) {
      if (d[edge[i].ed] == -1 && edge[i].c > 0) {
        d[edge[i].ed] = d[cur] + 1;
        q.push(edge[i].ed);
      }
    }
  }
  if (d[t] < 0) return 0;
  return 1;
}

int dinic(int x, int flow) {
  if (x == t) return flow;
  int i, a;
  for (i = head[x]; i != -1; i = edge[i].next) {
    if (d[edge[i].ed] == d[x] + 1 && edge[i].c > 0 &&
        (a = dinic(edge[i].ed, min(flow, edge[i].c)))) {
      edge[i].c -= a;
      edge[i ^ 1].c += a;
      return a;
    }
  }
  return 0;
}

void solve() {
  while (scanf("%d%d", &n, &m) != EOF) {
    init();
    while (bfs()) {
      int increment;
      increment = dinic(1, INF);
      ans += increment;
    }
    printf("%d\n", ans);
  }
}

int main() {
  solve();
  return 0;
}
