#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
double f[111][111];

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != 1) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) f[i][j] = 0;
    for (int i = 0; i != m; i++) {
      int u, v, per;
      scanf("%d%d%d", &u, &v, &per);
      f[u][v] = per / 100.0;
      f[v][u] = per / 100.0;
    }
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        if (i != k)
          for (int j = 1; j <= n; j++)
            if (i != j && j != k) f[i][j] = max(f[i][j], f[i][k] * f[k][j]);
    printf("%.6lf percent\n", f[1][n] * 100);
  }
  return 0;
}
