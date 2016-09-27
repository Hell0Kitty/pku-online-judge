#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
char a[200], b[200], ch;
int i, j, n, m, len, ans;
int f[200][200];
int main() {
  while ((ch = getchar()) != '0') {
    n = 1;
    a[n] = ch;
    while ((ch = getchar()) != '\n') {
      ++n;
      a[n] = ch;
    };
    m = 0;
    while ((ch = getchar()) != '\n') {
      ++m;
      b[m] = ch;
    };
    memset(f, 0, sizeof(f));
    for (i = 1; i <= n; ++i)
      for (j = 1; j <= m; ++j) {
        f[i][j] = f[i - 1][j] > f[i][j - 1] ? f[i - 1][j] : f[i][j - 1];
        if (a[i] == b[j] && f[i][j] < f[i - 1][j - 1] + 1)
          f[i][j] = f[i - 1][j - 1] + 1;
      };
    len = f[n][m];
    if (m < n) {
      j = m;
      m = n;
      n = j;
    };
    len = n - len;
    ans = 0;
    while (len > n - len || (n - len) * 2 < m) {
      ++ans;
      n *= 2;
    }
    ++ans;
    printf("%d\n", ans);
  };
  return 0;
}
