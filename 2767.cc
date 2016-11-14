#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <string>
using namespace std;
#define CC(x, i)             \
  do {                       \
    memset(x, i, sizeof(x)); \
  } while (0)
#define inf 0x7f7f7f7f
#define PII pair<int, int>
#define VI vector<int>
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define uniq(x)                           \
  do {                                    \
    sort(all(x));                         \
    x.resize(unique(all(x)) - x.begin()); \
  } while (0)
#define two(x) (1ll << (x))
#define forn(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define rep(i, x) for (int i = 0; i < (int)(x); i++)

typedef long long LL;
int n, h[10], r[10], R[10], p[10], ans = 20000;
double help(int RR, int rr, int mm) { return 1.0 * (mm - rr) / (RR - rr); }
void gao() {
  double hi[10];
  hi[0] = 0;
  for (int i = 1; i < n; i++) {
    double th = 0;
    for (int j = 0; j < i; j++) {
      // top
      if (r[p[i]] >= R[p[j]]) {
        th = max(th, hi[j] + h[p[j]]);
      }
      // kashang
      if (R[p[j]] >= r[p[i]] && R[p[j]] <= R[p[i]]) {
        th = max(th, (1 - help(R[p[i]], r[p[i]], R[p[j]])) * h[p[i]] + h[p[j]] +
                         hi[j] - h[p[i]]);
      }
      // kazhong
      if (R[p[j]] >= R[p[i]] && r[p[j]] <= R[p[i]]) {
        th = max(th,
                 help(R[p[j]], r[p[j]], R[p[i]]) * h[p[j]] + hi[j] - h[p[i]]);
      }
      // kaxia
      if (R[p[j]] >= r[p[i]] && r[p[j]] <= r[p[i]]) {
        th = max(th, help(R[p[j]], r[p[j]], r[p[i]]) * h[p[j]] + hi[j]);
      }
      // di
      if (r[p[i]] <= r[p[j]]) {
        th = max(th, hi[j]);
      }
    }
    hi[i] = th;
  }
  int ret = 0;
  rep(i, n) ret = max(ret, (int)(hi[i] + h[p[i]]));
  ans = min(ans, ret);
}
int main(int argc, char *argv[]) {
  int i, tt;
  for (scanf("%d", &tt), i = 0; i < tt; i++) {
    scanf("%d", &n);
    ans = 20000;
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", h + i, r + i, R + i);
    }
    for (int i = 0; i < n; i++) p[i] = i;
    do {
      gao();
    } while (next_permutation(p, p + n));
    cout << ans << endl;
  }
  return EXIT_SUCCESS;
}
