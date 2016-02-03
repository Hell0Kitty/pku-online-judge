#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct node {
  int x;
  int w;
  int f;
  int c;
  bool operator<(const node &a) const {
    if (x == a.x) return w < a.w;
    return x < a.x;
  }
} a[maxn];
int l, n, b, dp[1001][1001];
int main() {
  while (scanf("%d%d%d", &l, &n, &b) != EOF) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
      scanf("%d%d%d%d", &a[i].x, &a[i].w, &a[i].f, &a[i].c);
    sort(a, a + n);
    for (int i = 0; i <= b; i++) dp[0][i] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= b - a[i].c; j++)
        if (dp[a[i].x][j] != -1)
          dp[a[i].x + a[i].w][j + a[i].c] =
              max(dp[a[i].x + a[i].w][j + a[i].c], dp[a[i].x][j] + a[i].f);
    printf("%d\n", dp[l][b]);
  }
  return 0;
}
