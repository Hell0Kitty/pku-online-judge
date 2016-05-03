#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
const int MAX = 11000;
const double EPS = 1.0e-8;
const double INF = 1000000000.0;
bool dig(char x) { return x >= '0' && x <= '9'; }
int getval() {
  int ret = 0, sign = 1;
  char c;
  while (!dig(c = getchar()) && c != '-')
    ;
  if (c == '-')
    sign = -1;
  else
    ret = c - '0';
  while (dig(c = getchar())) ret = ret * 10 + c - '0';
  return ret * sign;
}
struct Point {
  double x, y, z;
} p[MAX];
double r2[MAX];
double Getr(double h, int n) {
  int i;
  double ret = 0, tmp;

  for (i = 0; i < n; i++) {
    tmp = r2[i] * h * h / ((h - p[i].z) * (h - p[i].z));
    if (tmp > ret) ret = tmp;
  }
  return ret;
}
int dblcmp(double x) {
  if (fabs(x) < EPS) return 0;
  return x < 0 ? -1 : 1;
}
int main() {
  int n = 0;
  int i, j, k;

  while (scanf("%d", &n) != EOF) {
    double low = 0, high = INF;
    for (i = 0; i < n; i++) {
      scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
      r2[i] = p[i].x * p[i].x + p[i].y * p[i].y;
      if (p[i].z > low) low = p[i].z;
    }

    double ah = -1, ar = -1;
    double mid, tr, ttr, mmid;
    int T = 100;
    while (T-- && dblcmp(low - high) != 0) {
      mid = (high + low) / 2;
      tr = Getr(mid, n);
      mmid = (mid + high) / 2;
      ttr = Getr(mmid, n);

      if (tr * mid < ttr * mmid) {
        ah = mid;
        ar = tr;
        high = mmid;
      } else {
        ah = mmid;
        ar = ttr;
        low = mid;
      }
    }
    printf("%.3f %.3f\n", ah, sqrt(ar));
  }

  return 0;
}
