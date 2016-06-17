#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <cstdlib>
#include <map>
#define maxn 1000005
//#define M 1000000000
#define inf 0xffffffff
#define LL long long
//#define mod 9901//1000000007
#define pi 3.1415926535898
//#define e 2.718281828459
#define eps 1e-9
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a, b) \
  cout << #a << " = " << a << " , " << #b << " = " << b << endl;
using namespace std;

bool is[maxn];
int prm[maxn];
int tot;

void getprime() {
  tot = 0;
  for (int i = 2; i < maxn; i++) {
    if (!is[i]) prm[tot++] = i;
    for (int j = 0; j < tot && prm[j] * i < maxn; j++) {
      is[prm[j] * i] = 1;
      if (i % prm[j] == 0) break;
    }
  }
}

LL euler(LL n) {
  LL ans = n;
  for (int i = 0; i < tot && prm[i] * prm[i] <= n; i++) {
    // for (int i = 2; i * i <= n; i++){
    if (n % prm[i] == 0) {
      ans = ans / prm[i] * (prm[i] - 1);
      while (n % prm[i] == 0) n /= prm[i];
    }
  }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}

int phi(int x) {
  int res = x;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      while (x % i == 0) x = x / i;
      res = res / i * (i - 1);
    }
  }
  if (x != 1) res = res / x * (x - 1);
  return res;
}

LL num[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

LL MOD(LL x, LL y) {
  if (x < y) return x;
  return x % y + y;
}

LL fen(LL a, LL k, LL c) {
  LL p = a, t = 1 % c;
  while (k) {
    if (k & 1) t = MOD((t * p), c);
    p = MOD((p * p), c);
    k >>= 1;
  }
  return MOD(t, c);
}

LL f(LL a, LL x, LL c) {
  if (x == 0) return 1;
  LL m = phi(c);
  LL ans = f(a, x - 1, m);
  return fen(a, ans, c);
}

LL s[7], dp[105][105];
const LL INF = -1;

int main() {
  // getprime();
  LL mod, p, i, j, k, c, ans;
  int b, n, m, top;
  memset(dp, -1, sizeof(dp));
  for (b = 1; b <= 100; b++)
    for (n = 1; n <= 100; n++) dp[b][n] = f(b, n, num[7]);
  while (~scanf("%d", &b) && b) {
    scanf("%d%d", &n, &m);
    if (dp[b][n] == -1) dp[b][n] = f(b, n, num[7]);
    ans = dp[b][n];
    for (i = 0; i < m; i++) s[i] = 0;
    top = m - 1;
    while (ans > 0 && top >= 0) {
      s[top--] = ans % 10;
      ans /= 10;
    }
    for (int i = 0; i < m; i++) printf("%lld", s[i]);
    puts("");
  }
  return 0;
}
