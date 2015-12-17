
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
using namespace std;
bool g[30][30], chk[30];
int link[30], n;
bool findpath(int x) {
  for (int y = 0; y < n; y++) {
    if (g[x][y] && !chk[y]) {
      chk[y] = true;
      if (link[y] == -1 || findpath(link[y])) {
        link[y] = x;
        return true;
      }
    }
  }
  return false;
}
int maxmatch() {
  memset(link, -1, sizeof(link));
  int ret = 0;
  for (int x = 0; x < n; x++) {
    memset(chk, false, sizeof(chk));
    if (findpath(x))
      ret++;
  }
  return ret;
}
int op[150];
bool small(char s1[], char s2[]) {
  if (op[s1[0]] != op[s2[0]])
    return op[s1[0]] < op[s2[0]];
  else
    return op[s1[1]] < op[s2[1]];
}
int main() {
  for (int i = 2; i <= 9; i++)
    op[i + '0'] = i;
  op['T'] = 10;
  op['J'] = 11;
  op['Q'] = 12;
  op['K'] = 13;
  op['A'] = 14;
  op['C'] = 1;
  op['D'] = 2;
  op['S'] = 3;
  op['H'] = 4;
  int T;
  for (scanf("%d", &T); T; T--) {
    scanf("%d", &n);
    memset(g, false, sizeof(g));
    char s1[30][3], s2[30][3];
    for (int i = 0; i < n; i++)
      scanf("%s", s1[i]);
    for (int i = 0; i < n; i++) {
      scanf("%s", s2[i]);
      for (int j = 0; j < n; j++)
        if (small(s1[j], s2[i]))
          g[i][j] = true;
    }
    printf("%d\n", maxmatch());
  }
  return 0;
}