#include <stdio.h>
#include <string.h>
const int Size = 36;
int board[Size][Size];
long long dp[Size][Size];
int n;
long long why(int x, int y) {
  if (x == n && y == n) return 1;
  if (0 == board[x][y]) return 0;
  if (dp[x][y]) return dp[x][y];
  for (int i = 0; i < 2; i++) {
    int nx, ny;
    if (i & 1) {
      nx = x + board[x][y];
      ny = y;
    } else {
      ny = y + board[x][y];
      nx = x;
    }
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) dp[x][y] += why(nx, ny);
  }
  return dp[x][y];
}
int main() {
  while (scanf("%d", &n) && n != -1) {
    getchar();
    for (int i = 1; i <= n; i++) {
      char str[Size];
      gets(str);
      for (int j = 0; j < n; j++) {
        board[i][j + 1] = str[j] - '0';
        dp[i][j + 1] = 0;
      }
    }
    printf("%lld\n", why(1, 1));
  }
  return 0;
}
