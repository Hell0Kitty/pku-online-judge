#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn = 1005;
char s[maxn][maxn];
int dp[2][maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      scanf("%s", s[i] + 1);
    }
    if (s[1][1] == '.') dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i][j] == '.') {
          if (i == 1 && j == 1) continue;
          dp[(i + 1) % 2][j] =
              ((s[i - 1][j] == '.' ? dp[i % 2][j] : 0) +
               (s[i][j - 1] == '.' ? dp[(i + 1) % 2][j - 1] : 0));
        }
      }
    }
    printf("Existuje %d ruznych cest.\n", dp[(n + 1) % 2][m]);
  }
  return 0;
}
