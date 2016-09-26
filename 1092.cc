#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

const int N = 222;
struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  Point operator+(Point a) { return Point(x + a.x, y + a.y); }
  Point operator-(Point a) { return Point(x - a.x, y - a.y); }
} pt[N];

typedef pair<int, int> PII;
typedef vector<Point> VPT;
typedef vector<int> VI;

inline double angle(Point x) { return atan2((double)x.y, (double)x.x); }
inline int cross(Point x, Point y) { return x.x * y.y - x.y * y.x; }

VI rel[N];
Point ori;
map<int, int> pid;
map<int, int> nx[N];
bool vis[N][N], vs[N];
int rec[N];

inline bool cmp(int a, int b) {
  return angle(pt[a] - ori) < angle(pt[b] - ori);
}
double area() {
  double ret = 0.0;
  rec[rec[0] + 1] = rec[1];
  for (int i = 1; i <= rec[0]; i++) ret += cross(pt[rec[i]], pt[rec[i + 1]]);
  return ret / 2.0;
}

bool test(int p) {
  int sz = rec[0], wn = 0;
  rec[sz + 1] = rec[1];
  for (int i = 1; i <= sz; i++) {
    if (pt[p].x == pt[rec[i]].x && pt[p].y == pt[rec[i]].y) return false;
    int k = cross(pt[rec[i + 1]] - pt[rec[i]], pt[p] - pt[rec[i]]);
    int d1 = pt[rec[i]].y - pt[p].y;
    int d2 = pt[rec[i + 1]].y - pt[p].y;
    if (k > 0 && d1 <= 0 && d2 > 0) wn++;
    if (k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  return wn != 0;
}

bool check() {
  for (int i = 1, sz = pid.size(); i <= sz; i++) {
    if (test(i)) return false;
  }
  return true;
}

int main() {
  int T, n, k, x, id;
  scanf("%d", &T);
  while (T-- && ~scanf("%d", &n)) {
    pid.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", &id);
      if (pid.find(id) == pid.end()) pid[id] = pid.size();
      rel[pid[id]].clear();
      nx[pid[id]].clear();
      scanf("%d%d", &pt[pid[id]].x, &pt[pid[id]].y);
      scanf("%d", &k);
      while (k--) {
        scanf("%d", &x);
        if (pid.find(x) == pid.end()) pid[x] = pid.size();
        rel[pid[id]].push_back(pid[x]);
      }
    }
    scanf("%d", &k);
    if (k < 3) {
      puts("0");
      continue;
    }
    for (int i = 1, sz; i <= n; i++) {
      ori = pt[i];
      sort(rel[i].begin(), rel[i].end(), cmp);
      sz = rel[i].size();
      if (sz <= 1) continue;
      rel[i].push_back(rel[i][0]);
      for (int j = 0; j < sz; j++) nx[rel[i][j + 1]][i] = rel[i][j];
      rel[i].pop_back();
    }
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for (int i = 1, len, t; i <= n; i++) {
      for (int j = 0, sz = rel[i].size(); j < sz; j++) {
        rec[0] = 0;
        int ls = i, cr = rel[i][j];
        if (vis[ls][cr]) continue;
        vis[ls][cr] = true;
        bool ok = true;
        memset(vs, 0, sizeof(vs));
        len = 1;
        while (nx[ls][cr]) {
          rec[++rec[0]] = cr;
          t = cr;
          cr = nx[ls][cr];
          if (cr <= 0) {
            len = -1;
            break;
          }
          if (vs[cr]) ok = false;
          vs[cr] = true;
          ls = t;
          if (vis[ls][cr]) break;
          vis[ls][cr] = true;
          len++;
        }
        if (ok && len == k && ls == i && area() >= 1e-5 && check()) cnt++;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
