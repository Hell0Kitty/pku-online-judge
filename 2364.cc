#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1005
int x[N], y[N];
int l, r, maxl, maxr, posl, posr;

int solve() {
  int a = 0, b = 0;
  int i, h;
  l = (-l) / 2;
  r /= 2;

  if (maxl == maxr) {
    h = x[l];
    for (i = l - 1; i >= posl; --i) {
      a += h;
      h = max(h, x[i]);
    }
    h = y[r];
    for (i = r - 1; i >= posr; --i) {
      b += h;
      h = max(h, y[i]);
    }
    return (posl + posr + 1) * maxl * 2 + min(a, b) * 2 * 2;
  } else {
    int mi = min(maxl, maxr);
    for (posl = 0; posl < l && x[posl] < mi; ++posl)
      ;
    for (posr = 0; posr < r && y[posr] < mi; ++posr)
      ;

    if (maxl < maxr) {
      h = x[l];
      for (i = l - 1; i >= posl; --i) {
        a += h;
        h = max(h, x[i]);
      }
      h = y[posr];
      for (i = posr; i <= r && y[i] <= mi; ++i) {
        h = max(h, y[i]);
        b += h;
      }
    } else {
      h = y[r];
      for (i = r - 1; i >= posr; --i) {
        a += h;
        h = max(h, y[i]);
      }
      h = x[posl];
      for (i = posl; i <= l && x[i] <= mi; ++i) {
        h = max(h, x[i]);
        b += h;
      }
    }
    return (posl + posr + 1) * mi * 2 + (a + min(a, b)) * 2;
  }
}

int main() {
  int i, k;
  while (scanf("%d%d", &l, &r) != EOF && l && r) {
    maxl = maxr = 0;
    for (i = l; i <= r; i += 2)
      if (i < 0) {
        scanf("%d", &k);
        x[(-i) / 2] = k;
        if (k >= maxl) {
          maxl = k;
          posl = (-i) / 2;
        }
      } else {
        scanf("%d", &k);
        y[i / 2] = k;
        if (k > maxr) {
          maxr = k;
          posr = i / 2;
        }
      }
    printf("%d\n", solve());
  }
  return 0;
}
