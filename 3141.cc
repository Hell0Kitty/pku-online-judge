#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define M(a) memset((a), 0, sizeof((a)))
#define maxn 110
using namespace std;
struct Point {
  int x, y;
  bool operator<(const Point &a) const { return x < a.x; }
} p[maxn];
int n, m, y[maxn];
int on[maxn];
int on2[maxn];
int lef[maxn];
bool init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &p[i].x, &p[i].y);
    y[i] = p[i].y;
  }
  return n;
}
int solve() {
  sort(p + 1, p + 1 + n);
  sort(y + 1, y + 1 + n);
  m = unique(y + 1, y + 1 + n) - y - 1;
  if (m <= 2)
    return n;

  int ans = 0;

  for (int a = 1; a <= m; a++) {
    for (int b = a + 1; b <= m; b++) {
      int ymin = y[a], ymax = y[b];
      int k = 0;
      for (int i = 1; i <= n; i++) {
        if (i == 1 || p[i].x != p[i - 1].x) {
          k++;
          on2[k] = on[k] = 0;
          lef[k] = k == 1 ? 0 : lef[k - 1] + on2[k - 1] - on[k - 1];
        }
        if (p[i].y > ymin && p[i].y < ymax)
          on[k]++;
        if (p[i].y >= ymin && p[i].y <= ymax)
          on2[k]++;
      }

      if (k <= 2)
        return n;
      // ans=on2[j]+lef[j]-(lef[i]-on[i])  j means right and i mean lef
      // ans=on2[j]+lef[j]+on[i]-lef[i]
      int M = 0;
      for (int j = 1; j <= k; j++) {
        ans = max(ans, on2[j] + lef[j] + M);
        M = max(M, on[j] - lef[j]);
      }
    }
  }
  return ans;
}

int main() {
  // freopen("1382.txt","r",stdin);
  int ks = 1;
  while (init()) {
    printf("Case %d: %d\n", ks++, solve());
  }
  return 0;
}