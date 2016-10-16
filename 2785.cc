#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 4100;
long long a[maxn], b[maxn], c[maxn], d[maxn];
long long cd[maxn * maxn];

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%lld%lld%lld%lld", &a[i], &b[i], &c[i], &d[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cd[i * n + j] = c[i] + d[j];
      }
    }
    sort(cd, cd + (n * n));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        long long need = -(a[i] + b[j]);
        ans += upper_bound(cd, cd + n * n, need) -
               lower_bound(cd, cd + n * n, need);
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}
