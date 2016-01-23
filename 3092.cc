#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int a[40], b[40];
int main() {
  int t, q = 1;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int p = 0;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    while (n != 0) {
      int temp = 1;
      int m = n;
      while (n % 2 == 0) {
        n /= 2;
        a[p]++;
      }
      while (temp <= n / 3) {
        b[p]++;
        temp *= 3;
      }
      p++;
      n = m - m / n * temp;
    }
    printf("%d %d", q++, p);
    for (int i = 0; i < p; i++) printf(" [%d,%d]", a[i], b[i]);
    puts("");
  }
}
