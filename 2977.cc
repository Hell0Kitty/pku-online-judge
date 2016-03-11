#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>
#define CL(x, v) \
  ;              \
  memset(x, v, sizeof(x));
#define INF 1 << 30
#define REP(i, r, n) for (int i = r; i <= n; i++)
#define RREP(i, n, r) for (int i = n; i >= r; i--)
#define EPS 1e-8
#define MID               \
  int mid = (l + r) >> 1; \
  int ls = o << 1;        \
  int rs = o << 1 | 1;
#define zero(x) fabs(x) < EPS ? 1 : 0
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
int lx, ly, lz, x, y, z;
int ans;
int f(int x) { return x * x; }
int main() {
  while (scanf("%d%d%d%d%d%d", &lx, &ly, &lz, &x, &y, &z) != EOF) {
    if (lx + ly + lz + x + y + z == 0) return 0;
    if (x == 0 || y == 0 || z == 0)
      ans = x * x + y * y + z * z;
    else {
      if (x == lx) {
        ans =
            min(min(f(lx + ly - y) + f(ly + z), f(lx + lz - z) + f(lz + y)),
                min((lx + y) * (lx + y) + z * z, (lx + z) * (lx + z) + y * y));
      }
      if (y == ly) {
        ans = min(min(f(ly + lz - z) + f(lz + x), f(ly + lx - x) + f(lx + z)),
                  min(f(ly + x) + f(z), f(ly + z) + f(x)));
      }
      if (z == lz) {
        ans =
            min(min(f(lz + ly - y) + f(ly + x), f(lz + lx - x) + f(lx + y)),
                min((lz + x) * (lz + x) + y * y, (lz + y) * (lz + y) + x * x));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
