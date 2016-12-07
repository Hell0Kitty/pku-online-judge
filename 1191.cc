#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 15;
const double M = 100000000.0;
double ans[N][10][10][10][10];
double K;
int sum[10][10][10][10];
int a[10][10];
int n;
int dpsum(int x1, int y1, int x2, int y2) {
  if (sum[x1][y1][x2][y2] != -1) return sum[x1][y1][x2][y2];
  if (x1 == x2 && y1 == y2) {
    sum[x1][y1][x2][y2] = a[x1][y1];
  } else if (x1 < x2) {
    sum[x1][y1][x2][y2] = dpsum(x1, y1, x1, y2) + dpsum(x1 + 1, y1, x2, y2);
  } else if (y1 < y2) {
    sum[x1][y1][x2][y2] = dpsum(x1, y1, x2, y1) + dpsum(x1, y1 + 1, x2, y2);
  }
  return sum[x1][y1][x2][y2];
}
double FFmin(double x, double y) { return (x < y) ? x : y; }
double dpans(int k, int x1, int y1, int x2, int y2) {
  if (ans[k][x1][y1][x2][y2] >= 0.0) {
    return ans[k][x1][y1][x2][y2];
  }
  if (k == 0) {
    ans[k][x1][y1][x2][y2] =
        ((sum[x1][y1][x2][y2] - K) * (sum[x1][y1][x2][y2] - K));
    return ans[k][x1][y1][x2][y2];
  }
  ans[k][x1][y1][x2][y2] = M;
  for (int x = x1; x < x2; ++x) {
    ans[k][x1][y1][x2][y2] =
        FFmin(ans[k][x1][y1][x2][y2],
              (dpans(k - 1, x1, y1, x, y2)) +
                  (sum[x + 1][y1][x2][y2] - K) * (sum[x + 1][y1][x2][y2] - K));
    ans[k][x1][y1][x2][y2] =
        FFmin(ans[k][x1][y1][x2][y2],
              (dpans(k - 1, x + 1, y1, x2, y2)) +
                  (sum[x1][y1][x][y2] - K) * (sum[x1][y1][x][y2] - K));
  }
  for (int y = y1; y < y2; ++y) {
    ans[k][x1][y1][x2][y2] =
        FFmin(ans[k][x1][y1][x2][y2],
              (dpans(k - 1, x1, y1, x2, y)) +
                  (sum[x1][y + 1][x2][y2] - K) * (sum[x1][y + 1][x2][y2] - K));
    ans[k][x1][y1][x2][y2] =
        FFmin(ans[k][x1][y1][x2][y2],
              (dpans(k - 1, x1, y + 1, x2, y2)) +
                  (sum[x1][y1][x2][y] - K) * (sum[x1][y1][x2][y] - K));
  }
  return ans[k][x1][y1][x2][y2];
}
void begin(int n) {
  for (int i = 0; i < n; ++i)
    for (int l1 = 1; l1 <= 8; ++l1)
      for (int l2 = 1; l2 <= 8; ++l2)
        for (int l3 = 1; l3 <= 8; ++l3)
          for (int l4 = 1; l4 <= 8; ++l4) {
            ans[i][l1][l2][l3][l4] = -1.0;
          }
  for (int l1 = 1; l1 <= 8; ++l1)
    for (int l2 = 1; l2 <= 8; ++l2)
      for (int l3 = 1; l3 <= 8; ++l3)
        for (int l4 = 1; l4 <= 8; ++l4) {
          dpsum(l1, l2, l3, l4);
        }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= 8; ++i) {
      for (int j = 1; j <= 8; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    memset(sum, -1, sizeof(sum));
    begin(n);
    K = 1.0 * sum[1][1][8][8] / n;
    printf("%.3f\n", sqrt(1.0 * dpans(n - 1, 1, 1, 8, 8) / n));
  }
  return 0;
}
