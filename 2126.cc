#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if (n <= 1) {
    printf("YES\n");
    return 0;
  }
  if (n > 2) {
    printf("NO\n");
    return 0;
  }
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (b * b - 4 * a * c >= 0)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
