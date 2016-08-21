#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
int main() {
  long long num;
  long long llist[100], sum[100], k = 1;
  sum[0] = 0;
  int i;
  int n;
  for (i = 1;; i++) {
    llist[i] = 9 * k;
    sum[i] = sum[i - 1] + llist[i];
    if (sum[i] > 2000000000) break;
    if (i % 2 == 0) k = k * 10;
  }
  n = i;

  int len, ll;
  while (scanf("%lld", &num)) {
    if (num == 0) break;
    if (num < 10) {
      printf("%lld\n", num);
      continue;
    }
    for (i = 1; i <= n; i++) {
      if (num <= sum[i]) break;
    }
    len = i;
    num -= sum[i - 1];
    char str[100];
    ll = len / 2 + len % 2;
    long long k = 1;
    for (i = 1; i < ll; i++) {
      k = k * 10;
    }
    num = num + k - 1;
    sprintf(str, "%d", num);
    printf("%s", str);
    if (len % 2 == 0) {
      for (i = ll - 1; i >= 0; i--) printf("%c", str[i]);
    } else {
      for (i = ll - 2; i >= 0; i--) printf("%c", str[i]);
    }
    printf("\n");
  }
  return 0;
}
