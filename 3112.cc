#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 1005

int n, m, p;
int ans;
int f[maxn];

void work() {
  ans = 0;
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a;
      scanf("%d", &a);
      if (a)
        f[j]++;
      else if (f[j] != 0) {
        if (f[j] >= p) ans++;
        f[j] = 0;
      }
    }
  }
  for (int i = 0; i < m; i++)
    if (f[i] >= p && f[i] != 0) ans++;
  printf("%d\n", ans);
}

int main() {
  while (scanf("%d%d%d", &m, &n, &p), n | m | p) {
    work();
  }
  return 0;
}
