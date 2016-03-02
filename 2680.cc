#include <cstdio>
#include <cstring>
#define UNIT 100000000
using namespace std;

int a[1010][55];

int main() {
  int i, j, n;
  memset(a, 0, sizeof(a));
  for (i = 2; i <= 1000; i++) {
    for (j = 0; j < 50; j++) a[i][j] = a[i - 1][j] * 2;
    if (i & 1) {
      a[i][0]--;
      for (j = 0; a[i][j] < 0; j++) a[i][j] += UNIT, a[i][j + 1]--;
    } else
      a[i][0]++;
    for (j = 0; j < 50; j++) {
      a[i][j + 1] += a[i][j] / UNIT;
      a[i][j] %= UNIT;
    }
  }
  for (; scanf("%d", &n) + 1;) {
    if (n == 1) {
      puts("0");
      continue;
    }
    for (j = 49; !a[n][j]; j--)
      ;
    printf("%d", a[n][j]);
    for (j--; j >= 0; j--) printf("%08d", a[n][j]);
    puts("");
  }
  return 0;
}
