
#include <iostream>
#include <cstdio>

#include <math.h>
using namespace std;

int main() {
  int n, m, i;
  int Case, flag;
  double sum, t = (double)sqrt(2.0);
  scanf("%d", &Case);
  for (i = 1; i <= Case; i++) {
    scanf("%d%d", &n, &m);
    if (n * m % 2)
      sum = n * m - 1 + t;
    else
      sum = n * m;
    printf("Scenario #%d:\n%.2lf\n\n", i, sum);
  }
  return 0;
}