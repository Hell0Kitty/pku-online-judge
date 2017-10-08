#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char st[15];

int com(int n, int r) {
  if (n - r < r) r = n - r;
  int i, j, s = 1;
  for (i = 0, j = 1; i < r; ++i) {
    s *= (n - i);
    for (; j <= r && s % j == 0; ++j) s /= j;
  }
  return s;
}

int main() {
  // freopen("t.txt", "r", stdin);
  gets(st);
  int len = strlen(st);
  if (len == 1) {
    printf("%d\n", st[0] - 'a' + 1);
    return 0;
  }
  bool ok = true;
  if (st[0] <= 'z' && st[0] >= 'a')
    ok = true;
  else
    ok = false;
  for (int i = 1; i < len; i++)
    if (!(st[i] <= 'z' && st[i] >= 'a' && st[i] > st[i - 1])) ok = false;
  if (!ok) {
    printf("0\n");
    return 0;
  }
  int ans = 26;
  for (int i = 2; i < len; i++) ans += com(26, i);
  ans += com(26, len) - com(26 - (st[0] - 'a'), len);
  for (int i = 1; i < len; i++)
    ans += com(26 - (st[i - 1] - 'a' + 1), len - i) -
           com(26 - (st[i] - 'a'), len - i);
  printf("%d\n", ans + 1);
  return 0;
}
