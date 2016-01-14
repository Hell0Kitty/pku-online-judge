#include <stdio.h>
__int64 a[12];

__int64 C(__int64 n, __int64 k) {
  __int64 i, sum = 1;
  for (i = 1; i <= k; i++) sum = sum * (n - i + 1) / i;
  return sum;
}
int main() {
  __int64 c, cas, i, j, n;
  for (i = 0; i < 12; i++) a[i] = 0;
  a[0] = 0;
  a[1] = 1;
  a[2] = 5;
  for (i = 3; i <= 11; i++)
    for (j = 1; j <= i; j++) a[i] += C(i, j) * (a[i - j] + 1);
  scanf("%I64d", &c);
  for (cas = 1; cas <= c; cas++) {
    scanf("%I64d", &n);
    printf("%I64d %I64d %I64d\n", cas, n, a[n]);
  }
  return 0;
}
