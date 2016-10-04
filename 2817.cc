#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <climits>
using namespace std;
const int maxn = 200005;
char s[11][11];
int lp[11][11], dp[2][1 << 11][11];
int cmp(char *fir, char *sec) {
  int lena = strlen(fir);
  int lenb = strlen(sec);
  int maxn = -1;
  for (int i = 0; i < lena; i++) {
    int tem = 0;
    for (int j = 0; j + i < lena && j < lenb; j++) {
      if (fir[i + j] == sec[j]) tem++;
    }
    if (tem > maxn) maxn = tem;
  }
  for (int i = 0; i < lenb; i++) {
    int tem = 0;
    for (int j = 0; j + i < lenb && j < lena; j++) {
      if (sec[i + j] == fir[j]) tem++;
    }
    if (tem > maxn) maxn = tem;
  }
  return maxn;
}
int main() {
  int n;
  while (scanf("%d", &n) && n > 0) {
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        lp[i][j] = cmp(s[i], s[j]);
        lp[j][i] = lp[i][j];
      }
    memset(dp, -1, sizeof(dp));
    int cur = 0;
    for (int i = 0; i < n; i++) dp[0][1 << i][i] = 0;
    for (int i = 1; i < n; i++) {
      cur ^= 1;
      for (int state = 0; state < (1 << n) - 1; state++) {
        for (int k = 0; k < n; k++) {
          if (((1 << k) & state) == 0)
            for (int nxt = 0; nxt < n; nxt++) {
              if (nxt != k && dp[cur ^ 1][state][nxt] >= 0)
                dp[cur][state | (1 << k)][k] =
                    max(dp[cur][state | (1 << k)][k],
                        dp[cur ^ 1][state][nxt] + lp[k][nxt]);
            }
        }
      }
    }
    int finalstate = (1 << n) - 1;
    int ans = -1;
    for (int i = 0; i < n; i++)
      ans = ans > dp[cur][finalstate][i] ? ans : dp[cur][finalstate][i];
    printf("%d\n", ans);
  }
}
