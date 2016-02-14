#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cstdlib>
#define eps 1e-8
#define inf 1e10
#define maxn 40
#define xmult(a, b, c) (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x)
struct point {
  double x, y;
} points[maxn], save[maxn], temp[maxn];
struct line {
  point s, e;
} lines[maxn];
double minn;
int n, k, ntemp;
double h;
int witch[maxn];
point intersection(point p1, point p2, double a, double b, double c) {
  double s = fabs(a * p1.x + b * p1.y + c);
  double e = fabs(a * p2.x + b * p2.y + c);
  point ret;
  ret.x = (p1.x * e + p2.x * s) / (s + e);
  ret.y = (p1.y * e + p2.y * s) / (s + e);
  return ret;
}
void getline(point p1, point p2, double &a, double &b, double &c) {
  a = p2.y - p1.y;
  b = p1.x - p2.x;
  c = p2.x * p1.y - p2.y * p1.x;
}
bool zero(double x) { return x > 0 ? x < eps : x > -eps; }
bool equal_p(const point &a, const point &b) {
  return zero(a.x - b.x) && zero(a.y - b.y);
}
double area(point *p, int n) {
  int i;
  double res = 0;
  for (i = 0; i < n; i++)
    res += p[(i + 1) % n].x * p[i].y - p[(i + 1) % n].y * p[i].x;
  return fabs(res) / 2.0;
}
double min(double a, double b) { return a > b ? b : a; }
void my_copy(point *a, point *b, int n) {
  int i;
  for (i = 0; i < n; i++) {
    a[i].x = b[i].x;
    a[i].y = b[i].y;
  }
}
void pri(point *p, int n) {
  int i;
  for (i = 0; i < n; i++) printf("%.2lf %.2lf\n", p[i].x, p[i].y);
}
void cut() {
  int i, j, t, m;
  double a, b, c;
  int cnt;
  for (t = 0; t < k; t++) {
    cnt = 0;
    getline(lines[witch[t]].s, lines[witch[t]].e, a, b, c);
    for (i = 0; i < ntemp; i++)  //逆时针用<= 号和 < 号
    {
      if (a * temp[i].x + b * temp[i].y + c <= 0)
        save[cnt++] = temp[i];
      else {
        if (a * temp[(i - 1 + ntemp) % ntemp].x +
                b * temp[(i - 1 + ntemp) % ntemp].y + c <
            0)
          save[cnt++] =
              intersection(temp[i], temp[(i - 1 + ntemp) % ntemp], a, b, c);
        if (a * temp[(i + 1) % ntemp].x + b * temp[(i + 1) % ntemp].y + c < 0)
          save[cnt++] = intersection(temp[i], temp[(i + 1) % ntemp], a, b, c);
      }
    }

    if (t != k - 1) {
      ntemp = cnt;
      my_copy(temp, save, cnt);
    } else {
      ntemp = n;
      my_copy(temp, points, n);
    }
  }
  minn = min(minn, area(save, cnt));
}
void dfs(int time, int s) {
  int i;
  if (time == k) {
    cut();
    return;
  }
  for (i = s; i < n; i++) {
    witch[time] = i;
    dfs(time + 1, i + 1);
  }
}
double distance(point p1, point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
void change() {
  int i;
  for (i = 0; i < n; i++) {
    point p1 = points[i], p2 = points[(i + 1) % n];
    point dir;
    dir.x = p2.x - p1.x;
    dir.y = p2.y - p1.y;
    double dis = distance(p1, p2);
    lines[i].s.x = p1.x - dir.y * h / dis;
    lines[i].s.y = p1.y + dir.x * h / dis;
    lines[i].e.x = p2.x - dir.y * h / dis;
    lines[i].e.y = p2.y + dir.x * h / dis;
  }
}
int main() {
  while (scanf("%d%d%lf", &n, &k, &h), n + k + h) {
    int i;
    for (i = 0; i < n; i++) {
      scanf("%lf%lf", &points[i].x, &points[i].y);
    }
    my_copy(temp, points, n);
    change();
    minn = inf;
    ntemp = n;
    if (k == 0) {
      printf("0.00\n");
      continue;
    }
    if (k < n)
      dfs(0, 0);
    else {
      k = n;
      for (i = 0; i < n; i++) witch[i] = i;
      cut();
    }
    printf("%.2lf\n", area(points, n) - minn);
  }
  return 0;
}
