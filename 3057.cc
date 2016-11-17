#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
#include <cmath>
#define INF 0x7fffffff
#define pb push_back
#define pn(x) cerr << x << endl

using namespace std;
typedef long long ll;
typedef pair<int, int> poi;
const int maxv = 15 * 15 * 15 * 15;

vector<int> dx, dy, px, py;
const int dirx[4] = {0, 0, -1, 1};
const int diry[4] = {1, -1, 0, 0};
char mapp[15][15];
int dis[15][15][15][15];
bool used[maxv];
vector<int> G[maxv];
int match[maxv];
int dnum, pnum;
int n;
int T, X, Y;
void bfs(int sx, int sy, int dis[15][15]) {
  dis[sx][sy] = 0;
  queue<int> qx, qy;
  qx.push(sx), qy.push(sy);
  while (!qx.empty()) {
    int x = qx.front(), y = qy.front();
    qx.pop(), qy.pop();
    for (int i = 0; i < 4; i++) {
      int tx = x + dirx[i], ty = y + diry[i];
      if (tx >= 0 && tx < X && ty >= 0 && ty < Y && mapp[tx][ty] == '.' &&
          dis[tx][ty] < 0) {
        qx.push(tx), qy.push(ty);
        dis[tx][ty] = dis[x][y] + 1;
      }
    }
  }
}
bool dfs(int v) {
  used[v] = 1;
  for (int i = 0; i < G[v].size(); i++) {
    int u = G[v][i], w = match[u];
    if (w < 0 || !used[w] && dfs(w)) {
      match[v] = u;
      match[u] = v;
      return 1;
    }
  }
  return 0;
}
void solve() {
  int ans = 0;
  for (int i = 0; i < n * dnum; i++) {
    memset(used, 0, sizeof used);
    if (dfs(i)) ans++;
    if (ans >= pnum) {
      cout << i / dnum + 1 << endl;
      return;
    }
  }
  cout << "impossible" << endl;
  return;
}
int main() {
  // freopen("in.txt","r",stdin);
  //	freopen("out.txt","w",stdout);
  cin >> T;
  while (T--) {
    cin >> X >> Y;
    n = X * Y;
    dx.clear(), dy.clear(), px.clear(), py.clear();
    for (int i = 0; i < maxv; i++) G[i].clear();
    for (int i = 0; i < X; i++)
      for (int j = 0; j < Y; j++) {
        cin >> mapp[i][j];
        if (mapp[i][j] == 'D')
          dx.pb(i), dy.pb(j);
        else if (mapp[i][j] == '.')
          px.pb(i), py.pb(j);
      }
    memset(dis, -1, sizeof dis);
    for (int i = 0; i < dx.size(); i++)
      bfs(dx[i], dy[i], dis[dx[i]][dy[i]]);  ////OK
    memset(match, -1, sizeof match);
    dnum = dx.size(), pnum = px.size();
    for (int i = 0; i < px.size(); i++) {
      for (int j = 0; j < dx.size(); j++) {
        if (dis[dx[j]][dy[j]][px[i]][py[i]] >= 0) {
          for (int k = dis[dx[j]][dy[j]][px[i]][py[i]]; k <= n; k++) {
            G[(k - 1) * dnum + j].pb(i + n * dnum);
          }
        }
      }
    }
    solve();
  }
  return 0;
}
