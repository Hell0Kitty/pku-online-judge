#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

#pragma comment(linker, "/STACK;1024000000")
#define EPS (1e-8)
#define LL long long
#define _LL _int64
#define INF 0x3f3f3f3f
#define Mod 364875103

using namespace std;

double dp[35][130];
struct N {
  double x1, x2, y1, y2;
  int col;
} tun[130];

double Cal(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double Cal(double x, double y, N a) {
  return Cal(x, y, a.x1, a.y1) + Cal(a.x1, a.y1, a.x2, a.y2);
}

int seq[35];

int main() {
  double sx, sy, ex, ey;
  int T;
  while (cin >> T) {
    int n, m, i, j, k;
    while (T--) {
      cin >> sx >> sy >> ex >> ey;
      cin >> n;
      for (i = 1; i <= n; ++i) cin >> seq[i];
      cin >> m;
      m <<= 1;
      for (i = 1; i <= m; i += 2) {
        cin >> tun[i].x1 >> tun[i].y1 >> tun[i].x2 >> tun[i].y2 >> tun[i].col;
        tun[i + 1] = tun[i];
        swap(tun[i + 1].x1, tun[i + 1].x2);
        swap(tun[i + 1].y1, tun[i + 1].y2);
      }
      for (i = 0; i <= n; ++i)
        for (j = 0; j <= m; ++j) dp[i][j] = 1000000000000LL;
      for (i = 1; i <= m; ++i) {
        if (tun[i].col == seq[1]) dp[1][i] = min(dp[1][i], Cal(sx, sy, tun[i]));
      }
      for (i = 2; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
          if (tun[j].col == seq[i - 1]) {
            for (k = 1; k <= m; ++k) {
              if (tun[k].col == seq[i])
                dp[i][k] = min(
                    dp[i][k], dp[i - 1][j] + Cal(tun[j].x2, tun[j].y2, tun[k]));
            }
          }
        }
      }
      double Min = 1000000000000LL;
      for (i = 1; i <= m; ++i) {
        if (tun[i].col == seq[n]) {
          Min = min(Min, dp[n][i] + Cal(tun[i].x2, tun[i].y2, ex, ey));
        }
      }
      printf("%.3f\n", Min - EPS);
    }
  }
  return 0;
}
