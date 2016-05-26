#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define MAXN 2600
#define eps 1e-8
#define offset 1000000
#define zero(x) (((x) > 0 ? (x) : (-x)) < eps)
using namespace std;

struct pt {
  double x, y;
};

struct info {
  int idx;
  double area;
  bool operator<(const info &p) const { return area < p.area - eps; }
};

pt poly[MAXN][MAXN];
int altitude[MAXN];
int cnt[MAXN];
info ori[MAXN];
info outside[MAXN];
info inside[MAXN];
int opos, ipos;
pt st = (pt){0, 0}, ed = (pt){100000, 0};

int n, m, p;

double xmult(pt p1, pt p2, pt p0) {
  return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

int inside_polygon(pt q, int n, pt *p, int on_edge = 1) {
  pt q2;
  int i = 0, count;
  while (i < n)
    for (count = 0, q2.x = rand() + offset, q2.y = rand() + offset; i < n; i++)
      if (zero(xmult(q, p[i], p[(i + 1) % n])) &&
          (p[i].x - q.x) * (p[(i + 1) % n].x - q.x) < eps &&
          (p[i].y - q.y) * (p[(i + 1) % n].y - q.y) < eps)
        return on_edge;
      else if (zero(xmult(q, q2, p[i])))
        break;
      else if (xmult(q, p[i], q2) * xmult(q, p[(i + 1) % n], q2) < -eps &&
               xmult(p[i], q, p[(i + 1) % n]) *
                       xmult(p[i], q2, p[(i + 1) % n]) <
                   -eps)
        count++;
  return count & 1;
}

double area_polygon(int n, pt *p) {
  double s1 = 0, s2 = 0;
  for (int i = 0; i < n; i++) {
    s1 += p[(i + 1) % n].y * p[i].x;
    s2 += p[(i + 1) % n].y * p[(i + 2) % n].x;
  }
  return fabs(s1 - s2) / 2;
}

void Solve() {
  int i, j, a, b;
  long long up = 0, down = 0, tmp;
  scanf("%d", &n);
  for (i = 0, opos = ipos = 0; i < n; i++) {
    scanf("%d%d", &altitude[i], &cnt[i]);
    for (j = 0; j < cnt[i]; j++) scanf("%lf%lf", &poly[i][j].x, &poly[i][j].y);
    ori[i] = (info){i, area_polygon(cnt[i], poly[i])};
    a = inside_polygon(st, cnt[i], poly[i], 1);
    b = inside_polygon(ed, cnt[i], poly[i], 1);
    if (a == 1 && b == 0)
      outside[opos++] = ori[i];
    else if (a == 0 && b == 1)
      inside[ipos++] = ori[i];
  }
  sort(outside, outside + opos);
  sort(inside, inside + ipos);
  for (i = 0; i < opos - 1; i++) {
    tmp = altitude[outside[i + 1].idx] - altitude[outside[i].idx];
    if (tmp > eps)
      up += tmp;
    else if (tmp < -eps)
      down += tmp;
  }
  for (i = ipos - 1; i > 0; i--) {
    tmp = altitude[inside[i - 1].idx] - altitude[inside[i].idx];
    if (tmp > eps)
      up += tmp;
    else if (tmp < -eps)
      down += tmp;
  }
  if (ipos > 0 && opos > 0) {
    tmp = altitude[inside[ipos - 1].idx] - altitude[outside[opos - 1].idx];
    if (tmp > eps)
      up += tmp;
    else if (tmp < -eps)
      down += tmp;
  }
  printf("%I64d %I64d\n", up, -down);
}

int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) Solve();
  return 0;
}
