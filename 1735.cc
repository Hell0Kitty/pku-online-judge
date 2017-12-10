#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct fuck {
  char map[6][6];
  int hash;
  int step;
  int last, bitch;
} f[100008];
struct shit {
  int a, b, c, d;
} pf[100008], df[100008];
bool vis[200000];
int k, indek;
int dir[2][2] = {0, 1, 1, 0};
void fuckswap(char *a, char *b) {
  char t;
  t = *a;
  *a = *b;
  *b = t;
}
int gethash(fuck h) {
  int i, j, bitch = 1;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++) {
      bitch = bitch << 1;
      if (h.map[i][j] == '1') bitch = bitch | 1;
    }
  return bitch;
}
int bfs() {
  int i, j, nx, ny, t, fuckbitch, fuckhash;
  queue<fuck> q;
  struct fuck g;
  f[1].step = 0;
  f[1].last = 0;
  f[1].bitch = 1;
  vis[f[1].hash] = false;
  q.push(f[1]);
  while (!q.empty()) {
    g = q.front();
    fuckbitch = g.bitch;
    fuckhash = g.hash;
    q.pop();
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++) {
        for (t = 0; t < 2; t++) {
          nx = i + dir[t][0];
          ny = j + dir[t][1];
          if (nx < 4 && ny < 4 && g.map[nx][ny] != g.map[i][j]) {
            swap(g.map[nx][ny], g.map[i][j]);
            g.hash = gethash(g);
            if (vis[g.hash]) {
              vis[g.hash] = false;
              g.step = g.step + 1;
              ++k;
              g.last = g.bitch;
              g.bitch = k;
              q.push(g);
              f[k] = g;
              pf[k].a = i;
              pf[k].b = j;
              pf[k].c = nx;
              pf[k].d = ny;
              if (g.hash == f[0].hash) return g.step;
              g.step = g.step - 1;
              g.bitch = fuckbitch;
            }
            swap(g.map[nx][ny], g.map[i][j]);
          }
        }
      }
  }
  return -1;
}
int main() {
  int i, j, sb;
  memset(vis, true, sizeof(vis));
  for (i = 0; i < 4; i++) scanf("%s", f[1].map[i]);
  getchar();
  for (i = 0; i < 4; i++) scanf("%s", f[0].map[i]);
  f[0].hash = gethash(f[0]);
  f[1].hash = gethash(f[1]);
  if (f[0].hash == f[1].hash)
    printf("0\n");
  else {
    k = 1;
    indek = 0;
    printf("%d\n", bfs());

    while (k > 0) {
      df[indek++] = pf[k];
      k = f[k].last;
    }
    for (i = indek - 2; i >= 0; i--)
      printf("%d %d %d %d\n", df[i].a + 1, df[i].b + 1, df[i].c + 1,
             df[i].d + 1);
  }
  return 0;
}