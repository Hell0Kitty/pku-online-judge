#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int ans, n, id, id1, id2;
double W, H, w, h;
double x, arg, pi = acos(-1.0), k, b, in, eps = 1e-6;
struct brick {
  double x, y, w, h;
  int p;
};
brick a[1000];
bool visit[1000], up;
int main() {
  int i, j, s, p, q;
  double x0, y0, x1, y1, nx1, ny1;
  while (scanf("%lf%lf%lf%lf%d", &W, &H, &w, &h, &n) && W + H + w + h + n) {
    for (i = 0; i < n; i++) {
      scanf("%lf%lf%d", &a[i].x, &a[i].y, &a[i].p);
      a[i].w = w;
      a[i].h = h;
    }
    a[n].x = a[n].y = a[n].p = 0;
    a[n].w = W;
    a[n].h = H;
    memset(visit, false, sizeof(visit));
    scanf("%lf%lf", &x, &arg);
    arg = arg * pi / 180.000;
    k = tan(arg);
    b = -k * x;
    x1 = x;
    y1 = 0;
    id1 = n;
    id2 = 0;
    up = true;
    ans = 0;
    while (true) {
      in = (double)1000000000 * (double)1000000000;
      for (i = 0; i <= n; i++) {
        x0 = a[i].x;
        y0 = k * x0 + b;
        if (y0 <= a[i].y + a[i].h && y0 >= a[i].y) {
          if ((up && y0 > y1 + eps) || (!up && y0 < y1 - eps)) {
            if (in > (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)) {
              in = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
              id1 = i;
              id2 = 3;
              nx1 = x0;
              ny1 = y0;
            }
          }
        }
        x0 = a[i].x + a[i].w;
        y0 = k * x0 + b;
        if (y0 <= a[i].y + a[i].h && y0 >= a[i].y) {
          if ((up && y0 > y1 + eps) || (!up && y0 < y1 - eps)) {
            if (in > (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)) {
              in = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
              id1 = i;
              id2 = 1;
              nx1 = x0;
              ny1 = y0;
            }
          }
        }
        y0 = a[i].y;
        x0 = (y0 - b) / k;
        if (x0 <= a[i].x + a[i].w && x0 >= a[i].x) {
          if ((up && y0 > y1 + eps) || (!up && y0 < y1 - eps)) {
            if (in > (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)) {
              in = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
              id1 = i;
              id2 = 0;
              nx1 = x0;
              ny1 = y0;
            }
          }
        }
        y0 = a[i].y + a[i].h;
        x0 = (y0 - b) / k;
        if (x0 <= a[i].x + a[i].w && x0 >= a[i].x) {
          if ((up && y0 > y1 + eps) || (!up && y0 < y1 - eps)) {
            if (in > (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)) {
              in = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
              id1 = i;
              id2 = 2;
              nx1 = x0;
              ny1 = y0;
            }
          }
        }
      }
      if (id1 == n && id2 == 0) break;
      if (id1 < n) ans += a[id1].p;
      if (id2 == 0) {
        x0 = x1;
        y0 = 2 * a[id1].y - y1;
        if (nx1 == x0)
          k = (double)1000000000 * (double)100000000;
        else
          k = (ny1 - y0) / (nx1 - x0);
        b = y0 - k * x0;
        up = !up;
      } else if (id2 == 2) {
        x0 = x1;
        y0 = 2 * (a[id1].y + a[id1].h) - y1;
        if (nx1 == x0)
          k = (double)1000000000 * (double)100000000;
        else
          k = (ny1 - y0) / (nx1 - x0);
        b = y0 - k * x0;
        up = !up;
      } else if (id2 == 1) {
        y0 = y1;
        x0 = 2 * (a[id1].x + a[id1].w) - x1;
        if (nx1 == x0)
          k = (double)1000000000 * (double)100000000;
        else
          k = (ny1 - y0) / (nx1 - x0);
        b = y0 - k * x0;
      } else if (id2 == 3) {
        y0 = y1;
        x0 = 2 * a[id1].x - x1;
        if (nx1 == x0)
          k = (double)1000000000 * (double)100000000;
        else
          k = (ny1 - y0) / (nx1 - x0);
        b = y0 - k * x0;
      }
      x1 = nx1;
      y1 = ny1;
      if (id1 < n) {
        for (j = id1; j < n; j++) a[j] = a[j + 1];
        n--;
        if (n == 0) break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
