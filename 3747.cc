#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);
struct point {
  double x, y;
  point(double x0 = 0, double y0 = 0) {
    x = x0;
    y = y0;
  }
} p[100];

double dist(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
  int n;
  double r;
  while (scanf("%d%lf", &n, &r) != EOF) {
    scanf("%lf%lf", &p[0].x, &p[0].y);
    for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
    int ok;
    for (int k = 0; k < 100000; k++) {
      point tp =
          point(r * cos(PI * 2 * k / 100000.0), r * sin(PI * 2 * k / 100000.0));
      ok = true;
      for (int i = 1; i <= n; i++)
        if (dist(tp, p[0]) > dist(tp, p[i]) - 1e-6) {
          ok = false;
          break;
        }
      if (ok) {
        break;
      }
    }
    if (ok)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
