#include <cstdio>
#include <cmath>
#define M 100010
int a[M], n, k, m, max;
int ok(int ans) {
  long long cnt = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > ans) {
      int t = ceil(1.0 * (a[i] - ans) / (k - 1));
      if (t > ans) return 0;
      cnt += t;
    }
  return cnt <= (long long)ans * m;
}
int solve() {
  int l = 0, r = max, mid;
  if (k == 1) return max;
  while (l < r) {
    mid = (r + l) >> 1;
    if (ok(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      max = a[i] > max ? a[i] : max;
    }
    scanf("%d%d", &m, &k);
    printf("%d\n", solve());
  }
  return 0;
}
