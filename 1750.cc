#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxl 20

char st[2][maxl];

int main() {
  int sum = 0;
  int i = 0;
  st[1][0] = '\0';
  while (scanf("%s", st[i]) != EOF) {
    int same = 0;
    for (int j = 0; j < sum + 1; j++)
      if (st[i][j] == st[i ^ 1][j] && st[i][j] != 0)
        same++;
      else
        break;
    if (same == sum + 1)
      sum++;
    else
      sum = same;
    for (int j = 0; j < sum; j++) putchar(' ');
    printf("%s\n", st[i]);
    i ^= 1;
  }
  return 0;
}