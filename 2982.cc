#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <algorithm>
#define forn(i, n) for (int i = 0; i < n; i++)
#define clr(a, b) memset(a, b, sizeof(a))
#define ll long long
#define Min(a, b) \
  if (a > b) a = b
#define MP(x, y) make_pair(x, y)
#define sqr(x) ((x) * (x))
using namespace std;

const int inf = 1e8;
int d[105][105], in[105][105];
int a[105], b[105], c[105];
int n, m, k;
int q[1000000], mod = 1000000;

void spfa() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) d[i][j] = inf, in[i][j] = 0;
  d[0][0] = 0;
  int l = 0, r = 0;
  q[r++] = 0;
  q[r++] = 0;
  while (l != r) {
    int x = q[l++];
    l %= mod;
    int y = q[l++];
    l %= mod;
    in[x][y] = 0;
    for (int i = 1; i <= k; i++) {
      int nx = x + a[i];
      int ny = y + b[i];
      if (nx > n || ny > m || nx < 0 || ny < 0) continue;
      if (d[nx][ny] > d[x][y] + c[i]) {
        d[nx][ny] = d[x][y] + c[i];
        if (!in[nx][ny]) {
          in[nx][ny] = 1;
          q[r++] = nx;
          r %= mod;
          q[r++] = ny;
          r %= mod;
        }
      }
    }
  }
}
int main() {
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    if (n == 0 && m == 0 && k == 0) break;
    for (int i = 1; i <= k; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
    spfa();
    if (d[n][m] == inf)
      puts("-1");
    else
      printf("%d\n", d[n][m]);
  }
  return 0;
}
