#include <stdio.h>
#include <string.h>

int main() {
  int i, j, r, c;
  int k, m, a, b, flag;
  int map[10000];

  while (scanf("%d", &k) != EOF, k) {
    memset(map, 0, sizeof map);
    scanf("%d", &m);
    for (i = 0; i < k; i++) {
      scanf("%d", &a);
      map[a]++;
    }
    flag = 1;
    int count;
    for (i = 0; i < m; i++) {
      scanf("%d %d", &r, &c);
      count = 0;
      for (j = 0; j < r; j++) {
        scanf("%d", &b);
        if (map[b] > 0)  //娌￠�
          count++;
      }
      if (count < c) flag = 0;
    }
    if (flag == 0)
      puts("no");
    else
      puts("yes");
  }

  return 0;
}
