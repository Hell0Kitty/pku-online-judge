#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;
#define N 1005
bitset<N> dp[2][N][2], one, zero;
int data[N], n, maxnum;
int main() {
  int test;
  scanf("%d", &test);
  one.set();
  zero.reset();
  while (test--) {
    one.set();
    zero.reset();
    scanf("%d%d", &n, &maxnum);
    for (int i = 0; i < n; i++) scanf("%d", data + i);
    bitset<N> res = one;
    for (int i = 0; i <= maxnum; i++) dp[0][i][0] = zero, dp[0][i][1] = one;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= maxnum; j++) dp[i % 2][j][0] = dp[i % 2][j][1] = one;
      for (int j = 0; j <= maxnum; j++)
        dp[i % 2][j][0] &= dp[(i - 1) % 2][j][1];
      for (int j = 0; j < maxnum; j++)
        dp[i % 2][j][1] &= dp[(i - 1) % 2][j + 1][1].set(i);
      if (!data[i - 1])
        for (int j = 0; j <= maxnum; j++)
          dp[i % 2][j][0] &= dp[(i - 1) % 2][j][0];
      else
        for (int j = 0; j < maxnum; j++)
          dp[i % 2][j][1] &= dp[(i - 1) % 2][j + 1][0].set(i);
    }
    for (int i = 0; i <= maxnum; i++) res &= dp[n % 2][i][0];

    for (int i = 0; i < maxnum; i++)
      dp[0][i][0] = one, dp[0][i][1] = zero.set(0);
    dp[0][maxnum][0] = dp[0][maxnum][1] = one;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= maxnum; j++) dp[i % 2][j][0] = dp[i % 2][j][1] = one;
      for (int j = 0; j <= maxnum; j++)
        dp[i % 2][j][0] &= dp[(i - 1) % 2][j][1];
      for (int j = 0; j < maxnum; j++)
        dp[i % 2][j][1] &= dp[(i - 1) % 2][j + 1][1].set(i);
      if (!data[i - 1])
        for (int j = 0; j <= maxnum; j++)
          dp[i % 2][j][0] &= dp[(i - 1) % 2][j][0];
      else
        for (int j = 0; j < maxnum; j++)
          dp[i % 2][j][1] &= dp[(i - 1) % 2][j + 1][0].set(i);
    }
    for (int i = 0; i < maxnum; i++) res &= dp[n % 2][i][1];

    if (res.count() == 0)
      printf("0 0\n");
    else {
      int pos = -1;
      for (int i = 0; i < n && pos == -1; i++)
        if (res[i]) pos = i;
      printf("%d %d\n", res.count(), pos + 1);
    }
  }
  return 0;
}
