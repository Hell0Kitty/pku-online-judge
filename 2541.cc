#include <stdio.h>
#include <string.h>
char s[1001010];
int mark[1 << 14];
int main() {
  int n, m;
  scanf("%d%d%s", &n, &m, s);
  memset(mark, -1, sizeof(mark));
  for (int i = 0; i < n; i++) {
    int ns = 1;
    for (int j = 1; i - j >= 0 && j <= 13; j++) {
      ns = ns << 1 | (s[i - j] - '0');
      mark[ns] = s[i] - '0';
    }
  }
  for (int i = 0; i < m; i++) {
    int ns = 1, d = 0;
    for (int j = n - 1; j >= 0 && j >= n - 13; j--) {
      ns = ns << 1 | (s[j] - '0');
      if (mark[ns] != -1) d = mark[ns];
    }
    ns = 1;
    for (int j = n - 1; j >= 0 && j >= n - 13; j--) {
      ns = ns << 1 | (s[j] - '0');
      mark[ns] = d;
    }
    s[n++] = d + '0';
    printf("%d", d);
  }
  printf("\n");
  return 0;
}
