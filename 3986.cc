#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long i64;

const int MOD = (int)1e9 + 3;
const int MAXN = 53;

int n, k;
int A[MAXN];

i64 solve(int cur) {
  static i64 f[MAXN][2];
  memset(f, 0, sizeof f);
  f[0][0] = 1;
  i64 upper = (1ll << (cur + 1)) - 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++) {
      if (f[i][j] == 0) continue;
      if (A[i] >> cur & 1) {
        i64 x = upper - (1 << cur) + 1;
        f[i + 1][j] = ((i64)f[i][j] * x + f[i + 1][j]) % MOD;
        x = (A[i] & upper) - (1 << cur) + 1;
        f[i + 1][j ^ 1] = ((i64)f[i][j] * x + f[i + 1][j ^ 1]) % MOD;
      } else {
        i64 x = (A[i] & upper) + 1;
        f[i + 1][j] = ((i64)f[i][j] * x + f[i + 1][j]) % MOD;
      }
    }
  i64 ret = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = i + 1; j < n; j++)  // 可以预处理
      cnt += A[j] >> cur & 1;
    i64 sum = 0;
    if (A[i] >> cur & 1)
      for (int j = 0; j < 2; j++)
        if ((k >> cur & 1) == ((j + cnt) & 1)) sum = (sum + f[i][j]) % MOD;
    for (int j = i + 1; j < n; j++)  // 可以预处理
      if (A[j] >> cur & 1)
        sum = sum * ((A[j] & upper) - (1 << cur) + 1) % MOD;
      else
        sum = sum * ((A[j] & upper) + 1) % MOD;
    ret = (ret + sum) % MOD;
  }
  return ret;
}

int main() {
  while (true) {
    scanf("%d%d", &n, &k);
    if (n == 0 && k == 0) break;
    for (int i = 0; i < n; i++) scanf("%d", A + i);

    i64 ans = 0;
    for (int i = 30; i >= 0; i--) {
      ans = (ans + solve(i)) % MOD;
      int x = 0;
      for (int j = 0; j < n; j++) x ^= A[j] >> i & 1;
      if (x != (k >> i & 1)) break;
      if (i == 0) ans = (ans + 1) % MOD;
    }
    cout << ans << endl;
  }

  return 0;
}
