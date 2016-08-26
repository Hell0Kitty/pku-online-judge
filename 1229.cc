#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
#define N 1200
int s1[N], s2[N], l1, l2;
bool dp[N][N];
int t;
map<string, int> mp;
void trans(string s, int *t, int &len) {
  len = 0;
  for (int i = 0; i < s.length();) {
    if (s[i] == '.') {
      i++;
      continue;
    } else if (s[i] == '*')
      t[++len] = -1, t[++len] = -2, i++;
    else if (s[i] == '?')
      t[++len] = -1, t[++len] = -3, t[++len] = -3, i++;
    else if (s[i] == '!')
      t[++len] = -1, t[++len] = -1, t[++len] = -1, t[++len] = -2, i++;
    else {
      int j;
      for (j = i + 1; s[j] != '.' && j < s.length(); j++)
        ;
      string x = s.substr(i, j - i);
      if (!mp.count(x)) mp[x] = mp.size() + 1;
      t[++len] = mp[x];
      i = j + 1;
    }
  }
}
void gao(int i, int j) {
  if (s1[i] == -2 || s2[j] == -2 || s1[i] == -3) dp[i][j] = 1;
  j++;
  if (j > l2) return;
  if (s1[i] > 0) {
    for (int cnt = 0; j <= l2; j++) {
      if (s2[j] > 0 && s2[j] != s1[i]) break;
      if (s2[j] == -1 || s2[j] > 0) cnt++;
      if (cnt > 1) break;
      dp[i][j] = 1;
    }
  } else if (s1[i] == -2)
    for (; j <= l2; j++) dp[i][j] = 1;
  else if (s1[i] == -3 || s1[i] == -1) {
    for (int cnt = 0; j <= l2; j++) {
      if (s2[j] == -1 || s2[j] > 0) cnt++;
      if (cnt > 1) break;
      dp[i][j] = 1;
    }
  }
}
void solve() {
  dp[0][0] = 1;
  for (int i = 0; i < l1; i++)
    for (int j = 0; j <= l2; j++) {
      if (dp[i][j] == 0) continue;
      gao(i + 1, j);
    }
  printf("%s\n", dp[l1][l2] == 0 ? "NO" : "YES");
}
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    mp.clear();
    string s;
    cin >> s;
    trans(s, s1, l1);
    cin >> s;
    trans(s, s2, l2);
    solve();
  }
  return 0;
}
