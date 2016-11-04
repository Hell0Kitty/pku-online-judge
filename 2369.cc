#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
#define REP(x, y) for (int x = 0; x < y; x++)
#define DWN(x, y) for (int x = y - 1; x > -1; x--)
const int maxn = 1e3 + 10;
int num[maxn];
bool flag[maxn];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
    memset(flag, 0, n + 1);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      if (flag[i]) continue;
      int len = 0, u = i;
      do {
        len++;
        flag[u] = true;
        u = num[u];
      } while (!flag[u]);
      ans = lcm(ans, len);
    }
    printf("%d\n", ans);
  }
  return 0;
}
