#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

map<char, char> m;

int main() {
  string input, key;
  int len, i;
  cin >> key;
  cin.get();
  len = key.length();
  for (i = 0; i < len; i++) m['a' + i] = key[i];
  getline(cin, input);
  len = input.length();
  char temp;
  for (i = 0; i < len; i++) {
    if (isupper(
            input
                [i]))  //判断是否为大写字符，如果是将其转换为小写，得到结果后再大写输出
    {
      temp = tolower(input[i]);
      temp = m[temp];
      temp = toupper(temp);
      cout << temp;
    } else if (isspace(input[i]))  //判断是否为空格
      cout << input[i];
    else
      cout << m[input[i]];
  }
  cout << endl;
}
