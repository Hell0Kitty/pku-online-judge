#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define maxn 10
#define eps 10E-9

struct Point {
  double x, y;
} f[maxn], g[maxn];

int a, b;

int dblcmp(double a, double b) {
  if (abs(a - b) < eps) return 0;
  if (a > b) return 1;
  return -1;
}

void input() {
  for (int i = 0; i < 3; i++) scanf("%lf%lf", &f[i].x, &f[i].y);
  for (int i = 0; i < 3; i++) scanf("%lf%lf", &g[i].x, &g[i].y);
}

double dist(Point &a) { return a.x * a.x + a.y * a.y; }

double score(double a) {
  if (dblcmp(a, 9) <= 0) return 100;
  if (dblcmp(a, 36) <= 0) return 80;
  if (dblcmp(a, 81) <= 0) return 60;
  if (dblcmp(a, 144) <= 0) return 40;
  if (dblcmp(a, 225) <= 0) return 20;
  return 0;
}

void work() {
  a = b = 0;
  for (int i = 0; i < 3; i++) a += score(dist(f[i]));
  for (int i = 0; i < 3; i++) b += score(dist(g[i]));
  if (a == b)
    printf("SCORE: %d to %d, TIE.\n", a, b);
  else if (a < b)
    printf("SCORE: %d to %d, PLAYER 2 WINS.\n", a, b);
  else if (a > b)
    printf("SCORE: %d to %d, PLAYER 1 WINS.\n", a, b);
}

int main() {
  while (1) {
    input();
    if (dblcmp(f[0].x, -100) == 0) break;
    work();
  }
  return 0;
}
