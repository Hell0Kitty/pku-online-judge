#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 30005

int n, m;
int f[maxn], sum[maxn];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
  for (int i = 1; i <= n; i++) f[i] = f[i] % m;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (f[i] != 0) ans = max(ans, m - f[i]);
  printf("%d\n", ans);
  return 0;
}
