#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
__int64 a[100000000];
int main() {
  __int64 m, n;
  while (scanf("%I64d%I64d", &m, &n), m || n) {
    a[0] = 1;
    if (n > m / 2) n = m - n;

    for (int i = 1; i <= n; i++) a[i] = a[i - 1] * (m - i + 1) / i;
    printf("%I64d\n", a[n]);
  }
  return 0;
}
