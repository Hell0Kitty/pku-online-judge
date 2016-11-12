#include <iostream>
using namespace std;
int M, L, c[1010], dp[1010], n, pre[1010], sum, ans;
bool v[1010];
void dfs(int j) {
  if (j == 0) return;
  v[pre[j]] = 0;
  dfs(j - c[pre[j]]);
}
int main() {
  while (scanf("%d%d", &M, &L)) {
    if (M == 0 && L == 0) break;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &c[i]);
      v[i] = 1;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
      for (int j = M; j >= c[i]; j--)
        if (dp[j] < dp[j - c[i]] + c[i]) {
          dp[j] = dp[j - c[i]] + c[i];
          pre[j] = i;
        }
    dfs(dp[M]);
    sum = 0;
    ans = n;
    for (int i = 1; i <= n; i++)
      if (v[i] == 1) {
        sum += c[i];
        ans--;
      }
    if (sum <= L) {
      printf("%d", ans);
      for (int i = 1; i <= n; i++)
        if (v[i] == 0) printf(" %d", i);
      printf("\n");
    } else
      printf("Impossible to distribute\n");
  }
  return 0;
}
