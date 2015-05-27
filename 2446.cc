#include <stdio.h>
#include <memory.h>
int m, n, k, r, i, j, p, q, black, white, graph[34][34];
bool map[600][600];
bool ck[600];
int match[600];
int tmp, answer;
bool search(int k) {
  int i, t;
  for (i = 1; i <= q; i++)
    if (map[k][i] && ck[i]) {
      ck[i] = false;
      t = match[i];
      if (t == -1 || search(t)) {
        match[i] = k;
        return true;
      }
      match[i] = t;
    }
  return false;
}
int hungary() {
  answer = 0;
  for (j = 1; j <= q; j++) match[j] = -1;
  for (i = 1; i <= p; i++) {
    memset(ck, true, sizeof(ck));
    if (search(i)) answer++;
  }
  return answer;
}
int main() {
  for (i = 0; i <= m + 1; i++) graph[i][0] = graph[i][n + 1] = 0;
  for (j = 0; j <= n + 1; j++) graph[0][j] = graph[m + 1][j] = 0;
  while (scanf("%d%d%d", &m, &n, &k) != EOF) {
    if ((m * n - k) % 2 == 1) {
      while (k--) {
        scanf("%d%d", &j, &i);
      }
      printf("NO\n");
      continue;
    } else {
      r = (m * n - k) / 2;
      if (m % 2 == 1 && n % 2 == 1) {
        q = m * n / 2;
        p = q + 1;
      } else
        p = q = m * n / 2;
    }
    black = 1;
    white = -1;
    for (i = 1; i <= m; i++) {
      if (i % 2 == 1) {
        for (j = 1; j <= n; j += 2) graph[i][j] = (black++);
        for (j = 2; j <= n; j += 2) graph[i][j] = (white--);
      } else {
        for (j = 1; j <= n; j += 2) graph[i][j] = (white--);
        for (j = 2; j <= n; j += 2) graph[i][j] = (black++);
      }
    }
    while (k--) {
      scanf("%d%d", &j, &i);
      graph[i][j] = 0;
    }
    for (i = 1; i <= p; i++)
      for (j = 1; j <= q; j++) map[i][j] = false;
    for (i = 1; i <= m; i++)
      for (j = 1; j <= n; j++)
        if (graph[i][j] > 0) {
          if (graph[i - 1][j] < 0) map[graph[i][j]][-graph[i - 1][j]] = true;
          if (graph[i + 1][j] < 0) map[graph[i][j]][-graph[i + 1][j]] = true;
          if (graph[i][j + 1] < 0) map[graph[i][j]][-graph[i][j + 1]] = true;
          if (graph[i][j - 1] < 0) map[graph[i][j]][-graph[i][j - 1]] = true;
        }
    if (hungary() >= r)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
