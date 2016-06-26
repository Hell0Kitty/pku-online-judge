#include <iostream>
#include <string.h>
#include <stdio.h>
#define M 110
using namespace std;
int dep[M], low[M], head[M];
bool cut[M];
int e, n, rt, son;
struct E {
  int to, nxt;
} edge[M * M];

void addedge(int cu, int cv) {
  edge[e].to = cv;
  edge[e].nxt = head[cu];
  head[cu] = e++;
}

int min(int a, int b) { return a > b ? b : a; }
void dfs(int cnt, int u) {
  dep[u] = low[u] = cnt;
  for (int i = head[u]; i != -1; i = edge[i].nxt) {
    int v = edge[i].to;
    if (!dep[v]) {
      dfs(cnt + 1, v);
      if (u == rt)
        son++;
      else {
        low[u] = min(low[u], low[v]);
        if (dep[u] <= low[v]) cut[u] = true;
      }
    } else
      low[u] = min(low[u], dep[v]);
  }
}
int main() {
  int u, v;
  while (cin >> n && n) {
    memset(dep, 0, sizeof(dep));
    memset(low, 0, sizeof(low));
    memset(cut, false, sizeof(cut));
    memset(head, 0xFF, sizeof(head));
    e = 0;
    while (cin >> u && u)
      while (getchar() != '\n') {
        cin >> v;
        addedge(u, v);
        addedge(v, u);
      }
    rt = 1;
    son = 0;
    dfs(1, rt);
    int ans = 0;
    if (son > 1) ans++;
    for (int i = 1; i <= n; i++)
      if (cut[i]) ans++;
    cout << ans << endl;
  }
  return 0;
}
