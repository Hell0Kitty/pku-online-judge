#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXN 60
#define MAXM 120
double coeff[MAXM][MAXN];
double right[MAXN];
double ans[MAXN];
int solve[MAXN];
int avail;

char inp[10000];

int dbcmp(double p) { return fabs(p) < 1e-6 ? 0 : p > 0 ? 1 : -1; }

int isa(char c) { return isupper(c) || isdigit(c); }

int main() {
  while (fgets(inp, 1000, stdin) &&
         (inp[0] != 'E' || inp[1] != 'N' || inp[2] != 'D')) {
    memset(coeff, 0, sizeof(coeff));

    char *c;
    int cnt = 0;
    while (1) {
      c = inp;
      while (*c && !(isupper(*c) || isdigit(*c))) {
        c++;
      }

      if (isdigit(*c)) {
        break;
      } else {
        double x, y;
        /*
        printf("%s", c);
        */
        if (sscanf(c + 1, " %lf %lf", &x, &y) == 2) {
          int dir = (*c - 'A') << 1;
          /*
          printf("%lf %lf\n", x, y);
          */
          coeff[cnt][dir] = 1.0;
          right[cnt] = x;
          ++cnt;

          coeff[cnt][dir + 1] = 1.0;
          right[cnt] = y;
          ++cnt;
        }
      }
      fgets(inp, 1000, stdin);
    }

    while (1) {
      c = inp;
      while (*c && !isa(*c)) {
        c++;
      }

      if (isdigit(*c)) {
        int cur = *c - '0';
        char u, v, w;
        ++c;
        sscanf(c, " %c %c %c", &u, &v, &w);
        int pu = (u - 'A') << 1;
        int pv = (v - 'A') << 1;
        int pw = (w - 'A') << 1;
        /*
        printf("get function %d %d %d %d\n", cur, pu, pv, pw);
        */
        if (cur == 1) {
          coeff[cnt][pu] = 0.5;
          coeff[cnt][pv] = 0.5;
          coeff[cnt][pw] = -1.0;
          right[cnt] = 0.0;
          ++cnt;

          coeff[cnt][pu + 1] = 0.5;
          coeff[cnt][pv + 1] = 0.5;
          coeff[cnt][pw + 1] = -1.0;
          right[cnt] = 0.0;
          ++cnt;
        } else {
          if (cur == 2) {
            coeff[cnt][pu + 1] = 1.0;
            coeff[cnt][pv + 1] = -1.0;
            coeff[cnt][pv] = 1.0;
            coeff[cnt][pw] = -1.0;
            right[cnt] = 0.0;
            ++cnt;

            coeff[cnt][pu] = -1.0;
            coeff[cnt][pv] = 1.0;
            coeff[cnt][pv + 1] = 1.0;
            coeff[cnt][pw + 1] = -1.0;
            right[cnt] = 0.0;
            ++cnt;
          } else {
            coeff[cnt][pu + 1] = -1.0;
            coeff[cnt][pv + 1] = 1.0;
            coeff[cnt][pv] = 1.0;
            coeff[cnt][pw] = -1.0;
            right[cnt] = 0.0;
            ++cnt;

            coeff[cnt][pu] = 1.0;
            coeff[cnt][pv] = -1.0;
            coeff[cnt][pv + 1] = 1.0;
            coeff[cnt][pw + 1] = -1.0;
            right[cnt] = 0.0;
            ++cnt;
          }
        }
      } else {
        break;
      }
      fgets(inp, 1000, stdin);
    }
    int has = (*c - 'A') << 1;
    int i, j, k;

    /*
    for ( i = 0; i < cnt; i++)
    {
            for ( j = 0; j < 12; j++)
            {
                    printf("%.2lf ", coeff[i][j]);
            }
            printf("%.2lf\n", right[i]);
    }
    printf("done \n");
    */

    int p = 0;
    for (i = 0; i < MAXN; i++) {
      j = p;
      while (j < cnt && !dbcmp(coeff[j][i])) {
        ++j;
      }
      if (j != cnt) {
        if (p != j) {
          double swap = right[p];
          right[p] = right[j];
          right[j] = swap;
          for (k = 0; k < MAXN; k++) {
            swap = coeff[p][k];
            coeff[p][k] = coeff[j][k];
            coeff[j][k] = swap;
          }
        }

        for (j = 0; j < cnt; j++) {
          if (j != p && dbcmp(coeff[j][i])) {
            double key = coeff[j][i] / coeff[p][i];
            right[j] -= right[p] * key;
            for (k = 0; k < MAXN; k++) {
              coeff[j][k] -= coeff[p][k] * key;
            }
          }
        }
        ++p;
      }
    }

    /*
    for ( i = 0; i < cnt; i++)
    {
            for ( j = 0; j < 12; j++)
            {
                    printf("%.2lf ", coeff[i][j]);
            }
            printf("%.2lf\n", right[i]);
    }
    printf("done \n");
    */

    avail = 1;
    memset(solve, 0, sizeof(solve));
    for (i = cnt - 1; i != -1 && avail; i--) {
      int allzero = 1;
      for (j = 0; j < MAXN && allzero; j++) {
        allzero = dbcmp(coeff[i][j]) == 0;
      }

      if (allzero && dbcmp(right[i])) {
        avail = 0;
      }

      if (i < MAXN && !allzero) {
        k = 0;
        while (k != MAXN && !dbcmp(coeff[i][k])) {
          k++;
        }
        if (k != -1) {
          ans[k] = right[i];
          solve[k] = 1;
          for (j = k + 1; j < MAXN && solve[k]; j++) {
            if (dbcmp(coeff[i][j])) {
              if (solve[j]) {
                ans[k] -= coeff[i][j] * ans[j];
              } else {
                solve[k] = 0;
              }
            }
          }
          ans[k] /= coeff[i][k];
        }
      }
    }

    if (solve[has] && solve[has + 1]) {
      if (ans[has] >= -0.004 && ans[has] <= 0.004) ans[has] = 0.0;
      if (ans[has + 1] >= -0.004 && ans[has + 1] <= 0.004) ans[has + 1] = 0.0;
      printf("%.2lf %.2lf\n", ans[has], ans[has + 1] + 1e-6);
    } else {
      printf("UNCERTAIN!\n");
    }
  }

  return 0;
}
