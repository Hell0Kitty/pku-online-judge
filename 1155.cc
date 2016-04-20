#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct node {
  int now, val, next;
} tree[9005];

int n, m, len = 0;
int num[3005], head[3005], dp[3005][3005], tem[3005];

void add(int i, int x, int y) {
  tree[len].now = x;
  tree[len].val = y;
  tree[len].next = head[i];
  head[i] = len++;
}

void dfs(int root) {
  int i, j, k, p;
  for (i = head[root]; i != -1; i = tree[i].next) {
    p = tree[i].now;
    dfs(p);
    for (j = 0; j <= num[root]; j++) tem[j] = dp[root][j];
    for (j = 0; j <= num[root]; j++) {
      for (k = 1; k <= num[p]; k++)
        dp[root][k + j] = max(dp[root][j + k], tem[j] + dp[p][k] - tree[i].val);
    }
    num[root] += num[p];
  }
}

int main() {
  int i, j, k, a, b;
  while (~scanf("%d%d", &n, &m)) {
    memset(head, -1, sizeof(head));
    for (i = 1; i <= n - m; i++) {
      scanf("%d", &k);
      num[i] = 0;
      for (j = 0; j < k; j++) {
        scanf("%d%d", &a, &b);
        add(i, a, b);
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) dp[i][j] = -10000000;
    }
    for (i = n - m + 1; i <= n; i++) {
      num[i] = 1;
      scanf("%d", &dp[i][1]);
    }
    dfs(1);
    for (i = m; i >= 0; i--) {
      if (dp[1][i] >= 0) {
        printf("%d\n", i);
        break;
      }
    }
  }

  return 0;
}
