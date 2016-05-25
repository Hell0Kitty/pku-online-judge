#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

#define SIZE 110
#define mod 10000

using namespace std;

int n, m, a[SIZE], b[SIZE];

struct MT {
  int x, y;
  int mt[SIZE][SIZE];
} ans, def;

inline MT operator*(MT a, MT b) {
  MT c;
  memset(c.mt, 0, sizeof c.mt);
  c.x = a.x;
  c.y = b.y;
  for (int i = 1; i <= a.x; i++)
    for (int j = 1; j <= b.y; j++)
      for (int k = 1; k <= b.x; k++)
        c.mt[i][j] =
            (c.mt[i][j] + (a.mt[i][k] % mod) * (b.mt[k][j] % mod)) % mod;
  return c;
}

bool read() {
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  scanf("%d", &m);
  if (m <= n - 1) {
    printf("%d\n", a[m]);
    return false;
  }
  m = m - (n - 1);
  for (int i = 1; i <= n; i++) ans.mt[i][1] = a[i - 1];
  ans.x = n;
  ans.y = 1;
  memset(def.mt, 0, sizeof def.mt);
  for (int i = 1; i < n; i++) def.mt[i][i + 1] = 1;
  for (int i = 1; i <= n; i++) def.mt[n][i] = b[n - i];
  def.x = def.y = n;
  return true;
}

void go() {
  while (m) {
    if (m & 1) ans = def * ans;
    def = def * def;
    m >>= 1;
  }
  printf("%d\n", ans.mt[n][1]);
}

int main() {
  while (scanf("%d", &n), n) {
    if (!read())
      continue;
    else
      go();
  }
  return 0;
}
