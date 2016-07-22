#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int t;
int n;
int cas;
int left, right, sum;
int h[105][105];
bool visit[105][105];

bool dfs(int a, int b, int down, int up) {
  if (h[a][b] < down || h[a][b] > up) return false;
  if (a == n && b == n) return true;
  visit[a][b] = true;
  if (a > 1 && !visit[a - 1][b] && dfs(a - 1, b, down, up)) return true;
  if (b > 1 && !visit[a][b - 1] && dfs(a, b - 1, down, up)) return true;
  if (a < n && !visit[a + 1][b] && dfs(a + 1, b, down, up)) return true;
  if (b < n && !visit[a][b + 1] && dfs(a, b + 1, down, up)) return true;
  return false;
}

int solve(int l, int r) {
  int mid;
  int down, up;
  while (l <= r) {
    mid = (l + r) >> 1;
    down = max(h[1][1] - mid, 0);
    for (; down <= h[1][1]; down++) {
      memset(visit, 0, sizeof(visit));
      up = down + mid;
      if (dfs(1, 1, down, up)) break;
    }
    if (down <= h[1][1])
      r = mid - 1;
    else
      l = mid + 1;
  }
  return l;
}

int main() {
  scanf("%d", &t);
  for (cas = 1; cas <= t; cas++) {
    int __max = -1, __min = 500;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &h[i][j]);
        if (h[i][j] > __max) __max = h[i][j];
        if (h[i][j] < __min) __min = h[i][j];
      }
    }
    sum = __max - __min;
    int ans = solve(0, sum);
    printf("Scenario #%d:\n%d\n\n", cas, ans);
  }
  return 0;
}
