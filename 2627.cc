#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define N 1005
double v, m, pmax;
struct point {
  double x, y;
  int lev;
  bool vis;
};
point p[N], sp, ep, tp, pp;
queue<point> q;

double dis(double x1, double y1, double x2, double y2) {
  double sum = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  sum = sqrt(sum);
  return sum;
}
int fmin(int i, int j) { return i > j ? j : i; }
int main() {
  int i, n, ans, flag;
  double a, b;
  scanf("%lf%lf", &v, &m);
  pmax = v * m * 60;
  cin >> sp.x >> sp.y;
  cin >> ep.x >> ep.y;
  i = 1;
  while (cin >> p[i].x >> p[i].y) {
    p[i].lev = 0;
    p[i].vis = false;
    i++;
  }
  n = i;         //除去起点终点,from 1 to n-1
  ans = 999999;  //至少经过几个点
  flag = 0;      //.no
  while (!q.empty()) q.pop();

  if (dis(sp.x, sp.y, ep.x, ep.y) <= pmax) {
    cout << "Yes, visiting 0 other holes." << endl;
    return 0;
  }

  sp.lev = 0;
  sp.vis = true;
  q.push(sp);
  while (!q.empty()) {
    tp = q.front();
    q.pop();
    if (dis(tp.x, tp.y, ep.x, ep.y) <= pmax) {
      flag = 1;  // yes
      ans = fmin(ans, tp.lev);
      // break;
    }
    for (i = 1; i < n; i++) {
      if (dis(tp.x, tp.y, p[i].x, p[i].y) > pmax || p[i].vis == true) continue;
      p[i].vis = true;
      p[i].lev = tp.lev + 1;
      q.push(p[i]);
    }
  }
  if (flag == 1)
    cout << "Yes, visiting " << ans << " other holes." << endl;
  else
    cout << "No." << endl;
  return 0;
}
