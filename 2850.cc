#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#define LL long long
#define MaxN 100005
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define PI (acos(-1.0))
struct Point {
  double x, y;
};

typedef Point Vector;

Point a[500];
Point b, c;
Vector v1, v2;
void updatax(int i) {
  v1.x = (a[i + 1].x - a[i].x) / 2.0;
  v1.y = (a[i + 1].y - a[i].y) / 2.0;
  double L = sqrt(v1.x * v1.x + v1.y * v1.y);
  double ll = sqrt(4.0 - L * L);
  v2.x = -v1.y / L * ll;
  v2.y = v1.x / L * ll;
  b.x = a[i].x + v1.x + v2.x;
  b.y = a[i].y + v1.y + v2.y;
  c.x = a[i].x + v1.x - v2.x;
  c.y = a[i].y + v1.y - v2.y;
  if (b.y > c.y) {
    a[i].x = b.x;
    a[i].y = b.y;
  } else {
    a[i].x = c.x;
    a[i].y = c.y;
  }
}
int main() {
  int tt;
  scanf("%d", &tt);
  for (int t = 1; t <= tt; t++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lf", &a[i].x);
      a[i].y = 1.0;
    }
    for (int r = n - 1; r >= 0; r--)
      for (int i = 0; i < r; i++) {
        updatax(i);
      }
    printf("%d: ", t);
    printf("%.4lf %.4lf\n", a[0].x, a[0].y);
  }
}
