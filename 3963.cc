#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
bool f[4010][4010];
ll dp[2][4010], INF = 1e18;
int n, m, ans[4010];
struct node {
  int x, index;
};
node pos1[4010], pos2[4010];
bool cmp(node a, node b) { return a.x < b.x; }
void dfs(int a, int b) {
  if (a == 0) return;
  ans[pos1[a].index] = pos2[b].index;
  if (f[a][b] == 0)
    dfs(a - 1, b - 1);
  else
    dfs(a - 1, b);
}
int main() {
  int i, j, k, a, b;
  ll ret;
  while (~scanf("%d", &n)) {
    for (i = 1; i <= n; i++) {
      scanf("%I64d", &pos1[i].x);
      pos1[i].index = i;
    }
    scanf("%d", &m);
    for (j = 1; j <= m; j++) {
      scanf("%I64d", &pos2[j].x);
      pos2[j].index = j;
    }
    sort(pos1 + 1, pos1 + 1 + n, cmp);
    sort(pos2 + 1, pos2 + 1 + m, cmp);
    for (i = 0; i <= 1; i++)
      for (j = 0; j <= m; j++) dp[i][j] = INF;
    dp[0][0] = 0;
    for (i = 1; i <= n; i++) {
      if (i & 1)
        a = 0, b = 1;
      else
        a = 1, b = 0;
      dp[b][0] = INF;
      for (j = 1; j <= m; j++) {
        dp[b][j] = INF;
        ret = abs(pos1[i].x - pos2[j].x);
        if (dp[a][j - 1] <= dp[a][j]) {
          dp[b][j] = dp[a][j - 1] + ret;
          f[i][j] = 0;
        } else {
          dp[b][j] = dp[a][j] + ret;
          f[i][j] = 1;
        }
      }
    }
    printf("%I64d\n", dp[b][m]);
    dfs(n, m);
    printf("%d", ans[1]);
    for (i = 2; i <= n; i++) printf(" %d", ans[i]);
    printf("\n");
  }
}
