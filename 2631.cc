#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int imax_n = 10005;
struct node {
  int u, v, c;
  node() {}
  node(int u, int v, int c) : u(u), v(v), c(c) {}
} p[2 * imax_n];
int e;
int head[imax_n];
int next[imax_n * 2];
void addEdge(int u, int v, int c) {
  p[e] = node(u, v, c);
  next[e] = head[u];
  head[u] = e++;
}
void init() {
  memset(head, -1, sizeof(head));
  memset(next, -1, sizeof(next));
  e = 0;
}
bool vis[imax_n];
int dis[imax_n];
queue<int> q;
int bfs(int s) {
  int ans = 0;
  int temp_node;
  while (!q.empty()) q.pop();
  memset(vis, 0, sizeof(vis));
  q.push(s);
  vis[s] = 1;
  memset(dis, 0, sizeof(dis));
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (dis[x] > ans) {
      ans = dis[x];
      temp_node = x;
    }
    for (int i = head[x]; i + 1; i = next[i]) {
      int y = p[i].v;
      if (!vis[y]) {
        vis[y] = 1;
        q.push(y);
        if (dis[x] + p[i].c > dis[y]) dis[y] = dis[x] + p[i].c;
      }
    }
  }
  return temp_node;
}
int main() {
  int x, y, c;
  init();
  while (scanf("%d%d%d", &x, &y, &c) != EOF) {
    addEdge(x, y, c);
    addEdge(y, x, c);
  }
  x = bfs(1);
  y = bfs(x);
  printf("%d\n", dis[y]);
  return 0;
}
