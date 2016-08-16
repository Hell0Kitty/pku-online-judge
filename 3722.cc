#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <map>
using namespace std;
struct soldier {
  double x;
  int d;
  bool operator<(const soldier &temp) const {
    if (x == temp.x) return d < temp.d;
    return x < temp.x;
  }
};
soldier a[111], na[111];
struct point {
  double f, t;
};
point list[10000000];
int cnt, n, id;
double l, r, t, now, ax, temp, ans, nt, lt, k1, b1, k2, b2, value;
int main() {
  int i, j, s, p, q, id1, id2;
  scanf("%lf%lf%d%lf", &l, &r, &n, &t);
  for (i = 0; i < n; i++) {
    scanf("%lf%d", &a[i].x, &a[i].d);
    if (a[i].x == 0)
      a[i].d = 1;
    else if (a[i].x == l)
      a[i].d = -1;
  }
  if (n == 0)
    printf("%.3lf\n", l * t);
  else {
    sort(a, a + n);
    cnt = 1;
    for (i = 1; i < n; i++) {
      if ((a[i].x != a[cnt - 1].x) || (a[i].d != a[cnt - 1].d)) a[cnt++] = a[i];
    }
    n = cnt;
    now = cnt = 0;
    while (true) {
      value = 0;
      ax = min(l, a[0].x + r);
      id = 0;
      for (i = 1; i < n; i++) {
        if (max(0.0, a[i].x - r) > ax) {
          value += ax - max(0.0, a[id].x - r);
          id = i;
        }
        if (min(l, a[i].x + r) > ax) ax = min(l, a[i].x + r);
      }
      value += ax - max(0.0, a[id].x - r);
      list[cnt].t = now;
      list[cnt++].f = l - value;
      if (now >= 2 * l) break;
      value = 2 * l - now;
      for (i = 0; i < n - 1; i++) {
        if (a[i].d == 1 && a[i + 1].d == -1) {
          if (a[i + 1].x - a[i].x <= 2 * r) {
            if (value > (a[i + 1].x - a[i].x) / 2.00)
              value = (a[i + 1].x - a[i].x) / 2.00;
          } else {
            if (value > (a[i + 1].x - a[i].x - 2 * r) / 2.00)
              value = (a[i + 1].x - a[i].x - 2 * r) / 2.00;
          }
        } else if (a[i].d == -1 && a[i + 1].d == 1) {
          if (a[i + 1].x - a[i].x < 2 * r) {
            if (value > (2 * r - (a[i + 1].x - a[i].x)) / 2.00)
              value = (2 * r - (a[i + 1].x - a[i].x)) / 2.00;
          }
        }
      }
      if (a[0].d == -1) {
        if (a[0].x > r) {
          if (value > a[0].x - r) value = a[0].x - r;
        } else {
          if (value > a[0].x) value = a[0].x;
        }
      } else {
        if (a[0].x < r) {
          if (value > r - a[0].x) value = r - a[0].x;
        }
      }
      if (a[n - 1].d == 1) {
        if (l - a[n - 1].x > r) {
          if (value > l - a[n - 1].x - r) value = l - a[n - 1].x - r;
        } else {
          if (value > l - a[n - 1].x) value = l - a[n - 1].x;
        }
      } else {
        if (l - a[n - 1].x < r) {
          if (value > r - (l - a[n - 1].x)) value = r - (l - a[n - 1].x);
        }
      }
      while (value <= 0) puts("orz");
      for (i = 0; i < n; i++) {
        if (a[i].d == 1) {
          a[i].x += value;
          if (a[i].x == l) a[i].d = -1;
        } else {
          a[i].x -= value;
          if (a[i].x == 0) a[i].d = 1;
        }
      }
      sort(a, a + n);
      now += value;
    }
    cnt--;
    int ncnt = cnt;
    for (i = 0; list[i].t <= t || i < cnt; i++) {
      list[ncnt].t = list[i].t + 2 * l;
      list[ncnt++].f = list[i].f;
    }
    cnt = ncnt;
    ans = lt = 0;
    id1 = 0;
    for (i = 0; i < cnt; i++) {
      double k, b;
      nt = min(t, list[i + 1].t);
      k = (list[i + 1].f - list[i].f) / (list[i + 1].t - list[i].t);
      b = list[i].f - k * list[i].t;
      ans += 0.5 * k * (nt * nt - list[i].t * list[i].t) + b * (nt - list[i].t);
      if (nt == t) {
        id2 = i;
        break;
      }
    }
    value = ans;
    while (list[id1].t < 2 * l) {
      double x1 = lt, x2 = nt,
             x = min(list[id1 + 1].t - lt, list[id2 + 1].t - nt), dx;
      double A, B;
      k1 = (list[id1 + 1].f - list[id1].f) / (list[id1 + 1].t - list[id1].t);
      b1 = list[id1].f - k1 * list[id1].t;
      k2 = (list[id2 + 1].f - list[id2].f) / (list[id2 + 1].t - list[id2].t);
      b2 = list[id2].f - k2 * list[id2].t;
      A = 0.5 * (k2 - k1);
      B = k2 * x2 + b2 - k1 * x1 - b1;
      if (ans < value + A * x * x + B * x) ans = value + A * x * x + B * x;
      if (A != 0) {
        dx = -B / (2 * A);
        if (dx >= 0 && dx <= x) {
          if (ans < value + A * dx * dx + B * dx)
            ans = value + A * dx * dx + B * dx;
        }
      }
      value += A * x * x + B * x;
      lt += x;
      nt += x;
      if (lt >= list[id1 + 1].t) id1++;
      if (nt >= list[id2 + 1].t) id2++;
    }
    printf("%.3lf\n", ans);
  }
  return 0;
}
