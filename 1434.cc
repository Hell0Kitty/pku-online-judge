#include <stdio.h>
#include <algorithm>
using namespace std;
struct cistern {
  __int64 b, h, s;
  __int64 v;
};
cistern c[50004];
bool cmp(cistern a, cistern b) { return a.b < b.b; }
int main() {
  int cas;
  __int64 vol;
  scanf("%d", &cas);
  while (cas--) {
    int i, n;
    __int64 w, d;
    double sum = 0, mid, low, high = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%I64d%I64d%I64d%I64d", &c[i].b, &c[i].h, &w, &d);
      c[i].s = w * d;
      c[i].v = c[i].s * c[i].h;
      high = max(high, (double)(c[i].b + c[i].h));
      sum += c[i].v;
    }
    scanf("%I64d", &vol);
    if (vol > sum) {
      printf("OVERFLOW\n");
      continue;
    }
    sort(c, c + n, cmp);
    low = c[0].b;
    while (high - low > 0.0001) {
      sum = 0;
      mid = (high + low) / 2;
      for (i = 0; i < n; i++) {
        if (mid >= c[i].b + c[i].h)
          sum += c[i].v;
        else if (mid > c[i].b)
          sum += (mid - c[i].b) * c[i].s;
        if (mid < c[i].b) break;
      }
      if (sum >= vol) high = mid;
      if (sum < vol) low = mid;
    }
    printf("%.2lf\n", mid);
  }
  return 0;
}
