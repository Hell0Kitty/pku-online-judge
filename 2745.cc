#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const int N = 2005;
int n, m;
int dist[55][55];
int d[N][55], deg[N];
int pre[N], mcnt;
struct edge {
  int x, next;
} e[N << 2];

void dfs(int x, int fa, int k) {
  for (int i = pre[x]; ~i; i = e[i].next)
    if (e[i].x != fa) {
      int y = e[i].x;
      d[y][k] = d[x][k] + 1;
      dfs(y, x, k);
    }
}

void work() {
  int i, j, k, x, y;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) scanf("%d", &dist[i][j]);
  memset(d, 0, sizeof(d));
  memset(deg, 0, sizeof(deg));

  m = 1;
  memset(pre, -1, sizeof(pre)), mcnt = 0;
  for (k = 2; k <= n; ++k) {
    for (i = 1; i <= m; ++i) {
      x = dist[k][1] - d[i][1];
      for (j = 1; j < k; ++j)
        if (dist[k][j] - d[i][j] != x) break;
      if (j >= k) {
        // link x nodes to i
        while (x > 0) {
          ++m;
          e[mcnt] = (edge){i, pre[m]}, pre[m] = mcnt++;
          e[mcnt] = (edge){m, pre[i]}, pre[i] = mcnt++;
          ++deg[i], ++deg[m];
          for (j = 1; j < k; ++j) d[m][j] = d[i][j] + 1;
          i = m, --x;
        }
        dfs(i, 0, k);
        break;
      }
    }
  }
  sort(deg + 1, deg + 1 + m);
  for (i = 1; i <= m; ++i)
    if (deg[i] > 1) printf("%d%c", deg[i], " \n"[i == m]);
}

int main() {
  while (scanf("%d", &n), n) work();
  return 0;
}
