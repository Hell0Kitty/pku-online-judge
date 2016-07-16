#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 9;
struct D {
  int l, r;
  bool operator<(const struct D& xx) const {
    if (l == xx.l) return r < xx.r;
    return l < xx.l;
  }
} qry[maxn];
int dp[maxn];
int main() {
  int n, m, h, r;
  scanf("%d %d %d %d", &n, &m, &h, &r);
  for (int i = 1; i <= r; i++) {
    scanf("%d %d", &qry[i].l, &qry[i].r);
    if (qry[i].l > qry[i].r) swap(qry[i].l, qry[i].r);
  }
  sort(qry + 1, qry + 1 + r);
  qry[0].l = 0;
  for (int i = 1; i <= r; i++) {
    if (qry[i].l == qry[i - 1].l && qry[i].r == qry[i - 1].r) continue;
    dp[qry[i].l + 1]--;
    dp[qry[i].r]++;
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    ret += dp[i];
    printf("%d\n", ret + h);
  }
  return 0;
}
