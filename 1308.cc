#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 1006

struct Edge {
  int v, next;
} edge[1000005];

int name[maxn];
int n, ecount, tot, root;
int in[maxn];
int head[maxn];
bool vis[maxn];
bool ok;

void addedge(int a, int b) {
  edge[ecount].next = head[a];
  edge[ecount].v = b;
  head[a] = ecount;
  in[b]++;
  ecount++;
}

int find(int a) {
  for (int i = 0; i < n; i++)
    if (name[i] == a) return i;
  name[n++] = a;
  return n - 1;
}

void dfs(int root) {
  vis[root] = true;
  tot++;
  for (int i = head[root]; i != -1; i = edge[i].next) {
    if (vis[edge[i].v]) {
      ok = false;
      return;
    }
    if (!ok) return;
    dfs(edge[i].v);
  }
}

int main() {
  int t = 0;
  while (1) {
    t++;
    memset(in, 0, sizeof(in));
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    ecount = 0;
    n = 0;
    tot = 0;
    ok = true;
    int a, b;
    scanf("%d%d", &a, &b);
    if (a < 0 && b < 0) return 0;
    if (a == 0 && b == 0) {
      printf("Case %d is a tree.\n", t);
      continue;
    }
    a = find(a);
    b = find(b);
    addedge(a, b);
    while (1) {
      scanf("%d%d", &a, &b);
      if (a == 0 && b == 0) break;
      a = find(a);
      b = find(b);
      addedge(a, b);
    }
    root = -1;
    for (int i = 0; i < n; i++)
      if (in[i] == 0) root = i;
    if (root >= 0) dfs(root);
    if (ok && tot == n && root >= 0)
      printf("Case %d is a tree.\n", t);
    else
      printf("Case %d is not a tree.\n", t);
  }
  return 0;
}
