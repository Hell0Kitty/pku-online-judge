#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#define PII pair<int, int>
#define PPP pair<PII, PII>
#define MP make_pair
#define PB push_back
using namespace std;

const int maxn = 107;

int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0}, opp[] = {1, 0, 3, 2};
int n, m;
bool Map[maxn][maxn], use[maxn][maxn], In[maxn][maxn];
int D[maxn][maxn];

bool check_map(int x, int y) {
  if (x < 1 || x > n) return false;
  if (y < 1 || y > n) return false;
  return !use[x][y];
}

queue<PII> Q;

vector<PII> bfs(vector<PII> &zz, int lim) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) use[i][j] = false, D[i][j] = -1;
  while (Q.size()) Q.pop();
  for (int i = 0; i < zz.size(); i++)
    use[zz[i].first][zz[i].second] = true, Q.push(zz[i]);
  vector<PII> res;
  while (Q.size()) {
    int x = Q.front().first, y = Q.front().second;
    Q.pop();
    if (Map[x][y] && !In[x][y]) res.PB(MP(x, y));
    if (res.size() == lim) return res;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (check_map(xx, yy)) {
        use[xx][yy] = true;
        D[xx][yy] = opp[i];
        Q.push(MP(xx, yy));
      }
    }
  }
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(Map, false, sizeof(Map));
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    Map[x][y] = true;
  }
  memset(In, false, sizeof(In));
  vector<PII> zz;
  vector<PPP> ans;
  int x = (n + 1) / 2, y = (n + 1) / 2;
  zz.push_back(MP(x, y));
  if (!Map[x][y]) {
    PII p = bfs(zz, 1)[0];
    Map[p.first][p.second] = false;
    Map[x][y] = true;
    while (D[p.first][p.second] != -1) {
      int d = D[p.first][p.second];
      PII pp = MP(p.first + dx[d], p.second + dy[d]);
      ans.PB(MP(p, pp));
      p = pp;
    }
  }
  In[x][y] = true;
  int sum = 1;
  while (sum < m) {
    vector<PII> cc = bfs(zz, 50);
    sum += cc.size();
    for (int i = 0; i < cc.size(); i++) {
      PII p = cc[i];
      Map[p.first][p.second] = false;
      while (1) {
        int d = D[p.first][p.second];
        PII pp = MP(p.first + dx[d], p.second + dy[d]);
        if (In[pp.first][pp.second]) break;
        ans.PB(MP(p, pp));
        p = pp;
      }
      In[p.first][p.second] = true;
      Map[p.first][p.second] = true;
      zz.push_back(MP(p.first, p.second));
    }
  }
  if (ans.size() > 50000)
    while (1) puts("FUCK");
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d %d %d\n", ans[i].first.first, ans[i].first.second,
           ans[i].second.first, ans[i].second.second);
  return 0;
}
