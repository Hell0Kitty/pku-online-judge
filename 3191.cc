#include <iostream>
using namespace std;
int a[64];
int main() {
  int cnt = 0, n;
  scanf("%d", &n);
  while (n) {
    int x = n / -2;
    int y = n % -2;
    if (y < 0) {
      y += 2;
      x += 1;
    }
    a[++cnt] = y;
    n = x;
  }
  if (cnt == 0)
    printf("0");
  else {
    for (int i = cnt; i >= 1; --i) printf("%d", a[i]);
  }
  return 0;
}
