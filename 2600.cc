#include <cstdio>
#include <cmath>
#include <algorithm>

#define dis(a, b) sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

struct node {
  double x, y;
  node() {}
  node(double x, double y) : x(x), y(y) {}
  void get() { scanf("%lf%lf", &x, &y); }
} p[55], q[55];

int n;
bool ok;
double a[55];

void rotating(node tmp, node o, double angle, node &g) {
  double dx = tmp.x - o.x, dy = tmp.y - o.y;
  g.x = dx * cos(angle) - dy * sin(angle) + o.x;
  g.y = dx * sin(angle) + dy * cos(angle) + o.y;
}

int dx[] = {1, -1, 0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0, 1, -1};

int main() {
  while (~scanf("%d", &n)) {
    ok = false;
    for (int i = 0; i < n; i++) p[i].get();
    for (int i = 0; i < n; i++) scanf("%lf", &a[i]), a[i] *= pi / 180;
    q[0] = node(0, 0);
    for (double t = 2000; t > eps && !ok; t *= 0.88) {
      for (int i = 0; i < 8 && !ok; i++) {
        node tmp(q[0].x + dx[i] * t, q[0].y + dy[i] * t);
        for (int j = 1; j <= n && !ok; j++) {
          rotating(q[j - 1], p[j - 1], a[j - 1], q[j]);
        }
        if (fabs(dis(q[n], tmp) - dis(q[n], q[0])) < eps) ok = true;
        if (dis(q[n], q[0]) > dis(q[n], tmp)) q[0] = tmp;
      }
    }
    for (int i = 0; i < n; i++) printf("%.0f %.0f\n", q[i].x, q[i].y);
  }
  return 0;
}
