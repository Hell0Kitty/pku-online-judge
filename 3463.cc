#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define MAXN 1005
#define MAXM 500005
#define INF 1000000000
using namespace std;
struct node {
  int v, next, w;
} edge[MAXM];
int d[MAXN][2], e, n, m;
int cnt[MAXN][2];
int head[MAXN];
bool vis[MAXN][2];
void init() {
  e = 0;
  memset(head, -1, sizeof(head));
}
void insert(int x, int y, int w) {
  edge[e].v = y;
  edge[e].w = w;
  edge[e].next = head[x];
  head[x] = e++;
}
int dijkstra(int s, int t) {
  int flag, u;
  memset(vis, 0, sizeof(vis));
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) d[i][0] = d[i][1] = INF;
  cnt[s][0] = 1;
  d[s][0] = 0;
  for (int i = 1; i < 2 * n; i++) {
    int mini = INF;
    for (int j = 1; j <= n; j++) {
      if (!vis[j][0] && d[j][0] < mini) {
        u = j;
        flag = 0;
        mini = d[j][0];
      } else if (!vis[j][1] && d[j][1] < mini) {
        u = j;
        flag = 1;
        mini = d[j][1];
      }
    }
    if (mini == INF) break;
    vis[u][flag] = 1;
    for (int j = head[u]; j != -1; j = edge[j].next) {
      int w = edge[j].w;
      int v = edge[j].v;
      if (d[v][0] > mini + w) {
        d[v][1] = d[v][0];
        cnt[v][1] = cnt[v][0];
        d[v][0] = mini + w;
        cnt[v][0] = cnt[u][flag];
      } else if (d[v][0] == mini + w)
        cnt[v][0] += cnt[u][flag];
      else if (d[v][1] > mini + w) {
        d[v][1] = mini + w;
        cnt[v][1] = cnt[u][flag];
      } else if (d[v][1] == mini + w)
        cnt[v][1] += cnt[u][flag];
    }
  }
  int ans = 0;
  if (d[t][1] == d[t][0] + 1)
    ans = cnt[t][1] + cnt[t][0];
  else
    ans = cnt[t][0];
  return ans;
}
int main() {
  int s, t, T, x, y, w;
  scanf("%d", &T);
  while (T--) {
    init();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
      scanf("%d%d%d", &x, &y, &w);
      insert(x, y, w);
    }
    scanf("%d%d", &s, &t);
    printf("%d\n", dijkstra(s, t));
  }
  return 0;
}
