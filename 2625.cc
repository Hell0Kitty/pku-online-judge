#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MEM(a, b) memset((a), (b), sizeof(a))
const int INF = 10056;
const LL N = 30;
const double eps = 1e-11;
LL gcd(LL n, LL m) { return m == 0 ? n : gcd(m, n % m); }
void output(int n, char c) {
  while (n--) cout << c;
}

int digit(LL n) {
  int ret = 0;
  while (n) n /= 10, ret++;
  return ret;
}
int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt", "w", stdout);
  LL n;
  while (cin >> n) {
    LL l, r;
    l = 0;
    r = 1;
    LL m = 0;
    for (int i = 1; i <= n; i++) {
      l = l * i + r * n;
      r *= i;
      LL g = gcd(r, l);
      r /= g;
      l /= g;
      m += l / r;
      l %= r;
    }
    if (l == 0) {
      cout << m << endl;
      continue;
    }
    if (m != 0) output(digit(m) + 1, ' ');
    cout << l << endl;
    if (m != 0) cout << m << ' ';
    output(max(digit(l), digit(r)), '-');
    cout << endl;
    if (m != 0) output(digit(m) + 1, ' ');
    cout << r << endl;
  }
  return 0;
}
