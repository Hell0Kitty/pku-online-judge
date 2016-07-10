#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXD = 105;

int inc[MAXD][MAXD], ex[MAXD][MAXD];
int f[MAXD][MAXD];
int n, m, Max;
int max(int a, int b) { return a > b ? a : b; }

void init() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &ex[i][j]);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &inc[i][j]);
  memset(f, 0, sizeof f);
}

void dp() {
  for (int j = 1; j <= n; j++) f[1][j] = inc[1][j] - ex[1][j];
  for (int i = 2; i <= m; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        f[i][j] = max(f[i][j], f[i - 1][k] + inc[i][j] - ex[k][j]);
  Max = 0;
  for (int i = 1; i <= n; i++)
    if (Max < f[m][i]) Max = f[m][i];
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    if (n == m && m == 0) break;
    init();
    dp();
    printf("%d\n", Max);
  }
  return 0;
}
