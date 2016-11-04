#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

LL radix[15], n, m;

LL cal(LL x) {
  if (x < 0) return 0;
  LL sum = 1;
  for (int i = 1; 1; i++) {
    if (radix[i] > x) break;
    LL quo = x / radix[i];
    LL rem = x % radix[i - 1];
    LL now = (x % radix[i] - x % radix[i - 1]) / radix[i - 1];
    if (now == 0)
      sum += (quo - 1) * radix[i - 1] + rem + 1;
    else
      sum += quo * radix[i - 1];
  }
  return sum;
}

int main() {
  radix[0] = 1;
  for (int i = 1; i < 15; i++) radix[i] = radix[i - 1] * 10;
  while (scanf("%I64d%I64d", &m, &n), n != -1 || m != -1)
    printf("%I64d\n", cal(n) - cal(m - 1));
  return 0;
}
