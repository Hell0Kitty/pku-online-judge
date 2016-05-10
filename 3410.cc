#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define EPS 1e-10
#define MAXN 105

double PI = acos(-1.0);

struct point {
  point(double X = 0.0, double Y = 0.0) {
    x = X;
    y = Y;
  }
  double x, y;
};
point P1[MAXN], P2[MAXN], P3[MAXN];
int n1, n2, n3;

int fcmp(double a, double b) {
  if (a - b > EPS)
    return 1;
  else if (b - a > EPS)
    return -1;
  else
    return 0;
}

struct edge {
  edge(double ANG = 0.0, double preLEN = 0.0, double subLEN = 0.0) {
    ang = ANG;
    preLen = preLEN;
    subLen = subLEN;
  }
  bool operator==(edge &b) { return fcmp(preLen, b.preLen) == 0; }
  double ang, preLen, subLen;
};
edge E1[MAXN], E2[MAXN];

double getLen(point &ab) { return sqrt(ab.x * ab.x + ab.y * ab.y); }

double cross(point &ab, point &bc) { return ab.x * bc.y - ab.y * bc.x; }

double dot(point &ab, point &bc) { return ab.x * bc.x + ab.y * bc.y; }

double angle(point &ab, point &bc) {
  double dm = dot(ab, bc) / getLen(ab) / getLen(bc);
  double dr = acos(dm);
  double cr = cross(ab, bc);
  double res = dr * 180.0 / PI;

  if (cr < 0.0) {
    if (fcmp(res, 90.0) == 1)
      res = 180.0 + (180.0 - res);
    else
      res = 360.0 - res;
  }
  return res;
}

bool isConvex(int i, int j, int k) {
  int a;

  if (fcmp(E1[(i - 1 + n1) % n1].ang + E2[(j - 1 + n2) % n2].ang, 180.0) == 1)
    return false;

  if (fcmp(E1[(i + k + 1 + n1) % n1].ang + E2[(j + k + 1 + n2) % n2].ang,
           180.0) == 1)
    return false;

  for (a = (i + k + 2) % n1; a != (i - 1 + n1) % n1; a++, a %= n1) {
    if (fcmp(E1[a].ang, 180.0) == 1) return false;
  }

  for (a = (j + k + 2) % n2; a != (j - 1 + n2) % n2; a++, a %= n2) {
    if (fcmp(E2[a].ang, 180.0) == 1) return false;
  }
  return true;
}

int check() {
  int i, j, k, a, s, b;
  point sa, sb;
  for (s = 0; s < n1; s++) {
    a = (s - 1 + n1) % n1;
    b = (s + 1 + n1) % n1;
    sa = point(P1[a].x - P1[s].x, P1[a].y - P1[s].y);
    sb = point(P1[b].x - P1[s].x, P1[b].y - P1[s].y);
    E1[s] = edge(angle(sb, sa), getLen(sb), getLen(sa));
  }

  for (s = 0; s < n2; s++) {
    a = (s - 1 + n2) % n2;
    b = (s + 1 + n2) % n2;
    sa = point(P2[a].x - P2[s].x, P2[a].y - P2[s].y);
    sb = point(P2[b].x - P2[s].x, P2[b].y - P2[s].y);
    E2[s] = edge(angle(sa, sb), getLen(sb), getLen(sa));
  }

  for (i = 0; i < n1; i++)
    for (j = 0; j < n2; j++) {
      for (k = 0; k < min(n1, n2); k++) {
        if (!(E1[(i + k) % n1] == E2[(j + k) % n2])) break;
        if (k)
          if (fcmp(E1[(i + k - 1) % n1].ang + E2[(j + k - 1) % n2].ang,
                   360.0) != 0)
            break;
      }
      k--;
      if (k >= 0) {
        // printf("check %d %d %d\n",i,j,k);
        if (isConvex(i, j, k)) return 1;
      }
    }

  return 0;
}

int main() {
  int i;
  while (scanf("%d", &n1) != EOF) {
    for (i = 0; i < n1; i++) scanf("%lf%lf", &P1[i].x, &P1[i].y);
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
      scanf("%lf%lf", &P3[i].x, &P3[i].y);
      P2[n2 - 1 - i] = P3[i];
    }
    printf("%d\n", check());
  }

  return 0;
}
