#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
int const MAXN = 100000 + 1;
ll dp[100 + 1][200 + 5];
struct D {
  int v, d;
} sta[100 + 1];
int gmin(int a, int b) { return a < b ? a : b; }
int main() {
  memset(dp, -1, sizeof(dp));
  int v, d, tot = 0;
  int n;
  scanf("%d", &n);
  while (scanf("%d%d", &d, &v) != EOF) {
    sta[tot].v = v;
    sta[tot++].d = d;
  }
  sta[tot].d = n;
  sta[tot++].v = 0;
  int i, j;
  int st = 0, bottom = -1;
  if (sta[st].d > 100) {
    printf("Impossible\n");
    return 0;
  }
  for (st = 100 - sta[0].d; st >= 0; st--) {
    dp[0][st] = 0;
  }
  for (i = 0; i < tot - 1; i++) {
    d = sta[i].d;
    v = sta[i].v;
    int nd = sta[i + 1].d;
    int nv = sta[i + 1].v;  ///鍒嗗埆涓哄綋鍓嶈妭鐐箆锛宒鍜屼笅涓粨鐐箆锛宒
    bottom = -1;
    for (j = 0; j <= 200; j++) {
      if (dp[i][j] == -1) continue;
      if (bottom == -1) bottom = j;
    }
    int mmin = 0;
    if (bottom == -1) break;
    for (j = bottom + 1; j <= 200; j++) {
      if (dp[i][j] == -1)
        dp[i][j] = dp[i][j - 1] + v;
      else
        dp[i][j] = gmin(dp[i][j], dp[i][j - 1] + v);
      if (bottom >= nd - d) dp[i + 1][j - bottom] = dp[i][j];
    }
    if (nd - d > 200) break;
    if (bottom < nd - d)
      for (j = (200 - nd + d); j >= 0; j--) dp[i + 1][j] = dp[i][j + nd - d];
  }

  if (dp[tot - 1][100] == -1)
    printf("Impossible\n");
  else
    printf("%I64d\n", dp[tot - 1][100]);
  return 0;
}
