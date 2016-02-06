#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
using namespace std;
#define N 1000005
#define L(x) x << 1
#define R(x) x << 1 | 1
#define M(x, y) (x + y) >> 1
#define LL __int64
#define inf 10000000000000L

struct st {
  LL v;
  LL last;
} dp[105][505];

LL s[105][505], sum[105][505];

int main() {
  LL i, j, k, l, r;
  LL t, n, m;
  while (scanf("%I64d%I64d", &n, &m) != EOF) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        scanf("%I64d", &s[i][j]);
        sum[i][j] = sum[i][j - 1] + s[i][j];
      }
    }
    for (i = 1; i <= m; i++) {
      dp[1][i].v = s[1][i];
      dp[1][i].last = i;
    }
    for (i = 2; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        dp[i][j].last = j;
        dp[i][j].v = dp[i - 1][j].v + sum[i][j] - sum[i][j - 1];
      }
      for (j = 2; j <= m; j++) {
        if (dp[i][j].v > dp[i][j - 1].v + sum[i][j] - sum[i][j - 1]) {
          dp[i][j].v = dp[i][j - 1].v + sum[i][j] - sum[i][j - 1];
          dp[i][j].last = dp[i][j - 1].last;
        }
      }
      for (j = m - 1; j >= 1; j--) {
        if (dp[i][j].v > dp[i][j + 1].v + sum[i][j] - sum[i][j - 1]) {
          dp[i][j].v = dp[i][j + 1].v + sum[i][j] - sum[i][j - 1];
          dp[i][j].last = dp[i][j + 1].last;
        }
      }
    }
    LL ans = 1;
    for (i = 1; i <= m; i++)
      if (dp[n][i].v < dp[n][ans].v) ans = i;
    vector<LL> num;
    for (i = n; i >= 1; i--) {
      if (ans >= dp[i][ans].last)
        for (j = ans; j >= dp[i][ans].last; j--) num.push_back(j);
      else
        for (j = ans; j <= dp[i][ans].last; j++) num.push_back(j);
      ans = dp[i][ans].last;
    }
    for (i = num.size() - 1; i >= 0; i--) printf("%I64d\n", num[i]);
  }
  return 0;
}
