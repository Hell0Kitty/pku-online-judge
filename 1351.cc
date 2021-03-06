#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int n;
long long f[20][5][2][2];

int main() {
  memset(f, 0, sizeof(f));
  f[1][1][0][0] = 1;
  f[1][2][0][1] = 1;
  f[1][3][0][1] = 1;
  f[1][4][0][0] = 1;
  for (int i = 2; i <= 17; i++) {
    f[i][4][0][0] = f[i][1][0][0] = f[i - 1][1][0][0];
    f[i][4][0][1] = f[i][1][0][1] =
        f[i - 1][1][0][1] + f[i - 1][2][0][1] + f[i - 1][3][0][1];
    f[i][4][1][0] = f[i][1][1][0] =
        f[i - 1][1][1][0] + f[i - 1][4][0][0] + f[i - 1][4][1][0];
    f[i][4][1][1] = f[i][1][1][1] = f[i - 1][1][1][1] + f[i - 1][2][1][1] +
                                    f[i - 1][3][1][1] + f[i - 1][4][1][1] +
                                    f[i - 1][4][0][1];
    f[i][3][0][1] = f[i][2][0][1] = f[i - 1][1][0][0] + f[i - 1][1][0][1] +
                                    f[i - 1][2][0][1] + f[i - 1][3][0][1] +
                                    f[i - 1][4][0][0] + f[i - 1][4][0][1];
    f[i][3][1][1] = f[i][2][1][1] = f[i - 1][1][1][0] + f[i - 1][1][1][1] +
                                    f[i - 1][2][1][1] + f[i - 1][3][1][1] +
                                    f[i - 1][4][1][0] + f[i - 1][1][1][1];
  }
  while (scanf("%d", &n), n != -1) {
    printf("%d: ", n);
    printf("%I64d\n",
           f[n][1][1][1] + f[n][2][1][1] + f[n][3][1][1] + f[n][4][1][1]);
  }
  return 0;
}
