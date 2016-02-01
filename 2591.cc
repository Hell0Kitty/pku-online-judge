#include <stdio.h>
#define N 10000005
int num[N];
int main() {
  num[1] = 1;
  int i, j, k, x1, x2;
  j = 1, k = 1;
  for (i = 2; i < 10000001; i++) {
    x1 = num[j] * 2 + 1;
    x2 = num[k] * 3 + 1;
    if (x1 > x2) x1 = x2;
    num[i] = x1;
    if (num[j] * 2 + 1 == x1) j++;
    if (num[k] * 3 + 1 == x1) k++;
  }
  int n;
  while (scanf("%d", &n) != EOF) printf("%d\n", num[n]);
  return 0;
}
