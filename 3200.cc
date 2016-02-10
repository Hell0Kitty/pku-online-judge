#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 1005

struct Elem {
  long long x, y, r;
} block[maxn];

int n;

void input() {
  for (int i = 0; i < n; i++)
    scanf("%lld%lld%lld", &block[i].x, &block[i].y, &block[i].r);
}

bool unstable(Elem a, Elem b, Elem c) {
  double bx = b.x * 1.0 / c.x;
  double by = b.y * 1.0 / c.y;
  double xx = a.x - bx;
  double yy = a.y - by;
  return xx * xx + yy * yy >= a.r * a.r;
}

int main() {
  while (scanf("%d", &n), n) {
    input();
    bool ok = true;
    for (int i = 1; i < n; i++) {
      Elem b, c;
      b.x = b.y = 0;
      c.x = c.y = 0;
      for (int j = i; j > 0; j--) {
        b.x += block[j].x * block[j].r * block[j].r;
        c.x += block[j].r * block[j].r;
        b.y += block[j].y * block[j].r * block[j].r;
        c.y += block[j].r * block[j].r;
        if (unstable(block[j - 1], b, c)) {
          printf("Unfeasible %d\n", i);
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) printf("Feasible\n");
  }
  return 0;
}
