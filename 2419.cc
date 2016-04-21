#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define mmst(a, b) memset(a, b, sizeof(a))

typedef long long LL;

const int maxn = 105;

int n, m;
int vis[maxn][maxn];

int main() {
  int i, j, k, ans, u, v;

  scanf("%d%d", &n, &m);
  while (scanf("%d%d", &u, &v) != EOF) vis[u][v] = true;

  ans = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j < i; j++) {
      for (k = 1; k <= m; k++)
        if (vis[i][k] != vis[j][k]) break;
      if (k > m) break;
    }
    if (j >= i) ans++;
  }

  printf("%d\n", ans);

  return 0;
}
