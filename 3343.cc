#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define inf 1e11
#define LL long long
using namespace std;
const int N = 500;
int map[N][N];
int hp[N];
int hshill[N];
int ap[N];
int ashill[N];
int n, m;
int edge[N][N];
int cx[N];
int cy[N];
int mark[N];
void builtmap(LL mid) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      LL val =
          (LL)(mid - edge[i][j]) * hp[i] + hshill[i] - mid * ap[j] - ashill[j];
      if (val >= 0) map[i][j] = 1;
    }
}
int dfs(int u) {
  for (int v = 1; v <= m; v++) {
    if (map[u][v] && !mark[v]) {
      mark[v] = 1;
      if (cy[v] == -1 || dfs(cy[v])) {
        cx[u] = v;
        cy[v] = u;
        return 1;
      }
    }
  }
  return 0;
}
int maxmatch() {
  int res = 0;
  memset(cx, 0xff, sizeof(cx));
  memset(cy, 0xff, sizeof(cy));
  for (int i = 1; i <= n; i++) {
    if (cx[i] == -1) {
      memset(mark, 0, sizeof(mark));
      res += dfs(i);
    }
  }
  return res;
}
int main() {
  while (scanf("%d%d", &n, &m)) {
    if (n == 0 && m == 0) break;
    for (int i = 1; i <= n; i++) cin >> hshill[i] >> hp[i];
    for (int j = 1; j <= m; j++) cin >> ashill[j] >> ap[j];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> edge[i][j];
    LL lef = 0, rig = inf, ans = -1;
    while (lef <= rig) {
      LL mid = (lef + rig) / 2;
      memset(map, 0, sizeof(map));
      builtmap(mid);
      int tmp = maxmatch();
      if (tmp == m)
        ans = mid, rig = mid - 1;
      else
        lef = mid + 1;
    }
    if (ans == -1)
      cout << "IMPOSSIBLE" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
