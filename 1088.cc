#include <stdio.h>

const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

int heigth[101][101];
int opt[101][101];

int r, c;
int i, j;

bool isIn(int i, int j) { return (i > 0 && i <= r && j > 0 && j <= c); }

int dp(int i, int j) {
  int k;
  if (opt[i][j] > 0)
    return opt[i][j];
  else {
    for (k = 0; k < 4; k++)  //循环周围4个点
    {
      if (isIn(i + dx[k], j + dy[k]) &&
          heigth[i][j] <
              heigth[i + dx[k]][j + dy[k]])  //如果周围一个点在矩阵内且比该点高
      {
        int num = dp(i + dx[k], j + dy[k]);
        if (opt[i][j] <= num)  //如果该点opt[][]值比该点大
        {
          opt[i][j] = num + 1;
        }
      }
    }
    return opt[i][j];
  }
}

int main(void) {
  scanf("%d %d", &r, &c);
  for (i = 1; i <= r; i++)
    for (j = 1; j <= c; j++) {
      scanf("%d", &heigth[i][j]);
      opt[i][j] = 0;
    }

  for (i = 1; i <= r; i++)
    for (j = 1; j <= c; j++) opt[i][j] = dp(i, j);

  int max = 0;

  for (i = 1; i <= r; i++)
    for (j = 1; j <= c; j++)
      if (opt[i][j] > max) max = opt[i][j];
  printf("%d\n", max + 1);

  return 1;
}