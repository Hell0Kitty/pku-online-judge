#include <iostream>
using namespace std;
const int MAXN = 50000;
int main() {
  __int64 dp[MAXN];
  char s[MAXN];
  while (scanf("%s", s + 1) != EOF) {
    int len = strlen(s + 1);
    if (len == 1 && s[1] == '0') break;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= len; i++) {
      if (s[i] != '0') {
        dp[i] = dp[i - 1];
        int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if (num >= 11 && num <= 26) dp[i] += dp[i - 2];
      } else {
        if (s[i - 1] == '0')
          dp[i] == dp[i - 1];
        else if (s[i - 1] == '1' || s[i - 1] == '2')
          dp[i] = dp[i - 2];
      }
    }
    printf("%I64d\n", dp[len]);
  }
  return (0);
}
