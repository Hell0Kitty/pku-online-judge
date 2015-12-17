#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;
int n;
int c[15] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int main() {
  while (scanf("%d", &n) != EOF && (n >= 0)) {
    if (n == 0 || n > 409114 || (n > 46234 && n < 362880) ||
        (n > 5914 && n < 40320) || (n > 874 && n < 5040) ||
        (n > 154 && n < 720) || (n > 34 && n < 120) || (n > 10 && n < 24)) {
      printf("NO\n");
      continue;
    }
    int p = 9;
    while (n > 0 && p >= 0) {
      if (n >= c[p]) {
        n -= c[p];
      }
      p--;
    }
    if (n == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}