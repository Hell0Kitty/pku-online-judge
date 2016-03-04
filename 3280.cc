#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int w[30], n, m, dp[2005][2005];
char s[2005], ch;
int main() {
  int x, y;
  while (scanf("%d%d", &m, &n) != EOF) {
    getchar();
    scanf("%s", s);
    getchar();
    for (int i = 0; i < m; i++) {
      scanf("%ch", &ch);
      scanf("%d%d", &x, &y);
      getchar();
      w[ch - 'a'] = min(x, y);
    }
    for (int i = n - 1; i >= 0; i--)
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j])
          dp[i][j] = dp[i + 1][j - 1];
        else
          dp[i][j] =
              min(dp[i + 1][j] + w[s[i] - 'a'], dp[i][j - 1] + w[s[j] - 'a']);
      }
    printf("%d\n", dp[0][n - 1]);
  }
  return 0;
}
