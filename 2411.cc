#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int imax_n = 11;
__int64 f[imax_n + 1][1 << imax_n];
int path[10000][2];
int cnt;

int w, h;

void dfs(int x, int y, int col) {
  if (col == w) {
    path[cnt][0] = x;
    path[cnt++][1] = y;
    return;
  }
  dfs(x << 1, (y << 1) + 1, col + 1);
  dfs((x << 1) + 1, y << 1, col + 1);
  if (col + 2 <= w) dfs((x << 2) + 3, (y << 2) + 3, col + 2);
}
void slove() {
  if (w > h) {
    int tmp = w;
    w = h;
    h = tmp;
  }
  cnt = 0;
  dfs(0, 0, 0);
  memset(f, 0, sizeof(f));
  f[0][(1 << w) - 1] = 1;
  for (int i = 1; i <= h; i++) {
    for (int j = 0; j < cnt; j++) {
      f[i][path[j][0]] += f[i - 1][path[j][1]];
    }
  }
  printf("%I64d\n", f[h][(1 << w) - 1]);
}

int main() {
  while (scanf("%d%d", &w, &h), w + h) {
    if (w * h % 2) {
      printf("0\n");
    } else {
      slove();
    }
  }
  return 0;
}
