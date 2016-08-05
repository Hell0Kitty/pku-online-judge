#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 205
using namespace std;

int c[MAXN][MAXN], step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char s[MAXN][MAXN];
bool isMax(int i, int j, int &k) {
  int t, ii, jj;
  s[i][j] = '2';
  if (c[i][j] < 2) {
    for (t = 0; t < 4; t++) {
      ii = i + step[t][0];
      jj = j + step[t][1];
      if (s[ii][jj] == '0' && c[ii][jj] == 1) k++;
    }
  }
  for (t = 0; t < 4; t++) {
    ii = i + step[t][0];
    jj = j + step[t][1];
    if (s[ii][jj] == '1') {
      if (c[ii][jj] > 2) return false;
      return isMax(ii, jj, k);
    }
  }
  return true;
}

int main() {
  int n, m, i, j, k, no;
  for (; scanf("%d%d", &n, &m), n + m;) {
    memset(c, 0, sizeof(c));
    for (i = 0; i <= n + 1; i++) s[i][0] = '2', s[i][m + 1] = '\0';
    for (j = 0; j <= m + 1; j++) s[0][j] = s[n + 1][j] = '2';
    for (i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++)
        for (k = 0; k < 4; k++)
          if (s[i + step[k][0]][j + step[k][1]] == '1') c[i][j]++;
    for (i = 1, no = 0; i <= n; i++)
      for (j = 1; j <= m; j++)
        if (s[i][j] == '1' && c[i][j] < 2) {
          k = 0;
          if (isMax(i, j, k) && !k) no++;
        }
    printf("%d\n", no);
  }
  return 0;
}
