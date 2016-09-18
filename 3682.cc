#include <stdio.h>

double E[1005];
double F[1005];

int main() {
  int i, j, n;
  double q, p;
  while (1) {
    scanf("%d", &n);
    if (n == 0) break;
    scanf("%lf", &p);
    E[0] = 0;
    F[0] = 0;
    for (i = 1; i <= n; i++) {
      E[i] = 1 / p + E[i - 1];
      F[i] = F[i - 1] + 2 * E[i - 1] - 2 * E[i] + (1 + 2 * E[i]) / p;
    }
    printf("%.3lf %.3lf\n", E[n], F[n]);
  }
  return 0;
}
