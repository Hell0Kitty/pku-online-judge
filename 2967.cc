#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 1000005

int n;
int f[maxn];

int in() {
  char ch = '0';
  int ret = 0;
  while (ch <= '9' && ch >= '0') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret;
}

void input() {
  n = in();
  for (int i = 0; i < n; i++) f[i] = in();
}

bool ok(int a, int b, int c) { return a > c - b; }

bool work() {
  if (n <= 3) return false;
  if (ok(f[0], f[1], f[n - 1])) return false;
  for (int i = 0; i < n - 2; i++)
    if (ok(f[i], f[i + 1], f[i + 2])) return true;
  return false;
}

int main() {
  input();
  sort(f, f + n);
  if (work())
    printf("The set is accepted.\n");
  else
    printf("The set is rejected.\n");
  return 0;
}
