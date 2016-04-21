#include <stdio.h>
#include <string.h>
#define N 1050
int map[N][100], len[N];
int pre[N], tc[N][N];
int n, m;

void tcdfs(int u, int p) {
  int ii;
  int temp;

  for (ii = 1; ii <= len[u]; ii++) {
    temp = map[u][ii];
    if (pre[temp]) continue;
    pre[temp] = 1;
    tc[p][temp] = 1;
    tcdfs(temp, p);
  }
}

void dagtc() {
  int ii, jj;
  int num;

  memset(tc, 0, sizeof(tc));
  for (ii = 1; ii <= n; ii++) {
    memset(pre, 0, sizeof(pre));
    pre[ii] = 1;
    tcdfs(ii, ii);
  }

  for (ii = 1, num = 0; ii <= n; ii++)
    for (jj = 1; jj <= n; jj++) {
      if (ii == jj) tc[ii][ii] = 1;
      if (tc[ii][jj]) num++;
    }

  printf("%d\n", num);
}

int main() {
  int ii;
  int a, b, temp;
  while (scanf("%d %d", &n, &m) != EOF) {
    memset(len, 0, sizeof(len));
    for (ii = 1; ii <= m; ii++) {
      scanf("%d %d", &a, &b);
      a++, b++;
      len[a]++;
      map[a][len[a]] = b;
    }

    dagtc();
  }
  return 1;
}
