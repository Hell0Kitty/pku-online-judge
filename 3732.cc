#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

int maze[5][5];
bool ucol[20];
int lx, ly;

int dep;
inline int h() {
  bool col[20];
  memset(col, false, sizeof(col));
  for (int i = 0; i < lx; i++) {
    for (int j = 0; j < ly; j++) {
      col[maze[i][j]] = true;
    }
  }
  int cnt = 0;
  for (int i = 1; i < 20; i++) {
    cnt += col[i];
  }
  return cnt;
}

int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
void fill(int x, int y, int c) {
  int tc = maze[x][y];
  maze[x][y] = c;
  for (int i = 0; i < 4; i++) {
    int tx = x + dir[i][0];
    int ty = y + dir[i][1];
    if (tx < 0 || ty < 0 || tx >= lx || ty >= ly) continue;
    if (maze[tx][ty] != tc) continue;
    fill(tx, ty, c);
  }
}

bitset<1000007> vis[17];
unsigned zip() {
  unsigned z = 0;
  for (int i = 0; i < lx; i++) {
    for (int j = 0; j < ly; j++) {
      z = maze[i][j] + z * 131;
    }
  }
  return z % 1000007;
}

int ans[20][3];
bool dfs(int d) {
  int th = h();
  if (d == dep) return !th;
  if (d + th > dep) return false;
  for (int i = 0; i < lx; i++) {
    for (int j = 0; j < ly; j++) {
      bool tcol[20];
      memset(tcol, false, sizeof(tcol));
      tcol[0] = true;
      for (int k = 0; k < 4; k++) {
        int tx = i + dir[k][0];
        int ty = j + dir[k][1];
        if (tx < 0 || ty < 0 || tx >= lx || ty >= ly) continue;
        tcol[maze[tx][ty]] = true;
      }
      for (int k = 0; k < 20; k++) {
        if (k == maze[i][j]) continue;
        if (!tcol[k]) continue;
        int tmp[5][5];
        memcpy(tmp, maze, sizeof(tmp));
        fill(i, j, k);
        ans[d][0] = i;
        ans[d][1] = j;
        ans[d][2] = k;
        int _z = zip();
        if (vis[d][_z]) {
          memcpy(maze, tmp, sizeof(tmp));
          continue;
        }
        vis[d][_z] = true;
        if (dfs(d + 1)) return true;
        memcpy(maze, tmp, sizeof(tmp));
      }
    }
  }
  return false;
}

int main() {
  while (~scanf("%d%d", &lx, &ly)) {
    memset(ucol, false, sizeof(ucol));
    ucol[0] = true;
    for (int i = 0; i < lx; i++) {
      for (int j = 0; j < ly; j++) {
        scanf("%d", &maze[i][j]);
        ucol[maze[i][j]] = true;
      }
    }
    dep = 0;
    while (true) {
      for (int i = 0; i < dep; i++) vis[i].reset();
      if (dfs(0)) break;
      dep++;
    }
    printf("%d\n", dep);
    for (int i = 0; i < dep; i++) {
      printf("%d %d %d\n", ans[i][0] + 1, ans[i][1] + 1, ans[i][2]);
    }
  }
}
