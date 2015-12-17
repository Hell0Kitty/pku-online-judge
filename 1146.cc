#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
  string str;
  while (cin >> str && str[0] != '#') {
    bool flag = true;
    if (next_permutation(str.begin(), str.end())) {
      flag = false;
      cout << str << endl;
    }
    if (flag) cout << "No Successor\n";
  }
  return 0;
}