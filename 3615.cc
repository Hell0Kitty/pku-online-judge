#include <iostream>

const int MAXN = 305;
const int INF = 99999999;
int dist[MAXN][MAXN];

int N, M, T;

int max(int a, int b) { return a > b ? a : b; }
void init() {
  scanf("%d%d%d", &N, &M, &T);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      if (i == j)
        dist[i][j] = 0;
      else
        dist[i][j] = INF;
    }

  while (M--) {
    int x, y, h;
    scanf("%d%d%d", &x, &y, &h);
    if (dist[x][y] > h) dist[x][y] = h;
  }
}

void runFloyd() {
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) {
        int tmpMax = max(dist[i][k], dist[k][j]);
        if (tmpMax < dist[i][j]) dist[i][j] = tmpMax;
      }
}

int main() {
  init();
  runFloyd();
  int x, y;
  while (T--) {
    scanf("%d%d", &x, &y);
    if (dist[x][y] == INF)
      printf("-1\n");
    else
      printf("%d\n", dist[x][y]);
  }
  return 0;
}
