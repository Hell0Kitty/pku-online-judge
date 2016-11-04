#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 30

int dp[N + 10][N + 10], g, l;

int main() {
  for (int i = 0; i <= N; i++) {
    dp[i][0] = i;
    dp[i][i] = (1 << i) - 1;
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j < i; j++) dp[i][j] = dp[i - 1][j - 1] + 1 + dp[i - 1][j];

  int Case = 0;
  while (scanf("%d%d", &g, &l) && (g || l)) {
    printf("Case %d: ", ++Case);
    if (l > g)
      printf("%d\n", dp[g][g]);
    else
      printf("%d\n", dp[g][l]);
  }
  return 0;
}
