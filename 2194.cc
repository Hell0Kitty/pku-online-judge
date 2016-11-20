#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#define N 222

using namespace std;

struct PO {
  double x, y;
} p[N][N];

int n;

inline bool cmp(const PO &a, const PO &b) { return a.x < b.x; }

inline void read() {
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p[1][i].x);
    p[1][i].y = 1.0;
  }
  sort(p[1] + 1, p[1] + 1 + n, cmp);
}

inline PO rotate(PO a, double hd) {
  PO c;
  c.x = a.x * cos(hd) - a.y * sin(hd);
  c.y = a.x * sin(hd) + a.y * cos(hd);
  return c;
}

inline double getlen(PO &a)  //向量的模
{
  return sqrt(a.x * a.x + a.y * a.y);
}

inline double getdis2(PO &a, PO &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline void go() {
  int c = 1;
  while (n > 1) {
    c++;
    for (int i = 1; i < n; i++) {
      double af =
          atan2(sqrt(4.0 - getdis2(p[c - 1][i], p[c - 1][i + 1]) * 0.25),
                sqrt(getdis2(p[c - 1][i], p[c - 1][i + 1])) * 0.5);
      // atan2精度较高，其他的反三角函数精度都比较差。。。
      PO s;
      s.y = p[c - 1][i + 1].y - p[c - 1][i].y;
      s.x = p[c - 1][i + 1].x - p[c - 1][i].x;
      double k = 2.0 / getlen(s);
      s.y *= k;
      s.x *= k;

      s = rotate(s, af);
      p[c][i].y = p[c - 1][i].y + s.y;
      p[c][i].x = p[c - 1][i].x + s.x;
    }
    n--;
  }
  printf("%.4lf %.4lf\n", p[c][1].x, p[c][1].y);
}

int main() {
  while (scanf("%d", &n), n) read(), go();
  return 0;
}
