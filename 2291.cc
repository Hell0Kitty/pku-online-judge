#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main() {
  int n, m, i, max;

  while (scanf("%d", &n) != EOF) {
    for (; n > 0; n--) {
      scanf("%d", &m);
      int shu[m];
      for (i = 0; i < m; i++) {
        scanf("%d", &shu[i]);
      }
      qsort(shu, m, sizeof(int), comp);
      max = shu[0] * m;
      for (i = 1; i < m; i++) {
        if (shu[i] * (m - i) > max) {
          max = shu[i] * (m - i);
        }
      }
      printf("%d\n", max);
    }
  }
  return (0);
}
