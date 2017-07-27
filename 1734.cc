#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 1 << 29;
int dist[105][105], map[105][105], pre[105][105];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(map, -1, sizeof(map));
    memset(pre, -1, sizeof(pre));
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if (dist[a][b] == -1)
        dist[a][b] = dist[b][a] = map[a][b] = map[b][a] = c;
      else
        dist[a][b] = dist[b][a] = map[a][b] = map[b][a] = min(map[a][b], c);
      pre[a][b] = a;
      pre[b][a] = b;
    }
    for (int i = 1; i <= n; i++) dist[i][i] = map[i][i] = 0;
    int ans = inf, path[105], top;
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i < k; i++)
        for (int j = i + 1; j < k; j++) {
          if (dist[i][j] != -1 && map[i][k] != -1 && map[k][j] != -1 &&
              ans > dist[i][j] + map[i][k] + map[k][j]) {
            ans = dist[i][j] + map[i][k] + map[k][j];
            int t = j;
            top = 0;
            while (t != i) {
              path[top++] = t;
              t = pre[i][t];
            }
            path[top++] = i;
            path[top++] = k;
          }
        }
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          if (dist[i][k] != -1 && dist[k][j] != -1 &&
              (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j])) {
            dist[i][j] = dist[i][k] + dist[k][j];
            pre[i][j] = pre[k][j];
          }
    }
    if (ans == inf) {
      printf("No solution.\n");
      continue;
    }
    for (int i = 0; i < top - 1; i++) printf("%d ", path[i]);
    printf("%d\n", path[top - 1]);
  }
  return 0;
}