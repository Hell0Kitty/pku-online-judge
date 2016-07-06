#include <stdio.h>
int main() {
  int i, k, j, sum1, sum2, n, m, a[1001], flag, h, x;
  scanf("%d", &x);
  while (x--) {
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) scanf("%d", &a[i]);
    for (i = 1; i <= m; i++) {
      sum1 = sum2 = k = 0;
      for (j = 0; j < i; j++) sum1 += a[j];  //确定可能答案的数值
      if (i == m)                            //找不到就输出全部的和
      {
        printf("%d %d\n", n, sum1);
        break;
      }
      k = i;  //下个数值
      while (1) {
        sum2 += a[k];
        k++;
        if (sum2 == sum1)  //找后面想等的和
        {
          h = k;
          k = h;
          sum2 = 0;
          if (k == m)  //找到
          {
            flag = 0;
            break;
          }
        }
        if (k == m)  //找不到
        {
          flag = 1;
          break;
        }
      }
      if (!flag) {
        printf("%d %d\n", n, sum1);
        break;
      }
    }
  }
  return 0;
}
