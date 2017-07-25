#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXINT 99999999

using namespace std;

char mp[100][3];
int len = 1;

int data[100][100];

int findv(char tmpStr[]) {
  int i;

  for (i = 1; i < len; i++)
    if (strcmp(tmpStr, mp[i]) == 0) return i;
  return 0;
}

int insertv(char tmpStr[]) {
  strcpy(mp[len], tmpStr);
  len++;
  return len;
}

int main() {
  int n, m, p;

  int i, j, k;
  int q;

  scanf("%d", &q);
  getchar();

  int t;
  for (t = 1; t <= q; t++) {
    len = 1;

    scanf("%d%d%d", &n, &m, &p);
    getchar();

    for (i = 0; i < n; i++) {
      char tmpStr[3];
      scanf("%s", tmpStr);
      getchar();

      insertv(tmpStr);
    }

    for (i = 0; i < len; i++)
      for (j = 0; j < len; j++) data[i][j] = MAXINT;

    for (i = 0; i < m; i++) {
      char s1[10], s2[10];

      scanf("%s %s", s1, s2);
      getchar();

      int v1 = findv(s1);
      int v2 = findv(s2);

      data[v1][v2] = 1;
      data[v2][v1] = 1;
    }

    for (k = 1; k <= n; k++)
      for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
          if (data[i][j] > data[i][k] + data[k][j])
            data[i][j] = data[i][k] + data[k][j];
        }
    if (t == 1) printf("SHIPPING ROUTES OUTPUT\n\n");

    if (t > 1)
      printf("\nDATA SET %d\n\n", t);
    else
      printf("DATA SET %d\n\n", t);

    for (i = 0; i < p; i++) {
      int cost;
      char s1[10], s2[10];

      scanf("%d %s %s", &cost, s1, s2);
      getchar();

      int v1 = findv(s1);
      int v2 = findv(s2);
      if (data[v1][v2] < MAXINT) {
        printf("$%d\n", data[v1][v2] * cost * 100);
      } else
        printf("NO SHIPMENT POSSIBLE\n");
    }
  }
  printf("\nEND OF OUTPUT\n");

  return 0;
}
