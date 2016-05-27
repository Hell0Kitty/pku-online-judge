#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

#define MAXN 100005
#define MAXM 200005
struct Graph {
  int dfn[MAXN], low[MAXN];
  bool vst[MAXN];
  bool visit[MAXM];
  int N, M, size, depth;
  int ret;
  int S[MAXN], top;
  int block[MAXN], numB;
  int col[MAXN];
  bool odd, inblock[MAXN];
  int to[MAXM], idx[MAXM], prev[MAXM], E;
  int last[MAXN];

  void init(int n) {
    N = n;
    memset(visit, 0, sizeof(visit));
    E = 0;
    memset(last, -1, sizeof(last));
  }

  void addEdge(int u, int v, int id) {
    to[E] = v;
    idx[E] = id;
    prev[E] = last[u];
    last[u] = E++;
  }

  void dfs(int u, int c) {
    if (odd) return;
    if (col[u] != -1) {
      if (col[u] != c) {
        odd = true;
      }
      return;
    }
    col[u] = c;
    for (int i = last[u], v; ~i; i = prev[i]) {
      if (inblock[v = to[i]]) {
        dfs(v, 1 - c);
      }
    }
  }

  void CountBlock() {
    if (numB == 1) return;
    for (int i = 0; i < numB; i++) {
      col[block[i]] = -1;
      inblock[block[i]] = true;
    }
    odd = false;
    dfs(block[0], 0);
    if (odd) {
      for (int i = 0; i < numB; i++) vst[block[i]] = true;
    }
    for (int i = 0; i < numB; i++) {
      inblock[block[i]] = false;
    }
  }

  void Tarjan(int u) {
    dfn[u] = low[u] = depth++;
    S[top++] = u;
    for (int i = last[u]; ~i; i = prev[i]) {
      int v = to[i];
      int id = idx[i];
      if (dfn[v] == -1) {
        visit[id] = true;
        Tarjan(v);
        low[u] = min(low[u], low[v]);
        if (low[v] >= dfn[u]) {
          numB = 0;
          int x;
          do {
            x = S[--top];
            block[numB++] = x;
          } while (x != v);
          block[numB++] = u;
          CountBlock();
        }
      } else if (!visit[id]) {
        low[u] = min(low[u], dfn[v]);
      }
    }
  }

  void BCC() {
    depth = 0;
    size = 0;
    ret = 0;
    top = 0;
    for (int i = 0; i < N; i++) dfn[i] = -1, inblock[i] = false, vst[i] = false;
    for (int i = 0; i < N; i++)
      if (dfn[i] == -1) Tarjan(i);
    for (int i = 0; i < N; i++) ret += vst[i];
    printf("%d\n", ret);
  }

} g;

int main(int argc, char const *argv[]) {
  int Test;
  int n, m;
  scanf("%d", &Test);
  while (Test--) {
    scanf("%d%d", &n, &m);
    g.init(n);
    for (int i = 1; i <= m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--;
      b--;
      g.addEdge(a, b, i);
      g.addEdge(b, a, i);
    }
    g.BCC();
  }
  return 0;
}
