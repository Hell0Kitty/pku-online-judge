#include <stdio.h>
int main() {
  int T, i, j, n;
  int base[27] = {1}, result[27];
  for (i = 1; i < 27; ++i) base[i] = (base[i - 1] << 1) + 1;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d [", n);
    if (!n) {
      printf("]\n");
      continue;
    }
    for (j = 0, i = 26; n; --i) {
      while (n >= base[i]) {
        result[j++] = i;
        n -= base[i];
      }
    }
    while (j - 1) printf("%d,", result[--j]);
    printf("%d]\n", result[--j]);
  }
  return 0;
}
