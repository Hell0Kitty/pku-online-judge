#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef __int64 ll;
const ll inf = 0x7fffffffffffffff;

ll minn;
int n, m;
ll dp[505][505];
int mapn[505][505];

inline ll abs(ll a) { return a >= 0 ? a : -a; }

void Init() {
  for (int i = 0; i <= n || i <= m; i++) {
    dp[i][0] = dp[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= m; k++) {
      dp[i][k] = dp[i - 1][k] + dp[i][k - 1] - dp[i - 1][k - 1] + mapn[i][k];
    }
  }
}

inline ll fun(int up, int dw, int lf, int rg) {
  ll sum = 0;
  sum += dp[dw][rg] + dp[up - 1][lf - 1] - dp[up - 1][rg] - dp[dw][lf - 1];
  return sum;
}

inline void fuck(ll sum1, ll sum2, ll sum3) {
  ll sum = abs(sum1 - sum2) + abs(sum1 - sum3) + abs(sum2 - sum3);
  if (sum < minn) minn = sum;
}

int main() {
  while (scanf("%d%d", &n, &m) && (m || n)) {
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= m; k++) {
        scanf("%d", &mapn[i][k]);
      }
    }
    Init();
    minn = inf;
    for (int i = 1; i < n; i++) {
      for (int k = 1; k < m; k++) {
        ll sum1 = fun(1, i, 1, k);
        ll sum2 = fun(1, i, k + 1, m);
        ll sum3 = fun(i + 1, n, 1, k);
        ll sum4 = fun(i + 1, n, k + 1, m);
        fuck(sum1 + sum2, sum3, sum4);
        fuck(sum1 + sum3, sum2, sum4);
        fuck(sum2 + sum4, sum1, sum3);
        fuck(sum3 + sum4, sum1, sum2);
      }
    }
    for (int i = 1; i < n - 1; i++) {
      ll sum1 = fun(1, i, 1, m);
      for (int k = i + 1; k < n; k++) {
        ll sum2 = fun(i + 1, k, 1, m);
        ll sum3 = fun(k + 1, n, 1, m);
        fuck(sum1, sum2, sum3);
      }
    }
    for (int i = 1; i < m - 1; i++) {
      ll sum1 = fun(1, n, 1, i);
      for (int k = i + 1; k < m; k++) {
        ll sum2 = fun(1, n, i + 1, k);
        ll sum3 = fun(1, n, k + 1, m);
        fuck(sum1, sum2, sum3);
      }
    }
    printf("%I64d\n", minn);
  }
  return 0;
}
