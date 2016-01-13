#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef __int64 lld;
const int MAX = 64;  // 262144
const int INF = 1000000000;

const lld BIT = 1000000000;  ///定义进制

const int MM = 110;
struct BigNum {
  lld dig[MM];
  int len;
  void clr() {
    memset(dig, 0, sizeof(dig));
    len = 1;
  }
  void print(bool flag = false) {
    int i = len - 1;
    printf("%I64d", dig[i]);
    for (i--; i >= 0; i--) {
      printf("%09I64d", dig[i]);
    }
    if (flag) puts("");
  }
  bool zero() { return dig[0] == 0 && len == 1; }
  bool one() { return dig[0] == 1 && len == 1; }
};

BigNum add(BigNum a, BigNum b) {
  int i;
  if (b.len > a.len) a.len = b.len;
  for (i = 0; i < a.len; i++) {
    a.dig[i] += b.dig[i];
    if (a.dig[i] >= BIT) {
      a.dig[i + 1]++;
      a.dig[i] -= BIT;
    }
  }
  if (a.dig[a.len] > 0) a.len++;
  return a;
}

BigNum multi(BigNum a, BigNum b) {
  int i, j;
  BigNum c;
  lld t;
  c.clr();
  c.len = a.len + b.len;
  for (i = 0; i < a.len; i++)
    for (j = 0; j < b.len; j++) {
      t = (lld)(a.dig[i]) * (lld)(b.dig[j]);
      c.dig[i + j + 1] += (t + (lld)(c.dig[i + j])) / BIT;
      c.dig[i + j] = (t + (lld)(c.dig[i + j])) % BIT;
    }
  if (c.dig[c.len - 1] == 0) c.len--;
  return c;
}

BigNum dp[MAX][MAX];
BigNum c[MAX][MAX];

int main() {
  int i, j;
  int n, k;
  BigNum ONE;
  ONE.clr();
  ONE.dig[0] = 1;
  for (i = 0; i < MAX; i++) {
    for (j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        c[i][j] = ONE;
      else
        c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
    }
  }
  while (scanf("%d%d", &n, &k) != EOF)

  {
    for (i = 0; i <= n; i++)
      for (j = 1; j <= n; j++) dp[i][j].clr();
    if (k > n) k = n;
    dp[0][0] = ONE;
    BigNum ans;
    for (i = 1; i <= n; i++) {
      for (j = i; j <= n; j++) {
        for (int t = 1; t <= k && t <= j; t++) {
          ans = multi(dp[i - 1][j - t], c[j][t]);
          dp[i][j] = add(dp[i][j], ans);
        }
      }
    }
    ans.clr();
    for (i = 1; i <= n; i++) {
      ans = add(dp[i][n], ans);
    }
    ans.print(true);
    if (ans.len > 10)
      while (1)
        ;
  }
  return 0;
}
