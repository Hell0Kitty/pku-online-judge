#include <stdio.h>
char name[64][20];  //存储人名
main() {
  int n, i, j;
  int w, s, pos;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%s", name[i]);
  scanf("%d,%d", &w, &s);
  pos = w - 2;
  for (i = 0; i < n; i++) {
    for (j = 0; j < s; j++)  //走s步
    {
      pos++;                   //一步一步的走
      if (pos >= n) pos %= n;  //如果超出范围回到起点
      if (name[pos][18] != 1)
        continue;  //如果此人未被选出，继续向后走
      else {
        j--;
        continue;
      }  //如果此人被选出，使j不变，向下走
    }
    puts(name[pos]);    //走完s步，输出该人的名字
    name[pos][18] = 1;  //把此人标记为找过
  }
}
