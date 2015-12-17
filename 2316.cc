#include <iostream>
#include <string>
using namespace std;
int main() {
  int d[10];
  string str;
  int i;
  cin >> str;
  int len = str.size();
  for (i = 0; i < len; ++i) {
    d[i] = str[i] - 48;
  }
  while (cin >> str) {
    for (i = 0; i < len; ++i) {
      d[i] += (str[i] - 48);
    }
  }
  for (i = 0; i < len; ++i) {
    d[i] %= 10;
    cout << d[i];
  }
  cout << endl;
  return 0;
}