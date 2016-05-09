#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int n;
int o1, o2;
int xx1, xx2, yy1, yy2;
int c[170];

void find(int d, int t, int &wx, int &wy) {
  if (d == 0) {
    wx = 0;
    wy = 0;
    return;
  }
  int delta = c[d - 1] * c[d - 1];
  int xx, yy;
  if (delta >= t) {
    find(d - 1, t, xx, yy);
    wx = yy;
    wy = xx;
    return;
  }
  t = t - delta;
  if (delta >= t) {
    find(d - 1, t, xx, yy);
    wx = c[d - 1] + xx;
    wy = yy;
    return;
  }
  t = t - delta;
  if (delta >= t) {
    find(d - 1, t, xx, yy);
    wx = c[d - 1] + xx;
    wy = c[d - 1] + yy;
    return;
  }
  t = t - delta;
  if (delta >= t) {
    find(d - 1, t, xx, yy);
    wx = c[d - 1] - 1 - yy;
    wy = c[d] - 1 - xx;
  }
}
int main() {
  int total, lin;
  scanf("%d", &total);
  c[0] = 1;
  for (int i = 1; i <= 16; ++i) c[i] = c[i - 1] * 2;
  while (total > 0) {
    --total;
    scanf("%d%d%d", &n, &o1, &o2);
    find(n, o1, xx1, yy1);
    find(n, o2, xx2, yy2);
    __int64 xx = xx2 - xx1, yy = yy2 - yy1;
    __int64 ans = xx * xx + yy * yy;
    ans = sqrt(ans) * 10 + 0.5;
    printf("%I64d\n", ans);
  }
  return 0;
}
