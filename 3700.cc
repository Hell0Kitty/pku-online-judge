#include <iostream>
using namespace std;
#define max(a, b) a > b ? a : b
int n, res, a[60];
int up[60], down[60];
void dfs(int u, int v, int t) {
  if (u + v >= res) return;
  if (t > n) {
    if (u + v < res) res = u + v;
    return;
  }
  int i, tmp;

  for (i = 1; i <= u; i++)
    if (up[i] < a[t]) break;
  tmp = up[i];
  up[i] = a[t];
  dfs(max(i, u), v, t + 1);
  up[i] = tmp;

  for (i = 1; i <= v; i++)
    if (down[i] > a[t]) break;
  tmp = down[i];
  down[i] = a[t];
  dfs(u, max(i, v), t + 1);
  down[i] = tmp;
}
int main() {
  int i;
  while (scanf("%d", &n) && n) {
    res = 100;
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    dfs(0, 0, 1);
    printf("%d\n", res);
  }
}
