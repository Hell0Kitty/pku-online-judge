
#include <iostream>
using namespace std;

#define maxn 105
int nx, ny, jobnum;
int g[maxn][maxn];
int ans;
int sx[maxn], sy[maxn];
int cx[maxn], cy[maxn];
int path(int u) {
  sx[u] = 1;
  int v, i;
  for (v = 1; v <= ny; v++)
    if ((g[u][v] > 0) && (!sy[v])) {
      sy[v] = 1;
      if ((!cy[v]) || (path(cy[v]))) {
        cx[u] = v;
        cy[v] = u;
        return 1;
      }
    }
  return 0;
}

void solve() {
  ans = 0;
  int i, j;
  memset(cx, 0, sizeof(cx));
  memset(cy, 0, sizeof(cy));
  for (i = 1; i <= nx; i++)
    if (!cx[i]) {
      memset(sx, 0, sizeof(sx));
      memset(sy, 0, sizeof(sy));
      ans += path(i);
    }
}
int main() {
  int i, j, k, l;
  while (cin >> nx, nx > 0) {
    cin >> ny >> jobnum;
    if (cin.fail()) return 0;
    memset(g, 0, sizeof(g));
    for (k = 0; k < jobnum; k++) {
      cin >> l >> i >> j;
      g[i][j] = 1;
    }
    solve();
    cout << ans << endl;
  }
  return 0;
}
