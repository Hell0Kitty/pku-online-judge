#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
using namespace std;
const int MAX = 100000;
const int INF = 0xfffffff;

struct Edge {
  int v, f, nxt;
};
int n, m, k;
int src, sink;
int nume = 1;
int num = 1;
map<string, int> rec_dev;
int g[MAX];
Edge e[MAX];
int dist[MAX], vis[MAX];
string plux, device;
void addEdge(int u, int v, int c) {
  e[++nume].v = v;
  e[nume].f = c;
  e[nume].nxt = g[u];
  g[u] = nume;
}
void BFS() {
  memset(vis, 0, sizeof(vis));
  queue<int> que;
  que.push(src);
  dist[src] = 0;
  vis[src] = 1;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = g[u]; i; i = e[i].nxt)
      if (e[i].f && !vis[e[i].v]) {
        que.push(e[i].v);
        dist[e[i].v] = dist[u] + 1;
        vis[e[i].v] = 1;
      }
  }
}
int DFS(int u, int delta) {
  if (u == sink) return delta;
  int ret = 0;
  for (int i = g[u]; delta && i; i = e[i].nxt)
    if (dist[e[i].v] == dist[u] + 1) {  // e[i].f &&
      int dd = DFS(e[i].v, e[i].f < delta ? e[i].f : delta);
      e[i].f -= dd;
      e[i ^ 1].f += dd;
      delta -= dd;
      ret += dd;
    }
  return ret;
}
int Dinic() {
  int ret = 0;
  while (true) {
    memset(dist, 0, sizeof(dist));
    BFS();
    while (!vis[sink]) return ret;
    ret += DFS(src, INF);
  }
}
int main() {
  memset(g, 0, sizeof(g));
  src = 1;
  sink = MAX - 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> plux;
    rec_dev[plux] = ++num;
    addEdge(num, sink, 1);
    addEdge(sink, num, 0);
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> device >> plux;
    rec_dev[device] = ++num;
    if (!rec_dev[plux]) rec_dev[plux] = ++num;
    addEdge(src, rec_dev[device], 1);
    addEdge(rec_dev[device], src, 0);
    addEdge(rec_dev[device], rec_dev[plux], 1);
    addEdge(rec_dev[plux], rec_dev[device], 0);
  }
  cin >> k;
  for (int i = 1; i <= k; i++) {
    cin >> device >> plux;
    if (!rec_dev[device]) rec_dev[device] = ++num;
    if (!rec_dev[plux]) rec_dev[plux] = ++num;
    addEdge(rec_dev[device], rec_dev[plux], INF);
    addEdge(rec_dev[plux], rec_dev[device], 0);
  }
  cout << m - Dinic() << endl;
  return 0;
}