#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

const int MAX = 1010;
struct point {
  double x, y;
};
point p[MAX];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
    printf("%d", n);
    for (int i = 0; i < n; i++)
      printf(" %.6lf %.6lf", (p[i].x + p[(i + 1) % n].x) / 2.0,
             (p[i].y + p[(i + 1) % n].y) / 2.0);
    printf("\n");
  }
  return 0;
}
