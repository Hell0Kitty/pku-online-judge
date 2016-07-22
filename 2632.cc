#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;
struct NODE {
  int x, y;
  int dir;
} node[MAXN];
struct OP {
  int name, t;
  char move;
} op[MAXN];
bool flag;

bool ok(int k, int N, int M, int n) {
  for (int i = 1; i <= n; ++i) {
    if (node[i].x < 1 || node[i].x > N || node[i].y < 1 || node[i].y > M) {
      printf("Robot %d crashes into the wall\n", i);
      flag = false;
      return false;
    }
  }

  for (int j = 1; j <= n; ++j) {
    if (k != j && node[k].x == node[j].x && node[k].y == node[j].y) {
      printf("Robot %d crashes into robot %d\n", k, j);
      flag = false;
      return false;
    }
  }

  flag = true;
  return true;
}

void forward(NODE *a, OP b, int N, int M, int n) {
  while (b.t--) {
    if (a->dir == 'N')
      a->x -= 1;
    else if (a->dir == 'S')
      a->x += 1;
    else if (a->dir == 'W')
      a->y -= 1;
    else
      a->y += 1;
    if (!ok(b.name, N, M, n)) break;
  }
}

NODE turn_l(NODE a, OP b) {
  b.t = (b.t >= 4) ? (b.t % 4) : b.t;
  while (b.t--) {
    if (a.dir == 'N')
      a.dir = 'W';
    else if (a.dir == 'S')
      a.dir = 'E';
    else if (a.dir == 'E')
      a.dir = 'N';
    else
      a.dir = 'S';
  }

  return a;
}

NODE turn_r(NODE a, OP b) {
  // printf ("Dir: %c\n", a.dir);
  b.t = (b.t >= 4) ? (b.t % 4) : b.t;
  while (b.t--) {
    if (a.dir == 'N')
      a.dir = 'E';
    else if (a.dir == 'S')
      a.dir = 'W';
    else if (a.dir == 'W')
      a.dir = 'N';
    else
      a.dir = 'S';
  }

  return a;
}

void work(int N, int M, int n, int m) {
  int i;
  for (i = 1; i <= m; ++i) {
    if (op[i].move == 'F') forward(&node[op[i].name], op[i], N, M, n);
    // node[op[i].name] = forward (node[op[i].name], op[i], N, M, n);
    else if (op[i].move == 'L')
      node[op[i].name] = turn_l(node[op[i].name], op[i]);
    else if (op[i].move == 'R')
      node[op[i].name] = turn_r(node[op[i].name], op[i]);
    if (flag)
      continue;
    else
      break;
  }
  if (i == m + 1) puts("OK");
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int N, M, n, m;
    scanf("%d%d", &M, &N);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d %c", &node[i].y, &node[i].x, &node[i].dir);
      node[i].x = N + 1 - node[i].x;
    }

    for (int i = 1; i <= m; ++i) {
      scanf("%d %c %d", &op[i].name, &op[i].move, &op[i].t);
    }

    flag = true;
    work(N, M, n, m);
  }

  return 0;
}
