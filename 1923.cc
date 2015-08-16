#include <cstdio>
#include <cstring>
int dp[105][10005];
int n, m, c = 1;
int out(int y, int x) {
  return y < 0 || (y > x * (x - 1) / 2) || (y > 0 && y < x - 1);
}
int test(int x, int y) {
  int i;
  if (out(y, x)) return 0;
  if (!y) return 1;
  if (dp[x][y] != -1) return dp[x][y];
  for (i = 1; i <= x; i++) {
    dp[x][y] = test(x - i, y - i * (x - i));
    if (dp[x][y]) return 1;
  }
  return 0;
}
int main() {
  memset(dp, -1, sizeof(dp));
  while (scanf("%d %d", &n, &m) && (n + m)) {
    printf("Case %d: %d ", c++, n);
    if (test(n, m))
      printf(
          "lines with exactly %d crossings can cut the plane into %d pieces at "
          "most.\n",
          m, n + m + 1);
    else
      printf("lines cannot make exactly %d crossings.\n", m);
  }
  return 0;
}
