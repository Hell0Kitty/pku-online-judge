#include <stdio.h>
#include <math.h>
int main() {
  int m, x, k, p, q, min, max;
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &x);
    if (x % 2 == 1)
      min = x, max = x;
    else {
      p = 1;
      for (k = 1; k < 31; k++) {
        p = p * 2;
        q = p * 2;
        if (x % p == 0 && x % q != 0) break;
      }
      min = x - p + 1;
      max = x + p - 1;
    }
    printf("%d %d\n", min, max);
  }
  return 0;
}
