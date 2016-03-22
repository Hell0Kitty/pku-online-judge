#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int day;
int d[16];
int mat[20][20];
int tmp[20][20];
int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int calk(int x, int y) {
  int sum = mat[x][y];
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0];
    int yy = y + dir[i][1];
    if (xx >= 0 && xx < 20 && yy >= 0 && yy < 20) sum += mat[xx][yy];
  }
  return sum;
}

int main() {
  scanf("%d", &day);
  {
    for (int i = 0; i < 16; i++) scanf("%d", &d[i]);
    for (int i = 0; i < 20; i++)
      for (int j = 0; j < 20; j++) scanf("%d", &mat[i][j]);
    while (day--) {
      for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++) {
          tmp[i][j] = 0;
          tmp[i][j] = mat[i][j] + d[calk(i, j)];
          if (tmp[i][j] < 0) tmp[i][j] = 0;
          if (tmp[i][j] > 3) tmp[i][j] = 3;
        }
      for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++) mat[i][j] = tmp[i][j];
    }

    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 20; j++) {
        if (mat[i][j] == 0) printf(".");
        if (mat[i][j] == 1) printf("!");
        if (mat[i][j] == 2) printf("X");
        if (mat[i][j] == 3) printf("#");
      }
      printf("\n");
    }
  }
  return 0;
}
