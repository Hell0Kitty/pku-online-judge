#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 1010

vector<vector<int> > G_from;
vector<vector<int> > G_to;
bool map[MAXN][MAXN];

int main() {
  int n, m, u, v, ans;
  while (~scanf("%d%d", &n, &m)) {
    G_from.clear();
    G_from.resize(n + 2);
    G_to.clear();
    G_to.resize(n + 2);
    memset(map, false, sizeof(map));
    while (m--) {
      scanf("%d%d", &u, &v);
      map[u][v] = true;
      G_from[v].push_back(u);
      G_to[u].push_back(v);
    }
    ans = 0;
    for (int k = 1; k <= n; k++) {
      for (int i = 0; i < G_from[k].size(); i++) {
        for (int j = 0; j < G_to[k].size(); j++) {
          u = G_from[k][i], v = G_to[k][j];
          if (!map[u][v]) {
            map[u][v] = true;
            G_from[v].push_back(u);
            G_to[u].push_back(v);
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        if (i != j) {
          if (map[i][j]) ans++;
        }
    }
    printf("%d\n", n * (n - 1) / 2 - ans);
  }
  return 0;
}
