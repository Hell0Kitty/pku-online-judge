#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#define PI 3.141592653589793
#define EPS 1e-7

using namespace std;

struct PO {
  double x, y;
} sma, big;

inline int doublecmp(double x) {
  if (x > EPS)
    return 1;
  else if (x < -EPS)
    return -1;
  return 0;
}

inline PO rotate(PO &a, double hd) {
  PO c;
  c.x = a.x * sin(hd) - a.y * cos(hd);
  c.y = a.x * cos(hd) + a.y * sin(hd);
  return c;
}

inline bool go() {
  scanf("%lf%lf%lf%lf", &big.x, &big.y, &sma.x, &sma.y);
  double du = 0.0;
  PO c;
  while (du * 2 < PI) {
    c = rotate(sma, du);
    c.x += 2.0 * sma.y * cos(du);
    if (doublecmp(big.x - c.x) >= 0 && doublecmp(big.y - c.y) >= 0) return true;
    if (doublecmp(big.y - c.x) >= 0 && doublecmp(big.x - c.y) >= 0) return true;
    du += 0.002;
  }
  return false;
}

int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    if (go())
      printf("Escape is possible.\n");
    else
      printf("Box cannot be dropped.\n");
  }
  return 0;
}
