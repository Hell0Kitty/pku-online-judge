#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <sstream>
#include <string>
using namespace std;
#define out(X) cerr << #X << ": " << (X) << endl
#define SZ(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define FOR(I, L, H) for (int I = (L); I < (H); ++I)
#define MP(X, Y) make_pair((X), (Y))
#define PB push_back
#define ALL(X) X.begin(), X.end()
template <typename T>
inline bool checkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool checkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
typedef long long lint;

const int MAXN = 100000 + 100;
const int MAXINT = -1u >> 1;
const double PI = acos(-1.0);
const double g = 9.81;
const double a = 5.00;
const double vbegin = 25.00;
const double EPS = 1e-6;

int sgn(const double &x) { return (int)((x > EPS) - (x < -EPS)); }

struct Node {
  double dis;
  bool mine;
  void input() {
    char buff[10];
    scanf("%lf %s", &dis, buff);
    mine = (buff[0] == 'm' ? true : false);
  }
  bool operator<(const Node &A) const { return sgn(dis - A.dis) == -1; }
} e[MAXN];

bool stop(const double &y, const double &vx, const double &vy) {
  if (sgn(y) == 0 && sgn(vx) == 0 && sgn(vy) == 0) {
    return true;
  }
  return false;
}

lint getScore(const int &tmp, const int &N) {
  int cntE = 0;
  double ang = tmp;
  ang = ang / 180.0 * PI;
  double y = 1.0, x = 0.0;
  double vy = sin(ang) * vbegin;
  double vx = cos(ang) * vbegin;
  double S, t, Smax;
  while (!stop(y, vx, vy)) {
    if (sgn(y) > 0) {
      S = y;
      t = (vy + sqrt(vy * vy + 2.0 * S * g)) / g;
      y = 0.0;
      x += vx * t;
      vy = 0.0;
    }
    while (cntE < N && sgn(e[cntE].dis - x) < 0) {
      cntE++;
    }
    S = e[cntE].dis - x;
    Smax = vx / a;
    if (sgn(Smax - S) >= 0) {
      vx -= S * a;
      x += S;
      if (e[cntE].mine) {
        vx += 4.0;
        x += 2.0;
      } else
        return -100;
    } else {
      vx = 0.0;
      x += Smax;
    }
  }
  return lint(x * 100 + 0.5);
}

int main() {
  int T, N;
  scanf("%d", &T);
  while (scanf("%d", &N) == 1) {
    for (int i = 0; i < N; i++) {
      e[i].input();
    }
    e[N].dis = 1e100;
    e[N].mine = false;
    N++;
    sort(e, e + N);
    lint res = -100, optAng = -90;
    for (int ang = -90; ang < 90 + 1; ang++) {
      lint tmp;
      tmp = getScore(ang, N);
      if (tmp > res) {
        res = tmp;
        optAng = ang;
      }
    }
    cout << res << ' ' << optAng << endl;
  }
  return 0;
}
