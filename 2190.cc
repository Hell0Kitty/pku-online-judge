
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string str;
  cin >> str;
  int i, j, pos, sum, ans;
  bool flag;
  pos = str.find('?');

  if (pos == 9) {
    sum = 0;
    flag = false;
    for (i = 0, j = 10; i < 9; i++, j--) {
      sum += (str[i] - 48) * j;
    }
    for (ans = 0; ans < 10; ans++) {
      int tmp = sum;
      tmp += ans;
      if (tmp % 11 == 0) {
        flag = true;
        break;
      }
    }
    if (flag)
      cout << ans << endl;
    else {
      sum += 10;
      if (sum % 11 == 0)
        cout << "X" << endl;
      else
        cout << -1 << endl;
    }
  }
  // 如果？不在结尾的情况，也有两种情况讨论！
  else {
    if (str[9] == 'X') {
      sum = 0;
      flag = false;
      for (i = 0, j = 10; i < 9; i++, j--) {
        if (str[i] == '?')
          continue;
        else
          sum += (str[i] - 48) * j;
      }
      sum += 10;
      for (ans = 0; ans <= 9; ans++) {
        int tmp = sum;
        tmp += ans * (10 - pos);
        if (tmp % 11 == 0) {
          flag = true;
          break;
        }
      }
      if (flag)
        cout << ans << endl;
      else
        cout << "-1" << endl;
    } else {
      sum = 0;
      flag = false;
      for (i = 0, j = 10; i < 10; i++, j--) {
        if (str[i] == '?')
          continue;
        else
          sum += (str[i] - 48) * j;
      }
      for (ans = 0; ans <= 9; ans++) {
        int tmp = sum;
        tmp += ans * (10 - pos);
        if (tmp % 11 == 0) {
          flag = true;
          break;
        }
      }
      if (flag)
        cout << ans << endl;
      else
        cout << "-1" << endl;
    }
  }
}
/*
020110331?
156881111?
?201103311
03?1103311
1
X
0
3
*/
