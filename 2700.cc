#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;

LL n, a, b, c, s, t;

LL extgcd(LL a, LL b, LL &x, LL &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  LL res = extgcd(b, a % b, x, y);
  LL tmp = x;
  x = y;
  y = tmp - a / b * y;
  return res;
}

void solve(LL a, LL b, LL s, LL t, LL n) {
  bool swp = 0;
  if (a < b) {
    swp = 1;
    swap(a, b);
  }
  LL x1, y1, x2, y2;
  LL d = t - s;
  LL gcd1 = extgcd(a, b, x1, y1);
  LL gcd2 = extgcd(n, gcd1, x2, y2);
  if (-d % gcd2) {
    puts("no solution");
    return;
  }

  a /= gcd1;
  b /= gcd1;
  n /= gcd2;
  gcd1 /= gcd2;
  d /= gcd2;
  x2 *= d;
  y2 *= d;
  LL hmr = x2 / gcd1;
  y2 += n * hmr;

  LL ansx = 0, ansy = 0;
  LL minsum = 1LL << 62, x = x1 * y2, y = y1 * y2;
  LL sum, dx = x1 * n, dy = y1 * n;
  hmr = y / a;
  x += b * hmr;
  y -= a * hmr;
  hmr = dy / a;
  dx += b * hmr;
  dy -= a * hmr;
  while (1) {
    if (y < 0) {
      x -= b;
      y += a;
    } else if (y >= a) {
      x += b;
      y -= a;
    }
    sum = x + y;
    if (x >= 0 && (sum < minsum || (!swp && sum == minsum))) {
      ansx = x;
      ansy = y;
      minsum = sum;
    }
    if (x >= minsum) break;
    x += dx;
    y += dy;
  }
  if (swp) swap(ansx, ansy);
  cout << ansx << ' ' << ansy << endl;
}

int main() {
  while (1) {
    cin >> n;
    if (n == 0) break;
    cin >> a >> b >> s >> t;
    solve(a, b, s, t, n);
  }
  return 0;
}
