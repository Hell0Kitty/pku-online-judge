#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define N 60
using namespace std;
bool map[N][N];
int castle[N][N];
int room = 0;    //房间数
int step, p, q;  // step为搜索时走的步数，即当前房间的面积
bool inmap(int x, int y) {  // judge if the point is in the map
  return (x <= p && y <= q && x > 0 && y > 0);
}
void search(int x, int y) {  // search from (x,y)
  step++;
  map[x][y] = true;

  int temp = castle[x][y];
  if (temp < 8) {  // do not have the south wall
    if (inmap(x + 1, y) && !map[x + 1][y]) search(x + 1, y);
  } else
    temp -= 8;

  if (temp < 4) {  // do not have the east wall
    if (inmap(x, y + 1) && !map[x][y + 1]) search(x, y + 1);
  } else
    temp -= 4;

  if (temp < 2) {  // do not have the north wall
    if (inmap(x - 1, y) && !map[x - 1][y]) search(x - 1, y);
  } else
    temp -= 2;

  if (temp < 1) {  // do not have the west wall
    if (inmap(x, y - 1) && !map[x][y - 1]) search(x, y - 1);
  }
}
int main() {
  cin >> p >> q;
  // input
  for (int i = 1; i <= p; i++)
    for (int j = 1; j <= q; j++) cin >> castle[i][j];
  // init
  memset(map, false, sizeof(map));
  // search
  int lar = 0;
  for (int i = 1; i <= p; i++)
    for (int j = 1; j <= q; j++) {
      if (!map[i][j]) {
        step = 0;
        search(i, j);
        room++;
        if (lar < step)  // find the largest room
          lar = step;
      }
    }
  // output
  cout << room << endl;
  cout << lar << endl;
  return 0;
}
