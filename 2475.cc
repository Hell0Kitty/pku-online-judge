#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

#define L(x) x << 1
#define R(x) x << 1 | 1
#define M(x, y) (x + y) >> 1
#define LL long long
#define inf 0x7fffffff
#define N 50000

int mark[15] = {
    0,  1,  2,  4,  8,
    16, 32, 64, 128};  // atom -- element -- list -- elementlist -- set
int dp[250][250];
char s[250];

int main() {
  int i, j, k, l;
  int t, test = 1;
  cin >> t;
  while (t--) {
    cin >> s;
    memset(dp, 0, sizeof(dp));
    int len = strlen(s);
    for (i = 0; i < len; i++) {
      dp[i][i] = mark[1] + mark[2] + mark[3] + mark[4];
    }
    for (i = 0; i < len - 1; i++) {
      if (s[i] == '{' && s[i + 1] == '}') {
        dp[i][i + 1] = mark[5] + mark[4] + mark[3] + mark[2];
      }
    }
    for (i = 2; i < len; i++) {
      for (j = 0; j + i < len; j++) {
        for (k = j + 1; k < j + i; k++) {
          if (s[k] == ',') {
            if ((dp[j][k - 1] & mark[2]) != 0 &&
                (dp[k + 1][j + i] & mark[3]) != 0) {
              dp[j][j + i] = mark[3] + mark[4];
            }
            if ((dp[j][k - 1] & mark[3]) != 0 &&
                (dp[k + 1][j + i] & mark[2]) != 0) {
              dp[j][j + i] = mark[3] + mark[4];
            }
          }
        }
        if (s[j] == '{' && s[j + i] == '}' &&
            (dp[j + 1][j + i - 1] & mark[4]) != 0) {
          dp[j][j + i] += mark[5];
        }
        if (dp[j][j + i] & mark[5]) {
          dp[j][j + i] = mark[2] + mark[3] + mark[4] + mark[5];
        }
      }
    }
    if (dp[0][len - 1] & mark[5]) {
      printf("Word #%d: Set\n", test++);
    } else {
      printf("Word #%d: No Set\n", test++);
    }
  }
  return 0;
}
