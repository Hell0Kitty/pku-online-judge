#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[2][1001][4];
int xp[2][1001];
int n, K, m;
int cur, nex;
struct Node {
  int x, y;
  bool operator<(const Node &tt) const {
    if (y == tt.y) return x < tt.x;
    return y < tt.y;
  }
} node[1001];
void tomin(int &a, int b) {
  if (a > b) a = b;
}
int main() {
  scanf("%d%d%d", &n, &K, &m);
  memset(dp, INF, sizeof(dp));
  memset(xp, INF, sizeof(xp));
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &node[i].x, &node[i].y);
  }
  sort(node + 1, node + n + 1);
  int tot = 1;
  for (int i = 2; i <= n; i++) {
    if (node[i].y == node[i - 1].y)
      node[tot].x = 3;
    else
      node[++tot] = node[i];
  }
  n = tot;
  node[0].y = node[1].y - 1;
  cur = 0, nex = 1;
  for (int i = 1; i <= n; i++) {
    int dis = node[i].y - node[i - 1].y;
    for (int j = 0; j <= K; j++) {
      for (int s = 1; s < 4; s++)
        if ((s & node[i].x) == node[i].x) {
          int cnt = 0;
          for (int r = 0; r < 2; r++)
            if (s & (1 << r)) cnt++;
          tomin(dp[nex][j][s], dp[cur][j][s] + cnt * dis);
        }
      tomin(xp[nex][j], xp[cur][j] + 2 * dis);
      for (int k = 0; k < 4; k++) {
        int cnt = 0;
        for (int r = 0; r < 2; r++)
          if (k & (1 << r)) cnt++;
        if (node[i].x == k) tomin(dp[nex][j][k], xp[cur][j] + cnt * dis);
      }
    }
    for (int j = 1; j <= K; j++) {
      for (int ns = 1; ns < 4; ns++)
        if ((ns & node[i].x) == node[i].x) {
          int cnt = 0;
          for (int r = 0; r < 2; r++)
            if (ns & (1 << r)) cnt++;
          tomin(dp[nex][j][ns], xp[cur][j - 1] + cnt);
          for (int s = 0; s < 4; s++) {
            tomin(dp[nex][j][ns], dp[cur][j - 1][s] + cnt);
          }
        }
      tomin(xp[nex][j], dp[cur][j - 1][1] + dis + 1);
      tomin(xp[nex][j], dp[cur][j - 1][2] + dis + 1);
      if (j >= 2)
        for (int s = 0; s < 4; s++) {
          tomin(xp[nex][j], dp[cur][j - 2][s] + 2);
        }
    }
    cur = nex, nex = !cur;
    memset(dp[nex], INF, sizeof(dp[nex]));
    memset(xp[nex], INF, sizeof(xp[nex]));
  }
  int minx = INF;
  for (int s = 0; s < 4; s++) tomin(minx, dp[cur][K][s]);
  tomin(minx, xp[cur][K]);
  printf("%d\n", minx);
  return 0;
}
