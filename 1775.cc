#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int fac[20];
bool f[1000005];
int tot;

void dfs(int i, int sum) {
  if (sum > 1000000) return;
  f[sum] = true;
  if (i == tot) return;
  dfs(i + 1, sum + fac[i]);
  dfs(i + 1, sum);
}

int main() {
  fac[0] = 1;
  tot = 0;
  for (int i = 1; fac[i - 1] <= 1000000; i++) {
    fac[i] = fac[i - 1] * i;
    tot++;
  }
  memset(f, 0, sizeof(f));
  dfs(0, 0);
  int n;
  while (scanf("%d", &n), n >= 0)
    if (f[n] && n != 0)
      printf("YES\n");
    else
      printf("NO\n");
  return 0;
}