#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = (int)5e5 + 10;
const int N = 500000;
int n, m, cs;
struct node {
  int x, y;
  node() {}
  node(int a, int b) : x(a), y(b) {}
  bool operator<(const node &rhs) const { return x < rhs.x; }
};
struct Query {
  int x, y, i;
  Query() {}
  Query(int a, int b, int c) : x(a), y(b), i(c) {}
  bool operator<(const Query &rhs) const { return x < rhs.x; }
};
struct segtree {
  int cnt[maxn << 2];
  void build() { memset(cnt, 0, sizeof(cnt)); }
  void update(int pos, int l, int r, int rt) {
    cnt[rt] += 1;
    if (l == r) return;
    int m = (l + r) >> 1;
    if (pos <= m)
      update(pos, lson);
    else
      update(pos, rson);
  }
  int query(int ll, int rr, int l, int r, int rt) {
    if (ll <= l && rr >= r) return cnt[rt];
    int m = (l + r) >> 1;
    int ret = 0;
    if (ll <= m) ret += query(ll, rr, lson);
    if (rr > m) ret += query(ll, rr, rson);
    return ret;
  }
};
vector<node> pt;
vector<Query> qy;
int n1[50010], n2[50010], n3[50010], n4[50010];
segtree t;
void init() {
  t.build();
  pt.resize(0);
  qy.resize(0);
  memset(n1, 0, sizeof(n1));
  memset(n2, 0, sizeof(n2));
  memset(n3, 0, sizeof(n3));
  memset(n4, 0, sizeof(n4));
}
void solve() {
  init();
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    pt.push_back(node(x, y));
  }
  sort(pt.begin(), pt.end());
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    qy.push_back(Query(x, y, i));
  }
  sort(qy.begin(), qy.end());
  int pos = 0;
  for (int i = 0; i < qy.size(); i++) {
    while (pt[pos].x < qy[i].x && pos < pt.size()) {
      t.update(pt[pos].y, 0, N, 1);
      pos += 1;
    }
    int a3 = t.query(0, qy[i].y, 0, N, 1);
    n3[qy[i].i] = a3;
    n2[qy[i].i] = t.cnt[1] - a3;
  }
  t.build();
  reverse(pt.begin(), pt.end());
  reverse(qy.begin(), qy.end());
  pos = 0;
  for (int i = 0; i < qy.size(); i++) {
    while (pt[pos].x > qy[i].x && pos < pt.size()) {
      t.update(pt[pos].y, 0, N, 1);
      pos += 1;
    }
    int a4 = t.query(0, qy[i].y, 0, N, 1);
    n4[qy[i].i] = a4;
    n1[qy[i].i] = t.cnt[1] - a4;
  }
  for (int i = 0; i < m; i++) {
    int ans = abs(n1[i] + n3[i] - n2[i] - n4[i]);
    printf("%d\n", ans);
  }
  if (cs != 0) puts("");
}
int main() {
  scanf("%d", &cs);
  while (cs--) solve();
  return 0;
}
