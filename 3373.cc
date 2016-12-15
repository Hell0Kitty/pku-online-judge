#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s[105];
int dp[105][10], tem[105], a[105], mod, len, f[105][10005], k;

void init() {
  int i, j;
  for (i = 0; i <= 9; i++) dp[1][i] = i % mod;
  for (i = 2; i <= len; i++)
    for (j = 0; j <= 9; j++) dp[i][j] = (dp[i - 1][j] * 10) % mod;
  memset(f, 0, sizeof(f));
}

bool dfs(int cnt, int l, int k) {
  int i, j;
  if (!k) {
    for (i = 0; i < len; i++) printf("%d", tem[i]);
    printf("\n");
    return 1;
  }
  if (!cnt) return 0;
  if (l > len - 1) return 0;
  if (f[l][k] >= cnt) return 0;
  for (i = l; i < len; i++) {
    for (j = 0; j < a[i]; j++) {
      if (!i && !j) continue;
      tem[i] = j;
      int temp = (k - dp[len - i][a[i]] + dp[len - i][j]) % mod;
      if (temp < 0) temp += mod;
      if (dfs(cnt - 1, i + 1, temp)) return 1;
    }
    tem[i] = a[i];
  }
  for (i = len - 1; i >= l; i--) {
    for (j = a[i] + 1; j <= 9; j++) {
      if (!i && !j) continue;
      tem[i] = j;
      int temp = (k - dp[len - i][a[i]] + dp[len - i][j]) % mod;
      if (temp < 0) temp += mod;
      if (dfs(cnt - 1, i + 1, temp)) return 1;
    }
    tem[i] = a[i];
  }
  f[l][k] = cnt;
  return 0;
}

int main() {
  int i, j;
  while (~scanf("%s", s)) {
    scanf("%d", &mod);
    len = strlen(s);
    init();
    k = 0;
    for (i = 0; i < len; i++) tem[i] = a[i] = s[i] - '0';
    for (i = len - 1; i >= 0; i--) k = (k + dp[len - i][a[i]]) % mod;
    for (i = 0; i < len; i++)
      if (dfs(i, 0, k)) break;
  }

  return 0;
}
