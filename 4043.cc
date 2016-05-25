#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cctype>
#include <cfloat>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <csignal>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <string>
#include <bitset>
#include <memory>
#include <numeric>
#include <utility>
#include <algorithm>
#include <functional>
#define LL long long
#define LD long double
#define MAXN 10000002ll
#define MODN 1000000007ll
#define PB push_back
#define RPT(I, L, R) for (LL I = L; I < R; ++I)
#define TPR(I, R, L) for (LL I = R; I >= L; --I)
#define random(X, Y) \
  (int)(double(rand()) * double(Y - X) / double(RAND_MAX) + X)
using namespace std;
template <class T>
bool Umx(T& A, const T& B) {
  return B > A ? A = B, 1 : 0;
}
template <class T>
bool Umn(T& A, const T& B) {
  return B < A ? A = B, 1 : 0;
}
const LL inf = 0x7fffffff;

bool a[MAXN] = {1, 1, 0};
LL p[680000];
LL num, i, j, k, tmp, n, ans;
LL sum[MAXN] = {0ll, 1ll};

void Prime() {
  LL i, j;
  num = 0ll;
  for (i = 2ll; i < 3164ll; ++i)
    if (!a[i])
      for (j = i * i; j < MAXN; j += i) a[j] = 1;
  for (i = 2ll; i < MAXN; ++i)
    if (!a[i]) {
      p[num++] = i;
      sum[i] = sum[i - 1ll];
    } else
      sum[i] = sum[i - 1ll] * i % MODN;
}

int main() {
  Prime();
  while (scanf("%I64d", &n) && n != 0ll) {
    ans = sum[n];
    for (i = 0ll; p[i] * 2ll <= n; ++i) {
      k = 0ll;
      tmp = n;
      while (tmp) k += (tmp /= p[i]);
      if (!(k & 1ll)) ans = ans * p[i] % MODN;
    }
    printf("%I64dn", ans);
  }
  return 0;
}
