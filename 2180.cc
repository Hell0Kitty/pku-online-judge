#include <stdio.h>

char placed[64][64][64];
struct node {
  int x, y, z;
} box[25032];

int main() {
  int i, j, x, y, z, sum, N;
  char str[16];
  scanf("%d", &N);
  box[1].x = 32;
  box[1].y = 32;
  box[1].z = 0;
  placed[32][32][0] = 1;
  sum = 5;
  for (i = 2; i <= N; i++) {
    scanf("%d%s", &j, str);
    x = box[j].x;
    y = box[j].y;
    z = box[j].z;
    switch (str[0]) {
      case 'L':
        x--;
        break;
      case 'R':
        x++;
        break;
      case 'F':
        y--;
        break;
      case 'B':
        y++;
        break;
      case 'O':
        z++;
        break;
      case 'U':
        z--;
        break;
    }
    if (z < 0) break;
    if (placed[x][y][z]) break;
    box[i].x = x;
    box[i].y = y;
    box[i].z = z;
    placed[x][y][z] = 1;
    sum += 6;
    if (placed[x - 1][y][z]) sum -= 2;
    if (placed[x + 1][y][z]) sum -= 2;
    if (placed[x][y - 1][z]) sum -= 2;
    if (placed[x][y + 1][z]) sum -= 2;
    if (!z)
      sum--;
    else if (placed[x][y][z - 1])
      sum -= 2;
    if (placed[x][y][z + 1]) sum -= 2;
  }

  printf("%d\n", i <= N ? -1 : sum);

  return 0;
}
