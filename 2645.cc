#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long LL;

LL p, q;

inline LL gcd(LL a, LL b) {
  LL tmp;
  while (b) {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

int main() {
  LL n;
  LL t, s;
  LL a, b;
  LL g = 0;
  while (scanf("%I64d %I64d", &p, &q) != EOF && (p || q)) {
    if (p == 0) {
      printf("0 2\n");
      continue;
    }
    g = gcd(p, q);
    p /= g, q /= g;
    a = -1;
    for (LL i = 2; i <= 50000; i++) {
      n = i * i - i;

      if (n * p % q != 0) continue;
      t = n * p / q;
      s = sqrt(double(1 + 4LL * t));
      if (s * s == 1 + 4LL * t && 0 == ((1LL + s) % 2)) {
        a = i;
        b = (1LL + s) / 2;
        break;
      }
    }
    if (-1 == a) {
      printf("impossible\n");
    } else
      printf("%I64d %I64d\n", b, a - b);
  }

  return 0;
}
