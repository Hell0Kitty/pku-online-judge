#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N;
int dice[12][6];
int ans;
int dp[1 << 11][12][6];
bool vis[1 << 11][12][6];

int DFS(int S, int j, int botm) {
  bool& flag = vis[S][j][botm];
  int& res = dp[S][j][botm];

  if (flag) return res;

  res = -(1 << 30);
  for (int k = 0; k < N; ++k)
    if (k != j && (S & (1 << k))) {
      for (int m = 0; m < 6; ++m) {
        // printf("dice[%d][%d]=%d dice[%d][%d]=%d\n", k, m, dice[k][m], j,
        // botm, dice[j][botm] );
        if (dice[k][m] == dice[j][botm]) {
          int maxi = 0;
          for (int kk = 0; kk < 6; ++kk)
            if (kk != botm && kk + botm != 5) maxi = max(maxi, dice[j][kk]);
          // printf("maxi=%d\n", maxi);
          // printf( "dp[%d][%d][%d] = %d\n", S, j, botm, res );
          res = max(res, DFS(S ^ (1 << j), k, 5 - m) + maxi);
          // printf( "**dp[%d][%d][%d] = %d\n", S, j, botm, res );
          // printf("res=%d\n", res);
        }
      }
    }

  //   printf( "dp[%d][%d][%d] = %d\n\n", S, j, botm, res );

  flag = true;

  return res;
}

void init() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 6; ++j) {
      int maxi = 0;
      for (int m = 0; m < 6; ++m)
        if (m != j && j + m != 5) maxi = max(maxi, dice[i][m]);

      dp[1 << i][i][j] = maxi;
      vis[1 << i][i][j] = true;
    }
  }
  return;
}

int main() {
  // freopen("s.out", "w", stdout );
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < 6; ++i) scanf("%d", &dice[k][i]);

      int tp = dice[k][3];
      dice[k][3] = dice[k][4];
      dice[k][4] = tp;
    }

    ans = 0;
    memset(vis, false, sizeof(vis));
    memset(dp, 0, sizeof(dp));

    init();

    for (int i = 0; i < N; ++i)
      for (int j = 0; j < 6; ++j) {
        DFS((1 << N) - 1, i, j);
        ans = max(ans, dp[(1 << N) - 1][i][j]);
      }

    printf("%d\n", ans);
  }
  return 0;
}
