#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
  int l, m;
  while (scanf("%d%d", &l, &m) != EOF && !(l == 0 && m == 0)) {
    int ans = l + 1;
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      ans -= b - a + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
