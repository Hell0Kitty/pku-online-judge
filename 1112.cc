#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int maxn = 110;

bool graph[maxn][maxn], dp[maxn][maxn / 2];
int n, cnt, p[maxn][2][maxn], num[maxn][2], color[maxn], path[maxn][maxn];

bool dfs(int u);
void compute();

int main() {
  scanf("%d", &n);
  memset(graph, 0, sizeof(graph));
  memset(num, 0, sizeof(num));
  memset(color, -1, sizeof(color));
  for (int i = 1; i <= n; i++) {
    while (true) {
      int index;
      scanf("%d", &index);
      if (index == 0) break;
      graph[i][index] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (graph[i][j] && graph[j][i])
        graph[i][j] = graph[j][i] = false;
      else
        graph[i][j] = graph[j][i] = true;
    }
  }
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (color[i] == -1) {
      color[i] = 0;
      if (!dfs(i)) {
        printf("No solution\n");
        return 0;
      }
      cnt++;
    }
  }
  compute();

  return 0;
}

bool dfs(int u) {
  int col = color[u];
  int index = num[cnt][col];
  num[cnt][col]++;
  p[cnt][col][index] = u;
  for (int i = 1; i <= n; i++) {
    if (graph[u][i]) {
      if (color[i] == -1) {
        color[i] = col ^ 1;
        if (!dfs(i)) return false;
      } else if (color[u] == color[i])
        return false;
    }
  }
  return true;
}

void compute() {
  int i, j, k, tmp, res, col;
  memset(dp, 0, sizeof(dp));
  dp[0][num[0][0]] = true;
  path[0][num[0][0]] = 0;
  dp[0][num[0][1]] = true;
  path[0][num[0][1]] = 1;

  for (i = 1; i < cnt; i++) {
    for (j = n / 2; j >= 0; j--) {
      dp[i & 1][j] = false;
      tmp = j - num[i][0];
      if (tmp >= 0 && dp[(i - 1) & 1][tmp]) {
        dp[i & 1][j] = true;
        path[i][j] = 0;
        if (i == cnt - 1) break;
        continue;
      }
      tmp = j - num[i][1];
      if (tmp >= 0 && dp[(i - 1) & 1][tmp]) {
        dp[i & 1][j] = true;
        path[i][j] = 1;
        if (i == cnt - 1) break;
      }
    }
  }

  tmp = j;
  res = 0;
  for (i = cnt - 1; i >= 0; i--) {
    if (path[i][j] == 0) {
      res += num[i][0];
      j -= num[i][0];
    } else {
      res += num[i][1];
      j -= num[i][1];
    }
  }
  printf("%d", res);
  j = tmp;
  for (i = cnt - 1; i >= 0; i--) {
    col = 1;
    if (path[i][j] == 0) {
      col = 0;
      j -= num[i][0];
    } else
      j -= num[i][1];
    for (k = 0; k < num[i][col]; k++) printf(" %d", p[i][col][k]);
  }
  printf("\n%d", n - res);
  j = tmp;
  for (i = cnt - 1; i >= 0; i--) {
    col = 0;
    if (path[i][j] == 0) {
      col = 1;
      j -= num[i][0];
    } else
      j -= num[i][1];
    for (k = 0; k < num[i][col]; k++) printf(" %d", p[i][col][k]);
  }
  printf("\n");
}
