#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct point {
  int x, y;
};
point a[100], b[100], c[100], f[100], aa[100];
double xmult(point a, point b, point c) {
  return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}
bool cmp(point a, point b) {
  if (a.y < b.y || a.y == b.y && a.x < b.x) return true;
  return false;
}
bool mult(point sp, point ep, point op) {
  return (sp.x - op.x) * (ep.y - op.y) >= (ep.x - op.x) * (sp.y - op.y);
}

void gram(int n, int flag) {
  int i, t, p, h;
  point g;
  sort(aa, aa + n, cmp);
  a[0] = aa[0];
  p = 1;
  for (i = 1; i < n; i++)
    if (aa[i].x == aa[i - 1].x && aa[i].y == aa[i - 1].y)
      continue;
    else
      a[p++] = aa[i];
  n = p;

  b[0] = a[0];
  if (n == 1) {
    printf("%d %d\n%d %d\n", flag, 1, b[0].x, b[0].y);
    return;
  }
  b[1] = a[1];
  if (n == 2) {
    if (b[1].y > b[0].y)
      h = 1;
    else
      h = 0;
    printf("%d %d\n%d %d\n%d %d\n", flag, 2, b[h].x, b[h].y, b[(h + 1) % 2].x,
           b[(h + 1) % 2].y);
    return;
  }
  b[2] = a[2];

  int top = 1, len;
  for (i = 2; i < n; i++) {
    while (top && mult(a[i], b[top], b[top - 1])) top--;
    b[++top] = a[i];
  }
  len = top;
  b[++top] = a[n - 2];
  for (i = n - 3; i >= 0; i--) {
    while (top != len && mult(a[i], b[top], b[top - 1])) top--;
    b[++top] = a[i];
  }
  t = top;
  f[0] = b[0];
  h = 1;
  for (i = 0; i < t; i++) f[i] = b[i];
  g = b[t - 1];
  h = t - 1;
  for (i = 0; i < t; i++)
    if (f[i].y > g.y || f[i].y == g.y && f[i].x < g.x) {
      h = i;
      g = f[i];
    }
  for (i = 0; i < t; i++) c[i] = f[(i + h) % t];
  c[t] = c[0];
  printf("%d %d\n", flag, t);
  for (i = t; i > 0; i--) printf("%d %d\n", c[i].x, c[i].y);
}
int main() {
  int ii, tt, flag, n, i;
  scanf("%d", &tt);
  for (ii = 1; ii <= tt; ii++) {
    scanf("%d%d", &flag, &n);
    for (i = 0; i < n; i++) scanf("%d%d", &aa[i].x, &aa[i].y);
    gram(n, flag);
  }
  return 0;
}
