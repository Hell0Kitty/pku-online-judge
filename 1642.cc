#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 25

int n;
bool map[maxn][maxn][maxn];

void input() {
  memset(map, 0, sizeof(map));
  for (int i = 1; i <= n; i++) {
    int a;
    int j = 1;
    while (scanf("%d", &a), a) {
      for (int k = 1; k <= a; k++) map[i][j][k] = true;
      j++;
    }
  }
}

void work() {
  int i, j, k;
  i = 1;
  while (map[1][1][i]) {
    bool first = true;
    j = 1;
    while (map[j][1][i]) {
      k = 1;
      while (map[j][k][i]) k++;
      k--;
      if (first)
        first = false;
      else
        putchar(' ');
      printf("%d", k);
      j++;
    }
    i++;
    putchar('\n');
  }
  putchar('\n');
  i = 1;
  while (map[1][i][1]) {
    bool first = true;
    j = 1;
    while (map[1][i][j]) {
      k = 1;
      while (map[k][i][j]) k++;
      k--;
      if (first)
        first = false;
      else
        putchar(' ');
      printf("%d", k);
      j++;
    }
    i++;
    putchar('\n');
  }
  putchar('\n');
}

int main() {
  bool first = true;
  while (scanf("%d", &n), n) {
    if (first)
      first = false;
    else
      putchar('\n');
    input();
    work();
  }
  return 0;
}
