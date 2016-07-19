#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define EPS 1e-12

using namespace std;
struct POINT {
  double x, y;
} pp[1005], qq[1005];

double my;
int cp, cq, np, nq, are;
double min(double x, double y) {
  if (x < y) return x;
  return y;
}
int sig(double x) {
  if (fabs(x) < EPS)
    return 0;
  else if (x > 0)
    return 1;
  else
    return -1;
}
double crop(struct POINT *P, int s, int l, int r) {
  return (P[l].x - P[s].x) * (P[r].y - P[s].y) -
         (P[r].x - P[s].x) * (P[l].y - P[s].y);
}
double cala(int cc, int nn, struct POINT *P, double h) {
  double u1, u2;
  int s = cc;
  if (sig(P[s].y - h) >= 0) return 0.0;
  double a = 0.0;
  u1 = 0.0;
  u2 = 0.0;
  for (int i = s - 1; i > 0; --i) {
    if (sig(P[i].y - h) <= 0) {
      a += crop(P, s, i, i + 1);
      u1 = P[i].x;
    } else if (sig(P[i].y - h) > 0 && sig(P[i + 1].y - h) < 0) {
      u1 =
          (h - P[i].y) * (P[i].x - P[i + 1].x) / (P[i].y - P[i + 1].y) + P[i].x;
      a += (u1 - P[s].x) * (P[i + 1].y - P[s].y) -
           (P[i + 1].x - P[s].x) * (h - P[s].y);
      break;
    }
  }
  for (int i = s + 1; i <= nn; ++i) {
    if (sig(P[i].y - h) <= 0) {
      a += crop(P, s, i - 1, i);
      u2 = P[i].x;
    } else if (sig(P[i].y - h) > 0 && sig(P[i - 1].y - h) < 0) {
      u2 =
          (h - P[i].y) * (P[i - 1].x - P[i].x) / (P[i - 1].y - P[i].y) + P[i].x;
      a += (P[i - 1].x - P[s].x) * (h - P[s].y) -
           (u2 - P[s].x) * (P[i - 1].y - P[s].y);
      break;
    } else
      break;
  }

  a += (u2 - u1) * (h - P[s].y);
  a = fabs(a / 2);
  // cout<<"   "<<a;
  return a;
}

double findh(double s, double t) {
  double mid = (s + t) / 2;
  double cs;
  while (s + EPS <= t) {
    cs = cala(cp, np, pp, mid);

    cs += cala(cq, nq, qq, mid);

    if (fabs(cs - are) < EPS) return mid;

    if (cs <= are)
      s = mid;
    else
      t = mid;
    mid = (s + t) / 2;
  }
  return s;
}

int main() {
  int t;

  scanf("%d", &t);

  while (t--) {
    scanf("%d", &are);
    scanf("%d", &np);
    cp = cq = 1;

    for (int i = 1; i <= np; i++) {
      scanf("%lf%lf", &pp[i].x, &pp[i].y);
      if (pp[cp].y - pp[i].y > EPS) cp = i;
    }
    scanf("%d", &nq);

    for (int i = 1; i <= nq; i++) {
      scanf("%lf%lf", &qq[i].x, &qq[i].y);
      if (qq[cq].y - qq[i].y > EPS) cq = i;
    }
    my = min(min(pp[1].y, pp[np].y), min(qq[1].y, qq[nq].y));

    printf("%.3lf\n", findh(min(pp[cp].y, qq[cq].y), my));
  }
  return 0;
}
