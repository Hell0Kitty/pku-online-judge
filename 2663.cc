#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
long long f[50];
int main() {
  int n;
  while (scanf("%d", &n) && n != -1) {
    f[0] = 1, f[2] = 3;
    for (int i = 4; i <= n; i++) f[i] = f[i - 2] * 4 - f[i - 4];
    printf("%I64d\n", f[n]);
  }
}
