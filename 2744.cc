#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double dp[110], cost[10010];
int dis[110], INF = 1e9 + 7;
int main() {
  int n, m, i, j, k, r;
  double d, b, v, e, f, ret;
  while (~scanf("%d", &n) && n) {
    for (i = 1; i <= n; i++) scanf("%d", &dis[i]);
    scanf("%lf%d%lf%lf%lf", &d, &r, &v, &e, &f);
    for (i = 0; i < dis[n]; i++) {
      if (i < r)
        ret = 1.0 / (v - f * (r - i));
      else
        ret = 1.0 / (v - e * (i - r));
      if (i == 0)
        cost[i] = ret;
      else
        cost[i] = cost[i - 1] + ret;
    }
    for (i = 1; i <= n; i++) dp[i] = INF;
    dp[0] = 0;
    for (i = 0; i < n; i++) {
      if (i == 0)
        ret = 0;
      else
        ret = d;
      for (j = i + 1; j <= n; j++)
        dp[j] = min(dp[j], dp[i] + cost[dis[j] - dis[i] - 1] + ret);
    }
    printf("%.4f\n", dp[n]);
  }
}
