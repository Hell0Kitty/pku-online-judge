#include <stdio.h>
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) {
  int c = gcd(a, b);
  return a * b / c;
}
int main() {
  int a, b, c, d;
  char ch;
  while (scanf("%d/%d%c%d/%d", &a, &b, &ch, &c, &d) != EOF) {
    int m = lcm(b, d);
    int n;
    if (ch == '+')
      n = a * (m / b) + c * (m / d);
    else
      n = a * (m / b) - c * (m / d);
    if (n == 0)
      printf("0\n");
    else {
      int t = gcd(m, n);
      n = n / t;
      m = m / t;
      if (m < 0) m = -m, n = -n;
      if (m == 1)
        printf("%d\n", n);
      else
        printf("%d/%d\n", n, m);
    }
  }
  return 0;
}
