#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using std::vector;

inline int sign(const double x) {
  static const double EPS = 1e-8;
  if (x > EPS) return 1;
  return x < -EPS ? -1 : 0;
}
const double PI = std::acos(-1.0);
const int MAXN = 200;
const int HASHMOD = 65497;
const int SEED = 57123577;
int Testcase, n, cnt, hashid[65536], hashpos[MAXN * MAXN];
struct Point {
  double x, y;
  Point() {}
  Point(const double a, const double b) : x(a), y(b) {}
};
const Point EMPTY(-10086, -12580);
Point O, hash[65536];
inline bool operator!=(const Point& lhs, const Point& rhs) {
  return sign(lhs.x - rhs.x) || sign(lhs.y - rhs.y);
}
inline Point operator-(const Point& lhs, const Point& rhs) {
  return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}
inline bool operator<(const Point& lhs, const Point& rhs) {
  return sign(lhs.x - rhs.x) < 0 ||
         (sign(lhs.x - rhs.x) == 0 && sign(lhs.y - rhs.y) < 0);
}
inline double cross(const Point& A, const Point& B, const Point& C,
                    const Point& D) {
  const double x1 = B.x - A.x, y1 = B.y - A.y;
  const double x2 = D.x - C.x, y2 = D.y - C.y;
  return x1 * y2 - x2 * y1;
}
int intersection(const Point& p1, const Point& p2, const Point& p3,
                 const Point& p4, Point& p) {
  const double s1 = cross(p1, p3, p1, p4);
  const double s2 = cross(p2, p3, p2, p4);
  const double s3 = cross(p3, p1, p3, p2);
  const double s4 = cross(p4, p1, p4, p2);
  if (s1 * s2 < 0 && s3 * s4 < 0) {
    p.x = (s1 * p2.x - s2 * p1.x) / (s1 - s2);
    p.y = (s1 * p2.y - s2 * p1.y) / (s1 - s2);
    return 5;
  }
  return 0;
}
inline bool cmp(const Point& lhs, const Point& rhs) {
  return std::atan2(lhs.y, lhs.x) < std::atan2(rhs.y, rhs.x);
}
inline int locate(const Point& p) {
  const long long x = static_cast<long long>(p.x * 1e8);
  const long long y = static_cast<long long>(p.y * 1e8);
  int h = ((x * SEED + y) % HASHMOD + HASHMOD) % HASHMOD;
  while (hash[h] != EMPTY && hash[h] != p) ++h;
  return h;
}
inline int getid(const Point& p) {
  const int h = locate(p);
  if (hashid[h] != -1) return hashid[h];
  hash[h] = p, hashpos[cnt] = h;
  return hashid[h] = cnt++;
}

struct Segment {
  bool arc, vis;
  int target;
  // Segment() { }
  Segment(const int v, const bool isarc) : arc(isarc), vis(false), target(v) {}
};
vector<Segment> v[MAXN * MAXN];
void addedge(const Point& x, const Point& y, const bool isarc) {
  const int a = getid(x), b = getid(y);
  v[a].push_back(Segment(b, isarc));
  if (!isarc) v[b].push_back(Segment(a, isarc));
}
inline double arcarea(const Point& a, const Point& b) {
  double angle = -std::atan2(a.y, a.x) + std::atan2(b.y, b.x);
  if (sign(angle) < 0) angle += 2.0 * PI;
  return 50.0 * (angle - std::sin(angle));
}
inline bool cmp2(const Segment& lhs, const Segment& rhs) {
  if (lhs.target == rhs.target) return (lhs.arc ? 1 : 0) > (rhs.arc ? 1 : 0);
  return cmp(hash[hashpos[lhs.target]] - O, hash[hashpos[rhs.target]] - O);
}

double go(int st, vector<Segment>::iterator edge) {
  const int first = st;
  vector<int> p;
  double res = .0;
  do {
    const int target = edge->target;
    if (edge->arc) res += arcarea(hash[hashpos[st]], hash[hashpos[target]]);
    edge->vis = true;
    p.push_back(st);
    for (vector<Segment>::iterator e = v[target].begin(); e != v[target].end();
         ++e)
      if (edge->arc == e->arc && (edge->arc || e->target == st)) {
        edge = e == v[target].begin() ? v[target].end() : e;
        --edge;
        break;
      }
    st = target;
  } while (st != first);

  p.push_back(first);
  for (vector<int>::size_type i = 1; i < p.size(); ++i)
    res += cross(O, hash[hashpos[p[i - 1]]], O, hash[hashpos[p[i]]]) / 2.0;

  return res;
}

double solve() {
  static Point p[MAXN * MAXN], cut[MAXN][2], tmp;
  memset(hashid, 0xFF, sizeof(hashid));
  memset(hashpos, 0xFF, sizeof(hashpos));
  std::fill(hash, hash + 65536, EMPTY);
  cnt = 0;

  for (int i = 0; i < n; ++i) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    cut[i][0].x = 10.0 * std::cos(a), cut[i][0].y = 10.0 * std::sin(a);
    cut[i][1].x = 10.0 * std::cos(b), cut[i][1].y = 10.0 * std::sin(b);
    p[2 * i] = cut[i][0], p[2 * i + 1] = cut[i][1];
  }
  std::sort(p, p + 2 * n, cmp);
  for (int i = 0; i < 2 * n; ++i) addedge(p[i], p[(i + 1) % (2 * n)], true);

  for (int i = 0; i < n; ++i) {
    int tot = 0;
    p[tot++] = cut[i][0], p[tot++] = cut[i][1];
    for (int j = 0; j < n; ++j)
      if (i != j &&
          intersection(cut[i][0], cut[i][1], cut[j][0], cut[j][1], tmp))
        p[tot++] = tmp;
    std::sort(p, p + tot);
    for (int i = 1; i < tot; ++i) addedge(p[i - 1], p[i], false);
  }
  for (int i = 0; i < cnt; ++i) {
    O = hash[hashpos[i]];
    std::sort(v[i].begin(), v[i].end(), cmp2);
  }

  double ans = .0;
  for (int i = 0; i < cnt; ++i)
    for (vector<Segment>::iterator e = v[i].begin(); e != v[i].end(); ++e)
      if (!e->vis) {
        const double s = go(i, e);
        ans = std::max(ans, s);
      }

  for (int i = 0; i < cnt; ++i) v[i].clear();
  return ans;
}
int main() {
  for (scanf("%d", &Testcase); Testcase--;) {
    scanf("%d", &n);
    printf("%.2f\n", solve());
  }
}
