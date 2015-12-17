#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

void js(int (*a)[2], int (*c)[2]) {
  int b[2][2];
  b[0][0] = (a[0][0] * c[0][0] + a[0][1] * c[1][0]) % 10000;
  b[0][1] = (a[0][0] * c[0][1] + a[0][1] * c[1][1]) % 10000;
  b[1][0] = (a[1][0] * c[0][0] + a[1][1] * c[1][0]) % 10000;
  b[1][1] = (a[1][0] * c[0][1] + a[1][1] * c[1][1]) % 10000;
  a[0][0] = b[0][0];
  a[0][1] = b[0][1];
  a[1][0] = b[1][0];
  a[1][1] = b[1][1];
}
int main() {
  int a[2][2], b[2][2];
  int n;
  while (scanf("%d", &n), n >= 0) {
    if (n == 0) {
      printf("0\n");
      continue;
    }
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
    b[0][0] = 1;
    b[0][1] = 0;
    b[1][0] = 0;
    b[1][1] = 1;

    for (; n > 0; n = n >> 1, js(a, a)) //短小精悍呀、呵呵
      if (n & 1)
        js(b, a);
    printf("%d\n", b[0][1]);
  }
    return 0;
}