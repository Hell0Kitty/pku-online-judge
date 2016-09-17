#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <cmath>

using namespace std;

int t, n, m, GCD, phi, ans1, ans2;

int temp, num;

int fac[1000000];

int gcd(int x, int y) {
  int r;

  if (x < y) {
    swap(x, y);
  }

  while (x % y) {
    r = x % y;

    x = y;

    y = r;
  }

  return y;
}

int euler(int x) {
  int y = (int)sqrt(x + 0.5);

  int curans = x;

  for (int i = 2; i <= y; i++) {
    if (x % i == 0) {
      curans = curans / i * (i - 1);

      while (x % i == 0) {
        x /= i;
      }
    }
  }

  if (x > 1) {
    curans = curans / x * (x - 1);
  }

  return curans;
}

int quickpow(int m, int n, int k) {
  int b = 1;

  while (n > 0) {
    if (n & 1) {
      b = (long long)b * m % k;
    }

    n >>= 1;

    m = (long long)m * m % k;
  }

  return b;
}

int main() {
  int T = 0;

  while (scanf("%d/%d", &n, &m) != EOF) {
    T++;

    GCD = gcd(n, m);

    n /= GCD;

    m /= GCD;

    t = 0;

    while (m % 2 == 0) {
      t++;

      m /= 2;
    }

    ans1 = t + 1;

    phi = euler(m);

    if (phi == 1) {
      ans2 == 1;

    }

    else {
      num = 0;

      for (int i = 1; i * i <= phi; i++) {
        if (phi % i == 0)

        {
          fac[num++] = i;

          fac[num++] = phi / i;
        }
      }

      sort(fac, fac + num);

      for (int i = 0; i < num; i++) {
        temp = quickpow(2, fac[i], m);

        if (temp == 1) {
          ans2 = fac[i];

          break;
        }
      }
    }

    printf("Case #%d: ", T);

    printf("%d,%d\n", ans1, ans2);
  }

  return 0;
}
