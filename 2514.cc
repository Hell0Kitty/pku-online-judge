#include <iostream>
#include <cmath>
using namespace std;
__int64 one[21], tt[30], tz[30], ones[21];
__int64 mypow(__int64 a) {
  __int64 t = 1;
  for (int i = 1; i <= a; i++) t *= 10;
  return t;
}
void ini() {
  __int64 f = 10, w = 1;
  one[1] = 10;
  __int64 i;
  for (i = 2; i <= 18; i++) {
    w *= 10;
    one[i] = 9 * w * i + one[i - 1];
  }
  tt[1] = 4;
  tz[1] = 3;

  for (i = 2; i <= 18; i++) {
    f *= 10;
    w = (__int64)sqrt((double)f);
    if (w * w == f) w--;
    tz[i] = w;
    tt[i] = (w - tz[i - 1]) * i + tt[i - 1];
  }
}
__int64 redigit1(__int64 x) {
  __int64 j = 2;
  if (x <= 10) return x - 1;
  for (;; j++) {
    if (x <= one[j]) break;
  }
  if (x == one[j]) return 9;
  x -= one[j - 1];
  __int64 u = x / j;
  __int64 s = mypow(j - 1) + u - 1;
  if (u * j == x) return s % 10;
  s++;
  x -= u * j;
  s /= mypow(j - x);
  return s % 10;
}
__int64 redigit2(__int64 x) {
  if (x <= 4) return (x - 1) * (x - 1);
  int j = 2;
  while (x > tt[j]) j++;
  if (x == tt[j]) return (tz[j] * tz[j]) % 10;
  x -= tt[j - 1];
  __int64 p = x / j;
  __int64 y;
  x -= j * p;
  __int64 o = tz[j - 1] + p;
  if (x == 0) return (o * o) % 10;
  o++;
  o *= o;
  o /= mypow(j - x);
  return o % 10;
}
int main() {
  __int64 k, a, b, jin, ss, a1, a2;
  ini();
  while (scanf("%I64d", &k) && k) {
    k++;
    a = redigit1(k);
    b = redigit2(k);
    a1 = redigit1(k + 1);
    a2 = redigit2(k + 1);
    jin = 0;
    while (a1 + a2 > 8) {
      if (a1 + a2 >= 10) {
        jin = 1;
        break;
      }
      k++;
      a1 = redigit1(k + 1);
      a2 = redigit2(k + 1);
    }

    printf("%I64d\n", (a + b + jin) % 10);
  }
  return 0;
}
