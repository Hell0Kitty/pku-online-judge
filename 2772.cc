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
LL nn, ff, bb;
LL p[1024], b[1024];
LL mubiao = 0;
int ok(LL ti) {
  LL tot = 0;
  rep(i, nn) {
    if (b[i] == 0) {
      LL tt = ti - p[i] - ff;
      if (tt >= 0) {
        tot += tt / (2 * ff) + 1;
      }
    } else {
      LL tt = ti - (ff - p[i]);
      if (tt < 0) return 0;
      tot += tt / (2 * ff) + 1;
    }
  }
  return tot >= mubiao;
}
int main(int argc, char *argv[]) {
  int TT;
  cin >> TT;
  while (TT--) {
    cin >> nn >> ff >> bb;
    rep(i, nn) cin >> p[i] >> b[i];
    mubiao = bb;
    rep(i, nn) mubiao += b[i];
    if (ok(0)) {
      cout << 0 << endl;
      continue;
    }
    LL mLeft = 0, mRight = 3000000000LL;
    while (mLeft < mRight - 1) {
      LL mid = (mLeft + mRight) / 2;
      if (ok(mid))
        mRight = mid;
      else
        mLeft = mid;
    }
    cout << mRight << endl;
  }
  return EXIT_SUCCESS;
}
