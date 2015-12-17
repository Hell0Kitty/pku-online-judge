
#include <stdio.h>
#include <string.h>
int main() {
  bool map[120][120];
  int match1[120], match2[120], prev[120], que[120], pque, p1, m, n, i, i1, i2,
      now, k, num1, num2, num;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    memset(map, 0, sizeof(map));
    scanf("%d%d", &m, &k);
    for (i1 = 0; i1 < k; i1++) {
      scanf("%d%d", &num1, &num2);
      map[num1 - 1][num2 - 1] = true;
    }
    num = 0;
    memset(match1, int(-1), sizeof(match1));
    memset(match2, int(-1), sizeof(match2));
    for (i1 = 0; i1 < m; i1++) {
      p1 = 0;
      pque = 0;
      for (i2 = 0; i2 < m; i2++) {
        if (map[i1][i2]) {
          prev[i2] = -1;
          que[pque++] = i2;
        } else
          prev[i2] = -2;
      }
      while (p1 < pque) {
        now = que[p1];
        if (match2[now] == -1) break;
        p1++;
        for (i2 = 0; i2 < m; i2++) {
          if (prev[i2] == -2 && map[match2[now]][i2]) {
            prev[i2] = now;
            que[pque++] = i2;
          }
        }
      }
      if (p1 == pque) continue;
      while (prev[now] >= 0) {
        match1[match2[prev[now]]] = now;
        match2[now] = match2[prev[now]];
        now = prev[now];
      }
      match2[now] = i1;
      match1[i1] = now;
      num++;
    }
    printf("%d\n", m - num);
  }
  return 0;
}
