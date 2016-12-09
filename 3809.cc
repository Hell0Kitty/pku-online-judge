#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b) for (int i = a; i <= b; i++)

const int maxn = 1 << 11;
char str[maxn];
int q[maxn];
int dp[maxn][maxn];
int m, n;
int DP(int s, int ans) {
  if (dp[s][ans] != -1) return dp[s][ans];
  int num = 0;
  for (int i = 0; i < n; i++)
    if ((s & q[i]) == ans) num++;
  if (num <= 1) return dp[s][ans] = 0;
  int res = maxn;
  for (int i = 0; i < m; i++) {
    if (s & (1 << i)) continue;
    dp[s | (1 << i)][ans] = DP(s | (1 << i), ans);
    dp[s | (1 << i)][ans | (1 << i)] = DP(s | (1 << i), ans | (1 << i));
    res = min(res,
              max(dp[s | (1 << i)][ans], dp[s | (1 << i)][ans | (1 << i)]) + 1);
  }
  return dp[s][ans] = res;
}
int main() {
  while (~scanf("%d%d", &m, &n) && (m || n)) {
    clr(q, 0);
    for (int i = 0; i < n; i++) {
      scanf("%s", str);
      for (int j = 0; j < m; j++) q[i] = (q[i] << 1) + str[j] - '0';
    }
    clr(dp, -1);
    printf("%d\n", DP(0, 0));
  }
  return 0;
}
