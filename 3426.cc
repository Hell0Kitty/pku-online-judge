#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>

#define MAXN 1005
#define INF 100000000
using namespace std;

int in[MAXN][MAXN][2];
int dp[MAXN][MAXN][4];
int path[MAXN][MAXN][4][2];

typedef pair<int, int> PII;
typedef pair<PII, int> PII2;
int n;
int cx[] = {0, -1, 0, 1}, cy[] = {1, 0, -1, 0};
int fromdi[] = {3, 1, 2, 0};
int backcx[] = {-1, 1, 0, 0}, backcy[] = {0, 0, 1, -1};

bool canGo(PII2 from, int di) {
  PII2 next = PII2(PII(from.first.first + cx[di], from.first.second + cy[di]),
                   fromdi[di]);
  if (next.first.first < 0 || next.first.first >= n || next.first.second < 0 ||
      next.first.second >= n)
    return false;
  if (dp[next.first.first][next.first.second][next.second] <=
      dp[from.first.first][from.first.second][from.second] + 1)
    return false;
  if (from.first.first == 0 && from.first.second == 0) {
    if (di == 0 && in[0][0][0] != 2 && in[0][0][0] != 4) return true;
    if (di == 3 && in[0][0][1] != 2 && in[0][0][1] != 4) return true;
    return false;
  }
  if (from.second == 3 && in[from.first.first][from.first.second - 1][0] == 3 &&
      di == 3)
    return false;
  if (from.second == 3 && in[from.first.first][from.first.second - 1][0] == 1 &&
      di == 1)
    return false;
  if (from.second == 1 && in[from.first.first][from.first.second][0] == 2 &&
      di == 1)
    return false;
  if (from.second == 1 && in[from.first.first][from.first.second][0] == 4 &&
      di == 3)
    return false;

  if (from.second == 0 && in[from.first.first - 1][from.first.second][1] == 1 &&
      di == 0)
    return false;
  if (from.second == 0 && in[from.first.first - 1][from.first.second][1] == 3 &&
      di == 2)
    return false;
  if (from.second == 2 && in[from.first.first][from.first.second][1] == 2 &&
      di == 0)
    return false;
  if (from.second == 2 && in[from.first.first][from.first.second][1] == 4 &&
      di == 2)
    return false;

  if (di == 0 && in[from.first.first][from.first.second][0] != 2 &&
      in[from.first.first][from.first.second][0] != 4)
    return true;
  if (di == 3 && in[from.first.first][from.first.second][1] != 2 &&
      in[from.first.first][from.first.second][1] != 4)
    return true;
  if (di == 1 && in[from.first.first - 1][from.first.second][1] != 1 &&
      in[from.first.first - 1][from.first.second][1] != 3)
    return true;
  if (di == 2 && in[from.first.first][from.first.second - 1][0] != 1 &&
      in[from.first.first][from.first.second - 1][0] != 3)
    return true;
  return false;
}

void print(int ii, int jj, int fromm) {
  if (ii != 0 || jj != 0) {
    print(ii + backcx[fromm], jj + backcy[fromm], path[ii][jj][fromm][1]);
  }
  printf("%d %d\n", jj + 1, ii + 1);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> in[i][j][0] >> in[i][j][1];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < 4; k++) dp[i][j][k] = INF;

  dp[0][0][0] = dp[0][0][2] = 0;
  queue<PII2> Q;
  Q.push(PII2(PII(0, 0), 0));
  Q.push(PII2(PII(0, 0), 2));
  while (!Q.empty()) {
    PII2 top = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      if (canGo(top, i)) {
        dp[top.first.first + cx[i]][top.first.second + cy[i]][fromdi[i]] =
            dp[top.first.first][top.first.second][top.second] + 1;
        path[top.first.first + cx[i]][top.first.second + cy[i]][fromdi[i]][0] =
            fromdi[i];
        path[top.first.first + cx[i]][top.first.second + cy[i]][fromdi[i]][1] =
            top.second;
        Q.push(PII2(PII(top.first.first + cx[i], top.first.second + cy[i]),
                    fromdi[i]));
      }
    }
  }

  if (dp[n - 1][n - 1][0] == INF && dp[n - 1][n - 1][1] == INF &&
      dp[n - 1][n - 1][2] == INF && dp[n - 1][n - 1][3] == INF) {
    cout << 0 << endl;
  } else {
    int temp = 1000000000;
    int smallest = 0;
    for (int i = 0; i < 4; i++) {
      if (temp > dp[n - 1][n - 1][i]) {
        temp = dp[n - 1][n - 1][i];
        smallest = i;
      }
    }
    print(n - 1, n - 1, smallest);
  }
  return 0;
}
