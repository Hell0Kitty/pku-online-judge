#include <iostream>
using namespace std;
int main() {
  int num;
  char *a;
  int s, f, c, flag;
  while (cin >> num) {
    flag = 0;
    s = f = c = 0;
    a = new char[num];
    for (int i = 0; i < num; i++) {
      cin >> a[num];
      if (a[num] == 'S')
        s++;
      else if (a[num] == 'F')
        f++;
      else if (a[num] == 'C')
        c++;
    }
    if (s == num || f == num || c == num)
      flag = num;
    else if (s != 0 && f != 0 && c != 0)
      flag = num;
    else {
      if (s == 0)
        flag = f;
      else if (f == 0)
        flag = c;
      else if (c == 0)
        flag = s;
    }
    cout << flag << endl;
  }
}
