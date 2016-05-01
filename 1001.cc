#include <stdio.h>
#include <string.h>
#define LEN 200
char str1[6] = {0};  //记录初始浮点数的数组
int num1[6] = {0}, num2[LEN] = {0}, num[LEN] = {0};  //记录转换为数字后的各位数
void Multiply() {
  int i, j;
  for (i = 0; i <= 5; i++) {
    for (j = 0; j <= LEN - 1; j++)
      num[i + j] = num[i + j] +
                   num1[i] * num2[j];  //分别计算各位的乘积，并加到对应的位置上
  }
  for (i = 0; i <= LEN - 1; i++) {
    if (num[i] >= 10) {
      num[i + 1] = num[i + 1] + num[i] / 10;
      num[i] = num[i] % 10;  //判断各位是否需进位
    }
    num2[i] = num[i];
    num[i] = 0;
  }
}
int main() {
  int n, i, j, k, point, place;
  while (scanf("%s%d", str1, &n) == 2) {
    k = 0;
    for (i = 5; i >= 0; i--) {
      if (str1[i] != '.') {
        num2[k] = str1[i] - '0';
        num1[k++] = str1[i] - '0';
      } else
        point = i;  //记录小数点位数
    }
    for (i = 1; i <= n - 1; i++) Multiply();  //乘 n 次

    i = LEN - 1;
    while (num2[i] == 0) i--;
    j = 0;
    while (num2[j] == 0) j++;
    place = n * (5 - point);
    if (place >= i + 1)  //输出
    {
      printf(".");
      for (k = place - 1; k >= j; k--) printf("%d", num2[k]);
      printf("\n");
    } else {
      if (j > place - 1) {
        for (k = i; k > place - 1; k--) printf("%d", num2[k]);
      } else {
        for (k = i; k >= j; k--) {
          if (k == place - 1) printf(".");
          printf("%d", num2[k]);
        }
      }
      printf("\n");
    }
    memset(str1, 0, sizeof(str1));
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    memset(num, 0, sizeof(num));
  }
  return 0;
}
