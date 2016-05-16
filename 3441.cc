#include <iostream>
using namespace std;

const int INF = 1000000000;
char s[105][30];
int n, m, a, b, f[105][30], p[105][30], num = 0;

int main() {
  bool tag = false;
  while (scanf("%d%d", &n, &m), n || m) {
    if (tag)
      puts("");
    else
      tag = true;
    int i, j, k, t, col;
    for (i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    scanf("%d%d", &a, &b);
    for (i = 1; i <= n + 1; i++)
      for (j = 1; j <= m + 1; j++) f[i][j] = INF;
    f[b][m + 1] = -1;
    for (i = b - 1; i >= a; i--)
      for (t = 1; t <= m + 1; t++)
        for (j = 1; j <= m; j++)
          if (s[i][j] == 'O') {
            if (f[i][j] > f[i + 1][t] + (j != t)) {
              f[i][j] = f[i + 1][t] + (j != t);
              p[i][j] = t;
            }
          }
    printf("Case %d:\n\n", ++num);
    k = INF;
    for (i = 1; i <= m; i++)
      if (f[a][i] < k) {
        k = f[a][i];
        col = i;
      }
    if (k == INF) {
      puts("Not available");
      continue;
    }
    while (a < b) {
      k = a;
      while (p[a][col] == col) a++;
      printf("%c: %d-%d\n", col - 1 + 'A', k, a + 1);
      col = p[a][col];
      a++;
    }
  }
  return 0;
}
