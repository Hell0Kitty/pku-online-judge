#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define N 1010

using namespace std;
//奇数条边的时候满足，偶数时不确定
struct PO {
  double x, y;
} s[N], t[N];

int n;

inline void read() {
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &s[i].x, &s[i].y);
}

inline void go() {
  double a = 0.0, b = 0.0;
  for (int i = n; i >= 1; i--) {
    if (i & 1)
      a += s[i].x, b += s[i].y;
    else
      a -= s[i].x, b -= s[i].y;
  }
  t[1].x = a;
  t[1].y = b;
  for (int i = 2; i <= n; i++) {
    t[i].x = t[i - 1].x + 2.0 * (s[i - 1].x - t[i - 1].x);
    t[i].y = t[i - 1].y + 2.0 * (s[i - 1].y - t[i - 1].y);
  }
  printf("%d", n);
  for (int i = 1; i <= n; i++) printf(" %.6lf %.6lf", t[i].x, t[i].y);
  puts("");
}

int main() {
  while (scanf("%d", &n) != EOF) read(), go();
  return 0;
}
