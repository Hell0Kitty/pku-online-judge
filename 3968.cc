#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
  double x, y;
};
typedef Point Vector;
vector<Point> P;

struct Line {
  Point P, Q;
  Vector v;
};

int dcmp(double x, double y = 0) {
  static const double EPS = 1e-8;
  double d = x - y;
  if (d > -EPS && d < EPS) return 0;
  return d < 0 ? -1 : 1;
}

Vector operator-(Vector a, Vector b) { return (Vector){a.x - b.x, a.y - b.y}; }

double Cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

bool Left(Point P, const Line &L) { return dcmp(Cross(L.P - P, L.Q - P)) > 0; }

Point Intersection(const Line &a, const Line &b) {
  double t = Cross(b.v, a.P - b.P) / Cross(a.v, b.v);
  return (Point){a.P.x + t * a.v.x, a.P.y + t * a.v.y};
}

bool Check(int x) {
  int i, j, l, r, n = P.size();
  vector<Line> L(n);
  for (i = 0; i < n; i++) {
    j = (i + x + 1) % n;
    L[i].P = P[i];
    L[i].Q = P[j];
    L[i].v = P[j] - P[i];
  }
  vector<Point> P(n);
  vector<int> Q(n);
  Q[l = r = 0] = 0;
  for (i = 1; i < n; i++) {
    while (r > l && !Left(P[r - 1], L[i])) r--;
    while (r > l && !Left(P[l], L[i])) l++;
    Q[++r] = i;
    if (dcmp(Cross(L[Q[r]].v, L[Q[r - 1]].v)) == 0) {
      r--;
      if (Left(L[i].P, L[Q[r]])) Q[r] = i;
    }
    if (r > l) P[r - 1] = Intersection(L[Q[r]], L[Q[r - 1]]);
  }
  while (r > l && !Left(P[r - 1], L[Q[l]])) r--;
  while (r > l && !Left(P[l], L[Q[r]])) l++;
  return r - l + 1 >= 3;
}

int main() {
  int n, i;
  while (scanf("%d", &n) == 1) {
    P.resize(n);
    for (i = 0; i < n; i++) scanf("%lf%lf", &P[i].x, &P[i].y);
    reverse(P.begin(), P.end());
    int low = 1, high = n - 2, mid;
    while (low < high) {
      mid = (low + high) / 2;
      if (Check(mid))
        low = mid + 1;
      else
        high = mid;
    }
    printf("%d\n", low);
  }
  return 0;
}
