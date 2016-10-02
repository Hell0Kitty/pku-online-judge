#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
#define inf 1000000000

using namespace std;

struct xxoo {
  int to;
  __int64 cap;
  int rev;
};
int n, m, ans;
__int64 sum;
__int64 profit[7010];
int level[7010];
int iter[7010];
vector<xxoo> g[7010];

void init() {
  for (int i = 0; i < n; i++) g[i].clear();
  sum = 0;
  for (int p = 0; p < n; p++) {
    scanf("%I64d", &profit[p]);
    if (profit[p] > 0) sum += profit[p];
  }
  for (int j = 0; j < m; j++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back((xxoo){b, inf, g[b].size()});
    g[b].push_back((xxoo){a, 0, g[a].size() - 1});
  }
  for (int x = 1; x <= n; x++) {
    if (profit[x - 1] > 0) {
      g[0].push_back((xxoo){x, profit[x - 1], g[x].size()});
      g[x].push_back((xxoo){0, 0, g[0].size() - 1});
    } else if (profit[x - 1] < 0) {
      g[x].push_back((xxoo){n + 1, ~(profit[x - 1] - 1), g[n + 1].size()});
      g[n + 1].push_back((xxoo){x, 0, g[x].size() - 1});
    }
  }
}
void bfs(int s) {
  memset(level, -1, sizeof(level));
  queue<int> que;
  level[s] = 0;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int i = 0; i < g[v].size(); i++) {
      xxoo &e = g[v][i];
      if (e.cap > 0 && level[e.to] < 0) {
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
}
__int64 dfs(int s, int t, __int64 f) {
  if (s == t) return f;
  for (int &i = iter[s]; i < g[s].size(); i++) {
    xxoo &e = g[s][i];
    if (level[s] < level[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}
int dfs_point(int s) {
  iter[s] = 1;
  for (int i = 0; i < g[s].size(); i++) {
    xxoo &e = g[s][i];
    if (!iter[e.to] && e.cap > 0) {
      dfs_point(e.to);
      ans++;
    }
  }
}
void max_flow() {
  __int64 flow = 0;
  for (;;) {
    bfs(0);
    if (level[n + 1] < 0) break;
    memset(iter, 0, sizeof(iter));
    int f;
    while ((f = dfs(0, n + 1, inf)) > 0) {
      flow += f;
    }
  }
  memset(iter, 0, sizeof(iter));
  ans = 0;
  dfs_point(0);
  printf("%d %I64d\n", ans, sum - flow);
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    init();
    max_flow();
  }
  return 0;
}
