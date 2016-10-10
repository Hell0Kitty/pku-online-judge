#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
  int m, p, n, c;
  while (scanf("%d%d%d%d", &n, &m, &p, &c) != EOF &&
         !(n == 0 && m == 0 && p == 0 && c == 0))
    printf("%d\n", -(m - n - p));
  return 0;
}
