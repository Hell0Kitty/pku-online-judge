#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int n;

int main() {
  puts("Cards  Overhang");
  while (~scanf("%d", &n)) {
    double ans = 0;
    for (int i = 1; i <= n; i++) ans += 1.0 / (i * 2);
    printf("%5d%10.3f\n", n, ans);
  }
  return 0;
}
