#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <math.h>
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) < (b) ? (a) : (b)
#define mem(a) memset(a, 0, sizeof(a))
#define INF 1000000007
#define MAXN 105
using namespace std;
int a[402];
int main() {
  int cas;
  while (~scanf("%d", &cas))
    while (cas--) {
      mem(a);
      int n, i, j, x, y;
      scanf("%d", &n);
      for (i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        if (!(x & 1)) x--;
        if (y & 1) y++;
        for (j = x; j <= y; j++) a[j]++;
      }
      int max = 0;
      for (i = 1; i <= 400; i++) max = MAX(max, a[i]);
      printf("%d\n", max * 10);
    }
  return 0;
}
