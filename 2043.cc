#include <iostream>
#include <cmath>
#include <algorithm>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define INF 1000000000
using namespace std;

struct Point {
  double x, y;
};
struct Seg {
  Point s, t;
};
struct Node {
  double y1, y2;
};

Point p[105];
Seg a[105];
Node Y[105];
int yNum = 0;
int n;
double minx, maxx;

bool cmp(Node a, Node b) {
  if (a.y1 == b.y1) return a.y2 < b.y2;
  return a.y1 < b.y1;
}

int cal() {
  int ans = 0, i;
  double dx;
  int temp, pre, t1, t2;
  for (dx = minx; dx < maxx; dx += 1) {
    yNum = 0;
    for (i = 0; i < n; i++)
      if (a[i].s.x <= dx && a[i].t.x >= dx + 1) {
        Y[yNum].y1 =
            a[i].s.y +
            (a[i].t.y - a[i].s.y) * (dx - a[i].s.x) / (a[i].t.x - a[i].s.x);
        Y[yNum++].y2 =
            a[i].s.y +
            (a[i].t.y - a[i].s.y) * (dx + 1 - a[i].s.x) / (a[i].t.x - a[i].s.x);
      }
    sort(Y, Y + yNum, cmp);
    temp = 0, pre = -INF;
    for (i = 0; i < yNum - 1; i += 2) {
      t1 = (int)ceil(max(Y[i + 1].y1, Y[i + 1].y2));
      t2 = (int)floor(min(Y[i].y1, Y[i].y2));
      temp += t1 - t2;
      if (t2 <= pre) temp -= pre - t2;
      pre = t1;
    }
    if (temp > 0) ans += temp;
  }
  return ans;
}

int main() {
  while (scanf("%d", &n), n) {
    minx = INF;
    maxx = -INF;
    int i;
    for (i = 0; i < n; i++) {
      scanf("%lf%lf", &p[i].x, &p[i].y);
      maxx = max(maxx, p[i].x);
      minx = min(minx, p[i].x);
    }
    for (i = 0; i < n; i++) {
      if (p[i].x < p[(i + 1) % n].x)
        a[i].s = p[i], a[i].t = p[(i + 1) % n];
      else
        a[i].s = p[(i + 1) % n], a[i].t = p[i];
    }
    printf("%d\n", cal());
  }
  return 0;
}
