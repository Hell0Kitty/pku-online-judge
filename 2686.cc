#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1000000000
#define MAXN 40
using namespace std;
double dp[1 << 10][MAXN];
int d[MAXN][MAXN];
int t[MAXN];
int n, m, p, a, b;

void solve() {
  for (int i = 0; i < (1 << n); i++) fill(dp[i], dp[i] + m, INF);
  dp[(1 << n) - 1][a - 1] = 0;
  double res = INF;
  for (int s = (1 << n) - 1; s >= 0; s--) {
    res = min(res, dp[s][b - 1]);
    for (int v = 0; v < m; v++)
      for (int i = 0; i < n; i++) {
        if (s >> i & 1) {
          for (int u = 0; u < m; u++)
            if (d[v][u] >= 0)
              dp[s & ~(1 << i)][u] =
                  min(dp[s & ~(1 << i)][u], dp[s][v] + (double)d[v][u] / t[i]);
        }
      }
  }
  if (res == INF)
    cout << "Impossible" << endl;
  else
    printf("%.3f\n", res);
}

int main() {
  int x, y, z;
  while (cin >> n >> m >> p >> a >> b && n || m || p || a || b) {
    for (int i = 0; i < n; i++) cin >> t[i];
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= p; i++) {
      cin >> x >> y >> z;
      d[x - 1][y - 1] = d[y - 1][x - 1] = z;
    }
    solve();
  }
  return 0;
}
