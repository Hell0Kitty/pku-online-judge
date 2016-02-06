#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>
#include <map>
#define REP(i, n) for (int i = 0; i < n; ++i)
using namespace std;
#define MP make_pair
#define PB push_back

struct pt {
  int x, y;
  pt() {}
  pt(int _x, int _y) : x(_x), y(_y) {}
  void read() { scanf("%d%d", &x, &y); }
  pt operator+(const pt& a) const { return pt(x + a.x, y + a.y); }
  pt operator-(const pt& a) const { return pt(x - a.x, y - a.y); }
  pt operator*(const int a) const { return pt(x * a, y * a); }

  int len() const { return sqrt(x * x + y * y); }
  pt trunc(int s) const {
    int l = len();
    return pt(x * s / l, y * s / l);
  }
  void write() { printf("(%d %d) ", x, y); };

  bool operator<(const pt& a) const { return x < a.x || (x == a.x && y < a.y); }
};
int det(const pt& a, const pt& b) { return a.x * b.y - a.y * b.x; }
int dot(const pt& a, const pt& b) { return a.x * b.x + a.y * b.y; }

void Assert(int x) {
  if (!x)
    while (1) puts("fuck");
}
bool intersect(int a, int b, int c, int d) { return max(a, c) <= min(b, d); }
bool cross(pt a, pt b, pt c, pt d) {
  if (a.x == b.x)
    return c.y <= b.y && c.y >= a.y;
  else
    return c.x <= b.x && c.x >= a.x;
}
pt cross_point(pt a, pt b, pt c, pt d) {
  if (a.x == b.x)
    return pt(a.x, c.y);
  else
    return pt(c.x, a.y);
}
const int V = 11000;
pair<pt, pt> seg[1000];

struct Graph {
  int low[V], now[V], dfn[V];
  int loop_num;
  int n, bnum, sign, top;
  bool ge[V];
  vector<int> adj[V];
  vector<int> block[V * 2];
  pair<int, int> stack[100000];

  void connect(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  void dfs(int v, int fa) {
    dfn[v] = low[v] = ++sign;
    int son = 0;
    ge[v] = false;

    for (int i = 0; i < adj[v].size(); i++)
      if (adj[v][i] != fa) {
        int u = adj[v][i];
        if (dfn[u] == 0) {
          stack[++top] = make_pair(v, u);
          dfs(u, v);
          low[v] = min(low[v], low[u]);
          if (low[u] >= dfn[v]) {
            block[++bnum].clear();
            do {
              int l = stack[top].first;
              int r = stack[top].second;
              if (now[l] != bnum) {
                block[bnum].push_back(l);
                now[l] = bnum;
              }
              if (now[r] != bnum) {
                block[bnum].push_back(r);
                now[r] = bnum;
              }
              top--;
            } while (
                !(stack[top + 1].first == v && stack[top + 1].second == u));
            if (v != 1) ge[v] = true;
          }
          if (v == 1)
            if (++son > 1) ge[v] = true;
        } else
          low[v] = min(low[v], dfn[u]);
      }
  }

  int SccNum() {
    memset(dfn, 0, sizeof(dfn));
    memset(ge, 0, sizeof(ge));
    memset(now, 0, sizeof(now));

    sign = top = 0;
    bnum = 0;
    for (int i = 0; i < n; ++i)
      if (dfn[i] == 0) dfs(i, -1);

    int ret = 0;
    for (int i = 1; i <= bnum; ++i) {
      if (block[i].size() > 2) ret++;
    }
    return ret;
  }

  void init() { REP(i, V) adj[i].clear(); }
};
Graph graph;
int n;

void fix(pt& a, pt& b) {
  if (a.x == b.x) {
    if (a.y > b.y) swap(a, b);
  } else {
    if (a.x > b.x) swap(a, b);
  }
}

void MergeSeg(map<int, vector<pair<int, int> > >& mp, int x_or_y, int& cnt) {
  map<int, vector<pair<int, int> > >::iterator it;
  for (it = mp.begin(); it != mp.end(); ++it) {
    vector<pair<int, int> >& vec = it->second;
    int x = it->first, y = it->first;
    sort(vec.begin(), vec.end());
    int lmost, rmost;
    for (int i = 0; i < vec.size(); ++i) {
      if (i == 0) {
        lmost = vec[0].first;
        rmost = vec[0].second;
        continue;
      }
      if (vec[i].first > rmost) {
        if (x_or_y == 0)
          seg[cnt++] = MP(pt(x, lmost), pt(x, rmost));
        else
          seg[cnt++] = MP(pt(lmost, y), pt(rmost, y));
        lmost = vec[i].first;
      }
      rmost = max(rmost, vec[i].second);
    }
    if (rmost > lmost) {
      if (x_or_y == 0)
        seg[cnt++] = MP(pt(x, lmost), pt(x, rmost));
      else
        seg[cnt++] = MP(pt(lmost, y), pt(rmost, y));
    }
  }
}
int MergeSeg() {
  map<int, vector<pair<int, int> > > mp_x, mp_y;
  for (int i = 0; i < n; ++i) {
    if (seg[i].first.x == seg[i].second.x)
      mp_x[seg[i].first.x].PB(MP(seg[i].first.y, seg[i].second.y));
    else if (seg[i].first.y == seg[i].second.y)
      mp_y[seg[i].first.y].PB(MP(seg[i].first.x, seg[i].second.x));
  }

  int cnt = 0;
  MergeSeg(mp_x, 0, cnt);
  MergeSeg(mp_y, 1, cnt);
  return cnt;
}
int main() {
  while (~scanf("%d", &n) && n != 0) {
    REP(i, n) {
      seg[i].first.read();
      seg[i].second.read();
      fix(seg[i].first, seg[i].second);
    }
    n = MergeSeg();
    map<pt, int> index;
    graph.init();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      vector<pt> tmp;
      for (int j = 0; j < n; ++j) {
        if (i != j) {
          if (cross(seg[i].first, seg[i].second, seg[j].first, seg[j].second)) {
            pt c = cross_point(seg[i].first, seg[i].second, seg[j].first,
                               seg[j].second);
            if (index.find(c) == index.end()) index[c] = cnt++;
            tmp.push_back(c);
          }
        }
      }
      sort(tmp.begin(), tmp.end());
      for (int j = 0; j < (int)tmp.size() - 1; ++j) {
        graph.connect(index[tmp[j]], index[tmp[j + 1]]);
      }
    }

    graph.n = cnt;
    Assert(cnt < 10000);
    cout << graph.SccNum() << endl;
  }
}
