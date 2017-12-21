#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <queue>
#define MAX 85
using namespace std;

int map[MAX][MAX];
int level[MAX][MAX];
int result[MAX][MAX];
int n, m;
struct NODE {
  int x, y;
  int lev;
} end, start, ntemp;

queue<NODE> mq;

bool canNotVisit(const int &x, const int &y, const int mode) {
  if (mode < 4) {
    if (mode == 0)
      return map[x - 1][y - 1] && map[x - 1][y];
    else
      return map[x][y] && map[x][y - 1];
  } else {
    if (mode == 4)
      return map[x][y - 1] && map[x - 1][y - 1];
    else
      return map[x][y] && map[x - 1][y];
  }
}

void pushQueue(const int &x, const int &y, const int &lev) {
  NODE temp;
  temp.x = x;
  temp.y = y;
  temp.lev = lev;
  mq.push(temp);
}

int main(void) {
  int dis[] = {-1, 0, 1, 0, 0, -1, 0, 1};
  int ncases;
  char ch;
  int x, y, lev, a, b;
  scanf("%d", &ncases);
  while (ncases--) {
    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d", &start.x, &start.y, &end.x, &end.y);

    memset(map, 0, sizeof(map));
    memset(level, 0, sizeof(level));
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j) result[i][j] = INT_MAX;

    for (int i = 0; i < n; ++i) {
      getchar();
      for (int j = 0; j < m; ++j) {
        scanf("%c", &ch);
        map[i][j] = ch - '0';
        if (map[i][j]) {
          level[i][j] = level[i][j + 1] = level[i + 1][j] =
              level[i + 1][j + 1] = n + m;
          pushQueue(i, j, n + m);
          pushQueue(i, j + 1, n + m);
          pushQueue(i + 1, j, n + m);
          pushQueue(i + 1, j + 1, n + m);
        }
      }
    }

    while (!mq.empty()) {
      ntemp = mq.front();
      mq.pop();
      x = ntemp.x, y = ntemp.y, lev = ntemp.lev - 1;
      for (int i = 0; i < 8; i += 2) {
        a = x + dis[i];
        b = y + dis[i + 1];
        if (a >= 0 && a <= n && b >= 0 && b <= m && !canNotVisit(x, y, i) &&
            lev > level[a][b]) {
          level[a][b] = lev;
          ntemp.x = a;
          ntemp.y = b;
          ntemp.lev = lev;
          mq.push(ntemp);
        }
      }
    }
    start.lev = result[start.x][start.y] = level[start.x][start.y];
    end.lev = level[end.x][end.y];
    mq.push(start);
    while (!mq.empty()) {
      ntemp = mq.front();
      mq.pop();
      x = ntemp.x;
      y = ntemp.y;
      lev = ntemp.lev;
      for (int i = 0; i < 8; i += 2) {
        a = x + dis[i];
        b = y + dis[i + 1];
        if (a >= 0 && a <= n && b >= 0 && b <= m && !canNotVisit(x, y, i) &&
            lev + level[a][b] < result[a][b]) {
          result[a][b] = lev + level[a][b];
          ntemp.x = a;
          ntemp.y = b;
          ntemp.lev = result[a][b];
          mq.push(ntemp);
        }
      }
    }
    if (result[end.x][end.y] == INT_MAX)
      printf("no solution\n");
    else
      printf("%d\n", result[end.x][end.y]);
  }
  return 0;
}
