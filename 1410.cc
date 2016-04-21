#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define eps 1E-10

struct Point {
  int x, y;
} point[5], s, e;

bool in(Point &a) {
  if (a.x <= point[2].x && a.x >= point[0].x && a.y <= point[2].y &&
      a.y >= point[0].y)
    return true;
  return false;
}

bool inter(Point &a, Point &b, Point &c, Point &d) {
  if (min(a.x, b.x) > max(c.x, d.x) || min(a.y, b.y) > max(c.y, d.y) ||
      min(c.x, d.x) > max(a.x, b.x) || min(c.y, d.y) > max(a.y, b.y))
    return 0;
  double h, i, j, k;
  h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
  j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
  k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);
  return h * i <= eps && j * k <= eps;
}

int main() {
  // freopen("t.txt", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d%d%d%d%d", &s.x, &s.y, &e.x, &e.y, &point[0].x, &point[0].y,
          &point[2].x, &point[2].y);
    if (point[0].x > point[2].x) swap(point[0].x, point[2].x);
    if (point[0].y > point[2].y) swap(point[0].y, point[2].y);
    point[1].x = point[0].x;
    point[1].y = point[2].y;
    point[3].x = point[2].x;
    point[3].y = point[0].y;
    point[4] = point[0];
    bool ok = false;
    for (int i = 0; i < 4; i++)
      if (inter(point[i], point[i + 1], s, e)) {
        ok = true;
        break;
      }
    if (in(s) || in(e)) ok = true;
    if (ok)
      printf("T\n");
    else
      printf("F\n");
  }
  return 0;
}
