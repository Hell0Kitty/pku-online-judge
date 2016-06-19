#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define mem(name, value) memset(name, value, sizeof(name))
#define FOR(i, n) for (int i = 1; i <= n; i++)
using namespace std;
const int maxn = 1000 + 5;
const int maxm = 10000 + 5;
int f[maxm][50];
bool check(int t1, int t2, int n) {
  for (int i = 0; i <= n; i++)
    if ((f[t1][i] & f[t2][i]) != 0) return true;
  return false;
}
int main() {
  int n, q;
  while (scanf("%d", &n) == 1) {
    int t1, t2;
    mem(f, 0);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &t1);
      for (int j = 1; j <= t1; j++) {
        scanf("%d", &t2);
        int m1 = i / 30, m2 = i % 30;
        f[t2][m1] |= (1 << m2);
      }
    }
    scanf("%d", &q);
    while (q--) {
      scanf("%d%d", &t1, &t2);
      if (check(t1, t2, n / 30))
        printf("Yes\n");
      else
        printf("No\n");
    }
  }
  return 0;
}
