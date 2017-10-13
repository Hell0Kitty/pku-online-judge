#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int f[15], g[15];

int main() {
  f[0] = 0;
  int ans;
  for (int i = 1; i <= 12; i++) f[i] = (1 << i) - 1;
  g[0] = 0;
  for (int i = 1; i <= 12; i++) {
    g[i] = 0x3f3f3f3f;
    for (int j = 1; j <= i; j++) g[i] = min(g[i], g[i - j] * 2 + f[j]);
    printf("%d\n", g[i]);
  }
  return 0;
}
