#include <iostream>
using namespace std;

int main() {
  int x, y, z, n;
  scanf("%d%d%d%d", &x, &y, &z, &n);
  for (int i = 0; i < n; ++i)
    printf("0 0 %.8lf %d %d %.8lf\n", (z * 1.0 / n) * i, x, y,
           (z * 1.0 / n) * (i + 1));
  return 0;
}
