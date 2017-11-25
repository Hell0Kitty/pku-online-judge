#include <iostream>
#include <string>
using namespace std;
string wk, wq, bk;
int dir[9][2] = {{0, 1},
                 {1, 1},
                 {1, 0},
                 {1, -1},
                 {0, -1},
                 {-1, -1},
                 {-1, 0},
                 {-1, 1},
                 {0, 0}};
bool check(char wqx, char wqy) {
  int d, i, dwk, dwq;
  char x, y, dx, dy;
  for (d = 0; d < 9; ++d) {
    x = bk[0] + dir[d][0];
    y = bk[1] + dir[d][1];
    if (x < 'a' || x > 'h' || y < '1' || y > '8') continue;
    bool flag = false;
    for (dwk = 0; dwk < 8; ++dwk) {
      dx = wk[0] + dir[dwk][0];
      dy = wk[1] + dir[dwk][1];
      if (dx == x && dy == y) {
        flag = true;
        break;
      }
    }
    for (dwq = 0; !flag && dwq < 8; ++dwq) {
      for (i = 1;; ++i) {
        dx = wqx + i * dir[dwq][0];
        dy = wqy + i * dir[dwq][1];
        if (dx < 'a' || dx > 'h' || dy < '1' || dy > '8') break;
        if (x == dx && y == dy) {
          flag = true;
          break;
        }
        if (dx == wk[0] && dy == wk[1]) break;
      }
    }
    if (!flag) return false;
  }
  return true;
}

int main() {
  char x, y;
  int d, i;
  while (cin >> wk >> wq >> bk) {
    bool yes = false;
    for (d = 0; !yes && d < 8; ++d) {
      for (i = 1;; ++i) {
        x = wq[0] + i * dir[d][0];
        y = wq[1] + i * dir[d][1];
        if (x < 'a' || x > 'h' || y < '1' || y > '8') break;

        if ((x == wk[0] && y == wk[1]) || (x == bk[0] && y == bk[1])) break;
        if (check(x, y)) {
          yes = true;
          break;
        }
      }
    }
    if (yes)
      printf("%c%c\n", x, y);
    else
      printf("no\n");
  }
  return 0;
}
