#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int way[8][3] = {{0, 1, 2},
                       {3, 4, 5},
                       {6, 7, 8},
                       {0, 3, 6},
                       {1, 4, 7},
                       {2, 5, 8},
                       {0, 4, 8},
                       {2, 4, 6}};
char s[10];
bool check(char c) {
  int i, j;
  for (i = 0; i < 8; ++i) {
    for (j = 0; j < 3; ++j) {
      if (s[way[i][j]] != c) break;
    }
    if (j == 3) return true;
  }
  return false;
}

int main() {
  int x, o;
  while (strcmp(gets(s), "end")) {
    x = count(s, s + 9, 'X');
    o = count(s, s + 9, 'O');
    if (x < o || o + 1 < x || x < 3)
      puts("invalid");
    else if (x > o && check('X') && !check('O'))
      puts("valid");
    else if (x == o && check('O') && !check('X'))
      puts("valid");
    else if (x + o == 9 && !check('X') && !check('O'))
      puts("valid");
    else
      puts("invalid");
  }
  return 0;
}
