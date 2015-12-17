#include <stdio.h>
#include <math.h>
int N, i, j, c[10001][32], tmp, a, b;
int main() {

  scanf("%d", &N);
  for (i = 1; i <= 10000; i++)
    for (j = 0; j < 32; j++)
      c[i][j] = 0;
  for (i = 1; i <= N; i++) {
    scanf("%d", &j);
    while (j--) {
      scanf("%d", &tmp);
      a = 1 << (i % 32 - 1);
      if ((c[tmp][i / 32] & a) == 0)
        c[tmp][i / 32] += a;
    }
  }
  scanf("%d", &N);
  while (N--) {
    scanf("%d %d", &a, &b);
    tmp = 0;
    for (i = 0; i < 32 && tmp == 0; i++)
      tmp = c[a][i] & c[b][i];
    if (tmp != 0)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
