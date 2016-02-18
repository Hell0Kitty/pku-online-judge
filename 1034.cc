#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-8;
bool chk[120], g[120][120];
int n, m, xm[120], ym[120];
bool findpath(int x) {
  for (int y = 0; y < m; y++) {
    if (g[x][y] && !chk[y]) {
      chk[y] = true;
      if (ym[y] == -1 || findpath(ym[y])) {
        xm[x] = y;
        ym[y] = x;
        return true;
      }
    }
  }
  return false;
}
int maxmatch() {
  memset(xm, -1, sizeof(xm));
  memset(ym, -1, sizeof(ym));
  int ret = 0;
  for (int i = 0; i < n; i++) {
    memset(chk, false, sizeof(chk));
    if (findpath(i)) ret++;
  }
  return ret;
}
int po[120][2], so[120][2];
double cal(int x1, int y1, int x2, int y2) {
  return sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
bool check(int i, int j, int k) {
  double a, b, c;
  a = cal(po[i][0], po[i][1], so[k][0], so[k][1]);
  b = cal(po[j][0], po[j][1], so[k][0], so[k][1]);
  c = cal(po[i][0], po[i][1], po[j][0], po[j][1]);
  if (a + b < 2.0 * c + eps)
    return true;
  else
    return false;
}
int main() {
  int nn;
  while (scanf("%d%d", &nn, &m) != EOF) {
    memset(g, false, sizeof(g));
    for (int i = 0; i < nn; i++) scanf("%d%d", &po[i][0], &po[i][1]);
    for (int i = 0; i < m; i++) scanf("%d%d", &so[i][0], &so[i][1]);
    n = nn - 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (check(i, i + 1, j)) g[i][j] = true;
    }
    printf("%d\n", nn + maxmatch());
    for (int i = 0; i < n; i++) {
      printf("%d %d ", po[i][0], po[i][1]);
      if (xm[i] != -1) printf("%d %d ", so[xm[i]][0], so[xm[i]][1]);
    }
    printf("%d %d\n", po[n][0], po[n][1]);
  }
  return 0;
}
