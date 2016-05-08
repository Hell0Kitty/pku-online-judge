#include <iostream>
#include <cstdio>
#include <math.h>
#define eps 1e-8
#define INF 10000000000.0
#define zeor(x) (x > 0.0 ? x < eps : -x < eps)
struct Point {
  double x, y;
};
struct Line {
  double a, b, c;
};
struct Circle {
  double r;
  Point center;
};
struct pOnCircle {
  int cnt;
  double dis;
  double x, y;
};
Circle c[30];
int n;
//两点距离
double distance(Point p1, Point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
//求点到线距离
double pToline(Point p, Line l) {
  return fabs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}
//两点求线
Line twoPoLine(Point p1, Point p2) {
  Line l;
  l.a = p2.y - p1.y;
  l.b = p1.x - p2.x;
  l.c = p2.x * p1.y - p1.x * p2.y;
  return l;
}
//求点关于线对称点
Point pLinePoint(Point p, Line l) {
  Point p2;
  double d = l.a * l.a + l.b * l.b;
  p2.x =
      ((l.b * l.b - l.a * l.a) * p.x - 2 * l.a * l.b * p.y - 2 * l.a * l.c) / d;
  p2.y =
      ((l.a * l.a - l.b * l.b) * p.y - 2 * l.a * l.b * p.x - 2 * l.b * l.c) / d;
  return p2;
}
//求两条直线的交点(保证相交)
Point intersection(Point p1, Point p2, Point p3, Point p4) {
  Point ret = p1;
  double t = ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) /
             ((p1.x - p2.x) * (p3.y - p4.y) - (p3.x - p4.x) * (p1.y - p2.y));
  ret.x += (p2.x - p1.x) * t;
  ret.y += (p2.y - p1.y) * t;
  return ret;
}
//求直线与圆的交点（保证有交点）
void interLineCircle(double r, Point center, Point l1, Point l2, Point &p1,
                     Point &p2) {
  Point p = center;
  p.x += l1.y - l2.y;
  p.y += l2.x - l1.x;
  p = intersection(p, center, l1, l2);
  double temp = distance(l1, l2);
  double dis = distance(center, p);
  double t = sqrt(r * r - dis * dis) / temp;
  p1.x = p.x + (l2.x - l1.x) * t;
  p1.y = p.y + (l2.y - l1.y) * t;
  p2.x = p.x + (l1.x - l2.x) * t;
  p2.y = p.y + (l1.y - l2.y) * t;
}
//判断方向是否正确
bool isDir(Point orign, Point dir, Point inter) {
  return (dir.x * (inter.x - orign.x) + (inter.y - orign.y) * dir.y) >= 0;
}

void fun(Point ori, Point d) {
  int num = 0;
  pOnCircle node;
  Point dir = d;
  Point orign = ori;
  while (true) {
    node.dis = INF;
    int i, j, cnt = 0;
    Point temp;
    temp.x = orign.x + dir.x;
    temp.y = orign.y + dir.y;
    Line l = twoPoLine(orign, temp);
    for (i = 1; i <= n; i++)
      if (i != node.cnt && c[i].r - pToline(c[i].center, l) > eps) {
        Point p[2];
        double dis[2];
        interLineCircle(c[i].r, c[i].center, orign, temp, p[0],
                        p[1]);  //求直线与圆的交点
        dis[0] = distance(p[0], orign);
        dis[1] = distance(p[1], orign);
        int index = (dis[0] - dis[1] >= eps ? 1 : 0);
        if (isDir(orign, dir, p[index]))  //方向判断
        {
          if (dis[index] > eps && node.dis - dis[index] >= eps) {
            node.dis = dis[index];
            node.x = p[index].x;
            node.y = p[index].y;
            node.cnt = i;
          }
        }
      }
    if (INF - node.dis > eps) {
      if (num >= 10) {
        printf("...\n");
        return;
      } else {
        printf("%d ", node.cnt);
        num++;
        Point inter;
        inter.x = node.x;
        inter.y = node.y;
        Line lin = twoPoLine(c[node.cnt].center, inter);
        Point next = pLinePoint(orign, lin);
        dir.x = next.x - inter.x;
        dir.y = next.y - inter.y;
        orign.x = inter.x;
        orign.y = inter.y;
      }
    } else {
      printf("inf\n");
      return;
    }
  }
}

int main() {
  int i, j, k = 1;
  while (scanf("%d", &n), n) {
    for (i = 1; i <= n; i++) {
      scanf("%lf %lf %lf", &c[i].center.x, &c[i].center.y, &c[i].r);
    }
    Point orign;
    Point dir;
    scanf("%lf %lf %lf %lf", &orign.x, &orign.y, &dir.x, &dir.y);
    printf("Scene %d\n", k++);
    fun(orign, dir);
    printf("\n");
  }
  return 0;
}
