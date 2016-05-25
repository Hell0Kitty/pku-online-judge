#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 10005
#define maxm 100005

struct Edge {
  int v, next;
} edge[maxm];

int n, m;
int head[maxn];
int ecount;
bool vis[maxm];

void addedge(int a, int b) {
  edge[ecount].v = b;
  edge[ecount].next = head[a];
  head[a] = ecount++;
}

void dfs(int a) {
  for (int i = head[a]; i != -1; i = edge[i].next) {
    if (vis[i]) continue;
    int v = edge[i].v;
    vis[i] = true;
    dfs(v);
  }
  printf("%d\n", a + 1);
}

int main() {
  memset(head, -1, sizeof(head));
  ecount = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    addedge(a, b);
    addedge(b, a);
  }
  memset(vis, 0, sizeof(vis));
  dfs(0);
  return 0;
}
