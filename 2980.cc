#include <iostream>
#include <cstdio>

using namespace std;
int a, b, c, r;

inline int ceiling(int a, int b) {
  if (a < 0) return 0;
  if (a % b == 0) return a / b;
  return a / b + 1;
}

int main() {
  int ans;
  while (scanf("%d%d%d%d", &a, &b, &c, &r), a + b + c + r) {
    int n = ceiling(100, r + 2), tmp;
    ans = 1000000;
    for (int i = 0; i <= n; i++) {
      tmp = ceiling(100, r) * c;
      tmp += (i + ceiling((100 - (r + 2) * i), r)) * a;
      tmp += (i + ceiling((100 - (r - 1) * i), r)) * b;
      if (tmp < ans) ans = tmp;
    }
    printf("%d\n", ans);
  }
  return 0;
}
