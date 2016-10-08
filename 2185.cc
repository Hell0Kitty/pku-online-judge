#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
const int N = 10000 + 10;
int f[N];
void getFail(char *s, int f[]) {
  int m = strlen(s);
  f[0] = -1;
  for (int i = 1; i < m; i++) {
    int j = f[i - 1];
    while (j != -1 && s[j + 1] != s[i]) j = f[j];
    if (s[j + 1] == s[i]) j++;
    f[i] = j;
  }
}
int n, m;
char mz[N][80];
int cnt[N];
int check(char *s, int x) {
  int j = 0;
  for (int i = 0; i < m; i++) {
    if (s[i] != s[j]) return 0;
    j++;
    if (j > x) j = 0;
  }
  return 1;
}
void solve(int r) {
  f[0] = -1;
  for (int i = 1; i < n; i++) {
    int j = f[i - 1];
    while (j != -1 && strcmp(mz[j + 1], mz[i])) j = f[j];
    if (strcmp(mz[j + 1], mz[i]) == 0) j++;
    f[i] = j;
  }
  printf("%d\n", (n - 1 - f[n - 1]) * (r));
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; i++) {
      scanf("%s", mz[i]);
      getFail(mz[i], f);
      int j = m - 1;
      while (j != -1) {
        //  cout<<m - 1 - f[j]<<endl;
        cnt[m - 1 - f[j]]++;
        j = f[j];
      }
    }
    int r = 0;
    for (int i = 1; i <= m; i++)
      if (cnt[i] == n) {
        r = i;
        break;
      }
    for (int i = 0; i < n; i++) {
      mz[i][r] = 0;
    }

    solve(r);
  }
  return 0;
}
