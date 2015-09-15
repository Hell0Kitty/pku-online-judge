#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct point {
  int row;
  int col;
  int fa;
} po[30];
struct next {
  int row;
  int col;
};
int times;
int mapp[6][6];
int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int par) {
  if (par) dfs(po[par].fa);
  if (par > 0) {
    printf("(%d, %d)\n", po[par].row, po[par].col);
  }
  return;
}
void bfs() {
  queue<next> Q;
  po[1].fa = 0;
  po[1].row = 0;
  po[1].col = 0;
  times = 1;
  int flag;
  int num = 1;
  while (!Q.empty()) {
    Q.pop();
  }
  next st;
  st.row = 0;
  st.col = 0;
  Q.push(st);
  while (!Q.empty()) {
    st = Q.front();
    Q.pop();
    for (int i = 0; i < 4; ++i) {
      next temp;
      temp.row = st.row + step[i][0];
      temp.col = st.col + step[i][1];
      if (temp.row >= 0 && temp.row < 5 && temp.col >= 0 && temp.col < 5 &&
          !mapp[temp.row][temp.col]) {
        Q.push(temp);
        mapp[temp.row][temp.col] = true;
        po[++num].fa = times;
        po[num].row = temp.row;
        po[num].col = temp.col;
        if (temp.row == 4 && temp.col == 4) {
          flag = num;
          break;
        }
      }
    }
    times++;
  }
  dfs(flag);
  return;
}
int main() {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      scanf("%d", &mapp[i][j]);
    }
  }
  bfs();
}