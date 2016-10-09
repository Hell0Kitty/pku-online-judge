#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX = 2000 + 10;
int n, m, size, top, index;
int uu[MAX * MAX], vv[MAX * MAX], cc[MAX * MAX];
int head[MAX], dfn[MAX], low[MAX];
bool mark[MAX * MAX];

struct Edge {
  int v, id, next;
  Edge() {}
  Edge(int V, int Id, int NEXT) : v(V), id(Id), next(NEXT) {}
} edge[MAX * MAX];

void Init(int num) {
  for (int i = 0; i <= num; ++i) head[i] = -1, dfn[i] = 0;
  size = top = index = 0;
}

void InsertEdge(int u, int v, int id) {
  edge[size] = Edge(v, id, head[u]);
  head[u] = size++;
}

void tarjan(int u, int father) {
  if (dfn[u]) return;
  dfn[u] = low[u] = ++index;
  bool flag = true;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v, id = edge[i].id;
    if (v == father && flag) {
      flag = false;
      continue;
    }
    tarjan(v, u);
    low[u] = min(low[u], low[v]);
    if (low[v] <= dfn[u] && !mark[id]) uu[id] = u, vv[id] = v, mark[id] = true;
  }
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    Init(n);
    for (int i = 1; i <= m; ++i) {
      scanf("%d%d%d", &uu[i], &vv[i], &cc[i]);
      InsertEdge(uu[i], vv[i], i);
      if (cc[i] == 2) InsertEdge(vv[i], uu[i], i);
      mark[i] = false;
    }
    for (int i = 1; i <= n; ++i) tarjan(i, -1);
    for (int i = 1; i <= m; ++i) {
      if (cc[i] == 2) {
        printf("%d %d %d\n", uu[i], vv[i], mark[i] ? 1 : 2);
      }
    }
  }
  return 0;
}
