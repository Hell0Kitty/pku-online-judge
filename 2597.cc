#include <stdio.h>
#include <algorithm>
using namespace std;
struct node {
  int x, y;
} a[100];
int dp[200], way[200];
bool d[100][100];

bool cmp(node a, node b) {
  if (a.x != b.x)
    return a.x < b.x;
  else
    return a.y < b.y;
}
int main() {
  int n, ans, max;
  while (scanf("%d", &n) != EOF) {
    ans = 0;
    max = -1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) d[i][j] = false;
    for (int i = 0; i < n; i++) {
      dp[i] = 0;
      way[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      scanf("%d%d", &a[i].x, &a[i].y);
      if (a[i].x > a[i].y) {
        int temp = a[i].x;
        a[i].x = a[i].y;
        a[i].y = temp;
      }
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[i].y <= a[j].x) d[i][j] = true;

    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++)
        if (d[i][j]) {
          if (dp[i] < dp[j] + 1) {
            dp[i] = dp[j] + 1;
            way[i] = way[j];
          } else if (dp[i] == dp[j] + 1) {
            way[i] += way[j];
          }
        }
      if (dp[i] == 0) {
        dp[i] = 1;
        way[i] = 1;
      }

      if (max < dp[i]) {
        max = dp[i];
        ans = way[i];
      } else if (max == dp[i]) {
        ans += way[i];
      }
    }
    printf("%d %d\n", n - max, ans);
  }
  return 0;
}
