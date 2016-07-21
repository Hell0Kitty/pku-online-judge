#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string str;
void make(int s, int e, int type) {
  int c = 0;
  for (int i = s; i < e; i++)
    if (str[i] == '(') c++;
  c += type;
  string res = "";
  for (int i = 0; i < c; i++) res += "()";
  str = str.substr(0, s) + res + str.substr(e, str.length() - e);
}
bool solve(int s, int e) {
  if (s == e)
    return false;
  else {
    int c = -1, end;
    for (end = s + 1; end < e && c; end++) switch (str[end]) {
        case '(':
          c--;
          break;
        case ')':
          c++;
          break;
      };
    if (solve(end, e))
      return true;
    else if (solve(s + 1, end - 1)) {
      make(end, e, 0);
      return true;
    } else if (end != e) {
      make(end, e, -1);
      make(s + 1, end - 1, 1);
      return true;
    } else
      return false;
  }
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    str.clear();
    while (true) {
      string tmp;
      cin >> tmp;
      if (tmp == "$") break;
      str += tmp;
    }
    if (!solve(0, str.length())) make(0, str.length(), 1);
    for (int i = 0; i < str.length(); i++) cout << str[i] << " ";
    cout << "$" << endl;
  }
  return 0;
}
