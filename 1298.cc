#include <stdio.h>
#include <iostream>
#include <string>
#define F(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

int main() {
  char a[27] = {'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D',
                'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};
  string s;
  while (cin >> s && s != "ENDOFINPUT") {
    cin.ignore();
    getline(cin, s);
    F(i, 0, s.length() - 1)
    if (s[i] >= 65 && s[i] <= 90)
      printf("%c", a[s[i] - 65]);
    else
      printf("%c", s[i]);
    printf("\n");
    cin >> s;
  }
  return 0;
}
