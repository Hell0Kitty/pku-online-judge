#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define mo 9999991
#define INT_INF 0x3fffffff
#define LL_INF 0x3fffffffffffffff
#define inf 100000000
#define N 10005
#define E 1000000

using namespace std;
int T, n, k;
bool pig[100];
int main() {
  // freopen("pro.in","r",stdin);
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    if (n > k) {
      cout << 0 << endl;
      continue;
    }
    string ans = "";
    bool find = 1;
    memset(pig, 0, sizeof(pig));
    int now = k;
    while (1) {
      int a = now / n;
      int b = now % n;
      ans += char(a + '0');
      now = b * 10 + a;
      if (pig[now] == 1) {
        find = 0;
        break;
      }
      pig[now] = 1;
      if (b == 0 && a == k) {
        break;
      }
    }
    if (find) {
      cout << ans << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
