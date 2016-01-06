#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF (1 << 30)
using namespace std;

int n, k, a[1005], l[1005], r[1005], tot, sum, mn, st, mk, tmp, ed;
bool down;

void check(bool need) {
  int i;

  down = true;
  for (i = 1; i <= n; i++) {
    if (down && a[i] > a[i - 1]) {
      l[i] = i - 1;
      if (need) tot++;
      down = false;
    } else {
      l[i] = l[i - 1];
      if (!down && a[i] < a[i - 1]) down = true;
    }
  }

  down = true;
  for (i = n; i >= 1; i--) {
    if (l[i] != l[i + 1] && i != n)
      r[i] = i;
    else
      r[i] = r[i + 1];
  }
}

int solve() {
  int i, j, t, ret = 0;

  tot = 0;
  a[0] = a[n + 1] = 0;
  l[0] = 0;
  l[n + 1] = n + 1;
  r[0] = 0;
  r[n + 1] = n + 1;

  check(true);
  if (tot <= k) return 0;
  tot = tot - k;
  while (tot--) {
    mn = INF;
    for (i = 1; i <= n + 1; i++)
      if (l[i] != l[i - 1] || i == 1) {
        if (i > 1 && sum < mn) {
          mn = sum;
          mk = st;
          ed = i - 1;
        }
        st = i;
        tmp = max(a[l[i]], a[r[i]]);
        sum = max(0, a[i] - tmp);
      } else
        sum += max(0, a[i] - tmp);

    st = mk;
    ret += mn;
    tmp = max(a[l[st]], a[r[st]]);
    for (i = st; i <= ed; i++) a[i] = min(a[i], tmp);
    check(false);
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  printf("%d\n", solve());
  return 0;
}
