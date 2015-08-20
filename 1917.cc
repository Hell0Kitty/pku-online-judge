#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
  int tc, len1, len2, i, j, pos1, pos2, pos3, pos4;
  string input1, input2, s1, s2, s3, s4, s5, s6;
  bool flag1, flag2;
  cin >> tc;
  cin.get();  //放在这里才对
  while (tc--) {
    // cin.get();//之前放在这个位置，无限WA，因为每一次都取一个，所以就造成了输入的出错！
    getline(cin, input1);
    getline(cin, input2);
    s1.clear();
    s2.clear();
    s3.clear();
    s4.clear();
    s5.clear();
    s6.clear();
    flag1 = true;
    flag2 = true;
    len1 = input1.length();
    len2 = input2.length();
    for (i = 0; i < len1; i++) {
      if (input1[i] == '<' && flag1) {
        flag1 = false;
        pos1 = i;
      } else if (input1[i] == '<' && !flag1) {
        pos3 = i;
      } else if (input1[i] == '>' && flag2) {
        flag2 = false;
        pos2 = i;
      } else if (input1[i] == '>' && !flag2) {
        pos4 = i;
      }
    }
    for (i = 0; i < pos1; i++) {
      s5.push_back(input1[i]);
    }
    for (i = pos1 + 1; i < pos2; i++) {
      s1.push_back(input1[i]);
    }
    for (i = pos2 + 1; i < pos3; i++) {
      s2.push_back(input1[i]);
    }
    for (i = pos3 + 1; i < pos4; i++) {
      s3.push_back(input1[i]);
    }
    for (i = pos4 + 1; i < len1; i++) {
      s4.push_back(input1[i]);
    }
    for (i = 0; i < len2 && input2[i] != '.'; i++) {
      s6.push_back(input2[i]);
    }
    cout << s5 << s1 << s2 << s3 << s4 << endl;
    cout << s6 << s3 << s2 << s1 << s4 << endl;
  }
}
