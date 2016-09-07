#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {
    int ans = 100000000;
    int u, d, temp, temp1;
    for (int i = 1; i <= m; i++) {
      scanf("%d %d", &u, &d);
      if ((n * d) % (u + d) == 0) {
        temp1 = u + d;
        if (temp1 < ans) ans = temp1;
      } else {
        temp = (n * d / (u + d)) + 1;
        if (temp * u - (n - temp) * d < ans) ans = temp * u - (n - temp) * d;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
