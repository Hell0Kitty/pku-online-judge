#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
  int m, n, l, pos, left, right, curMin, curMax, rsMin, rsMax;
  scanf("%d", &m);
  while (m-- > 0) {
    scanf("%d%d", &l, &n);
    rsMin = -1;
    rsMax = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d", &pos);
      left = pos;
      right = l - pos;
      curMin = left <= right ? left : right;
      curMax = (curMin == left) ? right : left;
      if (curMin > rsMin) rsMin = curMin;
      if (curMax > rsMax) rsMax = curMax;
    }
    printf("%d %d\n", rsMin, rsMax);
  }
  return 0;
}
