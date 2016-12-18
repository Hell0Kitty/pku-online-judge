#include <stdio.h>
#include <string.h>
#define INF 0x1f1f1f1f
#define M 602
int map[M][M], dis[M], team[M];
bool flag[M];
void dijkstra(int s, int n) {
  int i, j, k, md, temp;
  memset(dis, 0x1f, sizeof(dis));
  memset(flag, false, sizeof(flag));
  dis[s] = 0;
  for (i = 1; i < n; i++) {
    md = INF;
    for (j = 1; j <= n; j++) {
      if (!flag[j] && dis[j] < md) {
        md = dis[j];
        temp = j;
      }
    }
    if (temp == 2) break;
    flag[temp] = true;
    for (j = 1; j <= n; j++)
      if (!flag[j] && map[temp][j] + md < dis[j]) dis[j] = md + map[temp][j];
  }
  if (dis[2] < map[1][1])
    printf("%d\n", dis[2]);
  else
    printf("-1\n");
}
int main() {
  int i, j, k, n, m, p, q;
  while (scanf("%d", &n), n) {
    scanf("%d", &m);
    memset(map, 0x1f, sizeof(map));
    for (j = 1; j <= m; j++) {
      scanf("%d%d%d", &p, &q, &k);
      map[p][q] = map[q][p] = k;
    }
    for (j = 1; j <= n; j++) scanf("%d", &team[j]);
    for (i = 1; i < n; i++)
      for (j = i + 1; j <= n; j++) {
        if (team[i] == team[j])
          continue;
        else if (team[i] == 1 && team[j] == 2)
          map[j][i] = map[1][1];
        else if (team[i] == 2 && team[j] == 1)
          map[i][j] = map[1][1];
      }
    dijkstra(1, n);
  }
}
