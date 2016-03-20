#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
int so, mo, br;
inline int dcmp(double x) { return (x > eps) - (x < -eps); }
struct point {
  int x, y, z;
};
struct poly {
  point p[1001];
  int n;
} ans, tem;
bool operator<(const point &a, const point &b) {
  return a.x < b.x || a.x == b.x && a.y < b.y;
}
inline void transform(const point &a, const point &b, const point &c,
                      const point &d, const poly &w, const poly &z, bool type) {
  double x1 = b.x - a.x, y1 = b.y - a.y, x2 = d.x - c.x, y2 = d.y - c.y,
         s = x2 * x2 + y2 * y2, u = (x1 * x2 + y1 * y2) / s,
         v = (x2 * y1 - x1 * y2) / s, tx, ty;
  int sum = 0, x, y;
  for (int i = 0; i < z.n; i++) {
    x = z.p[i].x - c.x, y = z.p[i].y - c.y;
    tx = (double)(u * x - v * y + a.x), ty = (double)(v * x + u * y + a.y);
    x = rint(tx), y = rint(ty);
    if (dcmp(tx - (double)x) || dcmp(ty - (double)y)) return;
    bool f = 1;
    for (int j = 0; f && j < w.n; j++)
      if (w.p[j].x == x && w.p[j].y == y) {
        f = 0;
        tem.p[i] = w.p[j];
        sum += w.p[j].z;
      }

    if (f) return;
  }
  if (type) {
    so++;
    if (sum > br) {
      br = sum;
      for (int i = 0; i < z.n; i++) ans.p[i] = tem.p[i];
    }
  } else
    mo++;
}
inline void maping(const poly &w, const poly &z, bool type) {
  for (int i = 0; i < w.n; i++)
    for (int j = 0; j < w.n; j++)
      if (i != j) transform(w.p[i], w.p[j], z.p[0], z.p[1], w, z, type);
}
inline void swap(point &a, point &b, const point &c) {
  if (c.z > b.z) {
    a = b;
    b = c;
  } else if (c.z > a.z)
    a = b;
}
int main() {
  poly w, z;
  char s[60];
  int m, tim = 1;
  while (scanf("%d", &w.n), w.n) {
    for (int i = 0; i < w.n; i++)
      scanf("%d%d%d", &w.p[i].x, &w.p[i].y, &w.p[i].z);
    scanf("%d", &m);
    printf("Map #%d\n", tim++);
    while (m--) {
      br = so = mo = 0;
      scanf("%d%s", &z.n, s);
      for (int i = 0; i < z.n; i++) scanf("%d%d", &z.p[i].x, &z.p[i].y);
      if (z.n > w.n) so = 0;
      if (z.n == 1) {
        so = w.n;
        ans.n = 1;
        ans.p[0].z = 0;
        for (int i = 0; i < w.n; i++)
          ans.p[0] = w.p[i].z > ans.p[0].z ? w.p[i] : ans.p[0];
      } else {
        maping(w, z, 1);
        maping(z, z, 0);
        so /= mo;
      }
      printf("\n%s occurs %d time(s) in the map.\n", s, so);
      if (so > 0) {
        sort(ans.p, ans.p + z.n);
        printf("Brightest occurrence:");
        for (int i = 0; i < z.n; i++)
          printf(" (%d,%d)", ans.p[i].x, ans.p[i].y);
        puts("");
      }
    }
    puts("-----");
  }
  return 0;
}
