#include <iostream>
#include <time.h>
#include <cmath>
#define sqr(x) (x) * (x)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FF(i, a) for (int i = 0; i < a; i++)
using namespace std;
const double eps = 1e-6;
const double INF = 1e20;
const double pi = acos(-1.0);
struct Houxuan {
  double x, y, z, dist;
} pp[10];
struct PT {
  double x, y, z;
} hole[30];
double dis(double x1, double y1, double z1, double x2, double y2, double z2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2) + sqr(z1 - z2));
}
int n;
int main() {
  int P = 10;
  while (scanf("%d", &n) && n) {
    double delta = 100.0;
    FF(i, n)
    scanf("%lf%lf%lf", &hole[i].x, &hole[i].y, &hole[i].z);
    FF(i, P) {
      pp[i].x = double(rand() % 10000 + 1) / 10000.0 * 100;
      pp[i].y = double(rand() % 10000 + 1) / 10000.0 * 100;
      pp[i].z = double(rand() % 10000 + 1) / 10000.0 * 100;
      pp[i].dist = 0;
      FF(j, n)
      pp[i].dist = max(pp[i].dist, dis(pp[i].x, pp[i].y, pp[i].z, hole[j].x,
                                       hole[j].y, hole[j].z));
    }
    while (delta > eps) {
      FF(i, P) {
        int idx = 0;
        double tmp = 0;
        FF(j, n) {
          double d =
              dis(hole[j].x, hole[j].y, hole[j].z, pp[i].x, pp[i].y, pp[i].z);
          if (d > tmp) {
            idx = j;
            tmp = d;
          }
        }
        pp[i].dist = min(pp[i].dist, tmp);
        pp[i].x = pp[i].x + (hole[idx].x - pp[i].x) / tmp * delta;
        pp[i].y = pp[i].y + (hole[idx].y - pp[i].y) / tmp * delta;
        pp[i].z = pp[i].z + (hole[idx].z - pp[i].z) / tmp * delta;
      }
      delta *= 0.98;
    }
    int idx = 0;
    FOR(i, 1, P) {
      if (pp[i].dist < pp[idx].dist) idx = i;
    }
    printf("%.5lf\n", pp[idx].dist);
  }
  return 0;
}
