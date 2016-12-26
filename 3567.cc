#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <stack>
#include <time.h>
#include <cmath>
#include <cstdlib>
#define MAXN 50005
#define INF 1e8
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
using namespace std;
struct Node {
  int w, p;
} node[MAXN];
int vcnt;
struct edge {
  int u, v, id, next;
} E[500000];
int head[MAXN], ecnt;
int low[MAXN], dfn[MAXN], col[MAXN], dis[MAXN];
int W[MAXN];  //每个点的权值
int t[MAXN];
bool vis[MAXN];
int N, M, Index, ans, root;
void Insert(int u, int v) {
  E[ecnt].u = u;
  E[ecnt].v = v;
  E[ecnt].id = ecnt;
  E[ecnt].next = head[u];
  head[u] = ecnt++;
}
void Init() {
  int i, j, u, v, w;
  memset(head, -1, sizeof(head));
  ecnt = 0;
  for (i = 1; i <= M; i++) {
    scanf("%d", &w);
    scanf("%d", &u);
    for (j = 2; j <= w; j++) {
      scanf("%d", &v);
      Insert(u, v);
      Insert(v, u);
      u = v;
    }
  }
}
int cmp(const void *p1, const void *p2) {
  return ((struct Node *)p2)->w - ((struct Node *)p1)->w;
}
stack<int> _S;
void Run(int n) {
  int i, j, p1, p2;
  for (i = 0; i < vcnt; i++) {
    p1 = node[i].p;
    int res = 0;
    for (j = i + 1; j < vcnt; j++) {
      p2 = node[j].p;
      res = max(res, min(abs(p2 - p1), n - abs(p2 - p1)) + node[j].w);
    }
    ans = max(ans, res + node[i].w);
  }
  qsort(node, vcnt, sizeof(node[0]), cmp);
  ans = max(ans, node[0].w + n / 2);
}
void Judge(int t[], int num, int now) {
  int i, v, res = 0;
  vcnt = 0;
  for (i = 0; i < num - 1; i++) {
    v = t[i];
    if (W[v]) {
      node[vcnt].w = W[v];
      node[vcnt++].p = i;
    }
    res = max(res, min(num - 1 - i, i + 1) + W[v]);
  }
  ans = max(ans, W[now] + res);  //跟新答案
  W[now] = max(W[now], res);     //更新节点
  Run(num);
}
void dfs(int now, int father) {
  int i, v, x;
  col[now] = 1;
  low[now] = dfn[now] = ++Index;
  for (i = head[now]; i != -1; i = E[i].next) {
    v = E[i].v;
    if (v != father && col[v] == 1)  //反向边
    {
      _S.push(E[i].id);
      low[now] = min(low[now], dfn[v]);
    }
    if (col[v] == 0)  //树边
    {
      _S.push(E[i].id);
      dfs(v, now);
      low[now] = min(low[now], low[v]);
      if (dfn[now] <= low[v]) {
        int num = 0;
        x = _S.top();
        _S.pop();
        if (E[x].v != now) {
          t[num++] = E[x].v;
          t[num++] = E[x].u;
          Judge(t, num, now);
        } else {
          t[num++] = E[x].u;
          while (1) {
            x = _S.top();
            _S.pop();
            t[num++] = E[x].u;
            if (t[num - 1] == now) break;
          }
          Judge(t, num, now);
        }
      }
    }
  }
  col[now] = 2;
}
void Solve() {
  Index = 0;
  memset(col, 0, sizeof(col));
  memset(dfn, 0, sizeof(dfn));
  memset(W, 0, sizeof(W));
  while (!_S.empty()) _S.pop();
  ans = 0;
  dfs(1, 1);
  printf("%d\n", ans);
}
int main() {
  while (scanf("%d%d", &N, &M) != EOF) {
    Init();
    Solve();
  }
  return 0;
}
