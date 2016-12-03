#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 4100;
const int maxm = 30000;
const int inf = 1 << 29;
struct node {
  int h;
  int m;
  int s;
  bool operator<(const node a) const {
    return h < a.h || (h == a.h && m < a.m) ||
           (h == a.h && m == a.m && s < a.s);
  }
  bool operator>(const node a) const {
    return h > a.h || (h == a.h && m > a.m) ||
           (h == a.h && m == a.m && s > a.s);
  }
  bool operator==(const node a) const {
    return h == a.h && m == a.m && s == a.s;
  }

} a[maxn], b[maxn], c[maxn];
int st, des, n, m, k, e, w[maxn], head[maxn], nxt[maxm], cost[maxm], flow[maxm],
    pnt[maxm], pre[maxn], dist[maxm];
bool vis[maxn];
queue<int> q;
void AddEdge(int u, int v, int f, int c) {
  pnt[e] = v;
  nxt[e] = head[u];
  cost[e] = c;
  flow[e] = f;
  head[u] = e++;
  pnt[e] = u;
  nxt[e] = head[v];
  cost[e] = -c;
  flow[e] = 0;
  head[v] = e++;
}
int Search(node a) {
  int l = 1, r = m - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (c[mid] == a) return mid;
    if (c[mid] < a)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
bool Spfa() {
  memset(dist, -1, sizeof(dist));
  memset(pre, -1, sizeof(pre));
  q.push(st);
  dist[st] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; i != -1; i = nxt[i]) {
      int v = pnt[i];
      if (flow[i] && dist[v] < dist[u] + cost[i]) {
        dist[v] = dist[u] + cost[i];
        pre[v] = i;
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  return dist[des] != -1;
}
int maxflow() {
  int ans = 0;
  while (Spfa()) {
    int mini = inf;
    for (int i = pre[des]; i != -1; i = pre[pnt[i ^ 1]])
      mini = min(mini, flow[i]);
    for (int i = pre[des]; i != -1; i = pre[pnt[i ^ 1]]) {
      flow[i] -= mini;
      flow[i ^ 1] += mini;
    }
    ans += mini * dist[des];
  }
  return ans;
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    e = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < n; i++) {
      scanf("%d:%d:%d", &a[i << 1].h, &a[i << 1].m, &a[i << 1].s);
      scanf("%d:%d:%d", &a[i << 1 | 1].h, &a[i << 1 | 1].m, &a[i << 1 | 1].s);
      b[i << 1] = a[i << 1];
      b[i << 1 | 1] = a[i << 1 | 1];
      scanf("%d", &w[i]);
    }
    sort(b, b + n * 2);
    m = 1;
    c[m++] = b[0];
    for (int i = 1; i < n * 2; i++)
      if (!(b[i] == b[i - 1])) c[m++] = b[i];
    st = 0, des = m;
    for (int i = 0; i < m; i++) AddEdge(i, i + 1, k, 0);
    for (int i = 0; i < n; i++) {
      int x = Search(a[i << 1]);
      int y = Search(a[i << 1 | 1]);
      AddEdge(x, y, 1, w[i]);
    }
    printf("%d\n", maxflow());
  }
  return 0;
}
