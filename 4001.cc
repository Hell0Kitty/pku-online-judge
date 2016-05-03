#include <stdio.h>
#include <string.h>
bool vis[11][11];
int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
int d[8][2] = {2, 1, 2, -1, -2, 1, -2, -1, 1, 2, 1, -2, -1, 2, -1, -2};
int dd[8][2] = {1, 0, 1, 0, -1, 0, -1, 0, 0, 1, 0, -1, 0, 1, 0, -1};
int main() {
  int x[8], y[8], kind[8], xx, yy;
  int i, j, u;
  char buf[5];
  int n;
  while (~scanf("%d%d%d", &n, &xx, &yy)) {
    if (!n && !xx && !yy) break;
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < n; i++) {
      scanf("%s%d%d", buf, &x[i], &y[i]);
      if (buf[0] == 'G') kind[i] = 0, u = i;
      if (buf[0] == 'R') kind[i] = 1;
      if (buf[0] == 'H') kind[i] = 2;
      if (buf[0] == 'C') kind[i] = 3;
      vis[x[i]][y[i]] = 1;
    }
    if (u != 0) {
      int tmp;
      tmp = kind[u];
      kind[u] = kind[0];
      kind[0] = tmp;
      tmp = x[u];
      x[u] = x[0];
      x[0] = tmp;
      tmp = y[u];
      y[u] = y[0];
      y[0] = tmp;
    }
    if (y[0] == yy) {
      for (i = xx + 1; i < x[0] && !vis[i][yy]; i++)
        ;
      if (i == x[0]) {
        puts("NO");
        continue;
      }
    }
    bool ok = 0, flag;
    for (i = 0; i < 4; i++) {
      int fx = xx + dir[i][0];
      int fy = yy + dir[i][1];
      if (fx < 1 || fx > 3 || fy < 4 || fy > 6) continue;
      flag = 0;
      for (j = 0; j < n; j++) {
        if (fx == x[j] && fy == y[j]) continue;
        if (kind[j] == 0) {
          if (y[j] == fy) {
            for (u = fx + 1; u < x[j] && !vis[u][fy]; u++)
              ;
            if (u == x[j]) {
              flag = 1;
              break;
            }
          }
        }
        if (kind[j] == 1) {
          if (y[j] == fy) {
            if (fx < x[j]) {
              for (u = fx + 1; u < x[j] && !vis[u][fy]; u++)
                ;
              if (u == x[j]) {
                flag = 1;
                break;
              }
            } else {
              for (u = x[j] + 1; u < fx && !vis[u][fy]; u++)
                ;
              if (u == fx) {
                flag = 1;
                break;
              }
            }
          }
          if (x[j] == fx) {
            if (y[j] < fy) {
              for (u = y[j] + 1; u < fy && !vis[fx][u]; u++)
                ;
              if (u == fy) {
                flag = 1;
                break;
              }
            } else {
              for (u = fy + 1; u < y[j] && !vis[fx][u]; u++)
                ;
              if (u == y[j]) {
                flag = 1;
                break;
              }
            }
          }
        }
        if (kind[j] == 2) {
          for (u = 0; u < 8; u++) {
            int dx = x[j] + d[u][0];
            int dy = y[j] + d[u][1];
            if (dx <= 0 || dx > 10 || dy <= 0 || dy > 9) continue;
            int ddx = x[j] + dd[u][0];
            int ddy = y[j] + dd[u][1];
            if (vis[ddx][ddy]) continue;
            if (dx == fx && dy == fy) {
              flag = 1;
              break;
            }
          }
          if (flag) break;
        }
        if (kind[j] == 3) {
          int cnt = 0;
          if (x[j] == fx) {
            if (y[j] < fy) {
              for (u = y[j] + 1; u < fy; u++)
                if (vis[fx][u]) cnt++;
              if (cnt == 1) {
                flag = 1;
                break;
              }
            } else {
              for (u = fy + 1; u < y[j]; u++)
                if (vis[fx][u]) cnt++;
              if (cnt == 1) {
                flag = 1;
                break;
              }
            }
          }
          if (y[j] == fy) {
            if (x[j] < fx) {
              for (u = x[j] + 1; u < fx; u++)
                if (vis[u][fy]) cnt++;
              if (cnt == 1) {
                flag = 1;
                break;
              }
            } else {
              for (u = fx + 1; u < x[j]; u++)
                if (vis[u][fy]) cnt++;
              if (cnt == 1) {
                flag = 1;
                break;
              }
            }
          }
        }
        if (flag) break;
      }
      if (flag)
        continue;
      else {
        puts("NO");
        ok = 1;
        break;
      }
    }
    if (!ok) puts("YES");
  }
  return 0;
}
