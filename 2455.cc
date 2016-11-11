#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

const int MAXN = 300;
const int MAXM = 90000;
const int INF = 0x3f3f3f3f;
struct Edge {
  int to, next, cap;
};

struct rawEdge {
  int from, to, dis;
};

Edge edge[MAXM];
rawEdge rawedge[MAXM];
int head[MAXN], level[MAXN];
int dis[250][250];
int src, des, cnt;

void addedge(int from, int to, int cap) {
  edge[cnt].to = to;
  edge[cnt].cap = cap;
  edge[cnt].next = head[from];
  head[from] = cnt++;

  edge[cnt].to = from;
  edge[cnt].cap = cap;
  edge[cnt].next = head[to];
  head[to] = cnt++;
}

int bfs() {
  queue<int> q;
  while (!q.empty()) q.pop();
  memset(level, -1, sizeof level);
  level[src] = 0;
  q.push(src);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (edge[i].cap && level[v] == -1) {
        level[v] = level[u] + 1;
        q.push(v);
      }
    }
  }
  return level[des] != -1;
}

int dfs(int u, int f) {
  if (u == des) return f;
  int tem;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (edge[i].cap > 0 && level[v] == level[u] + 1) {
      tem = dfs(v, min(f, edge[i].cap));
      if (tem > 0) {
        edge[i].cap -= tem;
        edge[i ^ 1].cap += tem;
        return tem;
      }
    }
  }
  level[u] = -1;
  return 0;
}

int Dinic() {
  int ans = 0, tem;

  while (bfs()) {
    while (tem = dfs(src, INF)) {
      ans += tem;
    }
  }
  return ans;
}

int main() {
  int n, m, t;
  int low, high, mid;
  while (scanf("%d%d%d", &n, &m, &t) == 3) {
    low = INF;
    high = 0;
    src = 1;
    des = n;
    for (int i = 0; i < m; i++) {
      int f, t, d;
      scanf("%d%d%d", &f, &t, &d);
      rawedge[i].from = f;
      rawedge[i].to = t;
      rawedge[i].dis = d;
      low = min(low, d);
      high = max(high, d);
    }

    while (low < high) {
      mid = (low + high) / 2;
      memset(head, -1, sizeof(head));
      cnt = 0;
      for (int i = 0; i < m; i++) {
        if (rawedge[i].dis <= mid) addedge(rawedge[i].from, rawedge[i].to, 1);
      }

      if (Dinic() < t)
        low = mid + 1;
      else
        high = mid;
    }
    printf("%d\n", low);
  }
  return 0;
}
