#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 105
#define maxs 2000 * 100
#define shift 1000 * 100
#define inf 0x3f3f3f3f

int n, s[maxn], f[maxn];
int dp[maxs];

void input() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &s[i], &f[i]);
}

void work() {
  for (int i = 0; i < maxs; i++) dp[i] = -inf;
  dp[0 + shift] = 0;
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    l = min(l, l + s[i]);
    r = max(r, r + s[i]);
    int step = 1;
    int begin = l, end = r;
    if (s[i] > 0) {
      step = -1;
      swap(begin, end);
    }
    for (int j = begin; j != end + step; j += step) {
      dp[j + shift] = max(dp[j - s[i] + shift] + f[i], dp[j + shift]);
    }
  }
  int ans = 0;
  for (int i = 0; i <= r; i++)
    if (dp[i + shift] >= 0) ans = max(ans, i + dp[i + shift]);
  printf("%d\n", ans);
}

int main() {
  input();
  work();
  return 0;
}
