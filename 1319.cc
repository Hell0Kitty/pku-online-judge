#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const double Sqrt3_2 = 0.8660254037844386;
int Skew(double x, double y) {
  int row = (y >= 1) + (int)((y - 1) / Sqrt3_2);  //计算行数
  return row * (int)x - (row / 2) * (x - (int)x < 0.5);
}

int main() {
  double x, y;
  while (scanf("%lf%lf", &x, &y) != EOF) {
    int grid = (int)x * (int)y;
    int skew = Skew(x, y) > Skew(y, x) ? Skew(x, y) : Skew(y, x);
    if (skew > grid)
      printf("%d skew\n", skew);
    else
      printf("%d grid\n", grid);
  }
  return 0;
}
