#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int T;
__int64 m, n;

__int64 tostep(__int64 s) {
  __int64 j, k;
  k = (__int64)ceil(pow(s * 1.0, 0.5));
  j = k * (k - 1);
  if (s <= j)
    return 2 * k - 2;
  else
    return 2 * k - 1;
}

int main() {
  int i, j;
  __int64 k;
  scanf("%d", &T);
  for (i = 0; i < T; i++) {
    scanf("%d%d", &m, &n);
    k = n - m;
    if (k == 0)
      printf("0\n");
    else
      printf("%I64d\n", tostep(k));
  }
  return 0;
}
