#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct point {
  double x;
  double y;
} p[20];
struct T {
  int xx;         //
  int yy;         //
  int zz;         //
  double mianji;  //
} res;
bool cmp(int a, int b) { return a < b; }
point operator-(const point &a, const point &b) {
  point temp;
  temp.x = a.x - b.x;
  temp.y = a.y - b.y;
  return temp;
}
double operator*(const point &a, const point &b) {
  return fabs(a.x * b.y - b.x * a.y);
}
double cal(point a, point b, point c) {
  point m = b - a;
  point n = c - a;
  return m * n / 2;
}
double cal2(point a, point b, point c, point d) {
  point m = c - d;
  point n = a - d;
  point h = b - d;
  return m * n / 2 + m * h / 2 + n * h / 2;
}
int main() {
  int n;
  while (scanf("%d", &n), n) {
    res.xx = -1;
    res.yy = -1;
    res.zz = -1;
    res.mianji = 0;
    getchar();
    int i, j, k, l;
    char ch;
    for (i = 0; i < n; i++) {
      scanf("%c", &ch);
      scanf("%lf %lf", &p[i].x, &p[i].y);
      getchar();
    }
    double mianji1, mianji2;
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        for (k = j + 1; k < n; k++) {
          //由p[i],p[j],p[k]组成的三角形
          mianji1 = cal(p[i], p[j], p[k]);
          bool flag = true;
          for (l = 0; l < n; l++) {
            if (l == i || l == j || l == k) {
              continue;
            }
            mianji2 = cal2(p[i], p[j], p[k], p[l]);
            if (mianji1 == mianji2) {
              flag = false;
              break;
            }
          }
          if (flag)  //三角形合法
          {
            if (mianji1 > res.mianji) {
              res.xx = i;
              res.yy = j;
              res.zz = k;
              res.mianji = mianji1;
            }
          }
        }
      }
    }
    int h[3];
    h[0] = res.xx;
    h[1] = res.yy;
    h[2] = res.zz;
    sort(h, h + 3, cmp);
    printf("%c%c%c\n", h[0] + 'A', h[1] + 'A', h[2] + 'A');
  }
  return 0;
}
