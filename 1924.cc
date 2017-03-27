#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

typedef long long LL;
const int N = 102;
const LL II = 1000000007;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct point {
  int x, y;
} pos[N][N], q[2222222], w, e;

int n, m, sx, sy, ex, ey, p;
char maps[N][N];
int t[8][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int len[N];
int type[N];        //怪物的类型,1-可移动,0-不能移动
bool vis[N][N][N];  //标记数组vis[k][i][j],k-步数,i、j位置
bool mon[N][N];  //标记当前怪物可以攻击的位置，false不能，true可以

void sett(int s, bool k) {
  int i, j, x, y, tx, ty;
  for (i = 0; i < p; i++) {
    j = s % len[i];  // step后的位置
    x = pos[i][j].x;
    y = pos[i][j].y;
    mon[x][y] = k;               //标记
    if (type[i] == 0) continue;  //如果是0怪物
    for (j = 0; j < 8; j++) {
      tx = x + t[j][0];
      ty = y + t[j][1];
      if (tx >= 0 && tx < n && ty >= 0 && ty < m) mon[tx][ty] = k;
    }
  }
}

bool pass(int x, int y) {
  if (maps[x][y] == '#') return false;
  if (!(x >= 0 && x < n && y >= 0 && y < m)) return false;
  if (mon[x][y]) return false;
  return true;
}

int BFS() {
  int i, j, k, tx, ty;
  memset(vis, false, sizeof(vis));
  memset(mon, false, sizeof(mon));
  int head = 0, tail = 0, step = 0;
  w.x = sx, w.y = sy;
  vis[0][sx][sy] = true;
  q[tail++] = w;
  while (head < tail && step <= 100) {
    step++;
    int size = tail - head;
    sett(step - 1, false);  //这个地方的顺序不能反了
    sett(step, true);
    while (size--) {
      e = q[head];
      head++;
      for (i = 0; i < 8; i++) {
        for (j = 0; j <= 2; j++) {
          w.x = e.x + j * t[i][0];
          w.y = e.y + j * t[i][1];
          if (!pass(w.x, w.y)) break;  //这个不能写continue，因为不能跳过#或怪物
          if (vis[step][w.x][w.y]) continue;
          vis[step][w.x][w.y] = true;
          if (w.x == ex && w.y == ey) return step;
          q[tail++] = w;
        }
      }
    }
  }
  return -1;
}

int main() {
  int i, j, T, t, ci = 0;
  while (cin >> n >> m && (n + m)) {
    if (ci != 0) puts("");
    ci++;
    p = 0;
    for (i = 0; i < n; i++) {
      scanf("%s", maps[i]);
      for (j = 0; j < m; j++) {
        if (maps[i][j] == 'p') {
          sx = i, sy = j, maps[i][j] = '.';
        } else if (maps[i][j] == 't') {
          ex = i, ey = j, maps[i][j] = '.';
        } else if (maps[i][j] == 'n') {
          type[p++] = 0, maps[i][j] = '.';
        } else if (maps[i][j] == 'a') {
          type[p++] = 1, maps[i][j] = '.';
        }
      }
    }
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
      scanf("%d", &len[i]);
      for (j = 0; j < len[i]; j++) {
        scanf("%d%d", &pos[i][j].x, &pos[i][j].y);
        pos[i][j].x--;  //因为从0开始的，所以要减1
        pos[i][j].y--;
      }
    }

    int bfs = BFS();
    if (bfs == -1)
      printf("impossible\n");
    else
      printf("%d\n", bfs);
  }
  return 0;
}
