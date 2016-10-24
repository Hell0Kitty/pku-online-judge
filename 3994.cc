#include <stdio.h>
int main() {
  int i = 0, n;
  while (scanf("%d", &n), n) {
    i++;
    printf("%d. %s %d\n", i, n % 2 ? "odd" : "even", n / 2);
  }
  return 0;
}
