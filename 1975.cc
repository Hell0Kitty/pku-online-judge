#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int h[101][101];
int d[101][101];

int main()

{
  int t;
  scanf("%d", &t);
  for (int l = 1; l <= t; l++) {
    memset(h, 0, sizeof(h));
    memset(d, 0, sizeof(d));
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b;
    for (int i = 1; i <= m; i++) {
      scanf("%d %d", &a, &b);
      h[a][b] = 1;
      d[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          if (d[i][j] == 1)
            d[i][j] = 1;
          else if (d[i][k] && d[k][j])
            d[i][j] = 1;

    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          if (h[i][j] == 1)
            h[i][j] = 1;
          else if (h[i][k] && h[k][j])
            h[i][j] = 1;

    int sum = 0;

    for (int i = 1; i <= n; i++) {
      int ans = 0;
      for (int j = 1; j <= n; j++) {
        if (d[i][j] == 1) ans++;
      }
      if (ans >= (n + 1) / 2) sum++;
    }

    for (int i = 1; i <= n; i++) {
      int ans = 0;
      for (int j = 1; j <= n; j++) {
        if (h[i][j] == 1) ans++;
      }

      if (ans >= (n + 1) / 2) sum++;
    }

    printf("%d\n", sum);
  }
  return 0;
}
