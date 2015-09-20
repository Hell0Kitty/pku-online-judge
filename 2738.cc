#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define N 1100
using namespace std;
int num[N];
int dp[N][N];
int dfs(int x, int y) {
  int a, b;
  if (dp[x][y] != -1) return dp[x][y];

  if (x == y - 1) return dp[x][y] = abs(num[x] - num[y]);

  if (num[x + 1] >=
      num[y])  //如果第一个人选左边，则比较左边第二个和最后一个大小，大的则为第二个人的选择，求出差值
    a = dfs(x + 2, y) + num[x] - num[x + 1];
  else
    a = dfs(x + 1, y - 1) + num[x] - num[y];

  if (num[x] < num[y - 1])  //同理，如果第一个人选择右边
    b = dfs(x, y - 2) + num[y] - num[y - 1];
  else
    b = dfs(x + 1, y - 1) + num[y] - num[x];

  return dp[x][y] = max(a, b);
}

int main() {
  int n;
  int ca = 1;
  while (~scanf("%d", &n)) {
    if (n == 0) break;
    for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
    memset(dp, -1, sizeof dp);

    printf(
        "In game %d, the greedy strategy might lose by as many as %d points.\n",
        ca++, dfs(1, n));
  }
  return 0;
}
