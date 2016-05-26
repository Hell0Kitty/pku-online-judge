#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string var, no, And;
string tex, ans;
vector<string> a;

int main() {
  cin >> tex;
  while (tex != "0") {
    var = no = And = "";
    for (int i = 0; i < tex.size(); ++i) {
      if (tex[i] == 'p' || tex[i] == 'q' || tex[i] == 'r' || tex[i] == 's' ||
          tex[i] == 't') {
        var += tex[i];
      } else if (tex[i] == 'N') {
        no += tex[i];
      } else if (tex[i] == 'K' || tex[i] == 'A' || tex[i] == 'C' ||
                 tex[i] == 'E') {
        And += tex[i];
      }
    }
    if (var.size() == 0) {
      puts("no WFF possible");
      cin >> tex;
      continue;
    }
    a.clear();
    for (int i = 0; i < var.size(); ++i) {
      string tmp = "";
      tmp += var[i];
      if (no.size()) {
        tmp = no + tmp;
        no = "";
      }
      a.push_back(tmp);
    }
    for (int i = 0; i < And.size(); ++i) {
      if (a.size() == 1) break;
      string tmp = "";
      tmp += And[i];
      a[0] = tmp + a[0] + a[1];
      if (no.size()) {
        a[0] = "N" + a[0];
        no.erase(0, 1);
      }
      a.erase(a.begin() + 1, a.begin() + 2);
    }
    cout << a[0] << endl;
    cin >> tex;
  }

  return 0;
}
