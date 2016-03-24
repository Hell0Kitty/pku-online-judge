#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
int n, k, win;
int adj[500], mark[500], maxx[500], flag[10][500];

int main() {
  int i, j, query;
  bool ok = false;
  while (scanf("%d", &n)) {
    if (!n)
      break;
    else if (ok)
      printf("\n");
    ok = true;
    memset(adj, 0, sizeof(adj));
    memset(maxx, 0, sizeof(maxx));
    for (i = 1; i <= 1 << n; i++) {
      flag[0][i] = i;
    }
    for (i = 1; i <= 1 << n; i++) maxx[i] = 1 << n;
    for (i = n - 1; i >= 0; i--) {
      for (j = 1; j <= 1 << i; j++) {
        scanf("%d", &flag[n - i][j]);
        maxx[flag[n - i][j]] = (1 << n) - (1 << (n - i)) + 1;
        if (flag[n - i][j] == flag[n - i - 1][2 * j]) {
          adj[flag[n - i - 1][2 * j - 1]] = flag[n - i - 1][2 * j];
        } else
          adj[flag[n - i - 1][2 * j]] = flag[n - i - 1][2 * j - 1];
      }
    }
    win = flag[n][1];
    memset(mark, 0, sizeof(mark));
    mark[win] = 1;
    int p = 1;
    for (i = 1;; i++) {
      for (j = 1; j <= 1 << n; j++) {
        if (mark[adj[j]] == i) {
          mark[j] = i + 1;
          p++;
        }
      }
      if (p == 1 << n) break;
    }
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &query);
      printf("Player %d can be ranked as high as %d or as low as %d.\n", query,
             mark[query], maxx[query]);
    }
  }
  return 0;
}
