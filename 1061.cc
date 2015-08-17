#include <cstdio>
long long X, Y;
void GCD(long long A, long long B, long long &gcd) {
  if (B) {
    GCD(B, A % B, gcd);
    long long t = X;
    X = Y;
    Y = t - (A / B) * Y;
  } else {
    gcd = A;
    X = 1, Y = 0;
  }
}
int main() {
  long long x, y, m, n, B;
  while (scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &B) != EOF) {
    long long A = n - m, C = x - y, gcd;
    GCD(A, B, gcd);
    if (C % gcd)
      printf("Impossible\n");
    else {
      X *= C / gcd;
      Y *= C / gcd;
      if (X > 0)
        X %= B;
      else
        X = X % B + B;
      printf("%lld\n", X);
    }
  }
  return 0;
}
