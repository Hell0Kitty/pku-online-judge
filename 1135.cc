#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 505
#define maxm maxn *maxn
#define inf 0x3f3f3f3f

struct Edge {
  int v, w, next;
} edge[maxm];

int n, m;
int head[maxn];
int edge_num;
int q[maxn];
int dist[maxn];
bool vis[maxn];

void addedge(int a, int b, int w) {
  edge[edge_num].v = b;
  edge[edge_num].w = w;
  edge[edge_num].next = head[a];
  head[a] = edge_num++;
}

void input() {
  memset(head, -1, sizeof(head));
  edge_num = 0;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    a--;
    b--;
    addedge(a, b, w);
    addedge(b, a, w);
  }
}

bool relax(int u, Edge &e) {
  if (dist[e.v] > dist[u] + e.w) {
    dist[e.v] = dist[u] + e.w;
    return true;
  }
  return false;
}

bool spfa(int x) {
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) dist[i] = inf;
  int front = 0;
  int rear = 1;
  q[front] = x;
  dist[x] = 0;
  vis[x] = true;
  while (front != rear) {
    int temp = q[front++];
    if (front == maxn) front = 0;
    vis[temp] = false;
    for (int i = head[temp]; i != -1; i = edge[i].next) {
      if (relax(temp, edge[i]) && !vis[edge[i].v]) {
        q[rear++] = edge[i].v;
        if (rear == maxn) rear = 0;
      }
    }
  }
  return false;
}

double get_time(int a, int b, int w) {
  if (a > b) swap(a, b);
  if (a + w <= b) return b;
  return b + (w - (b - a)) * 1.0 / 2;
}

void work() {
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (dist[ans] < dist[i]) ans = i;
  int a, b;
  double max_time;
  max_time = dist[ans];
  for (int u = 0; u < n; u++)
    for (int i = head[u]; ~i; i = edge[i].next) {
      int v = edge[i].v;
      double temp = get_time(dist[u], dist[v], edge[i].w);
      if (temp > max_time) {
        a = min(u, v);
        b = max(u, v);
        max_time = temp;
      }
    }
  if (max_time > dist[ans])
    printf(
        "The last domino falls after %.1f seconds, between key dominoes %d and "
        "%d.\n",
        max_time, a + 1, b + 1);
  else
    printf("The last domino falls after %.1f seconds, at key domino %d.\n",
           (double)dist[ans], ans + 1);
}

int main() {
  int t = 0;
  while (scanf("%d%d", &n, &m), n | m) {
    printf("System #%d\n", ++t);
    input();
    spfa(0);
    work();
    puts("");
  }
  return 0;
}
