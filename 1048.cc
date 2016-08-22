#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
char code[110][110];
char num[30];
int p;

void getpoint(int &x, int &y) {
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++)
      if ('?' == code[i][j]) {
        x = i;
        y = j;
        return;
      }
}

int find(int x, int y, int div, int flag) {
  switch (code[x][y]) {
    case 'o':
      return !find(x, y - 1, -1, 2);
    case '-':
      return find(x, y + div, div, flag);
    case '|':
      return find(x + div, y, div, flag);
    case ')':
      return find(x - 1, y - 3, -1, 2) & find(x + 1, y - 3, -1, 2);
    case '>':
      return find(x - 1, y - 3, -1, 2) | find(x + 1, y - 3, -1, 2);
    case '+':
      if ('-' == code[x][y - 1] && flag != 4)
        return find(x, y - 1, -1, 2);
      else if ('-' == code[x][y + 1] && flag != 2)
        return find(x, y + 1, 1, 4);
      else if ('|' == code[x - 1][y] && flag != 1)
        return find(x - 1, y, -1, 3);
      else
        return find(x + 1, y, 1, 1);
    default:
      return num[code[x][y] - 'A'] - '0';
  }
}

int main() {
  memset(code, 0, sizeof(code));
  while (EOF != scanf("%[^\n]%*c", code[0])) {
    int i, x, y, ans;
    for (i = 1; '*' != code[i - 1][0]; i++) gets(code[i]);
    getpoint(x, y);
    while (gets(num), '*' != num[0]) {
      if ('-' == code[x][y - 1])
        ans = find(x, y - 1, -1, 2);
      else if ('-' == code[x][y + 1])
        ans = find(x, y + 1, 1, 4);
      else if ('|' == code[x - 1][y])
        ans = find(x - 1, y, -1, 3);
      else
        ans = find(x + 1, y, 1, 1);
      printf("%d\n", ans);
    }
    putchar(10);
    memset(code, 0, sizeof(code));
  }
  return 0;
}
