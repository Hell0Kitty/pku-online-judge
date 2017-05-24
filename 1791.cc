#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 10e-9;

const int maxn = 1000 + 20;

int main() {
  int a, b, c, d, e, f;

  while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) != EOF && a && b && c &&
         d && e && f) {
    int ans = INF;
    int ta, tb;
    ta = a * c;
    tb = b * d;
    if (ta <= e && tb <= f) {
      int tans = 0;
      if (ta < e) tans += 1;
      if (tb < f) tans += 1;
      tans += a * b - 1;
      ans = min(ans, tans);
    }
    if (ta <= f && tb <= e) {
      int tans = 0;
      if (ta < f) tans += 1;
      if (tb < e) tans += 1;
      tans += a * b - 1;
      ans = min(ans, tans);
    }
    ta = a * d;
    tb = b * c;
    if (ta <= e && tb <= f) {
      int tans = 0;
      if (ta < e) tans += 1;
      if (tb < f) tans += 1;
      tans += a * b - 1;
      ans = min(ans, tans);
    }
    if (ta <= f && tb <= e) {
      int tans = 0;
      if (ta < f) tans += 1;
      if (tb < e) tans += 1;
      tans += a * b - 1;
      ans = min(ans, tans);
    }
    if (ans == INF) {
      printf("The paper is too small.\n");
    } else {
      printf("The minimum number of cuts is %d.\n", ans);
    }
  }

  return 0;
}
