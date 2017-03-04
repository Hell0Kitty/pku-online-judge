#include <stdio.h>
#include <string.h>
#define clr(x) memset(x, 0, sizeof(x))
int v[10005];
int main() {
  int n, k, p, i, res, num;
  while (scanf("%d%d", &n, &k) != EOF) {
    res = num = 0;
    clr(v);
    for (i = 0; i < n; i++) {
      scanf("%d", &p);
      if (!v[p]) {
        v[p] = 1;
        num++;
        if (num == k) {
          res++;
          clr(v);
          num = 0;
        }
      }
    }
    printf("%d\n", res + 1);
  }
  return 0;
}
