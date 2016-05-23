#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
struct Point {
  double x, y;
  double angle, dis;
  Point() {}
  Point(double x0, double y0) : x(x0), y(y0) {}
};
Point ps[1000];
double idis[1000][1000];
double Area(int i, int j, int k) {
  return fabs((double)(ps[i].x - ps[k].x) * (ps[j].y - ps[k].y) -
              (ps[j].x - ps[k].x) * (ps[i].y - ps[k].y)) /
         2;
}

const double pi = acos(-1.0);
double dis(Point &a, Point &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
  int T;
  scanf("%d", &T);
  for (int ii = 1; ii <= T; ii++) {
    double ans = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &ps[i].x, &ps[i].y);
    }
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) idis[i][j] = dis(ps[i], ps[j]);
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        for (int k = j + 1; k < n; k++) {
          double a = idis[i][j];
          double b = idis[j][k];
          double c = idis[i][k];
          double Stri = Area(i, j, k);
          double R = a * b * c / (4 * Stri);
          if (R > ans) ans = R;
        }
    printf("%.3f\n", ans);
  }

  return 0;
}
