#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> m;
map<string, string>::iterator it;

int main() {
  int l, n, i, len;
  string str1, str2;
  bool flag;
  cin >> l >> n;
  for (i = 0; i < l; i++) {
    cin >> str1 >> str2;
    m[str1] = str2;
  }
  for (i = 0; i < n; i++) {
    cin >> str1;
    flag = true;
    if (m[str1].length() != 0) {
      cout << m[str1] << endl;
      flag = false;
    }
    if (flag) {
      len = str1.length();
      if (str1[len - 1] == 'y' &&
          (str1[len - 2] != 'a' && str1[len - 2] != 'e' &&
           str1[len - 2] != 'i' && str1[len - 2] != 'o' &&
           str1[len - 2] != 'u')) {
        str1[len - 1] = 'i';
        str1 += "es";
      } else if (str1[len - 1] == 'o' || str1[len - 1] == 's' ||
                 str1[len - 1] == 'x' ||
                 (str1[len - 1] == 'h' &&
                  (str1[len - 2] == 'c' || str1[len - 2] == 's'))) {
        str1 += "es";
      } else
        str1 += "s";
      cout << str1 << endl;
    }
  }

  return 0;
}
