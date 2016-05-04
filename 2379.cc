#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct list {
  int sum1, sum2, num, p1[22], p2[22];
} a[1002];
struct in {
  int c, p, t, r;
} b[1002];
int cmp1(in x, in y) { return x.t < y.t; }
int cmp2(list x, list y) {
  if (x.sum1 == y.sum1 && x.sum2 == y.sum2)
    return x.num < y.num;
  else if (x.sum1 == y.sum1)
    return x.sum2 < y.sum2;
  return x.sum1 > y.sum1;
}

int main() {
  int m, n;
  int c, p, t, r, i;
  while (scanf("%d%d", &m, &n) != EOF) {
    memset(a, 0, sizeof(a));
    for (i = 1; i <= m; i++) a[i].num = i;
    for (i = 1; i <= n; i++)
      scanf("%d%d%d%d", &b[i].c, &b[i].p, &b[i].t, &b[i].r);
    sort(b + 1, b + 1 + n, cmp1);
    for (i = 1; i <= n; i++) {
      c = b[i].c;
      p = b[i].p;
      t = b[i].t;
      r = b[i].r;
      if (r == 0) a[c].p1[p] += 1200;
      if (r == 1 && a[c].p2[p] == 0) {
        a[c].sum1 += 1;
        a[c].sum2 += (a[c].p1[p] + t);
        a[c].p2[p] = 1;
      }
    }
    sort(a + 1, a + 1 + m, cmp2);
    for (i = 1; i < m; i++) printf("%d ", a[i].num);
    printf("%d\n", a[m].num);
  }
  return 0;
}
