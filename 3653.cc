#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 547;
int mapp[maxn][maxn];

int dijkstra(int start, int n) {
  int dis[maxn];
  int mark[maxn];
  int k, min;
  memset(mark, 0, sizeof(mark));
  for (int i = 1; i <= n; i++) dis[i] = INF;
  dis[start] = 0;
  for (int i = 1; i <= n; i++) {
    min = INF;
    for (int j = 1; j <= n; j++) {
      if (!mark[j] && dis[j] < min) {
        min = dis[j];
        k = j;
      }
    }
    mark[k] = 1;
    for (int j = 1; j <= n; j++) {
      if (mapp[k][j] != 0) {
        if (dis[j] > dis[k] + mapp[k][j]) dis[j] = dis[k] + mapp[k][j];
      }
    }
  }
  return dis[n];
}
int main() {
  int v, h, w;
  char dir;
  while (~scanf("%d%d", &v, &h)) {
    if (v == 0 && h == 0) break;
    memset(mapp, 0, sizeof(mapp));
    int a, b;
    for (int i = 0; i <= v; i++) {
      for (int j = 1; j <= h; j++) {
        scanf("%d %c", &w, &dir);
        if (w == 0) continue;
        a = i * (h + 1) + j;
        b = a + 1;
        int ti = 2520 / w;
        if (dir == '*')
          mapp[a][b] = mapp[b][a] = ti;
        else if (dir == '>')
          mapp[a][b] = ti;
        else
          mapp[b][a] = ti;
      }
      if (i != v)  //不是最后一行
      {
        for (int j = 1; j <= h + 1; j++)  //多一个
        {
          scanf("%d %c", &w, &dir);
          if (w == 0) continue;
          a = i * (h + 1) + j;
          b = a + h + 1;
          int ti = 2520 / w;
          if (dir == '*')
            mapp[a][b] = mapp[b][a] = ti;
          else if (dir == 'v')
            mapp[a][b] = ti;
          else
            mapp[b][a] = ti;
        }
      }
    }
    int tt = (v + 1) * (h + 1);

    int ans = dijkstra(1, tt);

    if (ans != INF)
      printf("%d blips\n", ans);
    else
      printf("Holiday\n");
  }
  return 0;
}
