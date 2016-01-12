#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = (1 + n / 2 - 1) * (n / 2 - 1) / 2 * 2;
    if (n & 1) ans += n / 2;
    printf("%d\n", ans);
  }
}
