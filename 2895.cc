#include <iostream>
using namespace std;
inline bool equal(int a, int b) {
  if (a < 15 && b < 15 && a / 3 == b / 3)
    return true;
  else if (a < 19 && b < 19 && a >= 15 && b >= 15)
    return true;
  else if (a < 22 && b < 22 && a >= 19 && b >= 19)
    return true;
  else if (a >= 22 && b >= 22)
    return true;
  else
    return false;
}
int main() {
  int test, map[255];
  map['A'] = map['D'] = map['G'] = map['J'] = map['M'] = map['P'] = map['T'] =
      map['W'] = 1;
  map['B'] = map['E'] = map['H'] = map['K'] = map['N'] = map['Q'] = map['U'] =
      map['X'] = 2;
  map['C'] = map['F'] = map['I'] = map['L'] = map['O'] = map['R'] = map['V'] =
      map['Y'] = 3;
  map['S'] = map['Z'] = 4;
  map[' '] = 1;
  cin >> test;
  while (test--) {
    int t1, t2, total = 0;
    char str[1024];
    cin >> t1 >> t2;
    cin.get();
    cin.getline(str, 1024);
    total += t1 * map[str[0]];
    for (int i = 1; str[i] != '\0'; i++)
      if (str[i] != ' ' && str[i - 1] != ' ' &&
          equal(str[i] - 65, str[i - 1] - 65))
        total += map[str[i]] * t1 + t2;
      else
        total += map[str[i]] * t1;
    cout << total << endl;
  }
  return 0;
}
