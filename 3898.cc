#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;

char s1[maxn];
char s2[maxn * 10];

int dp[maxn][maxn * 10];
int sum[maxn * 10];
const int inf = 0x3f3f3f3f;

int main() {
  while (~scanf("%s%s", &s1[1], &s2[1])) {
    int len1 = strlen(&s1[1]);
    int len2 = strlen(&s2[1]);

    sum[0] = 0;

    for (int i = 1; i <= len2; i++) sum[i] = sum[i - 1] + (s2[i] - 'a' + 1);
    for (int i = 0; i <= len1; i++)
      for (int j = 0; j <= len2; j++) dp[i][j] = inf;

    for (int i = 0; i <= len2; i++) {
      if (i > 0 && (s1[1] == '?' || s1[1] == s2[i]))
        dp[1][i] = sum[i] - sum[i - 1];
      else if (s1[1] == '*')
        dp[1][i] = 0;
    }

    bool flag = true;
    for (int i = 2; i <= len1; i++) {
      flag = false;
      if (s1[i] == '*') {
        int cur = inf;
        if (dp[i - 1][0] == 0) {
          dp[i][0] == 0;
          cur = 0;
          flag = true;
        }
        for (int j = 1; j <= len2; j++) {
          if (dp[i - 1][j] - sum[j] < cur) cur = dp[i - 1][j] - sum[j];
          if (cur + sum[j] < dp[i][j]) dp[i][j] = cur + sum[j], flag = true;
        }

      } else {
        for (int j = 1; j <= len2; j++) {
          if (dp[i - 1][j - 1] == inf) continue;
          if (s1[i] == '?' || s2[j] == s1[i]) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + s2[j] - 'a' + 1);
            flag = true;
          }
        }
      }
      if (!flag) break;
    }

    if (!flag) {
      puts("-1");
      continue;
    }

    int ans = inf;

    for (int i = 1; i <= len2; i++) ans = min(ans, dp[len1][i]);
    if (ans == -1)
      puts("-1");
    else
      printf("%d\n", ans);
  }
  return 0;
}
