#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>

#define LL long long
#define EPS (1e-8)

const double Double_PI = 2.0 * acos(-1.0);

using namespace std;

struct P {
  double x, y;
} sp[100100], p[100100];

int top;

bool cmp(P p1, P p2) {
  if (fabs(p1.x - p2.x) < EPS) {
    return p1.y < p2.y;
  }
  return p1.x < p2.x;
}

double X_Mul(P a1, P a2, P b1, P b2) {
  P v1 = {a2.x - a1.x, a2.y - a1.y}, v2 = {b2.x - b1.x, b2.y - b1.y};

  return (v1.x * v2.y - v1.y * v2.x);
}

P Line_Cross_Position(P l1, P l2, P s1, P s2) {
  P cp = s1;

  double t = fabs(X_Mul(l1, l2, l1, s1)) / fabs(X_Mul(l1, l2, s2, s1));

  cp.x += t * (s2.x - s1.x);
  cp.y += t * (s2.y - s1.y);

  return cp;
}

double Cal_Angle(P a1, P a2, P b1, P b2) {
  P v1 = {a2.x - a1.x, a2.y - a1.y}, v2 = {b2.x - b1.x, b2.y - b1.y};

  if (fabs(X_Mul(a1, a2, b1, b2)) < EPS) return 0;

  if (X_Mul(a1, a2, b1, b2) >= EPS)
    return acos(
        (v1.x * v2.x + v1.y * v2.y) /
        (sqrt((v1.x * v1.x + v1.y * v1.y) * (v2.x * v2.x + v2.y * v2.y))));
  return -acos(
             (v1.x * v2.x + v1.y * v2.y) /
             (sqrt((v1.x * v1.x + v1.y * v1.y) * (v2.x * v2.x + v2.y * v2.y))));
}

double Cal_Point_Dis(P p1, P p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double Point_In_Segment(P p, P p1, P p2) {
  if (fabs(Cal_Point_Dis(p1, p2) - Cal_Point_Dis(p, p1) -
           Cal_Point_Dis(p, p2)) < EPS)
    return true;
  return false;
}

bool Is_Point_In_Polygon(P tp, int n) {
  int i;

  double asum = 0;

  for (i = 0; i < n; ++i) {
    asum += Cal_Angle(tp, p[i], tp, p[i + 1]);
  }

  if (fabs(fabs(asum) - Double_PI) < EPS) return true;
  for (i = 0; i < n; ++i) {
    if (Point_In_Segment(tp, p[i], p[i + 1])) return true;
  }
  return false;
}

double Length_In_Polygon(P pa, P pb, int n) {
  double lsum, xm1, xm2;
  int i;
  P temp;

  for (i = 0; i < n; ++i) {
    xm1 = X_Mul(pa, pb, pa, p[i]);
    xm2 = X_Mul(pa, pb, pa, p[i + 1]);

    if (xm1 * xm2 < -EPS) {
      sp[top++] = Line_Cross_Position(pa, pb, p[i], p[i + 1]);
    } else {
      if (fabs(xm1) < EPS) sp[top++] = p[i];
      if (fabs(xm2) < EPS) sp[top++] = p[i + 1];
    }
  }

  sort(sp, sp + top, cmp);

  for (i = 1, lsum = 0; i < top; ++i) {
    temp.x = (sp[i].x + sp[i - 1].x) / 2;
    temp.y = (sp[i].y + sp[i - 1].y) / 2;

    if (Is_Point_In_Polygon(temp, n)) {
      lsum += Cal_Point_Dis(sp[i], sp[i - 1]);
    }
  }
  return lsum;
}

int main() {
  int i, n, m;
  P pa, pb;

  while (scanf("%d %d", &n, &m) && (n || m)) {
    for (i = 0; i < n; ++i) {
      scanf("%lf %lf", &p[i].x, &p[i].y);
    }

    p[n] = p[0];

    while (m--) {
      scanf("%lf %lf %lf %lf", &pa.x, &pa.y, &pb.x, &pb.y);

      top = 0;

      printf("%.3lf\n", Length_In_Polygon(pa, pb, n));
    }
  }
  return 0;
}
