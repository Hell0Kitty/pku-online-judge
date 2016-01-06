#include <iostream>
#include <stdio.h>
using namespace std;

const long long maxx = 30;

long long f[maxx][maxx], g[maxx], sumg[maxx], sumf[maxx][maxx], n;

long long binarysearch(long long *array, long long start, long long end,
                       long long goal) {
  long long l, r, mid;

  l = start;
  r = end;
  while (l < r) {
    mid = (l + r) / 2;
    if (array[mid] < goal)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}

void dfs(long long tot, long long num) {
  long long x = binarysearch(sumf[tot], 0, tot - 1, num), a, b;

  if (x > 0) {
    a = (num - sumf[tot][x - 1]) / g[tot - x - 1];
    b = (num - sumf[tot][x - 1]) % g[tot - x - 1];
    if (b == 0)
      b = g[tot - x - 1];
    else
      a++;
    printf("(");
    dfs(x, a);
    printf(")");
    num = b;
  }
  printf("X");
  if (tot - 1 - x > 0) {
    printf("(");
    dfs(tot - x - 1, num);
    printf(")");
  }
}

void work() {
  long long num;

  num = binarysearch(sumg, 0, maxx, n);
  n -= sumg[num - 1];
  dfs(num, n);
  printf("\n");
}

int main() {
  long long i, j;
  f[1][0] = 1;
  g[0] = 1;
  sumg[0] = 0;
  g[1] = sumg[1] = 1;
  for (i = 2; i < maxx; i++) {
    g[i] = sumf[i][0] = f[i][0] = g[i - 1];
    for (j = 1; j < i; j++) {
      f[i][j] = g[j] * g[i - 1 - j];
      g[i] += f[i][j];
      sumf[i][j] = sumf[i][j - 1] + f[i][j];
    }
    sumg[i] = g[i] + sumg[i - 1];
  }
  while (scanf("%d", &n) != EOF && n != 0) work();
  return 0;
}
