#include <stdio.h>
#include <stdlib.h>

int main() {
  int t, n, k1, k2, k3, r, ans, gun;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    k3 = k2 = k1 = n;
    r = 1;
    ans = n;
    while (k1 >= 10) {
      gun = ans / r;
      gun = gun % 10;
      r = r * 10;
      ans = ans / r;
      if (gun >= 5) {
        ans = ans + 1;
        ans = ans * r;
      } else {
        ans = ans * r;
      }
      k1 = k1 / 10;
    }
    printf("%d\n", ans);
  }
  return 0;
}
