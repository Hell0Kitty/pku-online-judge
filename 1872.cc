#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000000
struct node {
  int x, y;
  int up, to;
} q[MAXN], st;
int fa[MAXN];
bool vis[11][11][7][7];
int map[11][11];
int dir[7][7][4];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int right[7][7];
int n, m;
bool isok(int up, int x, int y) {
  if (!(x >= 1 && x <= n && y >= 1 && y <= m && map[x][y])) return false;
  if (map[x][y] == -1) return true;
  if (map[x][y] != up) return false;
  return true;
}
void change(node &tt, int d) {
  if (d == 0) {
    int tmp = tt.up;
    tt.up = tt.to;
    tt.to = 7 - tmp;
  } else if (d == 1) {
    int tmp = tt.to;
    tt.to = tt.up;
    tt.up = 7 - tmp;
  } else if (d == 2) {
    tt.up = right[tt.up][tt.to];
  } else if (d == 3) {
    tt.up = 7 - right[tt.up][tt.to];
  }
}
int num;
void print(int k) {
  if (k == 0) return;
  print(fa[k]);
  num++;
  if (num != 9)
    printf(",(%d,%d)", q[k].x, q[k].y);
  else {
    printf(",\n  (%d,%d)", q[k].x, q[k].y);
    num = 0;
  }
}
void bfs() {
  int rear = 0, front = 0;
  node tmp, tt;
  fa[0] = -1;
  q[rear++] = st;
  while (front < rear) {
    tmp = q[front];
    for (int i = 0; i < 4; i++) {
      int nx = tmp.x + dx[i];
      int ny = tmp.y + dy[i];
      if (isok(tmp.up, nx, ny)) {
        tt = tmp;
        tt.x = nx;
        tt.y = ny;
        change(tt, i);
        if (!vis[tt.x][tt.y][tt.up][tt.to]) {
          fa[rear] = front;
          q[rear++] = tt;
          if (tt.x == st.x && tt.y == st.y) {
            printf("  (%d,%d)", st.x, st.y);
            print(rear - 1);
            putchar(10);
            return;
          }
          vis[tt.x][tt.y][tt.up][tt.to] = 1;
        }
      }
    }
    front++;
  }
  printf("  No Solution Possible\n");
}
int main() {
  right[1][2] = 3;
  right[1][3] = 5;
  right[1][4] = 2;
  right[1][5] = 4;
  right[2][1] = 4;
  right[2][3] = 1;
  right[2][6] = 3;
  right[2][4] = 6;
  right[3][1] = 2;
  right[3][5] = 1;
  right[3][6] = 5;
  right[3][2] = 6;
  right[4][1] = 5;
  right[4][2] = 1;
  right[4][6] = 2;
  right[4][5] = 6;
  right[5][1] = 3;
  right[5][4] = 1;
  right[5][6] = 4;
  right[5][3] = 6;
  right[6][2] = 4;
  right[6][3] = 2;
  right[6][5] = 3;
  right[6][4] = 5;
  char name[50];
  while (scanf("%s", &name) && strcmp(name, "END") != 0) {
    num = 0;
    scanf("%d%d%d%d%d%d", &n, &m, &st.x, &st.y, &st.up, &st.to);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        scanf("%d", &map[i][j]);
      }
    memset(vis, 0, sizeof(vis));
    puts(name);
    bfs();
  }
  return 0;
}
