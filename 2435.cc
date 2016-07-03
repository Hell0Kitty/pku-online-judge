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
char mp[105][105], d[6] = {'A', 'N', 'S', 'W', 'E'};
bool vis[105][105];
pii s, t, pre[105][105], x, ans[5005];
int cnt = 0, tot = 0;
int dir[105][105], tans[5005];
int main() {
  int i, j, n, m;
  cin >> n >> m;
  n = n * 2 - 1, m = m * 2 - 1;
  for (i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (mp[i][j] == 'S')
        s.fi = i, s.se = j;
      else if (mp[i][j] == 'E')
        t.fi = i, t.se = j;
    }
  }
  queue<pii> q;
  q.push(s);
  vis[s.fi][s.se] = 1;
  while (1) {
    if (q.empty())
      while (1)
        ;
    x = q.front();
    q.pop();
    if (x.fi > 1 && mp[x.fi - 1][x.se] == '|')
      if (!vis[x.fi - 2][x.se]) {
        q.push(make_pair(x.fi - 2, x.se));
        vis[x.fi - 2][x.se] = 1;
        pre[x.fi - 2][x.se] = x;
        dir[x.fi - 2][x.se] = 1;
        if (x.fi - 2 == t.fi && x.se == t.se) break;
      }
    if (x.fi < n && mp[x.fi + 1][x.se] == '|')
      if (!vis[x.fi + 2][x.se]) {
        q.push(make_pair(x.fi + 2, x.se));
        vis[x.fi + 2][x.se] = 1;
        pre[x.fi + 2][x.se] = x;
        dir[x.fi + 2][x.se] = 2;
        if (x.fi + 2 == t.fi && x.se == t.se) break;
      }
    if (x.se > 1 && mp[x.fi][x.se - 1] == '-')
      if (!vis[x.fi][x.se - 2]) {
        q.push(make_pair(x.fi, x.se - 2));
        vis[x.fi][x.se - 2] = 1;
        pre[x.fi][x.se - 2] = x;
        dir[x.fi][x.se - 2] = 3;
        if (x.fi == t.fi && x.se - 2 == t.se) break;
      }
    if (x.se < m && mp[x.fi][x.se + 1] == '-')
      if (!vis[x.fi][x.se + 2]) {
        q.push(make_pair(x.fi, x.se + 2));
        vis[x.fi][x.se + 2] = 1;
        pre[x.fi][x.se + 2] = x;
        dir[x.fi][x.se + 2] = 4;
        if (x.fi == t.fi && x.se + 2 == t.se) break;
      }
  }
  for (x = t; x != s; x = pre[x.fi][x.se]) tans[++tot] = dir[x.fi][x.se];
  reverse(tans + 1, tans + 1 + tot);
  for (i = 1; i <= tot; i++) {
    if (tans[i] != tans[i - 1]) {
      ans[++cnt].fi = tans[i];
      ans[cnt].se = 1;
    } else
      ans[cnt].se++;
  }
  for (i = 1; i <= cnt; i++) printf("%c %d\n", d[ans[i].fi], ans[i].se);
  return 0;
}
