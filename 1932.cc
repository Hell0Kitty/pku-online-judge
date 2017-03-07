#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <limits.h>
using namespace std;
int n;
int map[110][110];
int en[110];
int SPFA() {
  queue<int> q;
  int i, k, max, now, j;
  int used[110], dis[110], in[110];
  for (i = 1; i <= n; i++) dis[i] = 0;
  memset(in, 0, sizeof(in));
  memset(used, 0, sizeof(used));
  dis[1] = 100;
  used[1] = 1;
  q.push(1);
  in[1]++;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    used[x] = 0;
    if (in[x] > n) break;
    for (i = 1; i <= n; i++)
      if (map[x][i] && dis[i] < dis[x] + en[i]) {
        dis[i] = dis[x] + en[i];
        if (!used[i]) {
          in[i]++;
          used[i] = 1;
          q.push(i);
        }
      }
  }
  while (!q.empty()) q.pop();
  if (dis[n] > 0)
    return 1;
  else {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        for (k = 1; k <= n; k++)
          if (map[j][i] && map[i][k]) map[j][k] = 1;
    for (i = 1; i <= n; i++)
      if (in[i] > n && map[i][n] && map[1][i]) return 1;
  }
  return 0;
}
int main() {
  int j, k, i, m, to, ans;
  int tmp[110][110];
  while (scanf("%d", &n) != EOF && n != -1) {
    memset(map, 0, sizeof(map));
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &en[i], &m);
      while (m--) {
        scanf("%d", &to);
        map[i][to] = 1;
      }
    }
    ans = SPFA();
    if (ans)
      printf("winnable\n");
    else
      printf("hopeless\n");
  }
  return 0;
}
