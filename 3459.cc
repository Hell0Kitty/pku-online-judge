#include <iostream>
#include <fstream>

using namespace std;

int m, n, c;
int dp[110][110];
int p[110][110];
int cost[110][110];

void read() {
  //  ifstream cin("in.txt");
  int i, j, k;
  int K;
  cin >> K;
  while (K--) {
    cin >> m >> n >> c;
    for (i = 1; i <= m; i++)
      for (j = 1; j <= n + 2; j++) cin >> p[i][j];
    for (i = 1; i <= m; i++)
      for (j = 0; j <= n; j++)
        cost[i][j] =
            p[i][j] * (p[i][n + 1] - c * j) - (100 - p[i][j]) * p[i][n + 2];
    for (i = 1; i <= n; i++) dp[0][i] = -100 * c * i;
    for (i = 1; i <= m; i++) dp[i][0] = -1 * p[i][n + 2] * 100 + dp[i - 1][0];
    for (i = 1; i <= m; i++)
      for (j = 1; j <= n; j++) {
        dp[i][j] = -999999999;
        for (k = 0; k <= j; k++)
          dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + cost[i][k]);
      }
    j = -999999999;
    for (i = 0; i <= n; i++) j = max(dp[m][i], j);
    cout << j << endl;
    for (i = 0; i <= n; i++)
      if (dp[m][i] == j) cout << i << ' ';
    cout << endl;
  }
}

int main() {
  read();
  return 0;
}
