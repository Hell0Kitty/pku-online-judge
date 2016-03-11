#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const double INF = 1e9;
int n, m, day, u, v, kind, len;
double dp[20][1 << 16], a[20], map[22][22];
void floyd() {
  int i, j, k;
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      if (i != k || map[i][k] < INF)
        for (j = 0; j < n; j++) {
          if (i != j || map[k][j] < INF) {
            map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
          }
        }
    }
  }
}
void init() {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < (1 << n); j++) {
      dp[i][j] = INF;
    }
    for (j = 0; j < n; j++) {
      map[i][j] = INF;
    }
    map[i][i] = 0;
  }
}
int main() {
  while (scanf("%d%d%d", &n, &m, &day), (n || m || day)) {
    double day1 = day * 12.0;
    int i, j, k, res = 0, ans = -1, cnt;
    init();
    for (i = 1; i <= m; i++) {
      scanf("%d", &j);
      res += 1 << (j - 1);
    }
    for (i = 0; i < n; i++) {
      scanf("%lf", &a[i]);
    }
    while (scanf("%d%d%d%d", &u, &v, &len, &kind), (u || v || len || kind)) {
      u--, v--;
      double hour = len * 1.0 / (kind ? 120.0 : 80.0);
      if (map[u][v] > hour) map[u][v] = hour, map[v][u] = hour;
    }
    floyd();
    for (i = 1; i < n; i++) dp[i][1 << i] = map[0][i] + a[i];
    for (j = 0; j < (1 << n); j++) {
      for (i = 0; i < n; i++) {
        if (j & (1 << i) && j != (1 << i)) {
          for (k = 0; k < n; k++) {
            if (j & (1 << k) && i != k && j != (1 << k)) {
              dp[i][j] = min(dp[i][j], dp[k][j - (1 << i)] + map[k][i] + a[i]);
            }
          }
          if (((j & res) == res) && dp[i][j] + map[i][0] <= day1) {
            // cout<<dp[i][j]+map[i][0]<<endl;
            int tmp = j;
            cnt = 0;
            while (tmp) {
              if (tmp % 2) cnt++;
              tmp >>= 1;
            }
            ans = max(ans, cnt);
          }
        }
      }
    }
    if (ans >= 0)
      printf("%d\n", ans);
    else
      printf("No Solution\n");
  }
  return 0;
}
