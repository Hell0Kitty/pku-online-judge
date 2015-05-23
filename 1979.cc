#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 22
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
char map[N][N];
int cnt;
int h, w;
bool ok(int x, int y) {
  if (x < 0 || x >= h) return false;
  if (y < 0 || y >= w) return false;
  if (map[x][y] == '#') return false;
  return true;
}
void dfs(int a, int b) {
  cnt++;
  map[a][b] = '#';
  int i;
  int x, y;
  for (i = 0; i < 4; i++) {
    x = a + dir[i][0];
    y = b + dir[i][1];
    if (ok(x, y)) {
      dfs(x, y);
    }
  }
}
int main() {
  int i, j;
  int s, t;
  while (scanf("%d %d", &w, &h), h || w) {
    getchar();
    for (i = 0; i < h; getchar(), i++)
      for (j = 0; j < w; j++) {
        scanf("%c", &map[i][j]);
        if (map[i][j] == '@') s = i, t = j;
      }
    cnt = 0;
    dfs(s, t);
    printf("%d\n", cnt);
  }
  return 0;
}