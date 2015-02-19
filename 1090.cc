#include <stdio.h>
#include <string.h>
int array[1001];
int res[1001], ans[1001];  // ans存二进制，由ans转化成的十进制存在res中
int ini() {
  int z, flag = 0;
  for (z = 1; z <= 1000; z++) {
    res[z] += flag;
    flag = res[z] / 10;
    res[z] %= 10;
  }
  return 0;
}
int add(int* flag, int fnum) {
  int i;
  for (i = 1; i <= fnum; i++) res[i] += flag[i];
  return ini();
}
int getres(int n) {
  int i, j, z, flag[1001], ff, fnum = 1;
  memset(flag, 0, sizeof(flag));
  flag[1] = 1;
  for (i = 1; i <= n; i++) {
    if (ans[i]) add(flag, fnum);
    for (j = 1; j <= fnum; j++) {
      flag[j] *= 2;
    }
    ff = 0;
    for (z = 1; z <= fnum; z++) {
      flag[z] += ff;
      ff = flag[z] / 10;
      flag[z] %= 10;
    }
    while (ff != 0) {
      flag[++fnum] = ff % 10;
      ff /= 10;
    }
  }
  return 0;
}
int main() {
  int i;
  int n, flag[1001], xx;
  while (scanf("%d", &n) != EOF) {
    memset(flag, 0, sizeof(flag));  //开始时目标状态全为0；
    memset(res, 0, sizeof(res));    //十进制答案初始化
    memset(ans, 0, sizeof(ans));    //二进制答案初始化
    for (i = 1; i <= n; i++) scanf("%d", &array[i]);
    for (i = n; i >= 1;
         i--)  //贪心从后往前，比如解决第四个不一样的问题就必须把前三个状态换成0
    // 0 1
    {
      if (flag[i] == array[i])  //如果一样就不需要转化；
        continue;
      flag[i - 1] = 1;  //如果不一样，那么就需要把前面的转化成0 0 0……1
      //之后加上一步把第i变成一样，然后加上前n-1个(0 0
      // 0……1)变成全0，经本人推出公式是2^n-1,那么刚好对应二进制里面第n+1位为1了；
      ans[i] = 1;
    }
    //二进制算出来了，后面的就是转化问题了，一个地方需要注意，也没什么好讲的了
    getres(n);
    xx = 0;
    for (i = 1000; i >= 1; i--) {
      if (xx == 0 && res[i] == 0) continue;
      xx = 1;
      printf("%d", res[i]);
    }
    if (xx == 0) printf("0");
    printf("\n");
  }
  return 0;
}