#include <stdio.h>
#include <memory.h>
#define MAX 781
int f[MAX], d[10];
int main() {
  int n, i, j, len, k, temp;
  while (scanf("%d", &n), n) {
    memset(f, 0, sizeof(f));
    memset(d, 0, sizeof(d));
    f[0] = 1;
    len = 1;
    for (i = 2; i <= n; i++) {
      for (j = 0; j < len; j++) f[j] *= i;
      for (j = 0; j < len; j++) {
        k = j;
        temp = f[j];
        f[j] %= 10;
        while (temp / 10) {
          temp /= 10;
          f[++k] += temp % 10;
        }
        len = (k + 1) > len ? (k + 1) : len;
      }
    }
    for (i = 0; i < len; i++) d[f[i]]++;
    printf(
        "%d! --\n   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n   (5)%5d  "
        "  (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",
        n, d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], d[8], d[9]);
  }
  return 0;
}
