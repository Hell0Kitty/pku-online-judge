#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define sign(x) ((x) > eps ? 1 : ((x) < -eps ? (-1) : (0)))  //符号函数
using namespace std;
const int MAXN = 1000;
const double eps = 1e-8, inf = 1e50;
struct point {
  double x, y;
  point() {}
  point(double _x, double _y) {
    x = _x;
    y = _y;
  }
} po[100];
inline double xmult(point o, point a, point b) {
  return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}
inline double xmult(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}
//求多边形面积
inline double getarea(point pg[], int n) {
  double area = 0;
  pg[n] = pg[0];
  for (int i = 0; i < n; i++)
    area += xmult(pg[i].x, pg[i].y, pg[i + 1].x, pg[i + 1].y);
  return fabs(area) / 2.0;
}
int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    int n, m, ans = 0, num;
    double area = 0.0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf%lf", &po[i].x, &po[i].y);
    point pg[100];
    scanf("%d", &m);
    for (int i = 1, k, tp; i <= m; i++) {
      scanf("%d", &num);
      k = 0;
      for (int j = 0; j < num; j++) {
        scanf("%d", &tp);
        pg[k++] = po[tp];
      }
      double ar = getarea(pg, num);
      if (ar > area) {
        area = ar;
        ans = i;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
