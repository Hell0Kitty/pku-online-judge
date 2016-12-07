#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1010;
bool vis[maxn][maxn];
int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
struct Node {
  int x, y, step;
};
int X, Y, n;
void bfs() {
  Node u, v;
  queue<Node> Q;
  u.x = 0;
  u.y = 0;
  u.step = 0;
  Q.push(u);
  vis[0 + 500][0 + 500] = 1;
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    if (u.x == X && u.y == Y) {
      printf("%d\n", u.step);
      return;
    }
    for (int i = 0; i < 4; i++) {
      int x = u.x + dir[i][0];
      int y = u.y + dir[i][1];
      if (vis[x + 500][y + 500]) continue;
      vis[x + 500][y + 500] = 1;
      v.x = x;
      v.y = y;
      v.step = u.step + 1;
      Q.push(v);
    }
  }
}
int main() {
  while (~scanf("%d%d%d", &X, &Y, &n)) {
    memset(vis, 0, sizeof(vis));
    while (n--) {
      int u, v;
      scanf("%d%d", &u, &v);
      vis[u + 500][v + 500] = 1;
    }
    bfs();
  }
  return 0;
}
