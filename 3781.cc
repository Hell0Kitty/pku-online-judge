#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int i, j, k;
  scanf("%d", &j);
  for (i = 0; i < j; i++) {
    int a[10] = {0};
    for (k = 0; k <= 10; k++) {
      scanf("%d", &a[k]);
    }
    sort(a + 1, a + 11);
    printf("%d %d\n", i + 1, a[8]);
  }
  return 0;
}
