#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
  int n, t, maxx, pos;
  int r[1006] = {0};
  int s, x, y;
  int i, j;
  // freopen("data.txt","r",stdin);
  while (scanf("%d%d", &n, &t) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &r[i]);
    if (n == 1) {
      for (i = 0; i < t; i++) cout << n << endl;
      continue;
    }
    s = 0;
    pos = -1;
    int tpos = -1;
    while (t--) {
      x = s % (n - 1);
      y = s / (n - 1);
      i = 0;
      while (x) {
        if (i != pos) {
          r[i] += 1;
          x--;
        }
        i++;
      }
      maxx = -1;
      for (i = 0; i < n; i++) {
        if (i != tpos)  //  自己不能再平分分数了
          r[i] += y;
        if (r[i] > maxx) {
          maxx = r[i];
          pos = i;
        }
      }
      tpos = pos;
      printf("%d\n", pos + 1);
      s = r[pos];
      r[pos] = 0;
    }
  }
  return 0;
}
