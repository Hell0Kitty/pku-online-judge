#include <stdio.h>
#include <string.h>
int f[1000005];
__int64 ans;
int main() {
  int i, j, k, t, n, d;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &d, &n);
    memset(f, 0, sizeof(f));
    int num = 0;
    ans = 0;
    while (n--) {
      scanf("%d", &k);
      num = (num + k) % d;
      if (num == 0) f[num]++;
      ans += f[num];
      if (num != 0) f[num]++;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
