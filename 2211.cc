#include <stdio.h>
int main() {                               // n：总共有多少人k：一张照片里有多少人a[20]：存给出照片状态
  int t, i, i2, j, n, k, a[20], ans, sum;  // ans：最终结果sum：中间结果
  scanf("%d", &t);  // t：testcase、i，i2，j：计数器
  for (j = 1; j <= t; j++) {
    ans = 0;
    scanf("%d%d", &n, &k);
    for (i = 0; i < k; i++) scanf("%d", a + i);
    for (i = 0; i < k; i++) {
      sum = *(a + i) - 1;
      for (i2 = n - i - 1; i2 >= n - k + 1; i2--)  //
        sum *= i2;
      ans += sum;
      for (i2 = i + 1; i2 < k; i2++) {
        if (a[i2] > a[i]) a[i2]--;
      }
    }
    printf("Variace cislo %d ma poradove cislo %d.\n", j, ans + 1);
  }
  return 0;
}
