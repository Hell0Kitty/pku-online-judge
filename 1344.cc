#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, go[200][200];
bool vis[200];
bool check(int a, int b, int &sa) {
  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (!vis[i] && i != a && i != b) {
      if (flag) {
        sa = go[a][i] - (go[a][i] + go[b][i] - go[a][b]) / 2;
        flag = false;
      } else if (sa != go[a][i] - (go[a][i] + go[b][i] - go[a][b]) / 2)
        return false;
    }
  }
  return true;
}
int main() {
  // freopen("data.txt","r",stdin);
  while (scanf("%d", &n), n) {
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++) {
      go[i][i] = 0;
      for (int j = i + 1; j < n; j++)
        scanf("%d", &go[i][j]), go[j][i] = go[i][j];
    }
    int ans = 0, sa, a, b;
    while (1) {
      bool flag = false;
      for (a = 0; a < n; a++) {
        if (vis[a]) continue;
        for (b = a + 1; b < n; b++) {
          if (vis[b]) continue;
          if (check(a, b, sa)) {
            flag = true;
            break;
          }
        }
        if (flag) break;
      }
      if (!flag) break;
      ans += go[a][b];
      vis[a] = vis[b] = true;
      for (int j = 0; j < n; j++) {
        if (!vis[j]) go[j][n] = go[n][j] = go[j][a] - sa;
      }
      n++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
