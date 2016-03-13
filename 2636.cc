#include <stdio.h>
int main() {
  int num;
  int t, n, i, sum;
  while (scanf("%d", &t) != EOF) {
    while (t--) {
      sum = 0;
      scanf("%d", &n);
      for (i = 0; i < n; i++) {
        scanf("%d", &num);
        sum += num;
      }
      printf("%d\n", sum - (n - 1));
    }
  }

  return 0;
}
