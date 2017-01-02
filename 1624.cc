#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <math.h>
#define eps 1e-8
#include <algorithm>
using namespace std;
struct Point {
  double x, y;
};
int n;
Point p[100];
double Xmult(Point a, Point b) { return a.x * b.y - a.y * b.x; }
int Sig(double a) { return a < -eps ? -1 : a > eps; }

Point Get_mid(Point a, Point b) {
  Point ret;
  ret.x = (a.x + b.x) * 0.5;
  ret.y = (a.y + b.y) * 0.5;
  return ret;
}
double Count(int a, int b) {
  double ans = 0;
  for (int i = a; i != b; i = (i + 1) % 8)
    ans += Xmult(p[i], p[(i + 1) % 8]);  //注意(i+1)%8
  ans += Xmult(p[b], p[a]);
  return ans * 0.5;
}
int main() {
  double c1, c2;
  double a1, a2;
  double all;
  int cas = 1;
  while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &p[0].x, &p[0].y, &p[2].x, &p[2].y,
               &p[4].x, &p[4].y, &p[6].x, &p[6].y)) {
    if (!p[0].x && !p[0].y && !p[2].x && !p[2].y,
        !p[4].x && !p[4].y && !p[6].x && !p[6].y)
      break;
    for (int i = 1; i <= 7; i += 2) p[i] = Get_mid(p[i - 1], p[(i + 1) % 8]);
    all = c1 = Count(0, 7);
    c2 = 0;
    for (int i = 0; i < 8; i++) {
      int j;
      if (i % 2 == 0)  //½Ç
      {
        j = (i + 3) % 8;
        while ((j + 2) % 8 != i) {
          a1 = Count(i, j);
          a2 = all - a1;
          if (fabs(a1 - a2) < fabs(c1 - c2)) {
            c1 = a1;
            c2 = a2;
          }
          j = (j + 1) % 8;
        }
      } else  //ÖÐµã
      {
        j = (i + 2) % 8;
        while ((j + 1) % 8 != i) {
          a1 = Count(i, j);
          a2 = all - a1;
          if (fabs(a1 - a2) < fabs(c1 - c2)) {
            c1 = a1;
            c2 = a2;
          }
          j = (j + 1) % 8;
        }
      }
    }
    if (c1 > c2) swap(c1, c2);
    printf("Cake %d: %.3f %.3f\n", cas++, c1, c2);
  }
  return 0;
}
