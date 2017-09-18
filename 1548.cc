#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAXV 600

typedef struct { int x, y; } Point;

Point pt[MAXV];
int pt_sum;
bool map[MAXV][MAXV], use[MAXV];
int link[MAXV];

int dfs(int x) {
  int i, j;
  for (i = 0; i < pt_sum; i++) {
    if (!use[i] && map[x][i]) {
      use[i] = 1;
      j = link[i];
      link[i] = x;
      if (j == -1 || dfs(j)) return true;
      link[i] = j;
    }
  }
  return false;
}

int hungary() {
  int i, num = 0;
  memset(link, -1, sizeof(link));
  for (i = 0; i < pt_sum; i++) {
    memset(use, 0, sizeof(use));
    if (dfs(i)) num++;
  }
  return pt_sum - num;
}

int main() {
  int i, j;
  pt_sum = 0;
  while (scanf("%d%d", &pt[pt_sum].x, &pt[pt_sum].y) && pt[pt_sum].x != -1 &&
         pt[pt_sum].y != -1) {
    pt_sum++;
    while (scanf("%d%d", &pt[pt_sum].x, &pt[pt_sum].y) && pt[pt_sum].x ||
           pt[pt_sum].y)
      pt_sum++;

    memset(map, 0, sizeof(map));
    for (i = 0; i < pt_sum; i++) {
      for (j = i + 1; j < pt_sum; j++) {
        if (pt[i].x <= pt[j].x && pt[i].y <= pt[j].y) {
          map[i][j] = 1;  //如果i在j的左上方
        } else {
          if (pt[i].x >= pt[j].x && pt[i].y >= pt[j].y) {
            map[j][i] = 1;  //如果j在i的左上方
          }
        }
      }
    }

    printf("%d\n", hungary());
    pt_sum = 0;
  }
  return 0;
}
