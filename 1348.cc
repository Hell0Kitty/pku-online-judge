#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Nod {
  int son;  //分子
  int mon;  //分母
} num[5];   //以 分子/分母 形式保存一个数

void getNum(int *a)  //将a数组转换成 分子/分母 形式
{
  int i;
  for (i = 0; i < 4; i++) {
    num[i].son = a[i];
    num[i].mon = 1;
  }
}

Nod operate(Nod a, Nod b, int ch)  //进行四则运算
{
  Nod temp;
  if (ch == 0)  // '+'
  {
    temp.mon = a.mon * b.mon;
    temp.son = a.son * b.mon + b.son * a.mon;
  } else if (ch == 1)  // '-'
  {
    temp.mon = a.mon * b.mon;
    temp.son = a.son * b.mon - b.son * a.mon;
  } else if (ch == 2)  //  '*'
  {
    temp.mon = a.mon * b.mon;
    temp.son = a.son * b.son;
  } else if (ch == 3)  //  '/'
  {
    temp.mon = a.mon * b.son;
    temp.son = b.mon * a.son;
  }
  return temp;
}

int computing(int *a, int e) {
  getNum(a);  //获得  分子/分母 的表示方式
  Nod temp1, temp2, temp3;
  int i, j, k;

  // ((a#b)#c)#d   '#'号代表运算符号
  for (i = 0; i < 4; i++) {
    temp1 = operate(num[0], num[1], i);
    if (temp1.mon == 0) continue;  //分母为0情况
    for (j = 0; j < 4; j++) {
      temp2 = operate(temp1, num[2], j);
      if (temp2.mon == 0) continue;
      for (k = 0; k < 4; k++) {
        temp3 = operate(temp2, num[3], k);
        if (temp3.mon == 0) continue;
        if (temp3.son % temp3.mon == 0 && temp3.son / temp3.mon == e) return 1;
      }
    }
  }

  //(a#(b#(c#d)))
  for (i = 0; i < 4; i++) {
    temp1 = operate(num[2], num[3], i);
    if (temp1.mon == 0) continue;
    for (j = 0; j < 4; j++) {
      temp2 = operate(num[1], temp1, j);
      if (temp2.mon == 0) continue;
      for (k = 0; k < 4; k++) {
        temp3 = operate(num[0], temp2, k);
        if (temp3.mon == 0) continue;
        if (temp3.son % temp3.mon == 0 && temp3.son / temp3.mon == e) return 1;
      }
    }
  }
  //(a#b)#(c#d)
  for (i = 0; i < 4; i++) {
    temp1 = operate(num[0], num[1], i);
    if (temp1.mon == 0) continue;
    for (j = 0; j < 4; j++) {
      temp2 = operate(num[2], num[3], j);
      if (temp2.mon == 0) continue;
      for (k = 0; k < 4; k++) {
        temp3 = operate(temp1, temp2, k);
        if (temp3.mon == 0) continue;
        if (temp3.son % temp3.mon == 0 && temp3.son / temp3.mon == e) return 1;
      }
    }
  }
  return 0;
}

int main() {
  int a[5], e;
  while (~scanf("%d", &a[0]) && a[0] != -1) {
    scanf("%d%d%d%d", &a[1], &a[2], &a[3], &e);
    int i, j;
    for (j = 0; j < 4; j++) printf("%d ", a[j]);
    for (i = 0; i < 24; i++) {
      if (computing(a, e) == 1) break;
      next_permutation(a, a + 4);  //获取下一个字典序
    }
    printf("%d ", e);
    if (i < 24)
      puts("OK!");
    else
      puts("NO!");
  }
  return 0;
}
