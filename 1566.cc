#include <iostream>
#include <string>
using namespace std;

string st;

bool syll(char a) {
  if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y')
    return true;
  return false;
}

bool judge(string a, int num) {
  int i, l = a.length(), temp = 0;

  if (syll(a[0])) temp++;
  for (i = 1; i < l; i++)
    if (syll(a[i]) && !syll(a[i - 1])) temp++;
  if (temp == num) return true;
  return false;
}

void work() {
  string st1, st2, st3;
  int t;

  t = st.find("/");
  st1 = st.substr(0, t);
  st.erase(0, t + 1);
  t = st.find("/");
  st2 = st.substr(0, t);
  st.erase(0, t + 1);
  st3 = st;
  if (!judge(st1, 5)) {
    cout << "1" << endl;
    return;
  }
  if (!judge(st2, 7)) {
    cout << "2" << endl;
    return;
  }
  if (!judge(st3, 5)) {
    cout << "3" << endl;
    return;
  }
  cout << "Y" << endl;
}

int main() {
  while (getline(cin, st) && st != "e/o/i") work();
  return 0;
}
