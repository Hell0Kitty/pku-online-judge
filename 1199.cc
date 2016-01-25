#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char mg[120][120];
int n, m;
int tx, ty, sx, sy;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool dir[120][120][4];
bool vis[120][120];
bool ans;
struct point {
  int x, y;
};
point pp[10000];
bool isok(int x, int y) {
  if (x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1)
    return true;
  else
    return false;
}
bool isok2(int x, int y) {
  if (x >= 1 && x <= n && y >= 1 && y <= m)
    return true;
  else
    return false;
}
bool istrue(int x, int y) {
  if (isok2(x + 1, y + 1) && mg[x + 1][y] == '.' && mg[x + 1][y + 1] == '.' &&
      mg[x][y + 1] == '.')
    return true;
  if (isok2(x - 1, y - 1) && mg[x - 1][y] == '.' && mg[x - 1][y - 1] == '.' &&
      mg[x][y - 1] == '.')
    return true;
  if (isok2(x - 1, y + 1) && mg[x - 1][y] == '.' && mg[x - 1][y + 1] == '.' &&
      mg[x][y + 1] == '.')
    return true;
  if (isok2(x + 1, y - 1) && mg[x][y - 1] == '.' && mg[x + 1][y - 1] == '.' &&
      mg[x + 1][y] == '.')
    return true;
  return false;
}
void bfs() {
  int front = 0, rear = 0;
  point st;
  st.x = 0, st.y = 0;
  vis[0][0] = true;
  mg[st.x][st.y] = '*';
  pp[rear++] = st;
  point tp;
  while (front < rear) {
    tp = pp[front++];
    if ((mg[tp.x - 1][tp.y] == '#' && mg[tp.x + 1][tp.y] == '#') ||
        (mg[tp.x][tp.y - 1] == '#' && mg[tp.x][tp.y + 1] == '#')) {
      sx = tp.x;
      sy = tp.y;
      return;
    }
    mg[tp.x][tp.y] = '*';
    for (int i = 0; i < 4; ++i) {
      int xx = tp.x + dx[i];
      int yy = tp.y + dy[i];
      if (isok(xx, yy)) {
        if (!vis[xx][yy] && mg[xx][yy] == '.') {
          point temp;
          temp.x = xx;
          temp.y = yy;
          vis[xx][yy] = true;
          pp[rear++] = temp;
        }
      }
    }
  }
}
void dfs(int x, int y, int d) {
  if (ans == true) return;

  if (istrue(x, y)) {
    ans = true;
  } else {
    for (int i = 3; i <= 6; ++i) {
      int td = (d + i) % 4;

      if (isok2(x + dx[td], y + dy[td]) && dir[x][y][td] == false &&
          mg[x + dx[td]][y + dy[td]] == '.') {
        dir[x][y][td] = true;
        dfs(x + dx[td], y + dy[td], td);
        break;
      }
    }
  }
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(vis, false, sizeof(vis));
    memset(mg, '.', sizeof(mg));

    getchar();
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%c", &mg[i][j]);
      }
      getchar();
    }
    bfs();

    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        if (mg[i][j] == '*') mg[i][j] = '#';
      }
    }

    memset(dir, false, sizeof(dir));
    ans = false;
    dfs(sx, sy, 0);
    if (ans)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
