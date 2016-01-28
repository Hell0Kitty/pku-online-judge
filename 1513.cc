#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>
#include <iostream>
#include <map>
using namespace std;
#define inf 0x3f3f3f3f
#define Max 110
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int dp[1100][1100], L, C, n;
int c[1100][1100];
int a[1100], sum[1100];
int up[1100], low[1100];
int rec;
int num;
int main() {
  int i, count = 1, j, k;
  while (scanf("%d", &n), n) {
    scanf("%d%d", &L, &C);
    num = 0;
    sum[0] = 0;
    int tmp = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum[i] = sum[i - 1] + a[i];
      if (sum[i] - sum[tmp] > L) {
        num++;
        tmp = i - 1;
        up[num] = tmp;
      }
    }

    num++;
    up[num] = n;
    tmp = n;
    rec = num;
    low[num] = n;
    for (i = n - 1; i >= 0; i--) {
      if (sum[tmp] - sum[i] > L) {
        tmp = i + 1;
        rec--;
        low[rec] = i + 1;
      }
    }

    for (i = 1; i <= num; i++) {
      for (j = low[i]; j <= up[i]; j++) {
        dp[i][j] = inf;
        if (i == 1) {
          dp[i][j] = 0;
          if (L - sum[j] >= 1 && L - sum[j] <= 10)
            dp[i][j] -= C;
          else if (L - sum[j] > 10)
            dp[i][j] += (L - sum[j] - 10) * (L - sum[j] - 10);

          continue;
        }
        for (k = (up[i - 1] < j - 1) ? up[i - 1] : j - 1;
             sum[j] - sum[k] <= L && k >= low[i - 1]; k--) {
          tmp = 0;
          if (L - (sum[j] - sum[k]) >= 1 && L - (sum[j] - sum[k]) <= 10)
            tmp -= C;
          else if (L - (sum[j] - sum[k]) > 10)
            tmp += (L - (sum[j] - sum[k]) - 10) * (L - (sum[j] - sum[k]) - 10);
          dp[i][j] = min(dp[i][j], dp[i - 1][k] + tmp);
        }
      }
    }
    printf(
        "Case %d:\n\nMinimum number of lectures: %d\nTotal dissatisfaction "
        "index: %d\n\n",
        count++, num, dp[num][n]);
  }
}
