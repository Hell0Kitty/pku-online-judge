#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int l = -55555;
int main() {
  int n, m, t, i, j, q, h, f, ll, v;
  char s[500];
  char ss[50];
  double a[55][45];
  int p[55];
  cin >> n;
  for (q = 1; q <= n; q++) {
    cin >> m >> t;
    getchar();
    gets(s);
    ll = strlen(s);
    j = 0;
    for (i = 1; i <= m; i++) {
      v = 0;
      while (s[j] != ' ' && s[j] != '\0') {
        ss[v] = s[j];
        v++;
        j++;
      }
      ss[v] = '\0';
      j++;
      if (ss[0] == 'L')
        p[i] = l;
      else
        sscanf(ss, "%d", p + i);
    }
    p[0] = 0;
    p[m + 1] = 0;
    for (i = 0; i <= m; i++) a[i][0] = 0;
    for (i = 0; i <= t; i++) a[m + 1][i] = 1;
    for (i = 1; i <= t; i++) {
      for (j = 0; j <= m; j++) {
        if (p[j + 1] == l) {
          if (i <= 2)
            a[j][i] = 0;
          else
            a[j][i] = a[j + 1][i - 2] / 2.0;
        } else {
          h = j + 1 + p[j + 1];
          if (h < 0) h = 0;
          if (h > m + 1) h = m + 1;
          a[j][i] = a[h][i - 1] / 2.0;
        }
        if (j == m)
          a[j][i] += 0.5;
        else {
          if (p[j + 2] == l) {
            if (i > 2) a[j][i] += a[j + 2][i - 2] / 2.0;
          } else {
            h = j + 2 + p[j + 2];
            if (h < 0) h = 0;
            if (h > m + 1) h = m + 1;
            a[j][i] += a[h][i - 1] / 2.0;
          }
        }
      }
    }
    if (fabs(a[0][t] - 0.5000) < 0.0000001)
      printf("Push. 0.5000\n");
    else {
      f = a[0][t] * 10000000;
      if (f > 5000000)
        printf("Bet for. %.4f\n", a[0][t]);
      else
        printf("Bet against. %.4f\n", a[0][t]);
    }
  }
  return 0;
}
