#include <stdio.h>
#include <queue>
#define inf 1000000000
using namespace std;

struct node {
  int p, x1, x2, ok, s;
} te, te2;
struct node2 {
  int x, y;
} h1[110];
char a[53][53];
queue<node> q;
int h2[5053], s[110][110][110];
int d[4][2] = {1, 0, -1, 0, 0, 1, 0, -1}, num_x, num_b, n, m, N;

int bfs(int p, int x1, int x2) {
  int i, j, k, Px, Py, X1x, X1y, X2x, X2y;
  while (!q.empty()) q.pop();
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      for (k = 0; k < N; k++) s[i][j][k] = inf;
  te.p = p, te.x1 = x1, te.x2 = x2, te.ok = 0, te.s = 0, q.push(te);
  s[p][x1][x2] = 0;
  while (!q.empty()) {
    te = q.front(), q.pop();
    if (te.ok == num_b && a[h1[te.p].x][h1[te.p].y] == 'E') return te.s;
    for (i = 0; i < 4; i++) {
      Px = h1[te.p].x + d[i][0], Py = h1[te.p].y + d[i][1];
      if (a[Px][Py] == '#' || (te.ok < num_b && a[Px][Py] == 'E')) continue;
      X1x = h1[te.x1].x, X1y = h1[te.x1].y;
      X2x = h1[te.x2].x, X2y = h1[te.x2].y;
      if (Px == X1x && Py == X1y) {
        X1x += d[i][0], X1y += d[i][1];
        if (a[X1x][X1y] == '#' || a[X1x][X1y] == 'E' ||
            (X1x == X2x && X1y == X2y))
          continue;
      } else if (Px == X2x && Py == X2y) {
        X2x += d[i][0], X2y += d[i][1];
        if (a[X2x][X2y] == '#' || a[X2x][X2y] == 'E' ||
            (X2x == X1x && X2y == X1y))
          continue;
      }
      te2.p = h2[100 * Px + Py], te2.x1 = h2[100 * X1x + X1y],
      te2.x2 = h2[100 * X2x + X2y], te2.s = te.s + 1;
      if (te2.s < s[te2.p][te2.x1][te2.x2]) {
        te2.ok = 0;
        if (a[X1x][X1y] == 'B') te2.ok++;
        if (a[X2x][X2y] == 'B') te2.ok++;
        q.push(te2);
        s[te2.p][te2.x1][te2.x2] = te2.s;
      }
    }
  }
  return inf;
}

int main() {
  int Xx[5], Xy[5], t, cs, i, j, p, x1, x2, ans;
  h1[0].x = 0, h1[0].y = 0, h2[0] = 0;
  a[0][0] = '#';
  scanf("%d", &t);
  for (cs = 0; cs < t; cs++) {
    scanf("%d%d", &n, &m);
    for (N = 1, num_x = 0, num_b = 0, i = 1; i <= n; i++) {
      scanf("%s", a[i] + 1);
      for (j = 1; j <= m; j++) {
        if (a[i][j] == 'B')
          num_b++;
        else if (a[i][j] == 'X')
          Xx[num_x] = i, Xy[num_x] = j, num_x++;
        else if (a[i][j] == 'S')
          p = N;
        if (a[i][j] != '#' && N < 110) {
          h1[N].x = i, h1[N].y = j;
          h2[100 * i + j] = N, N++;
        }
      }
    }
    if (num_x < num_b)
      printf("impossible\n");
    else {
      for (i = 0; i < num_x; i++) {
        if (i == 0) x1 = h2[100 * Xx[0] + Xy[0]];
        if (i == 1) x2 = h2[100 * Xx[1] + Xy[1]];
      }
      for (i = num_x; i < 2; i++) {
        if (i == 0) x1 = 0;
        if (i == 1) x2 = 0;
      }
      ans = bfs(p, x1, x2);
      if (ans == inf)
        printf("impossible\n");
      else
        printf("%d\n", ans);
    }
  }
  return 0;
}
