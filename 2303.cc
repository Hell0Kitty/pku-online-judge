#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 102;
int n, flag, p[3][maxn], res[3][maxn];
struct node {
  int h, d, w;
} nod[maxn << 1];
int cmp(node a, node b) {
  if (a.h != b.h) return a.h > b.h;
  if (a.d != b.d) return a.d > b.d;
  return a.w < b.w;
}
void init() {
  flag = 0;
  for (int i = 0; i <= n; i++) res[1][i] = res[2][i] = p[1][i] = p[2][i] = 0;
}
int check(int i, int j) {
  node tmp = nod[p[i][p[i][0]]];
  if (tmp.h - 2 * tmp.w >= nod[j].h && tmp.d - 2 * tmp.w >= nod[j].d) {
    return 1;
  }
  return 0;
}
int dfs(int idx) {
  if (idx > 2 * n) {
    if (p[1][0] == n && p[2][0] == n) {
      memcpy(res, p, sizeof(res));
      flag = 1;
    }
    return 1;
  }
  if (!flag)
    for (int i = 1; i <= 2; i++) {
      if (p[i][0] == 0) {
        p[i][++p[i][0]] = idx;
        dfs(idx + 1);
        p[i][0]--;
      } else if (p[i][0] < n && check(i, idx)) {
        p[i][++p[i][0]] = idx;
        dfs(idx + 1);
        p[i][0]--;
      }
    }
}
int main() {
  while (scanf("%d", &n), n) {
    int i, j;
    for (i = 1; i <= 2 * n; i++) {
      scanf("%d%d%d", &nod[i].h, &nod[i].d, &nod[i].w);
    }
    init();
    sort(nod + 1, nod + 2 * n + 1, cmp);
    dfs(1);
    for (i = 1; i <= 2; i++) {
      for (j = 1; j <= n; j++) {
        int idx = res[i][j];
        printf("%d %d %d\n", nod[idx].h, nod[idx].d, nod[idx].w);
      }
      if (i != 2)
        printf("-\n");
      else
        printf("\n");
    }
  }
  return 0;
}
