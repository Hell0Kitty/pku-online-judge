#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
  int n, c, i;
  scanf("%d", &c);
  for (i = 1; i <= c; i++) {
    scanf("%d", &n);
    int j, m;
    j = (n * 2 + 1) / 3;
    printf("%d %d %d\n", i, n, j);
    if (n == 3) {
      printf("[1,1] [3,2]\n");
      continue;
    } else if (n == 2) {
      printf("[1,1]\n");
      continue;
    }
    int p = 0;
    for (j = n + 1 - j, m = 1; m <= j && j <= n; j++, m = m + 2) {
      if (m > 1 && p % 8 != 0) printf(" ");
      printf("[%d,%d]", j, m);
      p++;
      if (p % 8 == 0) printf("\n");
    }
    for (m = 2; j <= n; j++, m = m + 2) {
      if (p % 8 != 0) printf(" ");
      printf("[%d,%d]", j, m);
      p++;
      if (p % 8 == 0) printf("\n");
    }
    printf("\n");
  }
  return 0;
}
