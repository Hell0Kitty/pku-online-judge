#include <cstdio>
typedef long long LL;
#define SIZE 1000000
int fac[SIZE + 5], tot, m, k;
void divide(int x) {
  tot = 0;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      fac[tot++] = i;
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) fac[tot++] = x;
}

LL solve(LL x) {
  LL ans = 0;
  for (int i = 1; i < (1 << tot); ++i) {
    LL bits = 0;
    LL mult = 1;
    for (int j = 0; j < tot; ++j) {
      if (i & (1 << j)) {
        bits++;
        mult *= fac[j];
      }
    }
    if (bits & 1)
      ans += x / mult;
    else
      ans -= x / mult;
  }
  return x - ans;
}

int main() {
  while (~scanf("%d %d", &m, &k)) {
    divide(m);
    LL l = 1, r = (1LL << 33), mid, tmp, ans;
    while (l < r) {
      mid = (l + r) >> 1;
      tmp = solve(mid);
      if (tmp >= k)
        r = mid;
      else
        l = mid + 1;
    }
    printf("%lld\n", l);
  }
}
