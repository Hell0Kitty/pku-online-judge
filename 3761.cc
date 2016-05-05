#include <stdio.h>
#define MOD 20100713
#define K 1000010
int fac[K];
void init() {
  fac[0] = 1;
  for (long long i = 1; i < K; i++) {
    fac[i] = (i * fac[i - 1]) % MOD;
  }
}
long long quickPow(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long t = quickPow(a, b / 2);
  t = (t * t) % MOD;
  if (b & 1)
    return (t * a) % MOD;
  else
    return t;
}
long long solve(int n, int k) {
  long long res = fac[k] * (quickPow(k + 1, n - k) - quickPow(k, n - k)) % MOD;
  if (res < 0)
    return res + MOD;
  else
    return res;
}
int main() {
  int tt, n, k;
  scanf("%d", &tt);
  init();
  while (tt--) {
    scanf("%d%d", &n, &k);
    printf("%lld\n", solve(n, k));
  }
  return 0;
}
