#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double PI = acos(-1.0), eps = 1e-8;
int main() {
  int T, ca = 0;
  for (scanf("%d", &T); T; T--) {
    double n, m, t, c, A[5];
    scanf("%lf%lf%lf%lf", &n, &m, &t, &c);
    A[0] = t * t * n * m;
    A[1] = (t - c) * (t - c) * n * m + (c * (t - c) + c * c / 4.0) * 4 +
           c * (t - c) * (n + m - 4);
    A[2] =
        2 * c * (t - c) * n * m - c * (t - c) * (n + m) + c * c * (n + m - 2);
    A[4] = PI * c * c / 4 * (n - 1) * (m - 1);
    A[3] = A[0] - A[1] - A[2] - A[4];
    printf("Case %d:\n", ++ca);
    for (int i = 1; i <= 4; i++)
      printf("Probability of covering %d tile%s = %.4lf%%\n", i,
             (i == 1) ? " " : "s", A[i] / A[0] * 100.0 + eps);
    printf("\n");
  }
  return 0;
}
