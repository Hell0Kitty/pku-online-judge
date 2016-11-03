#include <iostream>
using namespace std;

/*字符串转数字*/
int StrToNum(char* s) {
  int digit = 0;
  for (int i = 0; s[i]; i++) digit = digit * 10 + (s[i] - '0');

  return digit;
}

bool solve(int* exp) {
  char s[30];
  cin >> s;

  if (s[0] == 'E')  // END
    return false;
  else if (s[0] == 'B')  // BEGIN
    while (solve(exp))
      ;  //若因为OP返回，则继续；若因为END返回，则结束
  else if (s[0] == 'O')  // 0P
  {
    cin >> s;
    exp[0] += StrToNum(s);
    return solve(exp);
  } else  // LOOP
  {
    int TempExp[11] = {0};  //临时exp[]
    cin >> s;
    while (solve(TempExp))
      ;

    if (s[0] == 'n')  // LOOP n
    {
      for (int i = 10; i > 0; i--)
        TempExp[i] = TempExp[i - 1];  //表达式乘以n，则所有项的次数+1
      TempExp[0] = 0;
    } else  // LOOP Num
    {
      int x = StrToNum(s);
      for (int i = 0; i < 11; i++)
        TempExp[i] *= x;  //表达式乘以const，则所有项的系数*const
    }
    for (int i = 0; i < 11; i++) exp[i] += TempExp[i];
  }
  return true;
}

int main(void) {
  int test;
  cin >> test;
  for (int t = 1; t <= test; t++) {
    char s[6];
    int exp[11] = {0};  //指数为i的项，其系数为exp[i]

    solve(exp);

    cout << "Program #" << t << endl;
    cout << "Runtime = ";

    bool flag = false;
    bool before = false;  //标记输出当前项之前，是否输出过前面的项
    for (int i = 10; i >= 0; i--)
      if (exp[i])  //当系数不为0时，才输出该项
      {
        flag = true;

        if (before) {
          cout << '+';
          before = false;
        }

        if (!i)  //当指数为0时，直接输出系数
        {
          cout << exp[i];
          before = false;
        } else {
          bool sign = false;  //标记系数是否为1
          if (i && exp[i] != 1) {
            sign = true;
            cout << exp[i];
            before = true;
          }
          if (i)  //当指数不为0时
          {
            if (sign) cout << '*';
            cout << 'n';
            if (i != 1) cout << '^' << i;
            before = true;
          }
        }
      }
    if (!flag)
      cout << 0 << endl
           << endl;
    else
      cout << endl
           << endl;
  }
  return 0;
}
