#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#define ULL unsigned long long
#define LL long long
#define INF 0x7fffffff
#define MAXN 1000 + 3
using namespace std;

int start, aim;
int w, h, G[MAXN][MAXN];
int dshru[MAXN][MAXN], daim[MAXN][MAXN];
int mov[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool vis[MAXN][MAXN];
void bfs1(int x, int y) {
  int u = x * w + y;
  vis[x][y] = true;
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    x = u / w;
    y = u % w;
    for (int i = 0; i < 4; i++) {
      int dx = x + mov[i][0];
      int dy = y + mov[i][1];
      if (dx >= 0 && dx < h && dy >= 0 && dy < w && G[dx][dy] != 1 &&
          !vis[dx][dy]) {
        int v = dx * w + dy;
        q.push(v);
        vis[dx][dy] = true;
        dshru[dx][dy] = dshru[x][y] + 1;
      }
    }
  }
}
void bfs2(int x, int y) {
  int u = x * w + y;
  vis[x][y] = true;
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    x = u / w;
    y = u % w;
    for (int i = 0; i < 4; i++) {
      int dx = x + mov[i][0];
      int dy = y + mov[i][1];
      if (dx >= 0 && dx < h && dy >= 0 && dy < w && G[dx][dy] != 1 &&
          !vis[dx][dy]) {
        int v = dx * w + dy;
        q.push(v);
        vis[dx][dy] = true;
        daim[dx][dy] = daim[x][y] + 1;
      }
    }
  }
}
int main() {
  scanf("%d%d", &w, &h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%d", &G[i][j]);
      dshru[i][j] = 100000;
      daim[i][j] = 100000;
      if (G[i][j] == 2)
        start = i * w + j;
      else if (G[i][j] == 3)
        aim = i * w + j;
    }
  }
  memset(vis, false, sizeof(vis));
  dshru[start / w][start % w] = 0;
  bfs1(start / w, start % w);
  memset(vis, false, sizeof(vis));
  daim[aim / w][aim % w] = 0;
  bfs2(aim / w, aim % w);
  int _min = INF;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++)
      if (G[i][j] == 4) _min = min(_min, dshru[i][j] + daim[i][j]);
  }
  printf("%d\n", _min);
  return 0;
}
