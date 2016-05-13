#include <iostream>
#include <cmath>
using namespace std;

const int mod = 20090305;
char s[505];
int f[2][505][505], p[3][505][2], R[3], C;

void init() {
  int i, j, cnt, L = strlen(s);
  memset(p, 0, sizeof(p));
  for (i = 0; i < 3; i++) {
    cnt = 0;
    for (j = 0; j < L; j++) {
      if (s[j] == i + 'A') cnt++;
      if (j >= R[i]) p[i][j - R[i]][1] = cnt;
      if (j + R[i] < L) p[i][j + R[i]][0] = cnt;
    }
    for (j = 0; j < R[i]; j++) {
      p[i][L - 1 - j][1] = cnt;
      p[i][j][0] = 0;
    }
  }
}

int DP() {
  int ans = 0, i, j, k, t, L = strlen(s), cur = 1, pre = 0;
  memset(f, 0, sizeof(f));
  for (i = 0; i < L; i++)
    for (j = 0; j < L; j++) f[0][i][j] = 1;
  for (t = 0; t < L; t++) {
    memset(f[cur], 0, sizeof(f[cur]));
    for (i = p[0][t][0]; i <= p[0][t][1]; i++)
      for (j = p[1][t][0]; j <= p[1][t][1]; j++) {
        k = t + 1 - i - j;
        if (k < p[2][t][0] || k > p[2][t][1] || !f[pre][i][j]) continue;
        if (t == L - 1) {
          ans += f[pre][i][j];
          continue;
        }
        f[cur][i + 1][j] = (f[cur][i + 1][j] + f[pre][i][j]) % mod;
        f[cur][i][j + 1] = (f[cur][i][j + 1] + f[pre][i][j]) % mod;
        f[cur][i][j] = (f[cur][i][j] + f[pre][i][j]) % mod;
      }
    pre = !pre;
    cur = !cur;
  }
  return ans;
}

int main() {
  for (scanf("%d", &C); C--;) {
    scanf("%d%d%d", &R[0], &R[1], &R[2]);
    scanf("%s", s);
    init();
    printf("%d\n", DP());
  }
  return 0;
}
