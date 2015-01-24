// Memory Time
// 256K   32MS

#include <iostream>
#include <string.h>
using namespace std;

const int size = 1000;  //大数位数

int main(void) {
  int n;  //进制数
  while (cin >> n && n) {
    char *Stra = new char[size + 1];  //字符串n进制被减数
    char *Strb = new char[size + 1];  //字符串n进制减数
    int pa = 0;                       // Stra[]指针
    int Diga = 0, Digb = 0;           //数字10进制被减数、减数

    cin >> Stra >> Strb;

    for (int j = 0; Strb[j]; j++)  //把n进制字符串减数 转换为 10进制数字减数
    {
      Digb *= n;
      Digb += Strb[j] - '0';
    }
    for (int i = 0; Stra[i]; i++)  //把n进制字符串被减数 转换为 10进制数字被减数
    {
      Diga *= n;
      Diga += Stra[i] - '0';

      if (Diga >= Digb)  //同余模公式，为避免大数计算，进制转化时顺便求模
        Diga %= Digb;
    }
    if (!Diga)
      cout << 0 << endl;
    else {
      while (Diga)  //把10进制数字模 转换为 n进制字符串模
      {
        Stra[pa++] = Diga % n + '0';
        Diga /= n;
      }
      for (pa--; pa >= 0; pa--) cout << Stra[pa];
      cout << endl;
    }

    delete Stra;
    delete Strb;
  }
  return 0;
}