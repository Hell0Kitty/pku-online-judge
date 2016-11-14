#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
double fenzi[2], fenmu, S, x, y, eps = 1e-7, arg, delta, X, Y, pi = acos(-1.00),
                                 ansx, ansy, oox = 1412.000, ooy = 3756.000;
struct pp {
  char flag[11];
  double x, y, r, arg, x0, y0;
};
pp aa[111];
int n, cnt;
double area(double x1, double y1, double x2, double y2, double x3, double y3) {
  return ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) / 2.00;
}
void G(double x1, double y1, double x2, double y2, double x3, double y3) {
  x = (x1 + x2 + x3) / 3.00;
  y = (y1 + y2 + y3) / 3.00;
}
bool inter(double x1, double y1, double x2, double y2, double x3, double y3,
           double x4, double y4) {
  double a1, b1, c1, a2, b2, c2;
  a1 = y2 - y1;
  b1 = x1 - x2;
  c1 = y1 * x2 - y2 * x1;
  a2 = y4 - y3;
  b2 = x3 - x4;
  c2 = y3 * x4 - y4 * x3;
  if (a1 * b2 == a2 * b1) return false;
  x = (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1);
  y = (c2 * a1 - c1 * a2) / (b1 * a2 - b2 * a1);
  if (!((x < x1 + eps && x > x2 - eps) || (x < x2 + eps && x > x1 - eps)))
    return false;
  if (!((y < y1 + eps && y > y2 - eps) || (y < y2 + eps && y > y1 - eps)))
    return false;
  if (!((x < x3 + eps && x > x4 - eps) || (x < x4 + eps && x > x3 - eps)))
    return false;
  if (!((y < y3 + eps && y > y4 - eps) || (y < y4 + eps && y > y3 - eps)))
    return false;
  return true;
}
int main() {
  int i, j, s, p, q;
  double a, b, c, A, B, C, k, arg1, arg2;
  while (scanf("%s", aa[0].flag) && strcmp(aa[0].flag, "end") != 0) {
    scanf("%lf%lf", &aa[0].x, &aa[0].y);
    n = 1;
    while (true) {
      scanf("%s", aa[n].flag);
      if (strcmp(aa[n].flag, "close") == 0) {
        if (aa[n - 1].x != aa[0].x || aa[n - 1].y != aa[0].y) {
          strcpy(aa[n].flag, "line");
          aa[n].x = aa[0].x;
          aa[n++].y = aa[0].y;
        }
        break;
      }
      scanf("%lf%lf", &aa[n].x, &aa[n].y);
      if (strcmp(aa[n].flag, "arc") == 0) scanf("%lf", &aa[n].r);
      n++;
    }
    fenzi[0] = fenzi[1] = fenmu = 0;
    for (i = 1; i < n; i++) {
      if (i + 1 < n) {
        S = area(aa[0].x, aa[0].y, aa[i].x, aa[i].y, aa[i + 1].x, aa[i + 1].y);
        if (S != 0) {
          G(aa[0].x, aa[0].y, aa[i].x, aa[i].y, aa[i + 1].x, aa[i + 1].y);
          fenzi[0] += S * x;
          fenzi[1] += S * y;
          fenmu += S;
        }
      }
      if (strcmp(aa[i].flag, "arc") == 0) {
        a = 2 * (aa[i].x - aa[i - 1].x);
        b = 2 * (aa[i].y - aa[i - 1].y);
        c = aa[i].x * aa[i].x - aa[i - 1].x * aa[i - 1].x + aa[i].y * aa[i].y -
            aa[i - 1].y * aa[i - 1].y;
        if (b == 0) {
          x = c / a;
          y = aa[i].y + sqrt(aa[i].r * aa[i].r - (x - aa[i].x) * (x - aa[i].x));
          if ((aa[i].r < 0 &&
               (aa[i].y - y) * (aa[i - 1].x - x) <
                   (aa[i - 1].y - y) * (aa[i].x - x)) ||
              (aa[i].r > 0 &&
               (aa[i].y - y) * (aa[i - 1].x - x) >
                   (aa[i - 1].y - y) * (aa[i].x - x))) {
            y = aa[i].y -
                sqrt(aa[i].r * aa[i].r - (x - aa[i].x) * (x - aa[i].x));
            while ((aa[i].y - y) * (aa[i - 1].x - x) <
                   (aa[i - 1].y - y) * (aa[i].x - x))
              ;
          }
        } else {
          A = a * a + b * b;
          B = 2 * (b * aa[i].y - c) * a - 2 * b * b * aa[i].x;
          C = b * b * aa[i].x * aa[i].x +
              (c - aa[i].y * b) * (c - aa[i].y * b) - aa[i].r * aa[i].r * b * b;
          delta = B * B - 4 * A * C;
          x = (-B + sqrt(delta)) / (2 * A);
          y = (c - a * x) / b;
          if ((aa[i].r < 0 &&
               (aa[i].y - y) * (aa[i - 1].x - x) <
                   (aa[i - 1].y - y) * (aa[i].x - x)) ||
              (aa[i].r > 0 &&
               (aa[i].y - y) * (aa[i - 1].x - x) >
                   (aa[i - 1].y - y) * (aa[i].x - x))) {
            x = (-B - sqrt(delta)) / (2 * A);
            y = (c - a * x) / b;
          }
        }
        aa[i].x0 = x;
        aa[i].y0 = y;
        X = (aa[i].x + aa[i - 1].x) / 2.0;
        Y = (aa[i].y + aa[i - 1].y) / 2.0;
        arg = sqrt((aa[i].x - X) * (aa[i].x - X) +
                   (aa[i].y - Y) * (aa[i].y - Y)) /
              abs(aa[i].r);
        arg = 2 * asin(arg);
        aa[i].arg = arg;
        S = aa[i].r * aa[i].r * (arg - sin(arg)) / 2.00;
        if (aa[i].r > 0) S = -S;
        double val = sin(arg / 2.00);
        double len1 = 2.0 * abs(aa[i].r * aa[i].r * aa[i].r) * val * val * val /
                      (3.0 * abs(S)),
               len2 = sqrt((aa[i].x0 - X) * (aa[i].x0 - X) +
                           (aa[i].y0 - Y) * (aa[i].y0 - Y));
        x = aa[i].x0 + len1 * (X - aa[i].x0) / len2;
        y = aa[i].y0 + len1 * (Y - aa[i].y0) / len2;
        fenzi[0] += S * x;
        fenzi[1] += S * y;
        fenmu += S;
      }
    }
    ansx = fenzi[0] / fenmu;
    ansy = fenzi[1] / fenmu;
    printf("%.4lf %.4lf", ansx + eps, ansy + eps);
    cnt = 0;
    for (i = 1; i < n; i++) {
      if (strcmp(aa[i].flag, "line") == 0)
        cnt += inter(ansx, ansy, oox, ooy, aa[i - 1].x, aa[i - 1].y, aa[i].x,
                     aa[i].y);
      else if (strcmp(aa[i].flag, "arc") == 0) {
        k = (ansy - ooy) / (ansx - oox);
        b = (ansy * oox - ooy * ansx) / (oox - ansx);
        A = 1 + k * k;
        B = 2 * (b - aa[i].y0) * k - 2 * aa[i].x0;
        C = aa[i].x0 * aa[i].x0 + (b - aa[i].y0) * (b - aa[i].y0) -
            aa[i].r * aa[i].r;
        delta = B * B - 4 * A * C;
        if (delta >= 0) {
          x = (-B + sqrt(delta)) / (2 * A);
          y = k * x + b;
          if ((x < oox + eps && x > ansx - eps)) {
            arg = aa[i].arg;
            arg1 = (x - aa[i].x0) * (aa[i - 1].x - aa[i].x0) +
                   (y - aa[i].y0) * (aa[i - 1].y - aa[i].y0);
            arg1 /= (aa[i].r * aa[i].r);
            arg1 = acos(arg1);
            arg2 = (x - aa[i].x0) * (aa[i].x - aa[i].x0) +
                   (y - aa[i].y0) * (aa[i].y - aa[i].y0);
            arg2 /= (aa[i].r * aa[i].r);
            arg2 = acos(arg2);
            if (abs(arg1 + arg2 - arg) < eps) cnt++;
          }
          x = (-B - sqrt(delta)) / (2 * A);
          y = k * x + b;
          if ((x < oox + eps && x > ansx - eps)) {
            arg = aa[i].arg;
            arg1 = (x - aa[i].x0) * (aa[i - 1].x - aa[i].x0) +
                   (y - aa[i].y0) * (aa[i - 1].y - aa[i].y0);
            arg1 /= (aa[i].r * aa[i].r);
            arg1 = acos(arg1);
            arg2 = (x - aa[i].x0) * (aa[i].x - aa[i].x0) +
                   (y - aa[i].y0) * (aa[i].y - aa[i].y0);
            arg2 /= (aa[i].r * aa[i].r);
            arg2 = acos(arg2);
            if (abs(arg1 + arg2 - arg) < eps) cnt++;
          }
        }
      }
    }
    if (cnt % 2 == 0)
      printf(" -\n");
    else
      printf(" +\n");
  }
  return 0;
}
