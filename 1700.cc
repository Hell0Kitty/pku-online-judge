#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 1006

int n, f[maxn];

int cal(int a, int b, int y, int z) {
  return min(z + a + y + a, b + a + z + b);
}

void work() {
  int i = n - 1;
  int ans = 0;
  while (i > 2) {
    ans += cal(f[0], f[1], f[i - 1], f[i]);
    i -= 2;
  }
  if (i == 2)
    ans += f[0] + f[1] + f[2];
  else
    ans += f[1];
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &f[i]);
    sort(f, f + n);
    if (n == 1) {
      printf("%d\n", f[0]);
      continue;
    }
    work();
  }
  return 0;
}
