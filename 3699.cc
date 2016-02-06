#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 10001

char P[MAXN][11][201];
int n;
int m;
int qry;
int k;
int q;
int si;
int nres;
int cons;
char xd[11][201];
int id[11];
int kind[11];
char col[11][201];
int res[MAXN];
int width, height;

int val;
int maxl;
char str[301];
char sample[301];
char type[11];
char tmps[10];
int maxdis[11];

int main() {
  int i, j, h;
  char c;
  memset(P, 0x00, sizeof(P));
  scanf("%d %d %d", &n, &m, &k);
  for (i = 0; i < n; i++) {
    scanf("%s %s", col[i], type);
    if (strcmp(type, "STR") == 0) {
      kind[i] = 1;
    } else {
      kind[i] = 0;
    }
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%s", P[i][j]);
    }
  }
  while (k--) {
    scanf("%s", tmps);
    getchar();
    qry = 0;
    memset(xd, 0x00, sizeof(xd));
    while (1) {
      int tmp = 0;
      while (1) {
        c = getchar();
        if (c == ' ') {
          qry++;
          goto flag;
        } else if (c == ',')
          break;
        else
          xd[qry][tmp++] = c;
      }
      qry++;
    }

  flag:
    for (i = 0; i < qry; i++) {
      for (j = 0; j < n; j++) {
        if (strcmp(xd[i], col[j]) == 0) {
          id[i] = j;
          break;
        }
      }
    }
    j = 0;
    scanf("%s", tmps);

    getchar();
    memset(str, 0x00, sizeof(str));
    while (1) {
      c = getchar();
      if (c == '=') {
        q = 0;
        for (i = 0; i < n; i++) {
          if (strcmp(col[i], str) == 0) {
            cons = i;
            break;
          }
        }

        if (kind[i] == 1) {
          si = 1;
          while (c = getchar() == ' ') getchar();

          scanf("%s", sample);

          sample[strlen(sample) - 1] = '\0';

        } else {
          si = 0;
          scanf("%s", sample);

          val = atoi(sample);
        }
        break;
      } else if (c == '<') {
        q = 1;
        si = 0;
        for (i = 0; i < n; i++) {
          if (strcmp(col[i], str) == 0) {
            cons = i;
            break;
          }
        }

        scanf("%s", sample);

        val = atoi(sample);

        break;
      } else if (c == '>') {
        q = 2;
        si = 0;
        for (i = 0; i < n; i++) {
          if (strcmp(col[i], str) == 0) {
            cons = i;
            break;
          }
        }

        scanf("%s", sample);

        val = atoi(sample);

        break;
      } else if (c == ' ')
        continue;
      else
        str[j++] = c;
    }
    nres = 0;
    if (!si)  //限制条件是数字类型
    {
      if (q == 0) {
        for (i = 0; i < m; i++) {
          if (atoi(P[i][cons]) == val) {
            res[nres++] = i;
          }
        }
      } else if (q == 1) {
        for (i = 0; i < m; i++) {
          if (atoi(P[i][cons]) < val) {
            res[nres++] = i;
          }
        }
      } else if (q == 2) {
        for (i = 0; i < m; i++) {
          if (atoi(P[i][cons]) > val) {
            res[nres++] = i;
          }
        }
      }
    } else {
      for (i = 0; i < m; i++) {
        if (strcmp(P[i][cons], sample) == 0) {
          res[nres++] = i;
        }
      }
    }

    width = 1;

    for (i = 0; i < qry; i++) {
      maxdis[i] = strlen(col[id[i]]);
      for (j = 0; j < nres; j++) {
        if (maxdis[i] < strlen(P[res[j]][id[i]])) {
          maxdis[i] = strlen(P[res[j]][id[i]]);
        }
      }
      maxdis[i] += 2;
      width += maxdis[i] + 1;
    }
    printf("+");
    for (i = 1; i < width - 1; i++) {
      printf("-");
    }
    printf("+\n");
    printf("|");
    for (i = 0; i < qry; i++) {
      for (j = 0; j < (maxdis[i] - strlen(col[id[i]])) / 2; j++) {
        printf(" ");
      }
      printf("%s", col[id[i]]);
      for (j = 0; j < (maxdis[i] - strlen(col[id[i]]) + 1) / 2; j++) {
        printf(" ");
      }
      printf("|");
    }
    printf("\n");
    printf("|");
    for (i = 0; i < qry; i++) {
      for (j = 0; j < maxdis[i]; j++) {
        printf("-");
      }
      printf("|");
    }
    printf("\n");
    for (i = 0; i < nres; i++) {
      printf("|");
      for (j = 0; j < qry; j++) {
        for (h = 0; h < (maxdis[j] - strlen(P[res[i]][id[j]])) / 2; h++) {
          printf(" ");
        }
        printf("%s", P[res[i]][id[j]]);
        for (h = 0; h < (maxdis[j] - strlen(P[res[i]][id[j]] + 1)) / 2; h++) {
          printf(" ");
        }
        printf("|");
      }
      printf("\n");
    }
    printf("+");
    for (i = 1; i < width - 1; i++) {
      printf("-");
    }
    printf("+\n");
    printf("\n");
  }
  return 0;
}
