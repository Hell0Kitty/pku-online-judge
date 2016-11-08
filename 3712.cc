#include <cstdio>
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k), !(n == 0 && k == 0)) {
    if (k == 1) {
      printf("%d/n", 0);
      continue;
    }
    if (2 * k > n) {
      printf("%d\n", n * (n - 1) >> 1);
      continue;
    }
    int a = 0, b = 0;
    a = (n - 1) * n / 2 - (n - k) * (n - k + 1) / 2;
    if (n > (k * 2)) b = (k - 1) * (2 * k - 1);
    printf("%d\n", a > b ? a : b);
  }
}
