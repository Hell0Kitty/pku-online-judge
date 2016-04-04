#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define SZ(v) ((int)(v).size())
const int maxint = -1u >> 1;
const int maxn = 11 + 1;
const int INF = 1000000000;

int n;
int bc, wc, cc;
int WS, we, bs, be;
int f[maxn][maxn][1 << maxn];
bool used[maxn][maxn][1 << maxn];
vector<int> v[maxn];
char s[maxn];

struct node {
  int x1, x2, sta;
  node() {}
  node(int _x1, int _x2, int _sta) : x1(_x1), x2(_x2), sta(_sta) {}
  bool operator<(const node &a) const {
    return f[x1][x2][sta] > f[a.x1][a.x2][a.sta];
  }
};

int work() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < (1 << n); ++k) {
        f[i][j][k] = INF;
        used[i][j][k] = false;
      }
    }
  }
  priority_queue<node> que;
  que.push(node(bs, WS, 1 << bs));
  used[bs][WS][1 << bs] = true;
  f[bs][WS][1 << bs] = 0;
  while (!que.empty()) {
    node top = que.top();
    que.pop();
    used[top.x1][top.x2][top.sta] = false;
    for (int i = 0; i < (int)v[top.x1].size(); ++i) {
      int x1 = v[top.x1][i], x2 = top.x2, sta = top.sta | (1 << x1);
      if (x1 == x2) continue;
      int c = bc;
      if ((top.sta & (1 << x1)) == 0) c = bc * 2;
      if (f[x1][x2][sta] > f[top.x1][top.x2][top.sta] + c) {
        f[x1][x2][sta] = f[top.x1][top.x2][top.sta] + c;
        if (!used[x1][x2][sta]) {
          used[x1][x2][sta] = true;
          que.push(node(x1, x2, sta));
        }
      }
    }
    for (int i = 0; i < (int)v[top.x2].size(); ++i) {
      int x1 = top.x1, x2 = v[top.x2][i],
          sta = (top.sta | (1 << x2)) ^ (1 << x2);
      if (x1 == x2) continue;
      int c = wc;
      if ((top.sta & (1 << x2)) != 0) c = wc * 2;
      if (f[x1][x2][sta] > f[top.x1][top.x2][top.sta] + c) {
        f[x1][x2][sta] = f[top.x1][top.x2][top.sta] + c;
        if (!used[x1][x2][sta]) {
          used[x1][x2][sta] = true;
          que.push(node(x1, x2, sta));
        }
      }
    }
    for (int i = 0; i < (int)v[top.x1].size(); ++i) {
      for (int j = 0; j < (int)v[top.x2].size(); ++j) {
        int x1 = v[top.x1][i], x2 = v[top.x2][j],
            sta = (top.sta | (1 << x1) | (1 << x2)) ^ (1 << x2);
        if (x1 == x2) continue;
        int c = cc;
        if ((top.sta & (1 << x1)) == 0) c *= 2;
        if ((top.sta & (1 << x2)) != 0) c *= 2;
        if (f[x1][x2][sta] > f[top.x1][top.x2][top.sta] + c) {
          f[x1][x2][sta] = f[top.x1][top.x2][top.sta] + c;
          if (!used[x1][x2][sta]) {
            used[x1][x2][sta] = true;
            que.push(node(x1, x2, sta));
          }
        }
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < (1 << n); ++i) {
    ans = min(ans, f[be][we][i]);
  }
  return ans;
}
int main() {
  int t, ca = 0;
  scanf("%d", &t);
  while (t--) {
    printf("Case #%d: ", ++ca);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      v[i].clear();
      for (int j = 0; j < n; ++j) {
        if (i != j && s[j] == '1') v[i].push_back(j);
      }
    }
    scanf("%d%d%d", &wc, &bc, &cc);
    scanf("%d%d%d%d", &WS, &we, &bs, &be);
    int ans = work();
    if (ans == INF)
      printf("Stalemate\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
