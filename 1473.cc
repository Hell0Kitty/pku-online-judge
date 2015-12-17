
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
  int c = 0;
  while (true) {
    c++;
    double x = 0, y = 0;
    int times[8] = {0};
    char ord[205];
    int num[205];
    char dir[2];
    int numit = 0;
    int dirit = 0;
    scanf("%s", ord);
    if (ord[0] == 'E') break;
    for (int i = 0; i < strlen(ord); i++) {
      if ('0' <= ord[i] && ord[i] <= '9') {
        num[numit] = ord[i] - '0';
        numit++;
      } else if ('A' <= ord[i] && ord[i] <= 'Z') {
        dir[dirit] = ord[i];
        dirit++;
      } else {
        int n = 0;
        for (int j = numit - 1; j >= 0; j--)
          n += num[j] * pow(10.0, numit - j - 1);
        if (dirit == 1) {
          if (dir[0] == 'N')
            times[0] += n;
          else if (dir[0] == 'E')
            times[2] += n;
          else if (dir[0] == 'S')
            times[4] += n;
          else if (dir[0] == 'W')
            times[6] += n;
        } else if (dirit == 2) {
          if (dir[0] == 'N' && dir[1] == 'E')
            times[1] += n;
          else if (dir[0] == 'S' && dir[1] == 'E')
            times[3] += n;
          else if (dir[0] == 'S' && dir[1] == 'W')
            times[5] += n;
          else if (dir[0] == 'N' && dir[1] == 'W')
            times[7] += n;
        }
        numit = 0;
        dirit = 0;
      }
    }
    // for(int i = 0; i < 8; i++)
    // printf("%d ", times[i]);
    for (int i = 0; i < 4; i++) times[i] -= times[i + 4];
    x = double(times[1]) * sqrt(2.0) / 2 + double(times[2]) +
        double(times[3]) * sqrt(2.0) / 2;
    y = double(times[0]) + double(times[1]) * sqrt(2.0) / 2 -
        double(times[3]) * sqrt(2.0) / 2;
    double dis = sqrt(x * x + y * y);
    if (x == -0.0) x = 0.0;
    if (y == -0.0) y = 0.0;
    if (dis == -0.0) dis = 0.0;

    printf("Map #%d\nThe treasure is located at (%.3f,%.3f).\n", c, x, y);
    printf("The distance to the treasure is %.3f.\n", dis);
    printf("\n");
  }
  return 0;
}