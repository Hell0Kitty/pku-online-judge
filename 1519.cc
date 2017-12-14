#include <stdio.h>
#include <string.h>
const int maxn = 1005;
char a[maxn];
int main() {
  while (scanf("%s", a) != EOF) {
    if (strcmp(a, "0") == 0) break;
    int len;
    len = strlen(a);
    int ans = 0;
    for (int i = 0; i < len; i++) {
      ans += (a[i] - '0');
      if (ans >= 10) {
        ans = ans / 10 + ans % 10;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
