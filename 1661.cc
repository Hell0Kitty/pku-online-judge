#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 1005

struct Plat {
  int l, r, h, lt, rt;
} plat[maxn];

int n, m, cx, cy;

bool operator<(const Plat &a, const Plat &b) { return a.h > b.h; }

void input() {
  scanf("%d%d%d%d", &n, &cx, &cy, &m);
  plat[0].l = plat[0].r = cx;
  plat[0].h = cy;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &plat[i].l, &plat[i].r, &plat[i].h);
    if (plat[i].l > plat[i].r) swap(plat[i].l, plat[i].r);
  }
}

void work() {
  int j;
  int ans = 0x3f3f3f3f;
  for (int i = 0; i <= n; i++) plat[i].lt = plat[i].rt = 0x3f3f3f3f;
  plat[0].lt = plat[0].rt = 0;
  for (int i = 0; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      if (plat[i].h - plat[j].h > m) break;
      if (plat[i].h == plat[j].h) continue;
      if (plat[i].l <= plat[j].r && plat[i].l >= plat[j].l) {
        plat[j].lt =
            min(plat[i].h - plat[j].h + plat[i].lt + abs(plat[i].l - plat[j].l),
                plat[j].lt);
        plat[j].rt =
            min(plat[i].h - plat[j].h + plat[i].lt + abs(plat[i].l - plat[j].r),
                plat[j].rt);
        break;
      }
    }
    if (j > n && plat[i].h <= m) ans = min(ans, plat[i].lt + plat[i].h);
    for (j = i + 1; j <= n; j++) {
      if (plat[i].h - plat[j].h > m) break;
      if (plat[i].h == plat[j].h) continue;
      if (plat[i].r <= plat[j].r && plat[i].r >= plat[j].l) {
        plat[j].lt =
            min(plat[i].h - plat[j].h + plat[i].rt + abs(plat[i].r - plat[j].l),
                plat[j].lt);
        plat[j].rt =
            min(plat[i].h - plat[j].h + plat[i].rt + abs(plat[i].r - plat[j].r),
                plat[j].rt);
        break;
      }
    }
    if (j > n && plat[i].h <= m) ans = min(ans, plat[i].rt + plat[i].h);
  }
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    sort(plat, plat + n + 1);
    work();
  }
  return 0;
}
