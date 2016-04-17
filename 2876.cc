#include <iostream>
#include <string>
using namespace std;

string s[13];

int main() {
  string tem;
  int i;
  s[0] = "-";
  for (i = 1; i < 13; ++i) {
    s[i] += s[i - 1];
    s[i] += s[i - 1];
    s[i] += s[i - 1];
    fill_n(s[i].begin() + s[i - 1].length(), s[i - 1].length(), ' ');
  }
  while (cin >> i) {
    cout << s[i] << endl;
  }
}
