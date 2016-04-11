#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int sg[111][111], w[1000000];
bool f[222][256], prev[222][256];
bool mex[10010];
bool ans[222];
int N, M;
int main() {
  int i, j, k, x, y;
  for (i = 1; i <= 100; ++i) {
    for (j = 1; j <= 100; ++j) {
      memset(mex, 0, sizeof(mex));
      for (x = 1; x < i; ++x)
        for (y = 1; y < j; ++y) mex[sg[x][y] ^ sg[x][j] ^ sg[i][y]] = 1;
      for (k = 0;; ++k)
        if (!mex[k]) break;
      sg[i][j] = k;
    }
  }
  while (cin >> N >> M) {
    int now = 0;
    for (i = 0; i < N; ++i) {
      scanf("%d%d", &x, &y);
      now ^= sg[x][y];
    }
    memset(f, 0, sizeof(f));
    f[0][now] = 1;
    for (i = 1; i <= M; ++i) {
      scanf("%d%d", &x, &y);
      w[i] = sg[x][y];
      for (j = 0; j < 256; ++j)
        if (f[i - 1][j]) {
          f[i][j] = 1;
          prev[i][j] = 0;

          f[i][j ^ sg[x][y]] = 1;
          prev[i][j ^ sg[x][y]] = 1;
        }
    }
    now = 0;
    if (f[M][now]) {
      puts("Yes");
      for (i = M; i > 0; --i) {
        ans[i] = prev[i][now];
        if (prev[i][now]) now ^= w[i];
      }
      for (i = 1; i <= M; ++i)
        if (ans[i])
          puts("H");
        else
          puts("T");
    } else
      puts("No");
  }
  return 0;
}
