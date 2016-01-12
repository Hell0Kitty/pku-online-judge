#include "stdio.h"
#include "math.h"
#include "memory.h"
#define M1 (1e15 + 1.0)
typedef struct { double x, y; } point;
int n;
point pom, d;
point enemy[6][11];
int m[6];
double t1[6];
double t2[11];
double judgeline(point a1, point a2) {
  double t, x1, x2, y1, y2, u1, u2;
  x1 = a1.x - pom.x;
  y1 = a1.y - pom.y;
  x2 = a2.x - pom.x;
  y2 = a2.y - pom.y;
  u1 = x1 * d.y - y1 * d.x;
  u2 = x2 * d.y - y2 * d.x;
  if (u1 * u2 > 0) {
    t = M1;
    return t;
  }
  x1 = a1.x;
  y1 = a1.y;
  x2 = a2.x;
  y2 = a2.y;
  u1 = pom.x * (y2 - y1) - pom.y * (x2 - x1) - x1 * y2 + x2 * y1;
  u2 = d.y * (x2 - x1) - d.x * (y2 - y1);
  t = u1 / u2;
  if (t < 0) t = M1;
  return t;
}
double judgeenemy(int i) {
  int j;
  double tmin = M1;
  for (j = 1; j <= m[i]; j++) {
    t2[j] = judgeline(enemy[i][j - 1], enemy[i][j]);
    if (t2[j] < tmin) tmin = t2[j];
  }
  return tmin;
}
int solve() {
  int i, pmin;
  double min = M1;
  bool judge;
  for (i = 1; i <= n; i++) {
    t1[i] = judgeenemy(i);
    if (t1[i] < min) {
      min = t1[i];
      pmin = i;
    }
  }
  if (min > M1 - 2)
    judge = 0;
  else if (pmin != 1)
    judge = 0;
  else
    judge = 1;
  if (judge)
    printf("HIT\n");
  else
    printf("MISS\n");
  return 0;
}
int init() {
  memset(enemy, 0, sizeof(enemy));
  memset(m, 0, sizeof(m));
  memset(t1, 0, sizeof(t1));
  scanf("%lf%lf", &pom.x, &pom.y);
  scanf("%lf%lf", &d.x, &d.y);
  int i, j;
  for (i = 1; i <= n; i++) {
    scanf("%d", &m[i]);
    for (j = 1; j <= m[i]; j++) scanf("%lf%lf", &enemy[i][j].x, &enemy[i][j].y);
    enemy[i][0].x = enemy[i][m[i]].x;
    enemy[i][0].y = enemy[i][m[i]].y;
  }
  return 0;
}
int main() {
  while (scanf("%d", &n) != EOF && n > 0) {
    init();
    solve();
  }
  return 0;
}
