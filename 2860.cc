#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 20

int n, m, k;
int f[maxn], g[maxn];

void input() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) scanf("%d", &f[i]);
  for (int i = 0; i < k; i++) scanf("%d", &g[i]);
}

void work() {
  int ans = 0;
  for (int i = 0; i < k; i++)
    if (f[i] > g[i]) ans += f[i] - g[i];
  printf("%d\n", ans);
}

int main() {
  input();
  work();
  return 0;
}
