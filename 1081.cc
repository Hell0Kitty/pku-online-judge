#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define maxn 65

bool g[maxn][maxn];
int ans;
int n;
int c[maxn];
bool vis[maxn];
int lonely[maxn];

void check(int t) {
  memset(vis, 0, sizeof(vis));
  memset(lonely, 0, sizeof(lonely));
  for (int i = 0; i < t; i++) vis[c[i]] = true;
  int temp = 0;
  for (int i = 1; i <= n - 1; i++)
    for (int j = i + 1; j <= n; j++)
      if (vis[i] == vis[j] && !g[i][j]) {
        lonely[i]++;
        lonely[j]++;
      }
  for (int i = 0; i < n; i++) temp = max(temp, lonely[i]);
  ans = min(ans, temp);
}

void dfs(int now, int t) {
  if (now > n) return;
  if (t >= n / 2) {
    check(t);
    return;
  }
  c[t] = now;
  dfs(now + 1, t + 1);
  dfs(now + 1, t);
}

int main() {
  int a, b, maxa = 0;
  ans = 0x3f3f3f3f;
  while (scanf("%d", &a) != EOF) {
    maxa = max(a, maxa);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &b);
      g[a][b] = g[b][a] = true;
    }
  }
  n = maxa;
  dfs(1, 0);
  printf("%d\n", ans);
  return 0;
}
