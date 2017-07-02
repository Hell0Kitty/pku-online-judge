#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 10

int f[maxn];

void input() {
  for (int i = 1; i < 9; i++) scanf("%d", &f[i]);
}

void print() {
  char ch[2];
  ch[0] = '+';
  ch[1] = '-';
  int i = 0;
  while (i < 9 && f[i] == 0) i++;
  if (i >= 9) {
    printf("0\n");
    return;
  }
  if (i == 8) {
    printf("%d\n", f[8]);
    return;
  }
  if (f[i] < 0) putchar('-');
  if (abs(f[i]) > 1) printf("%d", abs(f[i]));
  putchar('x');
  if (8 - i > 1) printf("^%d", 8 - i);
  i++;
  for (; i < 8; i++)
    if (f[i]) {
      printf(" %c ", ch[f[i] < 0]);
      if (abs(f[i]) > 1) printf("%d", abs(f[i]));
      putchar('x');
      if (8 - i > 1) printf("^%d", 8 - i);
    }
  if (f[i] != 0) printf(" %c %d", ch[f[i] < 0], abs(f[i]));
  putchar('\n');
}

int main() {
  while (scanf("%d", &f[0]) != EOF) {
    input();
    print();
  }
  return 0;
}
