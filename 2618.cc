#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define M 16
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
typedef struct talP {
  short x, y;
  bool operator==(const talP &a) const { return a.x == x && a.y == y; }
} Point;
typedef struct talC {
  short face, up, left;
  talC() {}
  talC(int f, int u, int l) : face(f), up(u), left(l) {}
  void Set(int f, int u, int l) {
    face = f;
    up = u;
    left = l;
  }
  void Turn(short i) {
    short tmp;
    switch (i) {
      case UP:
        tmp = face, face = 5 - up, up = tmp;
        break;
      case DOWN:
        tmp = up, up = 5 - face, face = tmp;
        break;
      case LEFT:
        tmp = face, face = 5 - left, left = tmp;
        break;
      case RIGHT:
        tmp = left, left = 5 - face, face = tmp;
    }
  }
  bool operator==(const talC &a) const { return a.face == face; }
} Cube;
typedef struct talN {
  Point p;
  Cube c;
  int t;
  bool operator==(const talN &a) const { return a.p == p && a.c == c; }
} Node;
bool map[M][M][4];
bool vis[M][M][24];
bool matrix[6][6];
int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int r, c;
queue<Node> q;
Node start, end;
void InitMat() {
  short i, j;
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 6; j++) matrix[i][j] = i != j && i + j != 5;
  }
}
short GetValue(Cube cc) {
  short c = 0, k, i, j;
  i = cc.face;
  j = cc.up;
  for (k = 0; k < j; k++) c += matrix[i][k];
  return i * 4 + c;
}
int BFS() {
  Node cur, next;
  int x, y, i;
  vis[start.p.x][start.p.y][GetValue(start.c)] = true;
  q.push(start);
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    if (cur == end) return cur.t;
    next.t = cur.t + 1;
    for (i = 0; i < 4; i++) {
      if (map[cur.p.x][cur.p.y][i]) continue;
      x = cur.p.x + dir[i][0];
      y = cur.p.y + dir[i][1];
      if (x < 1 || x > r || y < 1 || y > c) continue;
      next.p.x = x;
      next.p.y = y;
      next.c = cur.c;
      next.c.Turn(i);
      if (vis[next.p.x][next.p.y][GetValue(next.c)]) continue;
      vis[next.p.x][next.p.y][GetValue(next.c)] = true;
      q.push(next);
    }
  }
  return -1;
}
int main() {
  char s[64], *p;
  int ans, x, y, flag = 1;
  InitMat();
  scanf("%d%d", &r, &c);
  scanf("%d%d", &start.p.x, &start.p.y);
  scanf("%d%d", &end.p.x, &end.p.y);
  getchar();
  while (gets(s)) {
    if (s[0] == 'v') {
      flag = 1;
      continue;
    }
    if (s[0] == 'h') {
      flag = 2;
      continue;
    }
    p = strchr(s, ' ');
    *p = 0, p++;
    x = atoi(s);
    y = atoi(p);
    switch (flag) {
      case 1:
        map[x][y][DOWN] = true, map[x + 1][y][UP] = true;
        break;
      case 2:
        map[x][y][RIGHT] = true, map[x][y + 1][LEFT] = true;
    }
  }
  start.c.Set(0, 1, 2);
  end.c.Set(0, 1, 2);
  start.t = end.t = 0;
  ans = BFS();
  printf(ans != -1 ? "%d\n" : "no\n", ans);
  return 0;
}
