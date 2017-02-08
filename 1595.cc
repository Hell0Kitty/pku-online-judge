#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
int prime[500], cnt = 0;
bool hash[524];
void Prime() {
  int t = (int)sqrt(1000.0) + 1;
  memset(hash, 0, sizeof(hash));
  for (int i = 3; i <= t; i += 2) {
    if (!hash[i >> 1]) {
      int x = i << 1;
      for (int j = i * i; j <= 1001; j += x) {
        hash[j >> 1] = true;
      }
    }
  }
  cnt = 1;
  prime[cnt++] = 1;
  prime[cnt++] = 2;
  t = 1000 / 2;
  for (int i = 1; i <= t; i++) {
    if (!hash[i]) {
      prime[cnt++] = i * 2 + 1;
    }
  }
}
void Solve(int num, int n) {
  int i = 0;
  for (i = 1; i < cnt; i++) {
    if (num < prime[i]) break;
  }
  i--;
  int t = (i + 1) / 2;
  if (2 * n >= i) {
    for (int j = 1; j <= i; j++) printf(" %d", prime[j]);
  } else {
    for (int j = t - n + 1; j <= t; j++) printf(" %d", prime[j]);
    if (i % 2 == 1) {
      for (int j = t + 1; j < t + n; j++) {
        printf(" %d", prime[j]);
      }
    } else
      for (int j = t + 1; j <= t + n; j++) {
        printf(" %d", prime[j]);
      }
  }
}
int main() {
  Prime();
  int num, n;
  while (scanf("%d %d", &num, &n) == 2) {
    printf("%d %d:", num, n);
    Solve(num, n);
    printf("\n\n");
  }
  return 0;
}
