#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char st[100];

bool check() {
  for (int i = 1; i < 4; i++)
    if (st[i] != st[i - 1]) return true;
  return false;
}

int main() {
  while (scanf("%s", st) != EOF) {
    if (st[0] == '-') break;
    printf("N=%s:\n", st);
    if (!check() || strlen(st) != 4) {
      printf("No!!\n");
      continue;
    }
    int t = 0;
    int len = 4;
    while (1) {
      sort(st, st + len);
      int x, y;
      x = y = 0;
      for (int i = len - 1; i >= 0; i--) x = x * 10 + st[i] - '0';
      for (int i = 0; i < len; i++) y = y * 10 + st[i] - '0';
      printf("%d-%d=%d\n", x, y, x - y);
      t++;
      if (x - y == 6174 || x - y == 0) break;
      x = x - y;
      len = 0;
      while (x > 0) {
        st[len] = x % 10 + '0';
        x /= 10;
        len++;
      }
    }
    printf("Ok!! %d times\n", t);
  }
  return 0;
}
