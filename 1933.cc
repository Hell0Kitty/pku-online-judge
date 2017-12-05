#include <stdio.h>
#include <string.h>
#define MAX 110
bool g[MAX][MAX], only[MAX][MAX], visit[MAX][MAX];
int f[MAX][MAX], s[MAX][MAX];
int a[MAX];
int dp[MAX][MAX], path[MAX][MAX];
int m, A;

void init() {
  int i, j, k;

  for (k = 1; k < m; k++)
    for (i = 1; i < 100; i++) {
      only[i][k] = f[i][k] = 0;
      for (j = a[k]; j < a[k + 1]; j++)
        if (g[i][j] == 1) {
          only[i][k] = 1;
          break;
        }
      f[i][k] = only[i][k];
      f[i][k] += f[i - 1][k];
    }

  for (i = 1; i < 100; i++)
    for (j = i + 1; j <= 100; j++) {
      s[i][j] = 0;
      for (k = 1; k < m; k++)
        if (f[j - 1][k] - f[i][k] + only[i][k]) s[i][j]++;
    }

  return;
}

int DP(int i, int j) {
  int k, ans;
  if (visit[i][j]) return dp[i][j];

  visit[i][j] = 1;
  if (j == 0) return dp[i][j] = s[i][100];

  dp[i][j] = 0;
  for (k = i + 1; k < 100; k++) {
    if (100 - k - 1 < j - 1) break;
    ans = DP(k, j - 1);
    if (ans + s[i][k] > dp[i][j]) {
      dp[i][j] = ans + s[i][k];
      path[i][j] = k;
    }
  }

  return dp[i][j];
}

void print_path(int i, int j) {
  int k;
  if (j <= 0) return;
  k = path[i][j];
  printf(" %d", k);
  print_path(k, j - 1);
  return;
}

int main() {
  int i, n, j, k;
  while (1) {
    scanf("%d", &n);
    if (n == -1) break;

    memset(g, 0, sizeof(g));
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &j, &k);
      g[k][j] = 1;
    }

    scanf("%d", &m);
    for (i = 1; i <= m; i++) scanf("%d", &a[i]);

    scanf("%d", &A);

    init();

    memset(visit, 0, sizeof(visit));
    DP(1, A - 2);

    printf("%d", A);
    printf(" 1");
    print_path(1, A - 2);
    printf(" 100\n");
  }
  return 0;
}
