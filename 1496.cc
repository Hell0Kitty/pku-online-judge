
#include <iostream>
#include <string>
using namespace std;
int c[27][27] = {0};

void play_table(void) {
  for (int i = 0; i <= 26; i++)
    for (int j = 0; j <= i; j++)
      if (!j || i == j)
        c[i][j] = 1;
      else
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  c[0][0] = 0;
  return;
}

int main(int i, int j) {
  play_table();

  char str[6];
  while (cin >> str) {
    int len = strlen(str);
    bool flag = false;
    for (i = 1; i < len; i++)
      if (str[i - 1] >= str[i]) {
        cout << 0 << endl;
        flag = true;
      }

    if (!flag) {
      int sum = 0;  // str的值，初始为0
      for (i = 1; i < len; i++)
        sum += c[26][i];  // c[26][i]表示 长度为i的字符串的个数

      for (i = 0; i < len; i++)

      {
        char ch = (!i) ? 'a' : str[i - 1] + 1;

        while (ch <= str[i] - 1)

        {
          sum += c['z' - ch][len - 1 - i];
          ch++;
        }
      }

      cout << ++sum << endl;
        }
    }
    return 0;
}