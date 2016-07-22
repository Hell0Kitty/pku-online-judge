#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define maxn 1005

struct point {
  double x, y;
} pnt[maxn], res[maxn];

int n, l;

bool mult(point sp, point ep, point op) {
  return (sp.x - op.x) * (ep.y - op.y) >= (ep.x - op.x) * (sp.y - op.y);
}

bool operator<(const point &l, const point &r) {
  return l.y < r.y || (l.y == r.y && l.x < r.x);
}

int graham(point pnt[], int n, point res[]) {
  int i, len, top = 1;
  sort(pnt, pnt + n);
  if (n == 0) return 0;
  res[0] = pnt[0];
  if (n == 1) return 1;
  res[1] = pnt[1];
  if (n == 2) return 2;
  res[2] = pnt[2];
  for (i = 2; i < n; i++) {
    while (top && mult(pnt[i], res[top], res[top - 1])) top--;
    res[++top] = pnt[i];
  }
  len = top;
  res[++top] = pnt[n - 2];
  for (i = n - 3; i >= 0; i--) {
    while (top != len && mult(pnt[i], res[top], res[top - 1])) top--;
    res[++top] = pnt[i];
  }
  return top;
}

double dis(point &p, point &q) {
  double x1 = p.x - q.x, y1 = p.y - q.y;
  return sqrt(x1 * x1 + y1 * y1);
}
int main() {
  scanf("%d%d", &n, &l);
  for (int i = 0; i < n; i++) scanf("%lf%lf", &pnt[i].x, &pnt[i].y);
  int tot = graham(pnt, n, res);
  double ans = l * 2 * 3.14159265;
  for (int i = 0; i < tot; i++) ans += dis(res[i], res[(i + 1) % tot]);
  printf("%.0f\n", ans);
  return 0;
}
