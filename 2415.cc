#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
struct node {
  int x, y, z;
};
int vis[52][52][52], n;
char map[52][52];
int bfs(struct node start) {
  queue<struct node> q;
  memset(vis, 0, sizeof(vis));
  q.push(start);
  vis[start.x][start.y][start.z] = 1;
  while (!q.empty()) {
    struct node tmp = q.front();
    q.pop();
    if (tmp.x == tmp.y && tmp.y == tmp.z) return vis[tmp.x][tmp.y][tmp.z] - 1;
    for (int i = 1; i <= n; i++) {
      if (vis[i][tmp.y][tmp.z] == 0 && map[tmp.x][i] == map[tmp.y][tmp.z]) {
        vis[i][tmp.y][tmp.z] = vis[tmp.x][tmp.y][tmp.z] + 1;
        struct node cur = tmp;
        cur.x = i;
        q.push(cur);
      }
      if (vis[tmp.x][i][tmp.z] == 0 && map[tmp.y][i] == map[tmp.x][tmp.z]) {
        vis[tmp.x][i][tmp.z] = vis[tmp.x][tmp.y][tmp.z] + 1;
        struct node cur = tmp;
        cur.y = i;
        q.push(cur);
      }
      if (vis[tmp.x][tmp.y][i] == 0 && map[tmp.z][i] == map[tmp.x][tmp.y]) {
        vis[tmp.x][tmp.y][i] = vis[tmp.x][tmp.y][tmp.z] + 1;
        struct node cur = tmp;
        cur.z = i;
        q.push(cur);
      }
    }
  }
  return -1;
}
int main() {
  int i, j, r;
  struct node start;
  while (scanf("%d", &n), n) {
    scanf("%d %d %d", &start.x, &start.y, &start.z);
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) scanf(" %c", &map[i][j]);
    r = bfs(start);
    if (r != -1)
      printf("%d\n", r);
    else
      printf("impossible\n");
  }
  return 0;
}
