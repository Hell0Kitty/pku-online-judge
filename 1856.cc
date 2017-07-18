#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int maxx, maxy, minx, miny, r, c;
char map[1200][1200];
bool check(int x, int y) {
  return x >= 0 && y >= 0 && x < r && y < c && map[x][y] == '#';
}
int dfs(int x, int y) {
  minx = min(minx, x);
  miny = min(miny, y);
  maxx = max(maxx, x);
  maxy = max(maxy, y);
  map[x][y] = '.';
  int ret = 1;
  for (int i = -1; i <= 1; i++)
    for (int j = -1; j <= 1; j++)
      if (check(x + i, y + j)) ret += dfs(x + i, y + j);
  return ret;
}
int main() {
  while (scanf("%d%d", &r, &c), (r || c)) {
    for (int i = 0; i < r; i++) scanf(" %s", map[i]);
    int ans = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (map[i][j] == '#') {
          minx = maxx = i;
          miny = maxy = j;
          int ret = dfs(i, j);
          if (ret == (maxx - minx + 1) * (maxy - miny + 1))
            ans++;
          else {
            ans = -1;
            i = r;
            break;
          }
        }
      }
    }
    if (ans == -1)
      printf("Bad placement.\n");
    else
      printf("There are %d ships.\n", ans);
  }
  return 0;
}
