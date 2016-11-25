#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define llong long long
#define Min(a, b) (a < b ? a : b)
#define Max(a, b) (a > b ? a : b)
#define Abs(a) ((a) > 0 ? (a) : -(a))
#define Mod(a, b) (((a)-1 + (b)) % (b) + 1)
using namespace std;
int n, m, t;
const int N = 10005;
const int M = 105;
const int inf = (1 << 30);
int a[N];
llong dp[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  sort(a + 1, a + 1 + n);
  for (int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + (i - 1) * llong(a[i] - a[i - 1]);
  llong ans = 0;
  for (int i = 1; i <= n; i++) ans += dp[i];
  printf("%lld\n", ans * 2);
  return 0;
}
