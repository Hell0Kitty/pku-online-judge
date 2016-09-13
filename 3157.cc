#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

string st;

int main() {
  cin >> st;
  bool java = false;
  bool cpp = false;
  if (st[0] == '_') {
    cout << "Error!" << endl;
    return 0;
  }
  for (int i = 0; i < st.length(); i++)
    if (st[i] >= 'A' && st[i] <= 'Z') {
      if (i == 0) {
        cout << "Error!" << endl;
        return 0;
      }
      java = true;
      break;
    }
  if (st.find('_') != string::npos) cpp = true;
  if (cpp && java) {
    cout << "Error!" << endl;
    return 0;
  }
  if (cpp) {
    if (st.find("__") != string::npos || st[st.length() - 1] == '_') {
      cout << "Error!" << endl;
      return 0;
    }
    for (int i = 0; i < st.length(); i++)
      if (st[i] == '_') {
        st.erase(i, 1);
        st[i] = st[i] - 'a' + 'A';
      }
  } else {
    for (int i = 0; i < st.length(); i++)
      if (st[i] >= 'A' && st[i] <= 'Z') {
        st[i] = st[i] - 'A' + 'a';
        st.insert(i, "_");
      }
  }
  cout << st << endl;
  return 0;
}
