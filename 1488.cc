
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
  string ans;
  int i = 0;
  while (getline(cin, ans)) {
    unsigned loc = 0;
    do {
      ++i;
      loc = ans.find('\"', loc);
      if (loc == string::npos) {
        --i;
        break;
      }
      if (i % 2)
        ans.replace(loc, 1, "``");
      else
        ans.replace(loc, 1, "''");
    } while (loc != string::npos);
    cout << ans << endl;
  }
  return 0;
}