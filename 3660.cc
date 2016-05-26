#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 106

int n, m;
bool g[maxn][maxn];

int main() {
  scanf("%d%d", &n, &m);
  memset(g, 0, sizeof(g));
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a][b] = true;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (g[j][i] && g[i][k]) g[j][k] = true;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int temp = 0;
    for (int j = 1; j <= n; j++) temp += g[i][j] + g[j][i];
    if (temp == n - 1) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
