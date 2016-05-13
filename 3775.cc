#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define Inf 0x3f3f3f3f
using namespace std;
const int maxn = 110;
const int maxm = 10005 * 2;
struct Node {
  int v, w, next;
  Node() {}
  Node(int v, int w, int next) {
    this->v = v;
    this->w = w;
    this->next = next;
  }
};
Node edges[maxm];
int head[maxn];
int len;

int dist[maxn], pre[maxn];
bool visit[maxn];
int adj_num[maxn];
int n, m, p;

double dp[maxn][maxn], PT[maxn][maxn], f[maxn][maxn];

inline double max(double x, double y) { return x > y ? x : y; }

inline double min(double x, double y) { return x < y ? x : y; }

void Init() {
  len = 0;
  memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int w) {
  edges[len].v = v;
  edges[len].w = w;
  edges[len].next = head[u];
  head[u] = len++;
}

void SPFA(int source) {
  queue<int> Q;
  int u, v;
  memset(visit, false, sizeof(visit));
  memset(dist, Inf, sizeof(dist));
  memset(pre, -1, sizeof(pre));
  dist[source] = 0, visit[source] = true;
  Q.push(source);
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    visit[u] = false;
    for (int i = head[u]; i != -1; i = edges[i].next) {
      v = edges[i].v;
      if (dist[v] > dist[u] + edges[i].w) {
        dist[v] = dist[u] + edges[i].w;
        pre[v] = u;
        if (!visit[v]) {
          visit[v] = true;
          Q.push(v);
        }
      }
    }
  }
  return;
}

double solve(int u, int left) {
  int i, j, k, t;
  if (dp[u][left] > 0) return dp[u][left];
  if (adj_num[u] == 0) return (dp[u][left] = PT[u][left]);

  for (i = head[u]; i != -1; i = edges[i].next) {
    for (j = 0; j <= left; ++j) {
      solve(edges[i].v, j);
    }
  }

  for (i = 0; i <= adj_num[u]; ++i) {
    for (j = 0; j <= left; ++j) {
      f[i][j] = 0.0;
    }
  }

  for (i = head[u], k = 1; i != -1; i = edges[i].next, ++k) {
    for (j = 0; j <= left; ++j) {
      for (t = 0; t <= j; ++t) {
        f[k][j] = max(f[k][j], f[k - 1][j - t] + dp[edges[i].v][t]);
      }
    }
  }
  k--;

  dp[u][left] = PT[u][left];
  for (j = 0; j <= left; ++j) {
    dp[u][left] = max(dp[u][left],
                      PT[u][j] + (1 - PT[u][j]) * f[k][left - j] / (k * 1.0));
  }
  return dp[u][left];
}

int main() {
  int u, v, w;
  while (scanf("%d %d", &n, &m) && n + m) {
    Init();
    for (int i = 0; i < m; ++i) {
      scanf("%d %d %d", &u, &v, &w);
      addEdge(u + 1, v + 1, w);
      addEdge(v + 1, u + 1, w);
    }
    scanf("%d", &p);
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= p; ++j) {
        PT[i][j] = 0.0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= p; ++j) {
        scanf("%lf", &PT[i][j]);
        dp[i][j] = -1.0;
      }
    }
    SPFA(1);
    Init();
    memset(adj_num, 0, sizeof(adj_num));
    for (int i = 1; i <= n; ++i) {
      if (pre[i] != -1) {
        adj_num[pre[i]]++;
        addEdge(pre[i], i, 0);
      }
    }
    printf("%.2lf\n", solve(1, p) * 100.0);
  }
  return 0;
}
