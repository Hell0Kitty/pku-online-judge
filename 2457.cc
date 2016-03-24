#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstdlib>
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
vector<int> G[1005];
int pre[1005], d[1005], ans[1005], tot = 0;
bool vis[1005];
int main() {
  int n, k, a, b, i;
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
  }
  pre[1] = 0;
  d[1] = 1;
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  int x, len, v;
  while (!q.empty()) {
    x = q.front();
    q.pop();
    len = G[x].size();
    for (i = 0; i < len; i++) {
      v = G[x][i];
      if (!vis[v]) {
        q.push(v);
        pre[v] = x;
        d[v] = d[x] + 1;
        vis[v] = 1;
        if (v == k) break;
      }
    }
    if (vis[k]) break;
  }
  if (!vis[k])
    printf("-1\n");
  else {
    printf("%d\n", d[k]);
    for (i = k; i; i = pre[i]) ans[++tot] = i;
    reverse(ans + 1, ans + 1 + tot);
    for (i = 1; i <= tot; i++) printf("%d\n", ans[i]);
  }
  return 0;
}
