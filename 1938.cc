

#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#include <string.h>
int a[35], b[20], c[40];

__int64 C(int n, int m) { return m > 0 ? (C(n - 1, m - 1) * n) / m : 1; }
int solve(char *s) {
  int len, sum = 0, i;
  len = strlen(s);
  for (i = 0; i < len; i++) {
    s[i] = s[i] - '0';
    sum += s[i] * pow(2.0, double(len - i - 1));
  }
  return sum;
}
int main() {
  int n, k, i, len, p, q, j;
  char s[50];
  while (scanf("%d", &n) != EOF && n) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &k);
    for (i = 1; i <= k; i++) {
      p = 0;
      for (j = 0; j < 40; j++) c[j] = 0;
      scanf("%s", s);
      for (j = 1; j <= n / 2; j++) {
        scanf("%d", &b[j]);
        for (q = 1; q <= n; q++) {
          if (a[q] == b[j]) {
            c[++p] = q;
            break;
          }
        }
      }
      sort(c + 1, c + n / 2 + 1);
      int sum = 0;
      for (j = 1; j <= n / 2; j++) {
        for (q = c[j - 1] + 1; q < c[j]; q++) sum += C(n - q, n / 2 - j);
      }
      if (sum == solve(s))
        printf("TRUE\n");
      else
        printf("FALSE\n");
    }
  }
  return 0;
}
