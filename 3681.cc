#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct point {
  int x, y;
} po[300];
bool comp(point a, point b) { return a.y < b.y; }
int x[300], n, m;
int getarea(int lx, int rx) {
  int d = 20000;
  int y[300], f = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (po[i].x >= lx && po[i].x <= rx) {
      y[r++] = po[i].y;
      if (r - f == m) {
        d = min(d, y[r - 1] - y[f]);
        f++;
      }
    }
  }
  return (d == 20000) ? (1 << 30) : (d + 2) * (rx - lx + 2);
}
int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    int nu = 0, ans = 1 << 30, sum;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &po[i].x, &po[i].y), x[i] = po[i].x;
    if (m == 1) {
      printf("4\n");
      continue;
    }
    sort(po, po + n, comp);
    sort(x, x + n);
    for (int i = 1; i < n; i++)
      if (x[i] != x[nu]) x[++nu] = x[i];
    nu++;
    for (int i = 0; i < nu; i++) {
      for (int j = i; j < nu; j++) {
        ans = min(ans, getarea(x[i], x[j]));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
