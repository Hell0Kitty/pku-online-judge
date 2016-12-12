#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

#define mnx 5020
#define mxe 2500020

int fst[mnx], nxt[mxe], to[mxe], e;
void init() {
  memset(fst, -1, sizeof fst);
  e = 0;
}
void add(int u, int v) { to[e] = v, nxt[e] = fst[u], fst[u] = e++; }

int pre[mnx], sccno[mnx], dc, scnt;

int n, m;
stack<int> S;

int dfs(int u) {
  int lowu = pre[u] = ++dc;
  S.push(u);
  for (int i = fst[u]; ~i; i = nxt[i]) {
    int v = to[i];
    if (!pre[v]) {
      int lowv = dfs(v);
      lowu = min(lowu, lowv);
    } else if (!sccno[v])
      lowu = min(lowu, pre[v]);
  }
  if (lowu == pre[u]) {
    ++scnt;
    while (1) {
      int x = S.top();
      S.pop();
      sccno[x] = scnt;
      if (x == u) break;
    }
  }
  return lowu;
}
bool out[mnx];
int ans[mnx], len;
int main() {
  while (scanf("%d", &n) && n) {
    scanf("%d", &m);
    init();
    while (m--) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(u, v);
    }
    memset(pre, 0, sizeof pre);
    memset(sccno, 0, sizeof sccno);
    dc = scnt = 0;
    for (int i = 1; i <= n; ++i)
      if (!pre[i]) dfs(i);
    memset(out, 0, sizeof out);
    for (int i = 1; i <= n; ++i)
      for (int j = fst[i]; ~j; j = nxt[j]) {
        int v = to[j];
        if (sccno[v] != sccno[i]) out[sccno[i]] = 1;
      }
    len = 0;
    for (int i = 1; i <= n; ++i)
      if (out[sccno[i]] == 0) ans[len++] = i;
    for (int i = 0; i < len; ++i)
      printf("%d%c", ans[i], i == len - 1 ? '\n' : ' ');
  }
  return 0;
}
