#include <stdio.h>
#include <string.h>
const int M = 205;
int n, cut, head[M], map1[M][M], ji[M];
int topo() {
  int i, in = -1, ind, di[M], j, k;
  cut = 0;
  for (i = 0; i < n; i++) {
    di[i] = 0;
    for (j = 0; j < n; j++) {
      di[i] += map1[j][i];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = n - 1; j >= 0; j--) {
      if (di[j] == 0) {
        di[j] = -1;
        break;
      }
    }
    if (j == -1) {
      return 0;
    }
    for (k = 0; k < n; k++) {
      di[k] -= map1[j][k];
    }
    ji[i] = j;
  }
  return 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int i, m, flat = 1, a, b, ans[M];
    scanf("%d%d", &n, &m);
    memset(map1, 0, sizeof(map1));
    for (i = 0; i < m; i++) {
      scanf("%d%d", &a, &b);
      a--;
      b--;
      map1[b][a] = 1;
    }
    i = topo();
    if (i) {
      for (i = 0; i < n; i++)  //最后的数据处理
      {
        ans[ji[i] + 1] = n - i;
      }
      for (i = 1; i < n; i++) {
        printf("%d ", ans[i]);
      }
      printf("%d\n", ans[n]);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}