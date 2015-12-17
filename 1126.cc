
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <cstring>
using namespace std;
string s;
bool ok(int x, int y) {
  if (x == y) {
    if (s[x] >= 'p' && s[x] <= 'z')
      return true;
    else
      return false;
  }
  if (s[x] == 'N') {
    if (ok(x + 1, y))
      return true;
    else
      return false;
  } else if (s[x] == 'C' || s[x] == 'D' || s[x] == 'E' || s[x] == 'I') {
    for (int i = x + 1; i <= y; i++)
      if (ok(x + 1, i) && ok(i + 1, y)) return true;
    // else  return false;
    return false;
  }
  return false;
}
int main() {
  char temp[1000];
  while (scanf("%s", temp) != EOF) {
    // if( s == "") break;
    s = temp;
    bool flag = false;
    if (s.length() == 1 && s[0] >= 'p' && s[0] <= 'z')
      flag = true;
    else if (ok(0, s.length() - 1))
      flag = true;
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}