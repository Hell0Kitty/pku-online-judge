#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
const int N = 205, INF = 1 << 29;

struct p {
  int x, y;
  p(int a = 0, int b = 0) {
    x = a;
    y = b;
  }
} f[N][N];
int n, map[N][N];
int dp[N][N];

void solve() {
  int u, v;
  for (int i = 0; i <= n + 1; ++i) {
    for (int j = 0; j <= n + 1; ++j) dp[i][j] = INF;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; ++j) {
      if (map[i][j]) {
        dp[i][j] = 0;
        f[i][j] = p(i, j);
        continue;
      }
      u = i - 1;
      v = j;
      if (dp[i][j] > dp[u][v] + 1) {
        dp[i][j] = dp[u][v] + 1;
        f[i][j] = f[u][v];
      } else if (dp[i][j] == dp[u][v] + 1) {
        if ((f[i][j].x != f[u][v].x) || (f[i][j].y != f[u][v].y))
          f[i][j] = p(-1, -1);
      }
      u = i;
      v = j - 1;
      if (dp[i][j] > dp[u][v] + 1) {
        dp[i][j] = dp[u][v] + 1;
        f[i][j] = f[u][v];
      } else if (dp[i][j] == dp[u][v] + 1) {
        if ((f[i][j].x != f[u][v].x) || (f[i][j].y != f[u][v].y))
          f[i][j] = p(-1, -1);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = n; j > 0; --j) {
      if (map[i][j]) continue;
      u = i - 1;
      v = j;
      if (dp[i][j] > dp[u][v] + 1) {
        dp[i][j] = dp[u][v] + 1;
        f[i][j] = f[u][v];
      } else if (dp[i][j] == dp[u][v] + 1) {
        if ((f[i][j].x != f[u][v].x) || (f[i][j].y != f[u][v].y))
          f[i][j] = p(-1, -1);
      }
      u = i;
      v = j + 1;
      if (dp[i][j] > dp[u][v] + 1) {
        dp[i][j] = dp[u][v] + 1;
        f[i][j] = f[u][v];
      } else if (dp[i][j] == dp[u][v] + 1) {
        if ((f[i][j].x != f[u][v].x) || (f[i][j].y != f[u][v].y))
          f[i][j] = p(-1, -1);
      }
    }
  }
  // cout<<dp[1][1]<<"  ##  "<<endl;
  for (int i = n; i > 0; --i) {
    for (int j = 1; j <= n; ++j) {
      if (map[i][j]) continue;
      u = i + 1;
      v = j;
      if (dp[i][j] > dp[u][v] + 1) {
        dp[i][j] = dp[u][v] + 1;
        f[i][j] = f[u][v];
      } else if (dp[i][j] == dp[u][v] + 1) {
        if ((f[i][j].x != f[u][v].x) || (f[i][j].y != f[u][v].y))
          f[i][j] = p(-1, -1);
      }
      u = i;
      v = j - 1;
      if (dp[i][j] > dp[u][v] + 1) {
        dp[i][j] = dp[u][v] + 1;
        f[i][j] = f[u][v];
      } else if (dp[i][j] == dp[u][v] + 1) {
        if ((f[i][j].x != f[u][v].x) || (f[i][j].y != f[u][v].y))
          f[i][j] = p(-1, -1);
      }
    }
  }
  // cout<<dp[1][1]<<"  ##  "<<endl;
  for (int i = n; i > 0; --i) {
    for (int j = n; j > 0; --j) {
      if (map[i][j]) continue;
      u = i + 1;
      v = j;
      if (dp[i][j] > dp[u][v] + 1) {
        dp[i][j] = dp[u][v] + 1;
        f[i][j] = f[u][v];
      } else if (dp[i][j] == dp[u][v] + 1) {
        if ((f[i][j].x != f[u][v].x) || (f[i][j].y != f[u][v].y))
          f[i][j] = p(-1, -1);
      }
      u = i;
      v = j + 1;
      if (dp[i][j] > dp[u][v] + 1) {
        dp[i][j] = dp[u][v] + 1;
        f[i][j] = f[u][v];
      } else if (dp[i][j] == dp[u][v] + 1) {
        if ((f[i][j].x != f[u][v].x) || (f[i][j].y != f[u][v].y))
          f[i][j] = p(-1, -1);
      }
    }
  }
  // cout<<dp[1][1]<<"  ##  "<<endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; ++j) {
      if (map[i][j]) continue;
      if (f[i][j].x == -1 && f[i][j].y == -1)
        continue;
      else {
        u = f[i][j].x;
        v = f[i][j].y;
        map[i][j] = map[u][v];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d", map[i][1]);
    for (int j = 2; j <= n; ++j) printf(" %d", map[i][j]);
    printf("\n");
  }
}

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) scanf("%d", &map[i][j]);
    }
    solve();
  }
  return 0;
}
