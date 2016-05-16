#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 10010;
struct event {
  int t, c;
  event() {}
  event(int a, int b) : t(a), c(b) {}
  bool operator<(const event &rhs) const { return t < rhs.t; }
};
vector<event> v1[maxn], v2[maxn];
int k, n, c, num[2][maxn], ans;
int work(vector<event> vv[], int k) {
  priority_queue<event> que;
  int res = 0, tmp = 0;
  for (int i = 1; i <= n; i++) {
    res += num[k][i];
    tmp -= num[k][i];
    for (int j = 0; j < vv[i].size(); j++) {
      tmp += vv[i][j].c;
      que.push(vv[i][j]);
    }
    while (tmp > c) {
      event tt = que.top();
      que.pop();
      if (tmp - c >= tt.c) {
        tmp -= tt.c;
        num[k][tt.t] -= tt.c;
      } else {
        num[k][tt.t] -= (tmp - c);
        tt.c -= (tmp - c);
        tmp = c;
        que.push(tt);
      }
    }
  }
  return res;
}
void solve() {
  memset(num, 0, sizeof(num));
  for (int i = 0; i < maxn; i++) {
    v1[i].clear();
    v2[i].clear();
  }
  for (int i = 0; i < k; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (x < y) {
      v1[x].push_back(event(y, z));
      num[0][y] += z;
    } else {
      x = n - x + 1;
      y = n - y + 1;
      v2[x].push_back(event(y, z));
      num[1][y] += z;
    }
  }
  ans = 0;
  ans += work(v1, 0);
  ans += work(v2, 1);
  printf("%d\n", ans);
  return;
}
int main() {
  while (scanf("%d%d%d", &k, &n, &c) == 3) solve();
  return 0;
}
