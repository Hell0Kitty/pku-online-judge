#include <iostream>

using namespace std;

long long dp[201][201];

void read() {
  int i, j, k, n, m;

  for (i = 1; i <= 200; i++) dp[i][i] = 1;

  for (i = 1; i <= 200; i++)

    for (j = i + 1; j <= 200; j++) dp[i][j] = dp[i - 1][j - 1] + dp[i][j - i];

  while (cin >> n >> m) {
    if (n == 0 && m == 0) return;

    cout << dp[m][n] << endl;
  }
}

int main() {
  read();

  return 0;
}
