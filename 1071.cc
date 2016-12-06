#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 101;
const int M = 10005;
int mp[N][N];
bool flag[N][N], ok;
int dir[M][3];
char str[4];
int n, m, num, l, r, d, u;
int di[5][2] = {{0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void init() {
  int i, j, a, b;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) scanf("%d", &mp[i][j]);
  }
  num = 0;
  int rr, dd;
  rr = dd = 0;
  l = r = d = u = 0;
  while (scanf("%d%d", &dir[num][0], &dir[num][1]),
         (dir[num][0] + dir[num][1])) {
    scanf("%s", str);
    switch (*str) {
      case 'L':
        dir[num][2] = 1;
        rr -= dir[num][0];
        l = min(l, rr);
        break;
      case 'R':
        dir[num][2] = 2;
        rr += dir[num][0];
        r = max(r, rr);
        break;
      case 'U':
        dir[num][2] = 3;
        dd -= dir[num][0];
        u = min(u, dd);
        break;
      case 'D':
        dir[num][2] = 4;
        dd += dir[num][0];
        d = max(d, dd);
        break;
    }
    num++;
  }
  l = -l;
  u = -u;
}

bool isok(int x, int y) { return (x >= 1 && y >= 1 && x <= n && y <= m); }

void dfs(int cx, int cy, int id) {
  if (ok) return;
  if (id == num) {
    ok = true;
    return;
  }
  int i, tx, ty;
  for (i = 1; i < dir[id][0]; i++) {
    tx = cx + di[dir[id][2]][0] * i;
    ty = cy + di[dir[id][2]][1] * i;
    if (isok(tx, ty) == false || mp[tx][ty]) return;
    flag[tx][ty] = true;
  }
  for (i = dir[id][0]; i <= dir[id][1]; i++) {
    tx = cx + di[dir[id][2]][0] * i;
    ty = cy + di[dir[id][2]][1] * i;
    if (isok(tx, ty) == false || mp[tx][ty]) return;
    if (flag[tx][ty] == false) {
      flag[tx][ty] = true;
      dfs(tx, ty, id + 1);
      flag[tx][ty] = false;
    }
  }
}

void fun() {
  init();
  int i, j;
  int ans = 0;
  for (i = u + 1; i <= n - d; i++) {
    for (j = l + 1; j <= m - r; j++) {
      if (mp[i][j]) continue;
      memset(flag, false, sizeof(flag));
      ok = false;
      flag[i][j] = true;
      dfs(i, j, 0);
      if (ok) ans++;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    fun();
  }
  return 0;
}
