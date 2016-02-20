#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
  double a, b, c, d;
  while (scanf("%lf%lf%lf%lf", &a, &b, &c, &d) != EOF) {
    int ans = 0;
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    while (c > a + 1e-8) {
      ans++;
      c /= 2.0;
    }
    while (d > b + 1e-8) {
      ans++;
      d /= 2.0;
    }
    printf("%d\n", ans);
  }
  return 0;
}
