#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn 105

int vis[maxn];
int lowc[maxn];
int cost[maxn][maxn];
int n;

void input() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &cost[i][j]);
}

int prim() {
  int i, j, p;
  int minc, res = 0;
  memset(vis, 0, sizeof(vis));
  vis[0] = 1;
  for (i = 0; i < n; i++) lowc[i] = cost[0][i];
  for (i = 1; i < n; i++) {
    minc = inf;
    p = -1;
    for (j = 0; j < n; j++)
      if (0 == vis[j] && minc > lowc[j]) {
        minc = lowc[j];
        p = j;
      }
    if (inf == minc) return -1;
    res += minc;
    vis[p] = 1;
    for (j = 0; j < n; j++)
      if (0 == vis[j] && lowc[j] > cost[p][j]) lowc[j] = cost[p][j];
  }
  return res;
}

int main() {
  while (scanf("%d", &n) != EOF) {
    input();
    printf("%d\n", prim());
  }
  return 0;
}
