#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#define eps 1e-8
#define pi acos(-1.0)
#define inf 107374182
#define inf64 1152921504606846976
#define lc l, m, tr << 1
#define rc m + 1, r, tr << 1 | 1
#define iabs(x) ((x) > 0 ? (x) : -(x))
#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A, X, SIZE) memcpy(A, X, sizeof(X[0]) * (SIZE))
#define memcopyall(A, X) memcpy(A, X, sizeof(X))
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

using namespace std;

double vb, vw, vr, vc;
int k;

double does(double first) {
  double temp = min(vr, vw + first) * (vw / (vw + first));
  double v = vb - first, last = vw + first;
  if (k <= 1) return temp;
  v /= (k - 1);
  if (vr + v > vc) v = vc - vr;
  for (int i = 1; i < k; i++) {
    temp = min(vr, last + v) * (temp / (min(vr, last) + v));
    last = min(vr, last + v);
  }
  return temp;
}

int main() {
  double l, r, lmid, rmid, leftover, ans1, ans2, ansa;
  while (scanf("%d", &k), k) {
    scanf("%lf%lf%lf%lf", &vb, &vw, &vr, &vc);
    if (vb + vw < vr) {
      puts("0");
      continue;
    }
    l = 0.0;
    r = vb;
    leftover = vb - (k - 1) * (vc - vr);
    if (l < leftover) l = leftover;
    if (r + vw > vc) r = vc - vw;
    while (r - l > eps) {
      lmid = (l + r) / 2;
      rmid = (lmid + r) / 2;
      if (does(lmid) <= does(rmid))
        r = rmid;
      else
        l = lmid;
    }
    printf("%d %.2f", k, r);
    if (k > 1) {
      ansa = (vb - r) / (k - 1);
      ansa = min(vc - vr, ansa);
      for (int i = 1; i < k; i++) {
        printf(" %.2f", ansa);
      }
    }
    puts("");
  }
  return 0;
}
