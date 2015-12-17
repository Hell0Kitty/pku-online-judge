
#include <iostream>
using namespace std;
const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};  // E W S N
struct NODE {
  int N, S, E, W;
  int flag;
  int cou;
};
NODE map[155][155];
int X, Y, R, D;
int aimX, aimY;
void show() {
  int i, j;
  for (i = 0; i < 20; i++) {
    for (j = 0; j < 20; j++) {
      printf("%d ", map[i][j].flag);
    }
    printf("\n");
  }
  printf("\n");
}
void init() {
  int i, j;
  char cmd[100];
  memset(map, 0, sizeof(map));
  for (i = 0; i < Y; i++) {
    cin >> cmd;
    for (j = 0; j < X; j++)  // EWSN为1时 该方向不能走
    {
      if (cmd[j] == '\\')  //
      {
        map[i + j][Y - 1 - i + j].E = 1;
        map[i + j][Y - 1 - i + j].flag = 1;
        map[i + j][Y - i + j].W = 1;
        map[i + j][Y - i + j].flag = 1;
        map[i + j + 1][Y - 1 - i + j].E = 1;
        map[i + j + 1][Y - 1 - i + j].flag = 1;
        map[i + j + 1][Y - i + j].W = 1;
        map[i + j + 1][Y - i + j].flag = 1;
      } else  // /
      {
        map[i + j][Y - 1 - i + j].S = 1;
        map[i + j][Y - 1 - i + j].flag = 1;
        map[i + j][Y - i + j].S = 1;
        map[i + j][Y - i + j].flag = 1;
        map[i + j + 1][Y - 1 - i + j].N = 1;
        map[i + j + 1][Y - 1 - i + j].flag = 1;
        map[i + j + 1][Y - i + j].N = 1;
        map[i + j + 1][Y - i + j].flag = 1;
      }
      // printf("%d-%d %d-%d %d-%d
      // %d-%d\n",i+j,Y-1-i+j,i+j,Y-i+j,i+j+1,Y-1-i+j,i+j+1,Y-i+j);
    }
  }
  for (i = 0; i < X; i++)  // U
  {
    map[i][i + Y].flag = 0;
  }
  for (i = Y - 1; i >= 0; i--)  // L
  {
    map[i][Y - i - 1].flag = 0;
  }
  for (i = Y; i < R; i++)  // D
  {
    map[i][i - Y].flag = 0;
  }
  for (i = X; i < D; i++)  // L
  {
    map[i][X + Y - 1 - (i - X)].flag = 0;
  }
  // show();
}
bool check(int x, int y, int d)  // dir 0 1 2 3 --E W S N
{
  bool re = false;
  if (d == 0 && !(map[x][y].E)) re = true;
  if (d == 1 && !(map[x][y].W)) re = true;
  if (d == 2 && !(map[x][y].S)) re = true;
  if (d == 3 && !(map[x][y].N)) re = true;
  if (re && map[x + dir[d][0]][y + dir[d][1]].flag == 1) return true;
  return false;
}
bool cycle(int x, int y, int d)  //是否形成一个环
{
  bool re = false;
  if (d == 0 && !(map[x][y].E)) re = true;
  if (d == 1 && !(map[x][y].W)) re = true;
  if (d == 2 && !(map[x][y].S)) re = true;
  if (d == 3 && !(map[x][y].N)) re = true;
  if (re && aimX == x + dir[d][0] && aimY == y + dir[d][1] &&
      map[x][y].cou >= 3)
    return true;
  return false;
}
int DFS(int y, int x, int c = 1) {
  // printf("%d,%d--%d==\n",x,y,c);
  int k;
  map[x][y].flag = 2;
  for (k = 0; k < 4; k++) {
    if (check(x, y, k)) {
      map[x + dir[k][0]][y + dir[k][1]].cou = map[x][y].cou + 1;
      return DFS(y + dir[k][1], x + dir[k][0], c + 1);
    }
    if (cycle(x, y, k)) {
      return c;
    }
  }

  return -1;
}
bool mainn(int T) {
  cin >> X >> Y;
  if (!X && !Y) return false;
  if (T > 1) printf("\n");
  R = X + Y;
  D = X + Y;
  init();
  // cal
  int cnt = 0;
  int i, j, tm, max = 0;
  for (i = 0; i < D; i++) {
    for (j = 0; j < R; j++) {
      if (map[i][j].flag != 1) continue;
      // printf("%d %d\n",i,j);
      aimX = i;
      aimY = j;
      tm = DFS(j, i);
      // printf("\n");
      if (tm == -1) continue;
      cnt++;
      if (tm > max) max = tm;
      // show();
    }
  }
  // show();
  printf("Maze #%d:\n", T);
  if (cnt) {
    printf("%d Cycles; the longest has length %d.\n", cnt, max);
  } else {
    printf("There are no cycles.\n");
  }
  return true;
}
int main() {
  int i = 1;
  while (mainn(i++))
    ;
  return 0;
}