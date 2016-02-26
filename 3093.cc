#include <cstdio>

#include <algorithm>

#include <cstring>

using namespace std;

int N, M, t, sum, ans, a[1001], F[1001];

int main() {
  scanf("%d", &t);

  int num = 0;

  while (++num <= t) {
    printf("%d ", num);

    scanf("%d%d", &N, &M);

    sum = 0;

    for (int i = 1; i <= N; i++) {
      scanf("%d", &a[i]);

      sum += a[i];
    }

    sort(a + 1, a + N + 1);

    if (a[1] > M) {
      printf("%d\n", 0);

      continue;
    }

    ans = 0;

    memset(F, 0, sizeof(F));
    F[0] = 1;

    for (int i = N; i > 0; i--) {
      sum -= a[i];

      for (int v = max(M - sum - a[i] + 1, 0); v <= M - sum; v++) ans += F[v];

      for (int v = M; v >= a[i]; v--) F[v] += F[v - a[i]];
    }

    printf("%d\n", ans);
  }

  return 0;
}
