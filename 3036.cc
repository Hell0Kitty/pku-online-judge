#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <set>
#define ll long long;
#define inf 0x3f3f3f3f
using namespace std;
int main(int argc, char *argv[]) {
  long long dp[16][31][31];
  memset(dp, 0, sizeof dp);
  dp[0][15][15] = 1;
  for (int i = 1; i <= 15; i++) {
    for (int j = 1; j <= 30; j++) {
      for (int k = 1; k <= 30; k++) {
        dp[i][j][k] = dp[i - 1][j][k + 1] + dp[i - 1][j + 1][k] +
                      dp[i - 1][j][k - 1] + dp[i - 1][j - 1][k] +
                      dp[i - 1][j + 1][k + 1] + dp[i - 1][j - 1][k - 1];
      }
    }
  }
  int n;
  scanf("%d", &n);
  while (n--) {
    int i;
    scanf("%d", &i);
    printf("%I64d\n", dp[i][15][15]);
  }
  return 0;
}
