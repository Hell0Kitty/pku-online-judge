#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
const double eps = 1e-9;
struct crack {
  double x, d;
};
bool operator<(const crack &a, const crack &b) { return a.x < b.x; }
crack ck[11];
double a[11], h[11];
double v[11], dis[11];
double ans[11];
int n, m, st;
double s;
void getv() {
  int i = st, j = 0;
  double sv = 0., last = 0.;
  while (i < n) {
    if (j <= m && ck[j].x < h[i] - eps) {
      sv += a[i] * ck[j].d;
      last = ck[j++].x;
    } else {
      v[i] = sv;
      dis[i] = h[i] - last;
      ++i;
    }
  }
}
int main() {
  while (scanf("%d %d %lf", &n, &m, &s) == 3) {
    for (int i = 0; i < n; ++i) {
      scanf("%lf %lf", h + i, a + i);
      h[i] /= s;
      if (i > 0) h[i] += h[i - 1];
    }
    for (int i = 0; i < m; ++i) {
      scanf("%lf %lf", &ck[i].x, &ck[i].d);
      ck[i].d /= s;
    }
    double q;
    scanf("%lf", &q);
    ck[m].d = q / s, ck[m].x = 0.;
    sort(ck, ck + m + 1);
    memset(ans, 0, sizeof(ans));
    for (st = 0; st < n;) {
      getv();
      int next = -1;
      for (int i = st; i < n; ++i)
        if (next < 0 || dis[i] / v[i] < dis[next] / v[next]) next = i;
      double tm = dis[next] / v[next];
      ans[st] += tm * q * a[st];
      for (int i = st; i < n; ++i) {
        h[i] -= v[i] * tm;
      }
      if (h[st] < eps) ++st;
    }
    for (int i = 0; i < n; ++i) printf("%.10f\n", ans[i]);
  }
  return 0;
}
