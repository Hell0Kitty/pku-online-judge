#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
using namespace std;
int path[2000], g[2000][2000], flag[2000], n, m, k;
void dfs(int v) {
  int i;
  for (i = 1; i <= m; i++) {
    if (!flag[i] && g[v][i]) {
      flag[i] = 1;
      dfs(g[v][i]);
      path[k++] = i;
    }
  }
}
int main() {
  int i;
  int x, y, z, start;
  while (cin >> x >> y && (x || y)) {
    memset(g, 0, sizeof(g));
    memset(flag, 0, sizeof(flag));
    memset(path, 0, sizeof(path));
    k = n = m = 0;
    start = 2000;
    do {
      cin >> z;
      g[x][z] = y;
      g[y][z] = x;
      g[x][0]++;
      g[y][0]++;
      m = m < z ? z : m;
      n = (x > y ? x : y) > n ? (x > y ? x : y) : n;
      start = (x < y ? x : y) < start ? (x < y ? x : y) : start;
    } while (cin >> x >> y && (x || y));
    for (i = 1; i <= n; i++) {
      if (g[i][0] % 2) {
        printf("Round trip does not exist.\n");
        break;
      }
    }
    if (i == n + 1) {
      dfs(start);
      for (int j = k - 1; j >= 0; j--) {
        printf("%d", path[j]);
        if (j != 0) {
          printf(" ");
        } else {
          printf("\n");
        }
      }
    }
  }
  return 0;
}
