#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
char input[20];
int spos, epos;
__int64 minup, mindown;
__int64 gcd(__int64 a, __int64 b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void trim(__int64 &up, __int64 &down) {
  __int64 gcdval;
  while ((gcdval = gcd(up, down)) != 1) {
    up /= gcdval;
    down /= gcdval;
  }
}

bool allZero() {
  for (int i = strlen(input) - 4; i >= 2; i--)
    if (input[i] != '0') return false;
  return true;
}
int main() {
  while (scanf("%s", input) && strcmp(input, "0") != 0) {
    if (!allZero()) {
      mindown = -1;
      epos = strlen(input) - 4;  //输入字符串数字位的结束位置
      spos = 2;                  //小数点后面的起始位置
      __int64 up = 0, down = 0, upd = 0, downd = 0, dupdown;

      //枚举循环部分的起始位置
      for (int t = spos; t <= epos; t++) {
        upd = up = 0;
        int k = spos;
        while (k < t && input[k] == '0') k++;  //找到非循环部分第一个不为0的位置
        for (; k <= epos; k++) {
          if (k < t)
            upd = upd * 10 + int(input[k] - '0');  //统计非循环部分的分子值
          if (k >= t)
            up = up * 10 + int(input[k] - '0');  //统计循环部分的分子值
        }

        downd = pow(10.0, t - spos);        //非循环部分的分母值
        down = pow(10.0, epos - spos + 1);  //所有小数部分的分母值
        dupdown = pow(10.0, epos - t + 1);  //循环部分的分母值
        down = down - down / dupdown;  //制造循环部分小数的最终分母值
        if (up != 0) trim(up, down);     //约分
        if (upd != 0) trim(upd, downd);  //约分

        __int64 newup, newdown;
        newup = up * downd + down * upd;
        newdown = down * downd;
        if (newup != 0) trim(newup, newdown);  //计算最终结果

        if (mindown == -1 || newdown < mindown)  //取分母最小的
        {
          mindown = newdown;
          minup = newup;
        }
      }
      printf("%I64d/%I64d\n", minup, mindown);
    } else
      printf("0/1\n");
  }
  return 0;
}
