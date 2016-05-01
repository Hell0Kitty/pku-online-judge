#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

const int mod = 10007;

char a[1010], b[1010];
int c[1010][1010];
int inv[1010];
int dp[1010][1010];
int n, m;

int get_pow(int x, int y, int z) {
  if (y == 0) return 1;
  int tmp = get_pow(x, y / 2, z);
  tmp = (LL)tmp * tmp % z;
  if (y % 2) tmp = (LL)tmp * x % z;
  return tmp;
}

void init() {
  memset(c, 0, sizeof(c));
  for (int i = 0; i <= 1000; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  for (int i = 1; i <= 1000; i++) inv[i] = get_pow(i, mod - 2, mod);
}

int dfs(int k, int m) {
  if (dp[k][m] != -1) {
    return dp[k][m];
  }
  if (m == 0) {
    return (k == 0) ? 1 : 0;
  }
  if (m == 1) {
    return (k == 3) ? 1 : 0;
  }
  int ans = 0;
  for (int i = 0; i <= 3; i++) {
    if (i > k || 3 - i > n - k) continue;
    ans = ((LL)dfs(k + 3 - 2 * i, m - 1) * c[k][i] * c[n - k][3 - i] % mod +
           ans) %
          mod;
  }
  int tmp = dfs(k, m - 2) * (c[n][3] - m + 2) % mod;
  tmp = (tmp + mod) % mod;
  ans = (ans - tmp + mod) % mod;
  ans = ans * inv[m] % mod;
  dp[k][m] = ans;
  return ans;
}

int main() {
  init();
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n + m == 0) break;
    scanf("%s%s", a, b);
    int tmp = 0;
    for (int i = 0; i < n; i++) tmp += (a[i] != b[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", dfs(tmp, m));
  }
  return 0;
}
