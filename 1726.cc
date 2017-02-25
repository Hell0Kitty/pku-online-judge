#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
const int num[4][4] = {{3, 5, 5, 7}, {5, 3, 7, 5}, {5, 7, 3, 5}, {7, 5, 5, 3}};
using namespace std;
int f[150][6][6][5], lx[150][6][6][5], ly[150][6][6][5], lz[150][6][6][5],
    a[110];
int n, ans, ansx, ansy, ansz;
char s[105];
const char path[3] = {'.', 'L', 'R'};

bool left(int x, int y) { return (x == 1 || x == 2) && y == 0; }
bool right(int x, int y) { return (y == 1 || y == 2) && x == 3; }

void updata(int i, int x, int y, int now) {
  if (x == now || (!left(x, y))) {
    if (f[i + 1][now][y][1] > f[i][x][y][0] + 1) {
      f[i + 1][now][y][1] = f[i][x][y][0] + 1;
      lx[i + 1][now][y][1] = x;
      ly[i + 1][now][y][1] = y;
      lz[i + 1][now][y][1] = 0;
    }
    if (f[i + 1][now][y][1] > f[i][x][y][2] + 1) {
      f[i + 1][now][y][1] = f[i][x][y][2] + 1;
      lx[i + 1][now][y][1] = x;
      ly[i + 1][now][y][1] = y;
      lz[i + 1][now][y][1] = 2;
    }
    if (f[i + 1][now][y][1] > f[i][x][y][1] + num[x][now]) {
      f[i + 1][now][y][1] = f[i][x][y][1] + num[x][now];
      lx[i + 1][now][y][1] = x;
      ly[i + 1][now][y][1] = y;
      lz[i + 1][now][y][1] = 1;
    }
  }
  if (y == now || (!right(x, y))) {
    if (f[i + 1][x][now][2] > f[i][x][y][0] + 1) {
      f[i + 1][x][now][2] = f[i][x][y][0] + 1;
      lx[i + 1][x][now][2] = x;
      ly[i + 1][x][now][2] = y;
      lz[i + 1][x][now][2] = 0;
    }
    if (f[i + 1][x][now][2] > f[i][x][y][1] + 1) {
      f[i + 1][x][now][2] = f[i][x][y][1] + 1;
      lx[i + 1][x][now][2] = x;
      ly[i + 1][x][now][2] = y;
      lz[i + 1][x][now][2] = 1;
    }
    if (f[i + 1][x][now][2] > f[i][x][y][2] + num[y][now]) {
      f[i + 1][x][now][2] = f[i][x][y][2] + num[y][now];
      lx[i + 1][x][now][2] = x;
      ly[i + 1][x][now][2] = y;
      lz[i + 1][x][now][2] = 2;
    }
  }
}

void print(int i, int j, int k, int l) {
  if (i == 0) return;
  int x = lx[i][j][k][l];
  int y = ly[i][j][k][l];
  int z = lz[i][j][k][l];
  print(i - 1, x, y, z);
  printf("%c", path[l]);
}

void solve() {
  n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') a[i + 1] = 4;
    if (s[i] == 'L') a[i + 1] = 0;
    if (s[i] == 'U') a[i + 1] = 1;
    if (s[i] == 'D') a[i + 1] = 2;
    if (s[i] == 'R') a[i + 1] = 3;
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= 4; ++j)
      for (int k = 0; k <= 4; ++k)
        for (int l = 0; l <= 2; ++l) f[i][j][k][l] = 100000000;

  f[0][0][3][0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 4; ++j)
      for (int k = 0; k < 4; ++k)
        if (j != k)
          if (a[i + 1] != 4)
            updata(i, j, k, a[i + 1]);
          else {
            for (int l = 0; l < 4; ++l) updata(i, j, k, l);
            for (int l = 0; l <= 2; ++l)
              if (f[i + 1][j][k][0] > f[i][j][k][l]) {
                f[i + 1][j][k][0] = f[i][j][k][l];
                lx[i + 1][j][k][0] = j;
                ly[i + 1][j][k][0] = k;
                lz[i + 1][j][k][0] = l;
              }
          }
  ans = 100000000;
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      for (int k = 0; k < 3; ++k)
        if (i != j && f[n][i][j][k] < ans) {
          ans = f[n][i][j][k];
          ansx = i;
          ansy = j;
          ansz = k;
        }
  print(n, ansx, ansy, ansz);
  printf("\n");
}

int main() {
  scanf("%s", &s);
  while (s[0] != '#') {
    solve();
    scanf("%s", &s);
  }
}