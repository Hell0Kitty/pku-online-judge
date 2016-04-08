#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x, y) ((x + y) >> 1)
#define L(x) (x << 1)
#define R(x) (x << 1 | 1)
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;

const int MAX = 110;
const double eps = 1e-12;
bool dy(double x, double y) { return x > y + eps; }        // x > y
bool xy(double x, double y) { return x < y - eps; }        // x < y
bool dyd(double x, double y) { return x > y - eps; }       // x >= y
bool xyd(double x, double y) { return x < y + eps; }       // x <= y
bool dd(double x, double y) { return fabs(x - y) < eps; }  // x ==
struct point {
  double x, y;
  point() {}
  point(double xx, double yy) : x(xx), y(yy) {}
  bool operator==(const point &a) { return dd(a.x, x) && dd(a.y, y); }
  void get() { scanf("%lf%lf", &x, &y); }
};
double crossProduct(point a, point b,
                    point c)  //向量 ac 在 ab 的方向 顺时针是正
{
  return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}
double disp2p(point a, point b)  //  a b 两点之间的距离
{
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double disp2p_sqr(point a, point b) {
  return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
point l2l_inst_p(point u1, point u2, point v1, point v2) {
  point ans = u1;
  double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) /
             ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
  ans.x += (u2.x - u1.x) * t;
  ans.y += (u2.y - u1.y) * t;
  return ans;
}
struct NODE {
  point p;
  int id;
};
struct circle {
  point c;
  double r;
  int id;
  void get() {
    c.get();
    scanf("%lf", &r);
  }
};
circle cir[MAX];
NODE a[MAX * MAX * 2];
point p[MAX][MAX * MAX * 2];
int len[MAX];

bool c2c_inst(point a, double r1, point b, double r2) {
  if (xy(disp2p(a, b), r1 + r2) && dy(disp2p(a, b), fabs(r1 - r2))) return true;
  return false;
}

void l2c_inst_p(point c, double r, point l1, point l2, point &p1, point &p2) {
  point p = c;
  double t;
  p.x += l1.y - l2.y;
  p.y += l2.x - l1.x;
  p = l2l_inst_p(p, c, l1, l2);
  t = sqrt(r * r - disp2p(p, c) * disp2p(p, c)) / disp2p(l1, l2);
  p1.x = p.x + (l2.x - l1.x) * t;
  p1.y = p.y + (l2.y - l1.y) * t;
  p2.x = p.x - (l2.x - l1.x) * t;
  p2.y = p.y - (l2.y - l1.y) * t;
}
void c2c_inst_p(point c1, double r1, point c2, double r2, point &p1,
                point &p2) {
  point u, v;
  double t;
  t = (1 + (r1 * r1 - r2 * r2) / disp2p(c1, c2) / disp2p(c1, c2)) / 2;
  u.x = c1.x + (c2.x - c1.x) * t;
  u.y = c1.y + (c2.y - c1.y) * t;
  v.x = u.x + c1.y - c2.y;
  v.y = u.y - c1.x + c2.x;
  l2c_inst_p(c1, r1, u, v, p1, p2);
}
point C;
bool cmp(const point &a, const point &b) {
  double t1 = atan2(a.y - C.y, a.x - C.x);
  double t2 = atan2(b.y - C.y, b.x - C.x);
  if (dd(t1, t2)) return xy(fabs(a.x), fabs(b.x));
  return xy(t1, t2);
}
bool cmp_equal(point &a, point &b) { return dd(a.x, b.x) && dd(a.y, b.y); }
bool cmp_NODE(NODE a, NODE b) {
  if (a.id == b.id) {
    if (dd(a.p.x, b.p.x)) return xy(a.p.y, b.p.y);
    return xy(a.p.x, b.p.x);
  }
  return a.id < b.id;
}
bool cmp_NODE_equal(NODE a, NODE b) {
  return dd(a.p.x, b.p.x) && a.id == b.id && dd(a.p.y, b.p.y);
}
point foot_line(point a, point l1, point l2)  // ac在l1l2的逆时针方向
{
  point c;
  c.x = a.x - l2.y + l1.y;
  c.y = a.y + l2.x - l1.x;
  return c;
}
bool inst[MAX];
bool see[MAX];
point getmid(point a, point b, circle &c) {
  point mid = point((a.x + b.x) / 2, (a.y + b.y) / 2);
  if (mid == c.c) mid = foot_line(c.c, a, b);
  point p1, p2;
  l2c_inst_p(c.c, c.r, c.c, mid, p1, p2);
  return dy(crossProduct(b, a, p1), 0) ? p2 : p1;
}
bool c2c_ainb(point a, double r1, point b, double r2) {
  return xyd(disp2p(a, b), r2 - r1);  // a在b中，如果是包括内切，用xyd
}
bool check(NODE a, int n) {
  FOR(i, a.id + 1, n)
  if (xy(disp2p_sqr(a.p, cir[i].c), cir[i].r * cir[i].r)) return false;
  return true;
}
bool check_cover_all(circle c, int n) {
  FOR(i, c.id + 1, n)
  if (c2c_ainb(c.c, c.r, cir[i].c, cir[i].r)) return false;
  return true;
}
int solve(int n) {
  int sum = 0;
  memset(inst, false, sizeof(inst));
  memset(len, 0, sizeof(len));
  FOR(i, 0, n) {
    FOR(k, i + 1, n)
    if (c2c_inst(cir[i].c, cir[i].r, cir[k].c, cir[k].r)) {
      point a, b;
      inst[i] = inst[k] = true;
      c2c_inst_p(cir[i].c, cir[i].r, cir[k].c, cir[k].r, a, b);
      p[i][len[i]++] = p[k][len[k]++] = a;
      p[i][len[i]++] = p[k][len[k]++] = b;
    }
  }

  int l = 0;
  FOR(i, 0, n) {
    C = cir[i].c;
    sort(p[i], p[i] + len[i], cmp);
    len[i] = unique(p[i], p[i] + len[i], cmp_equal) - p[i];
    p[i][len[i]] = p[i][0];
    FOR(k, 0, len[i]) {
      point t = getmid(p[i][k], p[i][k + 1], cir[i]);
      a[l].p = t;
      a[l++].id = i;
      FOR(j, 0, n)
      if (xy(disp2p_sqr(t, cir[j].c), cir[j].r * cir[j].r)) {
        a[l].p = t;
        a[l++].id = j;
      }
    }
  }
  sort(a, a + l, cmp_NODE);
  l = unique(a, a + l, cmp_NODE_equal) - a;

  memset(see, false, sizeof(see));
  FOR(i, 0, l)
  if (check(a[i], n)) see[a[i].id] = true;

  FOR(i, 0, n) {
    if (see[i]) {
      sum++;
      continue;
    }
    if (!inst[i] && check_cover_all(cir[i], n)) sum++;
  }
  return sum;
}
int main() {
  int n;

  while (~scanf("%d", &n) && n) {
    FOR(i, 0, n) {
      cir[i].get();
      cir[i].id = i;
    }
    int ans = solve(n);
    printf("%d\n", ans);
  }

  return 0;
}
