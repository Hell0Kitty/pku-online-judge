#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct Cube {
  int x, y, z;
  Cube(int a = 0, int b = 0, int c = 0) {
    x = a;
    y = b;
    z = c;
  }
  bool operator<(const Cube &t) const { return x * y > t.x * t.y; }
} cube[maxn];
int dp[maxn];
int main() {
  int n, tot, x, y, z, kase = 1;
  while (scanf("%d", &n), n) {
    for (int i = tot = 0; i < n; ++i) {
      scanf("%d%d%d", &x, &y, &z);
      cube[tot++] = Cube(x, y, z);
      cube[tot++] = Cube(y, z, x);
      cube[tot++] = Cube(x, z, y);
    }
    memset(dp, 0, sizeof dp);
    sort(cube, cube + tot);
    int maxHeight = 0;
    for (int i = 0; i < tot; ++i) {
      dp[i] = cube[i].z;
      for (int j = i - 1; j >= 0; --j) {
        if (cube[j].x > cube[i].x && cube[j].y > cube[i].y)
          dp[i] = max(dp[i], dp[j] + cube[i].z);
        if (cube[j].y > cube[i].x && cube[j].x > cube[i].y)
          dp[i] = max(dp[i], dp[j] + cube[i].z);
      }
      maxHeight = max(maxHeight, dp[i]);
    }
    printf("Case %d: maximum height = %d\n", kase++, maxHeight);
  }
  return 0;
}
