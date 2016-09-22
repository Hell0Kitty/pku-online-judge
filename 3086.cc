#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <bitset>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi = acos(-1.0), eps = 1e-8;
const int maxn = 1100, maxm = 110000, inf = 0x3f3f3f3f;
#define ll long long
const ll linf = 1122334455667788990;
int T(int n) {
  int i, sum = 0;
  for (i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int main() {
  int n, i, t, w, k, sum;
  cin >> n;
  if (n >= 1 && n <= 1000) {
    for (i = 1; i <= n; i++) {
      cin >> t;
      if (t >= 1 && t <= 300) {
        for (k = 1, sum = 0; k <= t; k++) {
          w = k * T(k + 1);
          sum += w;
        }
        cout << i << " " << t << " " << sum << endl;
      } else
        return 0;
    }
  } else
    return 0;

  return 0;
}
