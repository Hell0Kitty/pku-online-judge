#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxd = 10 + 5;
typedef long long ll;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int mz[maxd][maxd], visr[maxd][maxd], visc[maxd][maxd], grid[maxd][maxd];
char m[maxd][maxd];
int row[maxd], col[maxd];
void init() {
  mem(visr, 0), mem(visc, 0), mem(grid, 0);
  mem(row, 0), mem(col, 0);
  for (int i = 0; i < 9; ++i) {
    scanf("%s", m[i]);
    for (int j = 0; j < 9; ++j) {
      mz[i][j] = m[i][j] - '0';
      visr[i][mz[i][j]] = 1;
      visc[j][mz[i][j]] = 1;
      if (mz[i][j] != 0) row[i]++, col[j]++;
      int tmp = i / 3 * 3 + j / 3;
      grid[tmp][mz[i][j]] = 1;
    }
  }
  for (int i = 0; i < 9; ++i)
    if (row[i] == 8) {
      int j;
      for (j = 0; j < 9; ++j)
        if (mz[i][j] == 0) break;

      for (int k = 1; k <= 9; ++k)
        if (visr[i][k] == 0) {
          mz[i][j] = k;
          visr[i][k] = 1;
          visc[j][k] = 1;
          int tmp = i / 3 * 3 + j / 3;
          grid[tmp][k] = 1;
          break;
        }
    }

  for (int j = 0; j < 9; ++j)
    if (col[j] == 8) {
      int i;
      for (i = 0; i < 9; ++i)
        if (mz[i][j] == 0) break;

      for (int k = 1; k <= 9; ++k)
        if (visc[j][k] == 0) {
          mz[i][j] = k;
          visc[j][k] = 1;
          visr[i][k] = 1;
          int tmp = i / 3 * 3 + j / 3;
          grid[tmp][k] = 1;
          break;
        }
    }
}

bool dfs(int x, int y) {
  // if(!setnum(x,y)) return;
  if (x == 9) return true;
  bool flag = false;
  if (mz[x][y] == 0) {
    int tmp = x / 3 * 3 + y / 3;
    for (int i = 1; i <= 9; ++i)
      if (visr[x][i] == 0 && visc[y][i] == 0 && grid[tmp][i] == 0) {
        mz[x][y] = i;
        visr[x][i] = 1;
        visc[y][i] = 1;
        grid[tmp][i] = 1;
        if (y == 8)
          flag = dfs(x + 1, 0);
        else
          flag = dfs(x, y + 1);

        if (flag)
          return true;
        else {
          mz[x][y] = 0;
          visr[x][i] = 0;
          visc[y][i] = 0;
          grid[tmp][i] = 0;
        }
      }
  } else {
    if (y == 8)
      flag = dfs(x + 1, 0);
    else
      flag = dfs(x, y + 1);

    if (flag)
      return true;
    else
      return false;
  }
  return false;
}

void print(int k) {
  printf("Scenario #%d:\n", k);
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) printf("%d", mz[i][j]);
    printf("\n");
  }
  printf("\n");
}

int main() {
  int kase;
  scanf("%d", &kase);
  for (int k = 1; k <= kase; ++k) {
    init();
    dfs(0, 0);
    print(k);
  }
  return 0;
}
