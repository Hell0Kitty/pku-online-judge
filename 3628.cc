#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#define MAX 2000100
using namespace std;
int dp[MAX];
int cow[20];
int main() {
  int n, b, i, j;
  int m;
  int sum = 0;
  while (~scanf("%d%d", &n, &b)) {
    sum = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &cow[i]);
      sum += cow[i];
    }
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < n; i++)
      for (j = sum; j >= cow[i]; j--)
        dp[j] = max(dp[j], dp[j - cow[i]] + cow[i]);
    m = INT_MAX;
    for (i = b; i <= sum; i++)
      if (dp[i] >= b) m = min(m, dp[i] - b);
    printf("%d\n", m);
  }
}
