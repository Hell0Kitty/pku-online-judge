#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define inf 0x7f7f7f7f

using namespace std;

int getbits(int n) {
  int res;
  res = 0;
  while (n) {
    if (n % 2 == 1) {
      res++;
    }
    n /= 2;
  }
  return res;
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 0) break;
    int tmp = getbits(n);
    int ans, tt;
    for (int i = n + 1;; i++) {
      tt = getbits(i);
      if (tt == tmp) {
        ans = i;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
