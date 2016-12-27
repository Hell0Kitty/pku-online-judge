#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 30005

int n;
int cow[maxn];
int f[maxn][5];

void input() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &cow[i]);
}

void work() {
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      f[i][j] = f[i - 1][1];
      for (int k = 2; k <= j; k++) f[i][j] = min(f[i][j], f[i - 1][k]);
      if (cow[i] != j) f[i][j]++;
    }
  }
  int ans = n;
  for (int i = 1; i <= 3; i++) ans = min(ans, f[n][i]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      f[i][j] = f[i - 1][3];
      for (int k = 2; k >= j; k--) f[i][j] = min(f[i][j], f[i - 1][k]);
      if (cow[i] != j) f[i][j]++;
    }
  }
  for (int i = 1; i <= 3; i++) ans = min(ans, f[n][i]);
  printf("%d\n", ans);
}

int main() {
  input();
  work();
  return 0;
}
