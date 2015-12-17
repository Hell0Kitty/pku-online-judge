
#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

#define MAX 1000  //改变数组大小，可以改变计算位数
char res[MAX];

void converse(char *num) {
  char temp;
  int length = strlen(num);
  for (int i = 0; i < length / 2; i++) {
    temp = num[i];
    num[i] = num[length - i - 1];
    num[length - i - 1] = temp;
  }
}

char *add(char *x, char *y)  //加法
{
  int tag = 0;  //标识是否进位
  int lengthx = strlen(x);
  int lengthy = strlen(y);
  int length = lengthx > lengthy ? lengthx : lengthy;
  int temp = 0;  //进位

  converse(x);  //逆置数组
  converse(y);
  for (int i = lengthx; i < length; i++)  //高位补零
  {
    x[i] = '0';
  }
  for (int i = lengthy; i < length; i++) {
    y[i] = '0';
  }

  int i = 0;
  while (i < length) {
    if (tag) {
      temp = 1;
      tag = 0;
    }
    if (x[i] - 48 + y[i] + temp > '9') {
      tag = 1;
      res[i] = x[i] + y[i] - '9' - 1 + temp;
      temp = 0;
      i++;
      continue;
    }
    res[i] = x[i] + y[i] - '0' + temp;
    temp = 0;
    i++;
  }
  if (tag) {
    res[i] += '1';
    res[i + 1] = '\0';
  } else {
    res[i] = '\0';
  }
  converse(res);
  return res;
}

int main(void) {
  memset(res, 0, sizeof(res));
  while (true) {
    char num1[MAX];
    scanf("%s", num1);
    if (strlen(num1) == 1 && num1[0] == '0') break;
    add(res, num1);
    // char num2[MAX];
    //
    // printf("\n%s", add(num1, num2));
  }
  printf("%s\n", res);

  return 0;
}