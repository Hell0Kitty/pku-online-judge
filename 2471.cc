#include <cstdio>
#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> heap;
char ch, t[50];
int up = 0, down = 0, len = 0;
string str;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

char upper(char ch) { return ch > 'Z' ? ch - 'a' + 'A' : ch; }

int main() {
  heap.clear();
  while (EOF != (ch = fgetc(stdin))) {
    if (('a' <= ch && 'z' >= ch) || ('A' <= ch && 'Z' >= ch))
      t[len++] = upper(ch);
    else {
      if (0 == len) continue;
      len = t[len] = 0;
      str = t;
      if (str == "BULLSHIT") {
        down++;
        up += heap.size();
        heap.clear();
      } else
        heap.insert(str);
    }
  }
  int m = gcd(up, down);
  printf("%d / %d\n", up / m, down / m);
  return 0;
}
