#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
using namespace std;
typedef struct { int x, y, z; } node;
node a, b;
queue<node> q;
bool f[110][110][110];
int chg[6][3] = {
    {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
void bfs(int x, int y, int z) {
  if (f[x][y][z]) return;
  f[x][y][z] = true;
  a.x = x;
  a.y = y;
  a.z = z;
  q.push(a);
  while (!q.empty()) {
    a = q.front();
    q.pop();
    for (int i = 0; i < 6; i++) {
      b.x = a.x + chg[i][0];
      b.y = a.y + chg[i][1];
      b.z = a.z + chg[i][2];
      if (b.x > 0 && b.x < 101 && b.y > 0 && b.y < 101 && b.z > 0 &&
          b.z < 101 && (!f[b.x][b.y][b.z])) {
        f[b.x][b.y][b.z] = true;
        q.push(b);
      }
    }
  }
}
int main() {
  int t, m, x, y, z, i, j, k, ans;
  scanf("%d", &t);
  while (t--) {
    memset(f, false, sizeof(f));
    scanf("%d", &m);
    while (m--) {
      scanf("%d %d %d", &x, &y, &z);
      f[x][y][z] = true;
    }
    for (i = 1; i < 101; i++)
      for (j = 1; j < 101; j++) {
        bfs(i, j, 1);
        bfs(i, j, 100);
        bfs(i, 1, j);
        bfs(i, 100, j);
        bfs(1, i, j);
        bfs(100, i, j);
      }
    ans = 0;
    for (i = 1; i < 101; i++)
      for (j = 1; j < 101; j++)
        for (k = 1; k < 101; k++) {
          if (!f[i][j][k]) {
            bfs(i, j, k);
            ans++;
          }
        }
    printf("%d\n", ans);
  }
}
