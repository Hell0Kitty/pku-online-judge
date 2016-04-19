#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define MAXN 1000000
#define MAXA 10000

bool f[MAXN + MAXA];

int main(int argc, char *argv[]) {
  int a[4], t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    memset(f, false, sizeof(f));
    f[0] = true;
    sort(a, a + 4);
    int count = 0;
    int maxF = 0;
    for (int i = 1; i <= MAXN; i++) {
      for (int j = 0; j < 4; j++) {
        if (i - a[j] >= 0) {
          if (f[i - a[j]]) {
            f[i] = true;
            break;
          }
        }
      }
      if (!f[i]) {
        count++;
        maxF = i;
      }
    }
    printf("%d\n", count);
    bool flag = true;
    for (int i = MAXN + 1; i <= MAXN + a[0]; i++) {
      for (int j = 0; j < 4; j++) {
        if (i - a[j] >= 0) {
          if (f[i - a[j]]) {
            f[i] = true;
          }
        }
      }
      if (!f[i]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      printf("%d\n", maxF);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
