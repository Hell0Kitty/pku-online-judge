#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 1005

int f[maxn], g[maxn], n;

void input() {
  for (int i = 0; i < n; i++) scanf("%d", &f[i]);
}

void work() {
  int ans = 0;
  while (1) {
    ans++;
    for (int i = 0; i < n; i++) g[i] = f[i] / 2;
    for (int i = 0; i < n - 1; i++) {
      f[i + 1] = f[i + 1] / 2 + g[i];
      f[i + 1] += f[i + 1] & 1;
    }
    f[0] = g[n - 1] + f[0] / 2;
    f[0] += f[0] & 1;
    bool ok = true;
    for (int i = 1; i < n; i++)
      if (f[i] != f[0]) ok = false;
    if (ok) break;
  }
  printf("%d %d\n", ans, f[0]);
}

int main() {
  while (scanf("%d", &n), n) {
    input();
    work();
  }
  return 0;
}
