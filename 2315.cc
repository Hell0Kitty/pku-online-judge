#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
#define pi acos(-1)
#define eps (1e-8)

long long ans[64], n, m, k;
double s, l, r;

void calc(double xx) {
  long long x = (xx / pi / r / 2);
  if (abs(pi * 2 * r * x - xx) > eps) ++x;
  x %= k + 1;
  long long id = 0, mod = m + 1;
  while (x) {
    ans[id] += (x & 1);
    ans[id] %= mod;
    x /= 2;
    ++id;
  }
}
int main() {
  while (cin >> n >> m >> l >> r) {
    k = l / pi / r / 2;
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; ++i) cin >> s, calc(s);
    bool flag = 0;
    for (int i = 0; i < 64; ++i)
      if (ans[i]) flag = 1;
    if (flag)
      puts("Alice");
    else
      puts("Bob");
  }
  return 0;
}
