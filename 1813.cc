#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int a[100], b[100];
char s[100][10];
const double PI = acos(-1.0);
double dis(int x, int y) { return sqrt((double)(x * x + y * y)); }
double area(int x1, int y1, int x2, int y2, double r1, double r2) {
  double s = dis(x2 - x1, y2 - y1);
  if (r1 + r2 <= s)
    return 0;
  else if (r2 - r1 >= s)
    return PI * r1 * r1;
  else if (r1 - r2 >= s)
    return PI * r2 * r2;
  double q1 = acos((r1 * r1 + s * s - r2 * r2) / (2 * r1 * s));
  double q2 = acos((r2 * r2 + s * s - r1 * r1) / (2 * r2 * s));
  return (r1 * r1 * q1 + r2 * r2 * q2 - r1 * s * sin(q1));
}
bool inrec(int x1, int y1, int x2, int y2, int i, int j) {
  return (x1 <= i && i <= x2 && y1 <= j && j <= y2);
}
bool incir(int x, int y, int r, int i, int j) {
  return (i - x) * (i - x) + (j - y) * (j - y) <= r * r;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s[0]);
    if (s[0][0] == 'R')
      scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    else
      scanf("%d%d%d", &a[0], &a[1], &a[2]);
    scanf("%s", s[1]);
    if (s[1][0] == 'R')
      scanf("%d%d%d%d", &b[0], &b[1], &b[2], &b[3]);
    else
      scanf("%d%d%d", &b[0], &b[1], &b[2]);
    if (s[0][0] == 'C' && s[1][0] == 'C')
      printf("%.0f\n", area(a[0], a[1], b[0], b[1], a[2], b[2]));
    else {
      double ans = 0;
      for (int i = 0; i <= 2000; i++)
        for (int j = 0; j <= 2000; j++) {
          int ans1, ans2;
          if (s[0][0] == 'R')
            ans1 = inrec(a[0] * 200, a[1] * 200, a[2] * 200, a[3] * 200, i, j);
          else
            ans1 = incir(a[0] * 200, a[1] * 200, a[2] * 200, i, j);
          if (s[1][0] == 'R')
            ans2 = inrec(b[0] * 200, b[1] * 200, b[2] * 200, b[3] * 200, i, j);
          else
            ans2 = incir(b[0] * 200, b[1] * 200, b[2] * 200, i, j);
          if (ans1 && ans2) ans += 0.005 * 0.005;
        }
      printf("%.0f\n", ans);
    }
  }
  return 0;
}
