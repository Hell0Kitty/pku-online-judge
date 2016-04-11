#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100005;
int a[MAXN], f[MAXN], e[MAXN], me[MAXN];

int main() {
  int t, n, i, ans;

  while (1) {
    scanf("%d", &n);
    if (n == 0) return 0;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    memset(me, 0, sizeof(me));
    memset(f, 0, sizeof(f));
    memset(e, 0, sizeof(e));

    f[0] = a[0];
    e[n - 1] = a[n - 1];
    me[n - 1] = a[n - 1];

    for (i = 1; i < n; i++) {
      if (f[i - 1] > 0) {
        f[i] = f[i - 1] + a[i];
      } else {
        f[i] = a[i];
      }
    }
    for (i = n - 2; i > -1; i--) {
      if (e[i + 1] > 0) {
        e[i] = e[i + 1] + a[i];
      } else {
        e[i] = a[i];
      }
      me[i] = max(me[i + 1], e[i]);
    }

    ans = f[0] + me[1];
    for (i = 0; i < n - 1; i++) {
      ans = max(ans, f[i] + me[i + 1]);
    }
    printf("%d\n", ans);
  }
}
