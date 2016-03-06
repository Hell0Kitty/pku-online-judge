#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAX_ROW 205
#define MAX_COLUMN MAX_ROW

int row, column;
char grid[MAX_ROW][MAX_COLUMN];

void input() {
  memset(grid, 0, sizeof(grid));
  for (int i = 0; i < row; i++) scanf("%s", grid[i]);
}

void work() {
  int direction = -1;  // 1 is right, 0 is left
  int s_cnt = 0;
  int x = 0;
  int y = 0;
  while (grid[x][y] != 'S') y++;
  s_cnt++;
  while (x < row) {
    if (y != 0 && grid[x][y - 1] == 'S') {
      direction = 0;
      while (y > 0 && grid[x][y - 1] == 'S') y--, s_cnt++;
      x++, s_cnt++;
      continue;
    }
    if (y + 1 < column && grid[x][y + 1] == 'S') {
      if (direction == -1) s_cnt--;
      if (direction == 0) s_cnt -= 2;
      direction = 1;
      while (y + 1 < column && grid[x][y + 1] == 'S') y++, s_cnt++;
      x++, s_cnt++;
      continue;
    }
    x++, s_cnt++;
  }
  if (direction == 0) s_cnt--;
  printf("%d\n", s_cnt - 1);
}

int main() {
  while (scanf("%d%d", &row, &column), row | column) {
    input();
    work();
  }
  return 0;
}
