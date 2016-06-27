#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, a[30][30], v[30];
long long ans;
long long gcd(long long x, long long y) {
  long long t, r;
  if (x < y) {
    t = x;
    x = y;
    y = t;
  }
  while (y) {
    r = x % y;
    x = y;
    y = r;
  }
  return x;
}
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
void DFS(int t, long long res) {
  int i;
  if (t == 2) {
    ans = lcm(ans, res);
    return;
  }
  if (res != -1 && ans % res == 0) return;
  for (i = 1; i <= n; i++) {
    if (v[i] == 0 && a[t][i] != 0) {
      v[i] = 1;
      if (res != -1)
        DFS(i, gcd(res, a[t][i]));
      else
        DFS(i, a[t][i]);
      v[i] = 0;
    }
  }
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
    v[i] = 0;
  }
  ans = 1;
  v[1] = 1;
  DFS(1, -1);
  printf("%lld\n", ans);
}
