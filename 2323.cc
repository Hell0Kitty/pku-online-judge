#include <iostream>
using namespace std;
int main() {
  long long dp[19][200] = {0};
  dp[1][0] = 1;
  for (int i = 1; i < 18; i++)
    for (int j = 0; dp[i][j]; j++)
      for (int k = 0; k <= i; k++) dp[i + 1][j + k] += dp[i][j];
  int x, y;
  while (cin >> x >> y, x) cout << dp[x][y] << endl;
}
