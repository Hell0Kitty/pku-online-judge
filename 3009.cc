#include <stdio.h>
#include <string.h>
int map[105][105], si, sj, ei, ej, w, h;  // 1 right    2 down    3 left   4 up
int flag, t, dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}, mini;
int check(int x, int y) {
  if (x <= 0 || y <= 0 || x > h || y > w) return 0;
  return 1;
}
void dfs(int x, int y, int cnt, int turn, int speed) {
  //	printf("%d %d ****\n",x,y);

  if (check(x, y) == 0) {
    flag = 1;
    return;
  }
  if (x == ei && y == ej) {
    if (mini > cnt) mini = cnt;
    flag = 1;
    t = cnt;
    return;
  }
  //	printf("%d %d %d\n",x,y,speed);
  if (cnt > 10) return;
  if (speed == 0) {
    for (int i = 0; i < 4; i++) {
      int fx = x + dir[i][0];
      int fy = y + dir[i][1];
      if (map[fx][fy] == 1) continue;
      dfs(fx, fy, cnt + 1, i + 1, 1);
    }

  } else {
    if (turn == 1) {
      if (map[x][y + 1] == 1) {
        map[x][y + 1] = 0;
        dfs(x, y, cnt, 1, 0);
        map[x][y + 1] = 1;
      } else
        dfs(x, y + 1, cnt, 1, 1);
    }
    if (turn == 2) {
      if (map[x + 1][y] == 1) {
        map[x + 1][y] = 0;
        dfs(x, y, cnt, 2, 0);
        map[x + 1][y] = 1;
      } else
        dfs(x + 1, y, cnt, 2, 1);
    }
    if (turn == 3) {
      if (map[x][y - 1] == 1) {
        map[x][y - 1] = 0;
        dfs(x, y, cnt, 3, 0);
        map[x][y - 1] = 1;
      } else
        dfs(x, y - 1, cnt, 3, 1);
    }
    if (turn == 4) {
      if (map[x - 1][y] == 1) {
        map[x - 1][y] = 0;
        dfs(x, y, cnt, 4, 0);
        map[x - 1][y] = 1;
      } else
        dfs(x - 1, y, cnt, 4, 1);
    }
  }
  if (flag && speed)
    return;
  else if (flag && speed == 0)
    flag = 0;
}
int main() {
  int i, j, k;
  while (scanf("%d%d", &w, &h) != EOF) {
    if (w == 0 && h == 0) break;
    memset(map, 0, sizeof(map));
    flag = 0;
    mini = 99999999;
    for (i = 1; i <= h; i++)
      for (j = 1; j <= w; j++) {
        scanf("%d", &map[i][j]);
        if (map[i][j] == 2) {
          si = i;
          sj = j;
        }
        if (map[i][j] == 3) {
          ei = i;
          ej = j;
        }
      }
    dfs(si, sj, 0, 1, 0);
    if (mini < 99999999)
      printf("%d\n", mini);
    else
      printf("-1\n");
  }
  return 0;
}
