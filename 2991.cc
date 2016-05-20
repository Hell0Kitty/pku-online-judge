#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e4 + 10;
const double pi = acos(-1.0);

int n, q;
double vx[N << 2], vy[N << 2], delta[N << 2];
double deg[N];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt) {
  vx[rt] = vx[rt << 1] + vx[rt << 1 | 1];
  vy[rt] = vy[rt << 1] + vy[rt << 1 | 1];
}

void rotate(int rt, double del) {
  double rad = del * pi / 180.0;
  double x = vx[rt] * cos(rad) - vy[rt] * sin(rad);
  double y = vy[rt] * cos(rad) + vx[rt] * sin(rad);
  vx[rt] = x;
  vy[rt] = y;
}

void push_down(int rt) {
  if (delta[rt]) {
    rotate(rt << 1, delta[rt]);
    rotate(rt << 1 | 1, delta[rt]);
    delta[rt << 1] += delta[rt];
    delta[rt << 1 | 1] += delta[rt];
    delta[rt] = 0;
  }
}

void build(int l, int r, int rt) {
  delta[rt] = 0.0;
  if (l == r) {
    vx[rt] = 0.0;
    scanf("%lf", &vy[rt]);
    return;
  }
  int m = l + r >> 1;
  build(lson);
  build(rson);
  push_up(rt);
}

void update(int o, double del, int l, int r, int rt) {
  if (o < l) {
    delta[rt] += del;
    rotate(rt, del);
    return;
  }
  push_down(rt);
  int m = l + r >> 1;
  if (o < m) update(o, del, lson);
  update(o, del, rson);
  push_up(rt);
}

int main() {
  ios_base::sync_with_stdio(0);

  int kase = 0;
  while (scanf("%d%d", &n, &q) == 2) {
    build(root);
    if (++kase > 1) puts("");
    for (int i = 1; i <= n; ++i) deg[i] = 180.0;
    while (q--) {
      int x;
      double d;
      scanf("%d%lf", &x, &d);
      update(x, d - deg[x], root);
      deg[x] = d;
      printf("%.2f %.2f\n", vx[1], vy[1]);
    }
  }
  return 0;
}
