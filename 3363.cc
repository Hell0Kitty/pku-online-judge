#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 105

int n, m, r, c;
int map[maxn][maxn], vis[maxn][maxn];

void change(int x, int y) {
  for (int i = x; i < x + r; i++)
    for (int j = y; j < y + c; j++) vis[i][j] = 1 - vis[i][j];
}

bool ok() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (map[i][j] != vis[i][j]) return false;
  return true;
}

int main() {
  while (scanf("%d%d%d%d", &n, &m, &r, &c), n | m | r | c) {
    getchar();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char ch = getchar();
        map[i][j] = ch - '0';
      }
      getchar();
    }
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 0; i < n - r + 1; i++)
      for (int j = 0; j < m - c + 1; j++)
        if (map[i][j] != vis[i][j]) {
          change(i, j);
          ans++;
        }
    if (ok())
      printf("%d\n", ans);
    else
      printf("-1\n");
  }
  return 0;
}
