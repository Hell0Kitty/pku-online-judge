#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template <class T>
T _abs(T n) {
  return (n < 0 ? -n : n);
}
template <class T>
T _max(T a, T b) {
  return (!(a < b) ? a : b);
}
template <class T>
T _min(T a, T b) {
  return (a < b ? a : b);
}
template <class T>
T sq(T x) {
  return x * x;
}

#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int) c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair<int, int>
#define psi pair<string, int>

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

int k, L;
char a[80], b[80];
i64 dp[80][2][2], sum[80][2][2];

i64 func(int pos, int sf, int fl) {
  i64 &ret = dp[pos][sf][fl];
  i64 &sm = sum[pos][sf][fl];
  if (ret != -1) return ret;
  if (pos == L) {
    sm = 0;
    return ret = 1;
  }
  ret = 0;
  int lmt = b[pos] - '0', i, st = 1, nsf, nfl;
  i64 tmp, ts, x, y;
  if (sf) lmt = k - 1;
  if (pos) st = 0;
  for (i = st; i <= lmt; i++) {
    nsf = sf || i < lmt;
    nfl = 1 - fl;
    tmp = func(pos + 1, nsf, nfl);
    ts = 0;
    if (L % 2) {
      x = tmp / 2;
      y = tmp - x;
      if (fl)
        ts -= y * i - x * i;
      else
        ts += y * i - x * i;
    } else {
      if (fl)
        ts -= tmp * i;
      else
        ts += tmp * i;
    }
    ret += tmp;
    sm += ts + sum[pos + 1][nsf][nfl];
    if (L % 2 && tmp % 2) {
      fl = 1 - fl;
    }
  }
  return ret;
}

int main() {
  int i, l, fl;
  i64 res, nn;
  cin >> k >> a;
  l = strlen(a);
  b[0] = 0;
  nn = 0;
  res = 0;
  for (i = 1; i < l; i++) {
    b[i - 1] = k - 1 + '0';
    b[i] = 0;
    SET(dp);
    CLR(sum);
    fl = nn % 2;
    L = i;
    nn += i * func(0, 0, fl);
    res += sum[0][0][fl];
  }
  strcpy(b, a);
  SET(dp);
  CLR(sum);
  fl = nn % 2;
  L = i;
  nn += i * func(0, 0, fl);
  res += sum[0][0][fl];
  cout << res << endl;
  return 0;
}
