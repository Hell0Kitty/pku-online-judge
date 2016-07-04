#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define N 25
#define M 15
#define NS 2510
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

char map[N][N];
int row, col, kind, power, sx, sy, tot;
int A[M], B[M], per[NS];
bool vis[N][N][NS];
struct node  // bfs搜索时的状态
    {
  int x, y;  //当前所在的坐标
  int s;     //携带的物品的状态，压缩回来的十进制数
  int cost;  //花费了多少电量
  void func(int xx, int yy, int ss, int cc) {
    x = xx;
    y = yy;
    s = ss;
    cost = cc;
  }
  bool operator<(const struct node &a) const { return cost > a.cost; }
};
priority_queue<struct node> que;

void input() {
  cin >> row >> col >> kind >> power;
  for (int r = 0; r < row; r++) cin >> map[r];
  for (int i = 0; i < kind; i++) cin >> A[i] >> B[i];
  for (int r = 0; r < row; r++)
    for (int c = 0; c < col; c++)
      if (map[r][c] == '*') {
        sx = r;
        sy = c;
        break;
      }
}

void cal_per() {
  tot = (1 << kind);
  for (int s = 0; s < tot; s++) {
    per[s] = 1;
    for (int k = 0; k < kind; k++)
      if (s & (1 << k)) per[s] += B[k];
  }
}

int solve() {
  struct node a, b;
  memset(vis, 0, sizeof(vis));
  while (!que.empty()) que.pop();
  a.func(sx, sy, 0, 0);
  que.push(a);
  vis[sx][sy][0] = true;

  while (!que.empty()) {
    a = que.top();
    que.pop();
    if (a.cost + per[a.s] > power) continue;
    for (int k = 0; k < 4; k++) {
      int xx = a.x + dx[k];
      int yy = a.y + dy[k];
      int ss = a.s;
      int cc = a.cost + per[a.s];
      if (xx < 0 || xx >= row || yy < 0 || yy >= col || map[xx][yy] == '#')
        continue;

      if (xx == sx && yy == sy)
        if (ss == tot - 1)
          return cc;
        else
          continue;

      if (!vis[xx][yy][ss]) {
        b.func(xx, yy, ss, cc);
        que.push(b);
        vis[xx][yy][ss] = true;
      }

      if (map[xx][yy] >= 'A' && map[xx][yy] <= 'Z') {
        int index = map[xx][yy] - 'A';
        if (!(ss & (1 << index))) {
          ss |= (1 << index);
          cc += A[index];
          if (cc + A[index] > power) continue;
          if (xx == sx && yy == sy && ss == tot - 1) return cc;
          if (!vis[xx][yy][ss]) {
            b.func(xx, yy, ss, cc);
            que.push(b);
            vis[xx][yy][ss] = true;
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    input();
    cal_per();
    int res = solve();
    if (res == -1)
      cout << "Impossible" << endl;
    else
      cout << res << endl;
  }
  return 0;
}
