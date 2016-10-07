#include <iostream>
#include <string>
#define MAXN 500
using namespace std;

bool dp[MAXN][MAXN];

int main() {
  int test;
  string s_1;
  string s_2;
  string s_3;
  int i;
  int j;
  int k;
  int time = 0;
  cin >> test;
  while (test--) {
    cout << "Data set " << ++time << ": ";
    memset(dp, false, sizeof(dp));
    cin >> s_1 >> s_2 >> s_3;
    dp[0][0] = true;
    for (i = 0; i <= s_1.length(); ++i) {
      for (j = 0; j <= s_2.length(); ++j) {
        if (i - 1 >= 0 && dp[i - 1][j] && s_1[i - 1] == s_3[i + j - 1]) {
          { dp[i][j] = true; }
        }
        if (j - 1 >= 0 && dp[i][j - 1] && s_2[j - 1] == s_3[i + j - 1]) {
          { dp[i][j] = true; }
        }
      }
    }
    if (dp[s_1.length()][s_2.length()]) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
