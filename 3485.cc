#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
struct point {
  double left;
  double right;
} po[100000];
int cmp(const void *a, const void *b) {
  return (*(point *)a).right < (*(point *)b).right ? -1 : 1;
}
int main() {
  double way_long, dis;
  int n, i, j, k;
  double a, b;
  double rec;
  int re;
  while (scanf("%lf%lf%d", &way_long, &dis, &n) != EOF) {
    re = 0;
    for (i = 0; i < n; i++) {
      scanf("%lf%lf", &a, &b);
      rec = sqrt(dis * dis - b * b);
      po[i].left = a - rec;
      po[i].right = a + rec;
      if (po[i].left < 0) po[i].left = 0;
    }
    qsort(po, n, sizeof(po[0]), cmp);
    // for(i=0;i<n;i++)
    // printf("%lf\n",po[i].right);
    re = 0;
    i = 0;
    while (i < n) {
      k = i;
      re++;
      while (i < n && po[i].left <= po[k].right) i++;
    }
    printf("%d\n", re);
  }
  return 0;
}
