#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;

const int N = 100010;
typedef long long LL;
LL num[N];
int main() {
  // freopen("1.txt","r",stdin);
  int n;
  while (scanf("%d", &n) != EOF) {
    LL maxvalue = 0, rp = 0;
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; ++i) {
      scanf("%lld", &num[i]);
      if (num[i] > maxvalue) maxvalue = num[i];
    }
    LL k;
    scanf("%lld", &k);
    if (k == 1) {
      printf("%lld\n", maxvalue);
      continue;
    }
    LL lp = 1, ans = 0;
    rp = maxvalue;
    while (lp <= rp) {
      LL mid = (lp + rp) / 2, sum = 0;
      for (int i = 0; i < n; ++i) {
        if (num[i] > mid) {
          long long xx = ceil((num[i] - mid) * 1.0 / (k - 1));
          sum += xx;
        }
      }
      if (sum <= mid) {
        ans = mid;
        rp = mid - 1;
      } else
        lp = mid + 1;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
