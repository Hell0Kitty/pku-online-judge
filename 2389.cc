#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main() {
  char a[50], b[50];
  int i, j, c[100], la, lb, lc;
  scanf(" %s %s", a, b);
  la = strlen(a);
  lb = strlen(b);
  memset(c, 0, sizeof(c));
  for (i = la - 1; i >= 0; i--)
    for (j = lb - 1; j >= 0; j--) {
      c[la - 1 - i + lb - 1 - j] += (a[i] - '0') * (b[j] - '0');
    }
  lc = 0;
  while (lc < 100) {
    if (c[lc] > 9) {
      c[lc + 1] += c[lc] / 10;
      c[lc] %= 10;
    }
    lc++;
  }
  for (lc = 99; lc > 0; lc--)
    if (c[lc]) break;
  for (i = lc; i >= 0; i--) {
    printf("%d", c[i]);
  }
  return 0;
}
