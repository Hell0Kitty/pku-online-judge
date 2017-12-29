#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 100

int map[maxn][maxn];
int ans, ansx, ansy;

void input() {
  memset(map, 0, sizeof(map));
  for (int i = 1; i < 20; i++)
    for (int j = 1; j < 20; j++) scanf("%d", &map[i][j]);
}

void work() {
  ans = 0;
  int now;
  now = 0;
  for (int i = 1; i < 20; i++)
    for (int j = 19; j > 0; j--) {
      if (!map[i][j]) {
        now = 0;
        continue;
      }
      if (map[i][j] == map[i][j + 1])
        now++;
      else
        now = 1;
      if (now == 5 && map[i][j - 1] != map[i][j]) {
        ansx = i;
        ansy = j;
        ans = map[i][j];
        return;
      }
    }
  now = 0;
  for (int i = 1; i < 20; i++)
    for (int j = 19; j > 0; j--) {
      if (!map[j][i]) {
        now = 0;
        continue;
      }
      if (map[j][i] == map[j + 1][i])
        now++;
      else
        now = 1;
      if (now == 5 && map[j - 1][i] != map[j][i]) {
        ansx = j;
        ansy = i;
        ans = map[j][i];
        return;
      }
    }
  int x, y;
  now = 0;
  for (int i = 1; i <= 37; i++) {
    x = 19;
    y = i;
    while (x && y) {
      if (!map[x][y]) {
        now = 0;
        x--;
        y--;
        continue;
      }
      if (map[x][y] == map[x + 1][y + 1])
        now++;
      else
        now = 1;
      if (now == 5 && map[x - 1][y - 1] != map[x][y]) {
        ansx = x;
        ansy = y;
        ans = map[x][y];
        return;
      }
      x--;
      y--;
    }
  }
  now = 0;
  for (int i = 1; i <= 37; i++) {
    x = 1;
    y = i;
    while (x < 20 && y) {
      if (!map[x][y]) {
        now = 0;
        x++;
        y--;
        continue;
      }
      if (map[x][y] == map[x - 1][y + 1])
        now++;
      else
        now = 1;
      if (now == 5 && map[x + 1][y - 1] != map[x][y]) {
        ansx = x;
        ansy = y;
        ans = map[x][y];
        return;
      }
      x++;
      y--;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    work();
    if (ans == 0)
      printf("0\n");
    else
      printf("%d\n%d %d\n", ans, ansx, ansy);
  }
  return 0;
}
