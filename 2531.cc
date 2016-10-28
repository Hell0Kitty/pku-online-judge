#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#define inf 0x3fffffff
#define eps 1e-10

using namespace std;

int n;
int a[21][21];
int nx, ny;
int x[21], y[21];

int cal() {
  int sum = 0;
  for (int i = 0; i < nx; ++i) {
    for (int j = 0; j < ny; ++j) {
      if (a[x[i]][y[j]] != -1) sum += a[x[i]][y[j]];
    }
  }
  return sum;
}

int dfs(int i) {
  int ii, jj;
  if (i == n) {
    return cal();
  }
  x[nx] = i;
  nx++;
  ii = dfs(i + 1);
  nx--;
  y[ny] = i;
  ny++;
  jj = dfs(i + 1);
  ny--;
  return max(ii, jj);
}

int main() {
  while (scanf("%d", &n) != EOF) {
    memset(a, -1, sizeof(a));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
    nx = 0;
    ny = 0;
    printf("%d\n", dfs(0));
  }
  return 0;
}
