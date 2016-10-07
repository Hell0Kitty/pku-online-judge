#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int Max = 1030;

int row, col, ar[Max][Max];

int lowbit(int x) { return x & (-x); }

void add(int i, int j, int w) {
  int tmpj;
  while (i <= row) {
    tmpj = j;
    while (tmpj <= col) {
      ar[i][tmpj] += w;
      tmpj += lowbit(tmpj);
    }
    i += lowbit(i);
  }
}

int sum(int i, int j) {
  int tmpj, ans = 0;
  while (i > 0) {
    tmpj = j;
    while (tmpj > 0) {
      ans += ar[i][tmpj];
      tmpj -= lowbit(tmpj);
    }
    i -= lowbit(i);
  }
  return ans;
}

int main() {
  int n, ord, x, y, xx, yy, w;
  while (scanf("%d%d", &ord, &n) != EOF) {
    memset(ar, 0, sizeof(ar));
    row = col = n;
    while (scanf("%d", &ord) && ord != 3) {
      if (ord == 1) {
        scanf("%d%d%d", &x, &y, &w);
        x++, y++;  //  二维的其实下标为[1][1]，这个要记得。
        add(x, y, w);
      } else {
        scanf("%d%d%d%d", &x, &y, &xx, &yy);
        x++, y++, xx++, yy++;
        int ans =
            sum(xx, yy) - sum(x - 1, yy) - sum(xx, y - 1) + sum(x - 1, y - 1);
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
