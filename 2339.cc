#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 100 + 10;
char a[MAXN][MAXN], b[MAXN][MAXN];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int n, m, l;
void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[i][j] = a[i][j];
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (0 <= x && x < n && 0 <= y && y < m) {
          char ac = a[i][j], bc = a[x][y];
          if (bc == 'R' && ac == 'S') b[i][j] = 'R';
          if (bc == 'S' && ac == 'P') b[i][j] = 'S';
          if (bc == 'P' && ac == 'R') b[i][j] = 'P';
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) a[i][j] = b[i][j];
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cin >> n >> m >> l;
    getchar();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) a[i][j] = getchar();
      getchar();
    }
    while (l--) {
      solve();
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) putchar(a[i][j]);
      putchar(10);
    }
    if (t) putchar(10);
  }
  return 0;
}
