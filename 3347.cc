#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
struct data {
  double len, left, right;
} po[60];
const double q2 = sqrt(2.0), eps = 1e-4;
int main() {
  int n;
  while (scanf("%d", &n), n) {
    for (int i = 1; i <= n; i++) scanf("%lf", &po[i].len);
    for (int i = 1; i <= n; i++) {
      double left = 0;
      for (int j = 1; j < i; j++)
        left = max(left, po[j].right - fabs(po[i].len - po[j].len) / q2);
      po[i].left = left;
      po[i].right = left + po[i].len * q2;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        if (po[i].len > po[j].len && po[i].left < po[j].right)
          po[j].right = po[i].left;
        if (po[i].len < po[j].len && po[j].right > po[i].left)
          po[i].left = po[j].right;
      }
    }
    bool first = true;
    for (int i = 1; i <= n; i++) {
      if (po[i].left < po[i].right - eps) {
        if (first)
          first = false;
        else
          printf(" ");
        printf("%d", i);
      }
    }
    printf("\n");
  }
  return 0;
}
