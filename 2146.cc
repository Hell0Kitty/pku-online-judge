#include <cstdio>
#include <string.h>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;
struct cstr {
  char s[22];
  bool operator<(const cstr &c) const { return strcmp(s, c.s) < 0; }
} st[205];
int n, dis, d[20][20];
int dp(char *s1, char *s2) {
  int l1 = strlen(s1), l2 = strlen(s2);
  memset(d, 0, sizeof d);
  for (int i = 1; i <= l2; i++) d[0][i] = i;
  for (int i = 1; i <= l1; i++) d[i][0] = i;
  for (int i = 1; i <= l1; i++) {
    for (int j = 1; j <= l2; j++) {
      d[i][j] = INF;
      if (s1[i - 1] == s2[j - 1]) {
        d[i][j] = d[i - 1][j - 1];
      } else {
        d[i][j] = min(d[i][j - 1], min(d[i - 1][j], d[i - 1][j - 1])) + 1;
      }
      if (i >= 2 && j >= 2 && s1[i - 2] == s2[j - 1] &&
          s1[i - 1] == s2[j - 2]) {
        d[i][j] = min(d[i][j], d[i - 2][j - 2] + 1);
      }
      if (i >= 2 && j >= 3 && s1[i - 2] == s2[j - 1] &&
          s1[i - 1] == s2[j - 3]) {
        d[i][j] = min(d[i][j], d[i - 2][j - 3] + 2);
      }
      if (i >= 3 && j >= 2 && s1[i - 1] == s2[j - 2] &&
          s1[i - 3] == s2[j - 1]) {
        d[i][j] = min(d[i][j], d[i - 3][j - 2] + 2);
      }
    }
  }
  return d[l1][l2];
}

int main() {
  while (scanf("%d", &n), n) {
    scanf("%d", &dis);
    for (int i = 0; i < n; i++) scanf("%s", st[i].s);
    sort(st, st + n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int x = dp(st[i].s, st[j].s);
        if (x <= dis) {
          tot++;
          printf("%s,%s\n", st[i].s, st[j].s);
        }
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
