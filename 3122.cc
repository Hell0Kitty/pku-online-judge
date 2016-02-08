#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define maxn 10005
#define eps 1.0e-4
#define PI acos(-1.0)

int n, m;
int f[maxn];
double s[maxn], ms;

void input() {
  scanf("%d%d", &n, &m);
  m++;
  for (int i = 0; i < n; i++) scanf("%d", &f[i]);
  ms = -1;
  for (int i = 0; i < n; i++) {
    s[i] = f[i] * f[i] * PI;
    ms = max(s[i], ms);
  }
}

bool ok(double a) {
  int d = 0;
  for (int i = 0; i < n; i++) d += (int)(s[i] / a);
  return d >= m;
}

double binarysearch() {
  double l = eps;
  double r = ms;
  double mid;
  while (l + eps < r) {
    mid = (l + r) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  return l;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    double ans = binarysearch();
    printf("%.4f\n", ans);
  }
  return 0;
}
