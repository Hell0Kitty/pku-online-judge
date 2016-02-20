#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define EPS 1e-8
#define MAXN 35
#define INF 0xfffffff

struct Point {
  double x, y;
} p[MAXN << 1];

double cross_pro(Point p0, Point p1, Point p2) {
  return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

int dblcmp(double d)  // 三出口判断正负浮点数函数
{
  if (fabs(d) < EPS) return 0;  // 三点共线
  return (d > 0) ? 1 : -1;
}

bool is_intersect(Point p1, Point p2, Point p3, Point p4)  // 判断严格相交
{
  return dblcmp(cross_pro(p3, p4, p1)) * dblcmp(cross_pro(p3, p4, p2)) == -1;
  // 判断起点终点是否在wall的两侧
}

int compute(Point dest, int cnt) {
  int i, j, res, min = INF;
  for (i = 0; i < cnt; ++i) {
    res = 0;
    for (j = 0; j < cnt; j += 2)
      if (is_intersect(dest, p[i], p[j], p[j + 1])) ++res;
    if (min > res) min = res;
  }
  return min;
}

int main() {
  int i, n, cnt = 0;
  double x1, y1, x2, y2;
  Point dest;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    p[cnt].x = x1;
    p[cnt++].y = y1;
    p[cnt].x = x2;
    p[cnt++].y = y2;
  }
  scanf("%lf%lf", &dest.x, &dest.y);
  if (n == 0)
    printf("Number of doors = 1\n");
  else
    printf("Number of doors = %d\n", compute(dest, cnt) + 1);
  return 0;
}
