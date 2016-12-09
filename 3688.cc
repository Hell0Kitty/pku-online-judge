#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_N = 10000;
const int MAX_M = 100000;

int n, m;
int a[MAX_N];
bool dp[MAX_M][2];  // dp[i][0]:保存奇数能到

void solve() {
  memset(dp, false, sizeof(dp));
  dp[0][1] = true;
  for (int i = 0; i < n; i++) {
    for (int j = m - a[i]; j >= 0; j--) {
      int t = j + a[i];
      if (dp[j][0]) dp[t][1] = true;
      if (dp[j][1]) dp[t][0] = true;
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (dp[i][0] && !dp[i][1]) ans++;
  }
  printf("%d\n", ans);
}

int main() {
  while (scanf("%d%d", &n, &m) && n) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    solve();
  }
}
