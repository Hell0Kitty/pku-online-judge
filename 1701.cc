#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 10005

int n, u, d;
long long sum[maxn], f[maxn], extraup[maxn], extradown[maxn];
long long down[maxn], up[maxn];

void input() {
  scanf("%d%d%d", &n, &u, &d);
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &f[i]);
    sum[i] = sum[i - 1] + f[i];
  }
  extradown[0] = 0;
  for (int i = 1; i <= n; i++) extradown[i] = extradown[i - 1] + sum[i];
  extraup[n + 1] = 0;
  for (int i = n; i >= 1; i--)
    extraup[i] = extraup[i + 1] + sum[n] - sum[i - 1];
}

void work() {
  down[1] = 0;
  for (int i = 2; i <= n; i++)
    down[i] = sum[i - 2] * d + down[i - 1] + f[i - 1] * d + extradown[i - 2];
  up[n] = 0;
  for (int i = n - 1; i >= 1; i--)
    up[i] =
        (sum[n] - sum[i + 1]) * u + up[i + 1] + f[i + 1] * u + extraup[i + 2];
  long long temp = down[1] + up[1];
  int ans = 1;
  for (int i = 2; i <= n; i++)
    if (temp >= down[i] + up[i]) {
      temp = down[i] + up[i];
      ans = i;
    }
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    work();
  }
  return 0;
}
