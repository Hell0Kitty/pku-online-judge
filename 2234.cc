#include <stdio.h>
int M, n, r;
int main() {
  while (scanf("%d", &M) != EOF) {
    scanf("%d", &r);
    M--;
    while (M--) {
      scanf("%d", &n);
      r ^= n;
    }
    if (r == 0)
      printf("No\n");
    else
      printf("Yes\n");
  }
  return 0;
}
