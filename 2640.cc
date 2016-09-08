#include <cstdio>
#include <algorithm>
using namespace std;

const double eps = 1e-10;

int main() {
  int t;
  while (scanf("%d", &t) && t) {
    long long a[20];
    double kk;
    for (int i = 0; i < t; i++) {
      scanf("%lf", &kk);
      a[i] = (kk + eps) * 1000;
    }
    if (t == 1) {
      printf("NO\n");
      continue;
    }
    sort(a, a + t);
    bool tag = 0;
    for (int i = 0; i < t; i++) {
      for (int j = i + 1; j < t; j++)
        if (a[j] == a[i]) {
          tag = 1;
          break;
        }
      if (tag) break;
    }
    if (!tag) {
      long long s = 0;
      for (int i = t - 1; i >= 2; i--) {
        s = 0;
        for (int j = i - 1; j >= 0; j--) s += a[j];
        if (s >= a[i]) tag = true;
        if (tag) break;
      }
    }
    if (tag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
