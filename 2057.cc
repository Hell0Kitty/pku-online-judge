#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1010;
struct node {
  int fa, fb, L;
  bool flag;
} T[N];

vector<int> Q[N];
int n;

bool cmp(int x, int y) {
  return ((T[x].fb + 2) * T[y].L < (T[y].fb + 2) * T[x].L);
}
void dfs(int u) {
  for (int i = 0; i < (int)Q[u].size(); i++) dfs(Q[u][i]);

  T[u].fa = T[u].fb = T[u].L = 0;

  if (Q[u].size() == 0) T[u].L = 1;

  if (Q[u].size() > 0) {
    sort(Q[u].begin(), Q[u].end(), cmp);

    for (int i = 0; i < Q[u].size(); i++) {
      int v = Q[u][i];
      T[u].fa += (T[u].fb + 1) * T[v].L + T[v].fa;
      T[u].fb += T[v].fb + 2;
      T[u].L += T[v].L;
    }
    // 若节点u 上存在毛毛虫，则返回花费0
    if (T[u].flag) T[u].fb = 0;
  }
}
int main() {
  while (scanf("%d", &n), n) {
    for (int i = 0; i <= n; i++) Q[i].clear();
    char str[2];
    for (int x = 1; x <= n; x++) {
      int pre;
      scanf("%d %s", &pre, str);
      if (pre != -1) Q[pre].push_back(x);
      T[x].flag = ((str[0] == 'Y') ? true : false);
    }
    dfs(1);
    double ans = 1.0 * T[1].fa / T[1].L;
    printf("%.4f\n", ans);
  }
  return 0;
}
