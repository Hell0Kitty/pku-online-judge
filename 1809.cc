#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
long long f[4];

void input() {
  scanf("%d", &n);
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    f[((x & 1) << 1) + (y & 1)]++;
  }
}

void work() {
  long long ans = 0;
  for (int i = 0; i < 4; i++)
    for (int j = i; j < 4; j++)
      for (int k = j; k < 4; k++) {
        int x1 = i >> 1;
        int x2 = j >> 1;
        int x3 = k >> 1;
        int y1 = i & 1;
        int y2 = j & 1;
        int y3 = k & 1;
        if (!((x1 * y2 - y1 * x2 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3) &
              1)) {
          if (i == j && j == k)
            ans += f[i] * (f[i] - 1) * (f[i] - 2) / 6;
          else if (i == j)
            ans += f[i] * (f[i] - 1) * f[k] / 2;
          else if (j == k)
            ans += f[i] * (f[j] - 1) * f[j] / 2;
          else
            ans += f[i] * f[j] * f[k];
        }
      }
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    printf("Scenario #%d:\n", i + 1);
    input();
    work();
    putchar('\n');
  }
  return 0;
}
