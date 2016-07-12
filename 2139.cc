#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int d[400][400];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(d, -1, sizeof(d));
    for (int i = 0; i < m; i++) {
      int num, a[305];
      scanf("%d", &num);
      for (int j = 0; j < num; j++) {
        scanf("%d", &a[j]);
        for (int k = 0; k < j; k++) d[a[j]][a[k]] = d[a[k]][a[j]] = 1;
      }
    }
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        if (d[i][k] != -1) {
          for (int j = 1; j <= n; j++) {
            if (d[k][j] != -1 && (d[i][j] == -1 || d[i][j] > d[i][k] + d[k][j]))
              d[i][j] = d[i][k] + d[k][j];
          }
        }
      }
    }
    int ans = 1 << 30;
    for (int i = 1, tp; i <= n; i++) {
      d[i][i] = 0;
      tp = 0;
      for (int j = 1; j <= n; j++) tp += d[i][j];
      ans = min(ans, tp);
    }
    printf("%d\n", ans * 100 / (n - 1));
  }
  return 0;
}
