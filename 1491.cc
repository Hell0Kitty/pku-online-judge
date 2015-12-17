
#include <stdio.h>
#include <math.h>

int commonfactor(int a, int b) {
  int n;
  while (a != 0) {
    n = b % a;
    b = a;
    a = n;
  }
  if (b == 1)
    return 1;
  else
    return 0;
}

int main() {
  int n;
  while (scanf("%d", &n), n > 0) {
    int m[50], i, j, sum = 0;
    double x;

    for (i = 0; i < n; i++) scanf("%d", &m[i]);
    for (i = 0; i < n - 1; i++)
      for (j = i + 1; j < n; j++)
        if (commonfactor(m[i], m[j])) sum++;
    if (sum > 0) {
      x = sqrt(3.0 * n * (n - 1) / sum);
      printf("%.6lf\n", x);
    } else
      printf("No estimate for this data set.\n");
  }
  return 0;
}