#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 2008

int n;
char line[maxn];

void input() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char ch[3];
    scanf("%s", ch);
    line[i] = ch[0];
  }
}

void work() {
  int l = 0, r = n - 1;
  int ncount = 0;
  while (l <= r) {
    int a = l, b = r;
    while (a < b && line[a] == line[b]) a++, b--;
    if (line[a] > line[b])
      putchar(line[r--]);
    else
      putchar(line[l++]);
    ncount++;
    if (ncount % 80 == 0) putchar('\n');
  }
  if (ncount % 80) putchar('\n');
}

int main() {
  input();
  work();
  return 0;
}
