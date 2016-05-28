#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long n, m;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%I64d%I64d", &n, &m);
    long long l = -100000 * n, r = n * n + 100000 * n + n * n + n * n;
    long long ans = 0;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      long long cnt = 0;
      for (long long j = 1; j <= n; j++) {
        long long sl = 1, sr = n;
        long long scnt = 0;
        while (sl <= sr) {
          long long smid = (sl + sr) >> 1;
          long long val =
              smid * smid + 100000 * smid + j * j - 100000 * j + smid * j;
          if (val <= mid) {
            scnt = smid;
            sl = smid + 1;
          } else
            sr = smid - 1;
        }
        cnt += scnt;
      }
      if (cnt >= m) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
