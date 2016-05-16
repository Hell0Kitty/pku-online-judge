#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[105][105];
int main() {
  int pos1[105], pos2[105];
  char s1[105], s2[105], tp[205], ans[205];
  while (scanf("%s%s", s1 + 1, s2 + 1) != EOF) {
    memset(dp, 0, sizeof(dp));
    int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
    for (int i = 1; i <= len1; i++)
      for (int j = 1; j <= len2; j++)
        if (s1[i] == s2[j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    int len = dp[len1][len2];
    pos1[len] = pos2[len] = 10000;
    tp[len--] = '\0';
    for (int i = len1, j = len2; i != 0 && j != 0;) {
      if (s1[i] == s2[j] && dp[i][j] == dp[i - 1][j - 1] + 1)
        tp[len] = s1[i], pos1[len] = i, pos2[len] = j, len--, i--, j--;
      else if (dp[i][j] == dp[i - 1][j])
        i--;
      else
        j--;
    }
    len = dp[len1][len2];
    int top = 0;
    for (int i = 1, j = 1, k = 0; i <= len1 || j <= len2;) {
      while (i <= len1 && i < pos1[k]) ans[top++] = s1[i++];
      while (j <= len2 && j < pos2[k]) ans[top++] = s2[j++];
      if (k <= len) ans[top++] = tp[k++], i++, j++;
    }
    ans[top] = '\0';
    puts(ans);
  }
  return 0;
}
