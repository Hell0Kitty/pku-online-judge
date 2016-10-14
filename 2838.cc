#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 1005;
const int M = 20005;
struct arr {
  int y, nex;
} g[M * 2];
int n, sz, pos[N], q;
bool h[N][N], v[N];
void init(int x, int y) {  // cout<<x<<" "<<y<<endl;
  g[++sz].y = y;
  g[sz].nex = pos[x];
  pos[x] = sz;
}
void dfs(int x) {  // cout<<x<<" --------"<<endl;
  v[x] = 1;
  for (int i = pos[x]; i; i = g[i].nex) {
    int y = g[i].y;
    if (v[y] || !h[x][y]) continue;
    dfs(y);
  }
}
int main() {
  char c;
  int x, y;
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    scanf(" %c %d%d", &c, &x, &y);
    if (c == 'Q') {
      memset(v, 0, sizeof(v));
      dfs(x);
      if (v[y])
        printf("Y\n");
      else
        printf("N\n");
    } else if (c == 'I') {
      h[x][y] = h[y][x] = 1;
      init(x, y), init(y, x);
    } else {
      h[x][y] = h[y][x] = 0;
    }
  }

  return 0;
}
