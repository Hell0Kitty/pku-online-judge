#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 30

struct Node {
  long long up, down;
} g[maxn][maxn];

long long n;
long long c;
long long ans[maxn];

void getfirst(long long n, long long c, bool u) {
  if (n == 0) return;
  long long t;
  long long sum;
  if (!u) {
    sum = 0;
    t = ans[n + 1];
    while (sum + g[n][t].down < c) {
      sum += g[n][t].down;
      t++;
    }
  } else {
    sum = 0;
    t = 1;
    while (sum + g[n][t].up < c) {
      sum += g[n][t].up;
      t++;
    }
  }
  ans[n] = t;
  getfirst(n - 1, c - sum, !u);
  for (long long i = 1; i < n; i++)
    if (ans[i] >= t) ans[i]++;
}

int main() {
  g[1][1].up = 1;
  g[1][1].down = 1;
  for (long long i = 2; i <= 20; i++) {
    for (long long j = 1; j <= i; j++) {
      g[i][j].up = g[i][j].down = 0;
      for (long long k = j; k <= i - 1; k++) g[i][j].up += g[i - 1][k].down;
      for (long long k = 1; k <= j - 1; k++) g[i][j].down += g[i - 1][k].up;
    }
  }
  long long x;
  scanf("%lld", &x);
  while (x--) {
    scanf("%lld%lld", &n, &c);

    long long t = 1, sum = 0;
    while (sum + g[n][t].down + g[n][t].up < c) {
      sum += g[n][t].down + g[n][t].up;
      t++;
    }
    ans[n] = t;
    if (sum + g[n][t].down < c)
      getfirst(n - 1, c - sum - g[n][t].down, false);
    else
      getfirst(n - 1, c - sum, true);
    for (long long i = 1; i < n; i++)
      if (ans[i] >= t) ans[i]++;

    printf("%lld", ans[n]);
    for (int i = n - 1; i >= 1; i--) printf(" %lld", ans[i]);
    putchar('\n');
  }
  return 0;
}
