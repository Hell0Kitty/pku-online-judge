#include <stdio.h>
#include <string.h>
struct node {
  int p[65][65];
};
int mod, len;
struct node suan(struct node a, struct node b)  //矩阵a乘以矩阵b
{
  int i, j, k;
  struct node c;
  for (i = 1; i <= len; i++) {
    for (j = 1; j <= len; j++) {
      c.p[i][j] = 0;
      for (k = 1; k <= len; k++)
        c.p[i][j] = (a.p[i][k] * b.p[k][j] + c.p[i][j]) % mod;
    }
  }
  return c;
}
struct node haha(struct node a, struct node b, int n) {
  while (n)  //矩阵的快速幂
  {
    if (n % 2 == 1) b = suan(b, a);
    n = n / 2;
    a = suan(a, a);
  }
  return b;
}
int main() {
  int i, j, n, k;
  struct node a, b;
  while (scanf("%d%d%d", &n, &k, &mod) != EOF) {
    len = n * 2;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) scanf("%d", &a.p[i][j]);
    for (i = 1; i <= n; i++)  //右上部分
      for (j = n + 1; j <= n * 2; j++)
        if (i + n == j)
          a.p[i][j] = 1;
        else
          a.p[i][j] = 0;
    for (i = n + 1; i <= n * 2; i++)  //左下部分
      for (j = 1; j <= n; j++) a.p[i][j] = 0;
    for (i = n + 1; i <= 2 * n; i++)  //右下部分
      for (j = n + 1; j <= n * 2; j++)
        if (i == j)
          a.p[i][j] = 1;
        else
          a.p[i][j] = 0;
    for (i = 1; i <= n * 2; i++)  //把b变成单位矩阵
      for (j = 1; j <= n * 2; j++)
        if (i == j)
          b.p[i][j] = 1;
        else
          b.p[i][j] = 0;
    a = haha(a, b, k + 1);
    for (i = 1; i <= n; i++)  //减去单位矩阵
      for (j = n + 1; j <= len; j++) {
        if (i + n == j) a.p[i][j]--;
        while (a.p[i][j] < 0)  //为了防止溢出
          a.p[i][j] += mod;
      }
    for (i = 1; i <= n; i++) {
      for (j = n + 1; j < len; j++) printf("%d ", a.p[i][j]);
      printf("%d\n", a.p[i][len]);
    }
  }
  return 0;
}
