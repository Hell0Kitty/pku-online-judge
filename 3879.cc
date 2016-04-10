#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

#define REP(i, x) for (int i = 0; i < x; i++)
#define MP(x, y) make_pair(x, y)
const double eps = 1e-10;
struct pt {
  double x, y;
  pt(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  pt operator+(const pt a) { return pt(x + a.x, y + a.y); }
  pt operator-(const pt a) { return pt(x - a.x, y - a.y); }
  pt operator*(const double a) { return pt(x * a, y * a); }
  double len() { return sqrt(x * x + y * y); }
  void rd() { scanf("%lf%lf", &x, &y); }
  void write() { printf("(%.2f,%.2f)", x, y); }
};
double det(pt a, pt b) { return a.x * b.y - a.y * b.x; }
double dot(pt a, pt b) { return a.x * b.x + a.y * b.y; }
double dis(pt a, pt b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double sgn(double x) { return x > eps ? 1 : x < -eps ? -1 : 0; }

double point_line_dis(pt x, pt a, pt b) {
  return fabs(det(a - x, b - x) / dis(a, b));
}
double point_seg_dis(pt x, pt a, pt b) {
  if (sgn(dot(b - a, x - a)) * sgn(dot(b - a, x - b)) < 0)
    return point_line_dis(x, a, b);

  return min(dis(a, x), dis(b, x));
}
const int V = 3300;
const double INFI = 1e10;
pair<pt, pt> line[V];
pt o;
int n;

vector<pair<int, double> > adj[V];

struct node {
  double dis;
  int v;
  node(double _dis = 0, int _v = 0) : dis(_dis), v(_v) {}
  bool operator<(const node &a) const { return dis > a.dis + eps; }
};

priority_queue<node> Q;
bool use[V];
double dist[V];

void build(pt o, int id) {
  pt l = o + pt(-1, 0);
  pt r = o + pt(1, 0);
  adj[id].clear();
  bool first = true;
  for (int i = 0; i < n; i++)
    if (line[i].second.y < o.y - eps) {
      pt a = line[i].first;
      pt b = line[i].second;

      double deltay = line[i].second.y - o.y;

      if (first) {
        l = a;
        r = b;
        first = false;
      }

      l = o + (l - o) * (deltay / (l - o).y);
      r = o + (r - o) * (deltay / (r - o).y);

      if (det(l - o, a - o) > eps) l = a;
      if (det(r - o, b - o) < -eps) r = b;
      if (det(l - o, r - o) < -eps) return;

      if (sgn(det(l - o, a - o)) == 0) adj[id].push_back(MP(i, dis(o, a)));
      if (sgn(det(r - o, b - o)) == 0) adj[id].push_back(MP(i + n, dis(o, b)));
    }
  double left = point_seg_dis(o, l, r);
  adj[id].push_back(MP(2 * n + 1, left));
}

double djstra(int s) {
  while (!Q.empty()) Q.pop();

  Q.push(node(0, s));
  for (int i = 0; i < V; i++) dist[i] = INFI, use[i] = false;
  dist[s] = 0;

  while (!Q.empty()) {
    int v = Q.top().v;
    Q.pop();
    if (v == 2 * n + 1) return dist[v];

    if (use[v]) continue;
    use[v] = true;

    for (int i = 0; i < adj[v].size(); i++)
      if (dist[v] + adj[v][i].second < dist[adj[v][i].first] - eps) {
        int u = adj[v][i].first;
        dist[u] = dist[v] + adj[v][i].second;
        Q.push(node(dist[u], u));
      }
  }
  return -1;
}
double solve() {
  build(o, 2 * n);
  for (int i = 0; i < n; i++) {
    build(line[i].first, i);
    build(line[i].second, i + n);
  }
  return djstra(2 * n);
}
int cas = 0;
int main() {
  int test = 0;

  double x1, x2, y;
  while (1) {
    scanf("%d", &n);
    if (n == 0) break;

    o.rd();
    REP(i, n) {
      scanf("%lf%lf%lf", &y, &x1, &x2);
      line[i].first = pt(x1, y);
      line[i].second = pt(x2, y);
    }

    test += n;
    if (test > 10000) test /= 0;

    printf("%.10f\n", solve());
  }
}
