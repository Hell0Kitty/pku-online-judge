#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX 300
#define N 507

using namespace std;

char str[N];
int dp[N][N];
char s[MAX][MAX] = {
    "4",     // A
    "|3",    // B
    "(",     // C
    "|)",    // D
    "3",     // E
    "|=",    // F
    "6",     // G
    "#",     // H
    "|",     // I
    "_|",    // J
    "|<",    // K
    "|_",    // L
    "|8/|",  // M
    "|8|",   // N
    "0",     // O
    "|0",    // P
    "(,)",   // Q
    "|?",    // R
    "5",     // S
    "7",     // T
    "|_|",   // U
    "8/",    // V
    "8/8/",  // w
    "><",    // X
    "-/",    // Y
    "2",     // Z
};

int main() {
  char ss[MAX];
  while (~scanf("%s", ss)) {
    if (!strcmp(ss, "end")) break;
    int cnt = 0;
    int len3 = strlen(ss);
    for (int i = 0; i < len3; i++) {
      int len4 = strlen(s[ss[i] - 'A']);
      for (int j = 0; j < len4; j++) str[cnt++] = s[ss[i] - 'A'][j];
    }
    str[cnt++] = '\0';
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int len = strlen(str);
    for (int i = 1; i <= len; i++)
      for (int j = 0; j < 26; j++) {
        int len2 = strlen(s[j]);
        if (str[i - 1] != s[j][len2 - 1]) continue;
        if (len2 > i) continue;
        bool flag = false;
        int id = i - 1;
        for (int k = len2 - 1; k >= 0; k--)
          if (s[j][k] != str[id--]) flag = true;
        if (flag) continue;
        for (int k = 0; k < 26; k++) {
          dp[i][j] += dp[i - len2][k];
        }
      }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      ans += dp[len][i];
    }
    printf("%d\n", ans);
  }
}
