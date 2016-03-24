#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>
#define REP(i, n) for (int i = 0; i < n; ++i)

const int V = 100;
const double PI = acos(-1.0);
const double eps = 1e-10;
const double sqrt_3 = sqrt(3.0);

int sgn(double x) { return x > eps ? 1 : x < -eps ? -1 : 0; }
struct pt {
  double x, y;
  pt() {}
  pt(double _x, double _y) : x(_x), y(_y) {}
  void read() { scanf("%lf%lf", &x, &y); }
  pt operator+(const pt& a) const { return pt(x + a.x, y + a.y); }
  pt operator-(const pt& a) const { return pt(x - a.x, y - a.y); }
  pt operator*(const double a) const { return pt(x * a, y * a); }
  pt rotate(double ang) const {
    return pt(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));
  }

  double len() const { return sqrt(x * x + y * y); }
  pt trunc(double s) const {
    double l = len();
    return pt(x * s / l, y * s / l);
  }
  void write() { printf("(%.2f %.2f) ", x, y); };
};
double det(const pt& a, const pt& b) { return a.x * b.y - a.y * b.x; }
double dot(const pt& a, const pt& b) { return a.x * b.x + a.y * b.y; }

void Assert(int x) {
  if (!x)
    while (1) puts("fuck");
}
pt o;
double a[V], b[V], ta[V], tb[V];
int n, m;
int left[V], right[V];
double left_dis[V], right_dis[V];

double heightL(double x, double y) { return x * sqrt_3 + y; }
double heightR(double x, double y) { return -x * sqrt_3 + y; }
int main() {
  int test;
  std::cin >> test;
  for (int cas = 1; cas <= test; ++cas) {
    scanf("%d", &m);
    REP(i, m) {
      scanf("%lf", &a[i]);
      a[i] /= 2;
      ta[i] = i == 0 ? a[i] : ta[i - 1] + a[i - 1] + a[i];
    }
    o.read();
    scanf("%d", &n);
    REP(i, n) {
      scanf("%lf", &b[i]);
      b[i] /= 2;
      tb[i] = i == 0 ? o.x + b[i] : tb[i - 1] + b[i - 1] + b[i];
    }

    REP(i, n)
    REP(j, m) {
      // printf("%.2f %.2f\n",ta[j], tb[i]);
      assert(ta[j] != tb[i]);
    }

    for (int i = 0; i < n; ++i) {
      double minL = 1e10, minR = 1e10;
      left[i] = -1;
      right[i] = -1;
      left_dis[i] = 1e10;
      right_dis[i] = 1e10;

      for (int j = 0; j < m; ++j) {
        if (tb[i] - ta[j] > 0 && tb[i] - ta[j] < minL) {
          minL = tb[i] - ta[j];
          left[i] = j;
        }
        if (tb[i] - ta[j] < 0 && ta[j] - tb[i] < minR) {
          minR = ta[j] - tb[i];
          right[i] = j;
        }
      }
      if (left[i] != -1)
        left_dis[i] =
            heightL(tb[i] - b[i], o.y) - heightL(ta[left[i]] + a[left[i]], 0);
      if (right[i] != -1)
        right_dis[i] =
            heightR(tb[i] + b[i], o.y) - heightR(ta[right[i]] - a[right[i]], 0);
    }
    if (right[n - 1] == 0) {
      puts("WM");
      continue;
    }
    if (left[0] == m - 1) {
      puts("MW");
      continue;
    }
    double min_left = 1e10, min_right = 1e10;
    for (int i = 0; i < n; ++i) {
      if (left_dis[i] < min_left) min_left = left_dis[i];
      if (right_dis[i] < min_right) min_right = right_dis[i];
    }
    Assert(min_left != 1e10);
    Assert(min_right != 1e10);
    if (min_left < min_right) {
      o = o + pt(0, -min_left);

      // o.write();
      // printf("%f\n",(min_right-min_left)/sqrt_3);
      double min_dis = 1e10;
      for (int i = 0; i < n; ++i) {
        pt tip = pt(tb[i], o.y - b[i] * sqrt_3);
        if (right[i] != -1) {
          double tmp;
          for (int j = right[i]; j < m; ++j) {
            tmp = heightR(tb[i] + b[i], o.y) - heightR(ta[j] - a[j], 0);
            tip = tip + pt(1.0, -sqrt_3).trunc(tmp / sqrt_3);
            if (tip.y < a[j] * sqrt_3) break;
          }
          if (tmp < min_dis) min_dis = tmp;
        }
      }
      o = o + pt(1.0, -sqrt_3).trunc(min_dis / sqrt_3);
    } else {
      o = o + pt(0, -min_right);
      double min_dis = 1e10;
      for (int i = 0; i < n; ++i) {
        pt tip = pt(tb[i], o.y - b[i] * sqrt_3);
        if (left[i] != -1) {
          double tmp;
          for (int j = left[i]; j >= 0; --j) {
            tmp = heightL(tb[i] - b[i], o.y) - heightL(ta[j] + a[j], 0);
            tip = tip + pt(-1.0, -sqrt_3).trunc(tmp / sqrt_3);

            if (tip.y < a[j] * sqrt_3) break;
          }
          if (tmp < min_dis) min_dis = tmp;
        }
      }
      o = o + pt(-1.0, -sqrt_3).trunc(min_dis / sqrt_3);
    }
    printf("%.3f %.3f\n", o.x, o.y);
  }
}
