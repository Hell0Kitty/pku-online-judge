#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;
#define SZ(v) ((int)(v).size())
#define SQR(x) ((x) * (x))
const int maxint = -1u >> 1;
const int n = 10;
const int maxn = n + 2;
const double rt = 1e-2;
const double ss = 1e-5;
const double eps = 1e-9;
int sgn(double x) { return (x > eps) - (x < -eps); }

struct P {
  double x, y;
  P() {}
  P(double _x, double _y) : x(_x), y(_y) {}
  bool operator==(const P &a) const {
    return sgn(x - a.x) == 0 && sgn(y - a.y) == 0;
  }
  P operator-(const P &a) const { return P(x - a.x, y - a.y); }
  P operator+(const P &a) const { return P(x + a.x, y + a.y); }
  P operator*(const double &m) const { return P(x * m, y * m); }
  P operator/(const double &m) const { return P(x / m, y / m); }
  double length() const { return sqrt(SQR(x) + SQR(y)); }
  double dist(const P &a) const { return sqrt(SQR(a.x - x) + SQR(a.y - y)); }
  P turn_left() const { return P(-y, x); }
  P set(const double &m) const {
    double lenth = length();
    return P(x * m / lenth, y * m / lenth);
  }
  void input() { scanf("%lf %lf", &x, &y); }
};

const P dir[] = {P(0, -1), P(0, 1), P(-1, 0), P(1, 0)};
int ans;
int lv[maxn];
P pt[maxn];
double rd[maxn];
int type[maxn];
P ori;

bool ok(const P &mid) {
  for (int i = 0; i < n; ++i) {
    int s = sgn(mid.dist(pt[i]) - rd[i]);
    if (type[i] > 0 && s > 0) return false;
    if (type[i] < 0 && s <= 0) return false;
  }
  return true;
}
bool cmp(const P &p1, const P &p2) {
  double x1 = atan2(p1.y - ori.y, p1.x - ori.x),
         x2 = atan2(p2.y - ori.y, p2.x - ori.x);
  return x1 < x2;
}
void cross(vector<P> &rec, const P &pt1, double r1, const P &pt2, double r2) {
  if (pt1 == pt2) return;
  double d = pt1.dist(pt2);
  if (sgn(d - fabs(r1 - r2)) < 0 || sgn(d - (r1 + r2)) > 0) return;
  double s1 = (SQR(r1) - SQR(r2) + SQR(d)) / (2 * d);
  double s2 = sqrt(SQR(r1) - SQR(s1));
  P p1 = pt2 + (pt2 - pt1).set(s1) + (pt2 - pt1).turn_left().set(s2);
  P p2 = pt2 + (pt2 - pt1).set(s1) - (pt2 - pt1).turn_left().set(s2);
  rec.push_back(p1);
  if (!(p1 == p2)) rec.push_back(p2);
}
bool check(int now) {
  for (int i = 0; i < n; ++i) {
    double r = rd[i];
    if (type[i] == -1) r += ss;
    vector<P> rec;
    for (int j = 0; j < 4; ++j) {
      rec.push_back(pt[i] + dir[j].set(rd[i]));
    }
    for (int j = 0; j < n; ++j) {
      double r0 = rd[j];
      if (type[j] == -1) r0 += ss;
      if (sgn(r - r0) < 0)
        cross(rec, pt[j], r0, pt[i], r);
      else
        cross(rec, pt[i], r, pt[j], r0);
    }
    ori = pt[i];
    sort(rec.begin(), rec.end(), cmp);
    rec.erase(unique(rec.begin(), rec.end()), rec.end());
    for (int j = 0; j < (int)rec.size(); ++j) {
      if (ok(rec[j])) return true;
    }
  }
  return false;
}
void dfs(int dep, int now) {
  if (dep == n) {
    if (ans < now && check(now)) ans = now;
    return;
  }
  type[dep] = 1;
  dfs(dep + 1, now + lv[dep]);
  type[dep] = -1;
  dfs(dep + 1, now);
}
int main() {
  double ra, rb, r;
  while (scanf("%lf%lf%lf", &ra, &rb, &r) == 3) {
    ra += rb;
    ra *= rt;
    r *= rt;
    for (int i = 0; i < n; ++i) {
      pt[i].input();
      pt[i] = pt[i] * rt;
      scanf("%d", &lv[i]);
      if (i == 0)
        rd[i] = ra;
      else
        rd[i] = r;
    }
    type[0] = 1;
    ans = -0x7fffffff;
    dfs(1, 0);
    printf("%d\n", ans);
  }
  return 0;
}
