#include <stdio.h>
#include <stdint.h>
#include <math.h>
int judge(int64_t n) {
  int64_t i = 2;
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;
  for (i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return 0;
  return 1;
}
int main() {
  int64_t a, d, n, count;
  while (scanf("%lld %lld %lld", &a, &d, &n) != EOF) {

    if (a == 0 && d == 0 && n == 0)
      break;
    count = 0;
    while (1) {
      if (judge(a))
        count++;
      if (count == n) {
        printf("%lld\n", a);
        break;
      } else
        a += d;
    }
  }
  return 1;
}