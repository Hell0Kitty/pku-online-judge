#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
const int inf = 1000;
int dp[25][105][105], N, D, E;
int dfs(int l, int e, int d) {
  if (d >= D) return 0;
  if (dp[l][e][d] != inf) return dp[l][e][d];
  int ret = inf;
  for (int v = 1; v * v <= e; v++) ret = min(ret, dfs(l, e - v * v, d + v) + 1);
  if (l + 1 <= N && E >= d) ret = min(ret, dfs(l + 1, E - d, d));

  if (ret == inf) ret *= 2;
  return dp[l][e][d] = ret;
}
int main() {
  scanf("%d%d%d", &N, &E, &D);

  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= E; j++)
      for (int k = 0; k <= D; k++) dp[i][j][k] = inf;

  int ret = dfs(1, E, 0);
  if (ret >= inf) ret = 0;
  printf("%d\n", ret);

  return 0;
}
