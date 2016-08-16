#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
#define sqr(x) ((x) * (x))
using namespace std;

const int maxn = 40000 + 10;
double x[maxn], y[maxn], r[maxn];

struct qry {
  double x;
  int id;
  int stat;
  qry(double x = 0, int id = 0, int stat = 0) : x(x), id(id), stat(stat) {}
};

struct node {
  int id;
  node(int id = 0) : id(id) {}
  bool operator<(const node &b) const { return y[id] < y[b.id]; }
};

bool cmp(const qry &a, const qry &b) { return a.x < b.x; }

qry q[maxn * 2];
set<node> s;
int n, cnt;
bool inc[maxn];
set<node>::iterator wz[maxn];

void init() {
  cnt = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf%lf", &r[i], &x[i], &y[i]);
    q[cnt++] = qry(x[i] - r[i], i, 0);
    q[cnt++] = qry(x[i] + r[i], i, 1);
  }
}

bool incircle(int a, int b) {
  return sqrt(sqr(x[a] - x[b]) + sqr(y[a] - y[b])) + r[a] < r[b];
}

void solve() {
  sort(q, q + cnt, cmp);
  memset(inc, 0, sizeof(inc));
  int ans = 0;
  s.clear();
  for (int i = 0; i < cnt; ++i) {
    int id = q[i].id;
    if (q[i].stat) {
      if (!inc[id]) continue;
      s.erase(wz[id]);
    } else {
      set<node>::iterator it = s.lower_bound(id);
      if (it != s.end() && incircle(id, it->id)) continue;
      if (it != s.begin() && incircle(id, (--it)->id)) continue;
      inc[id] = true;
      ++ans;
      wz[id] = s.insert(node(id)).first;
    }
  }
  printf("%d\n", ans);
  int tot = 0;
  for (int i = 0; i < n; ++i)
    if (inc[i]) {
      if (tot++) printf(" ");
      printf("%d", i + 1);
    }
  printf("\n");
}

int main() {
  while (scanf("%d", &n) == 1 && n) {
    init();
    solve();
  }
}
