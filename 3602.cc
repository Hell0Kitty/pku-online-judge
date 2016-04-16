#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char s[1000];
int count1[1000];
int ff[7];
int len;

void solve() {
  int ans = 0;
  memset(count1, 0, sizeof(count1));
  memset(ff, 0, sizeof(ff));
  for (int i = 0; i < len; i++) {
    if (s[i] == 'f') {
      if (s[i + 1] == 'f' && (s[i + 2] == 'i' || s[i + 2] == 'l')) {
        if (s[i + 2] == 'i') ff[0] = 1;
        if (s[i + 2] == 'l') ff[1] = 1;
        i += 2;
      } else if (s[i + 1] == 'f' || s[i + 1] == 'i' || s[i + 1] == 'l') {
        if (s[i + 1] == 'f') ff[2] = 1;
        if (s[i + 1] == 'i') ff[3] = 1;
        if (s[i + 1] == 'l') ff[4] = 1;
        i++;
      } else
        count1[s[i]] = 1;
    } else if (s[i] == '`' && s[i + 1] == '`') {
      ff[5] = 1;
      i++;
    } else if (s[i] == '\'' && s[i + 1] == '\'') {
      ff[6] = 1;
      i++;
    } else
      count1[s[i]] = 1;
  }
  for (int i = 0; i <= 256; i++)
    if (count1[i]) ans++;
  for (int i = 0; i < 7; i++)
    if (ff[i]) ans++;
  cout << ans << endl;
}

int main() {
  char c;
  len = 0;
  while (cin >> c) {
    if (c == EOF) break;

    if (c == ' ' || c == '\n') continue;
    s[len++] = c;
  }
  solve();
  return 0;
}
