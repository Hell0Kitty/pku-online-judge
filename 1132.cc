#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX 32
char map[MAX][MAX];
int main() {
  int cas, cass = 1;
  scanf("%d", &cas);
  while (cas--) {
    int sx, sy, nx, ny, flag;
    for (int i = 0; i < MAX; i++)
      for (int j = 0; j < MAX; j++) map[i][j] = '.';
    scanf("%d%d", &sx, &sy);
    sx--, sy--;
    nx = sx;
    ny = sy;
    char str[1001];
    scanf("%s", str);
    for (int i = 0; i < strlen(str) - 1; i++) {
      if (str[i] == 'E') {
        map[ny][nx + 1] = 'X';
        nx++;
      } else if (str[i] == 'N') {
        map[ny + 1][nx + 1] = 'X';
        ny++;
      } else if (str[i] == 'W') {
        map[ny + 1][nx] = 'X';
        nx--;
      } else {
        map[ny][nx] = 'X';
        ny--;
      }
    }
    printf("Bitmap #%d\n", cass++);
    for (int i = MAX - 1; i >= 0; i--) {
      for (int j = 0; j < MAX; j++) printf("%c", map[i][j]);
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
