#include <cstdio>
#include <cstring>

int n, num[10005], prefix[10005], pre[10005];

int main() {
  while (scanf("%d", &n) == 1) {
    memset(pre, -1, sizeof(pre));
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", num + i);
      prefix[i] = (prefix[i - 1] + num[i]) % n;
    }

    int start, end;
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
      if (pre[prefix[i]] != -1) {
        start = pre[prefix[i]];
        end = i;
        break;
      } else
        pre[prefix[i]] = i;
    printf("%d\n", end - start);
    for (int i = start + 1; i <= end; i++) printf("%d\n", num[i]);
  }
  return 0;
}
