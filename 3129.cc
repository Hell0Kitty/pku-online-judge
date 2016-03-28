#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-8, pi = acos(-1.0);
struct point {
  double x, y, z;
} po[600];
double dmult(point a, point b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
double getm(point a) { return sqrt(a.x * a.x + a.y * a.y + a.z * a.z); }
int main() {
  int n, m;
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++)
      scanf("%lf%lf%lf", &po[i].x, &po[i].y, &po[i].z);
    scanf("%d", &m);
    bool vis[600];
    memset(vis, false, sizeof(vis));
    point p;
    double th;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      scanf("%lf%lf%lf%lf", &p.x, &p.y, &p.z, &th);
      for (int j = 0; j < n; j++) {
        if (!vis[j]) {
          if (acos(dmult(p, po[j]) / getm(p) / getm(po[j])) - th < eps) {
            cnt++;
            vis[j] = true;
          }
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
