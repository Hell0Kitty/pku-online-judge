#include <stdio.h>
#include <string.h>
#define M 650

int a[M], n;

int main() {
  int i, j, cf;
  while (scanf("%d", &n) > 0) {
    if (n == -1) break;
    printf("N=%d:\n", n);
    memset(a, 0, sizeof(a));
    a[0] = 1;
    a[1] = 2;
    for (i = 2; i < n; i++) {
      cf = 0;
      for (j = 1; j <= a[0]; j++) {
        a[j] *= i;
        a[j] += cf;
        cf = a[j] / 10;
        a[j] %= 10;
      }
      while (cf) {
        a[0]++;
        a[a[0]] = cf % 10;
        cf /= 10;
      }
    }
    for (i = a[0]; i; i--) printf("%d", a[i]);
    printf("\n");
  }
  return 0;
}
