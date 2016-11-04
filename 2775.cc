#include <iostream>
using namespace std;

const int mod = 9901;
int a[30005], size[30005], ans, n;

void insert(int x) {
  int p = 1;
  while (size[p]) {
    size[p]++;
    if (x <= a[p])
      p = p * 2;
    else
      p = p * 2 + 1;
  }
  a[p] = x;
  size[p] = 1;
}

int cal(int x, int mod) {
  int s = x, i;
  for (i = 1; i <= mod; i++) {
    if (s % mod == 1) break;
    s += x;
  }
  return i;
}

void DFS(int p) {
  ans = ans * cal(size[p], mod) % mod;
  if (size[p * 2]) DFS(p * 2);
  if (size[p * 2 + 1]) DFS(p * 2 + 1);
}

int main() {
  while (scanf("%d", &n), n) {
    memset(a, 0, sizeof(a));
    memset(size, 0, sizeof(size));
    int i, x;
    for (i = 1; i <= n; i++) {
      scanf("%d", &x);
      if (i == 1)
        a[1] = x, size[1] = 1;
      else
        insert(x);
    }
    ans = 1;
    DFS(1);
    for (i = 2; i <= n; i++) ans = ans * i % mod;
    printf("%d\n", ans);
  }
  return 0;
}
