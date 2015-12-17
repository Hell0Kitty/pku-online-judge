
#include "stdio.h"
#include "string.h"
#define M 40005

int a[26], ans[26], w[M][26], n;
int max = 0;
int v[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5,
           2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};

void dfs(int beg, int value, int c) {
  int i, j, va;
  if (c == 0) {
    if (value > max) max = value;
  }
  if (beg == n) return;
  for (i = beg; i < n; i++) {
    for (j = 0; j < 26; j++) {
      if (w[i][j] > a[j]) break;
    }
    if (j == 26) {
      va = value;
      for (j = 0; j < 26; j++) {
        a[j] -= w[i][j];
        va += w[i][j] * v[j];
      }
      dfs(i + 1, va, c - 1);
      for (j = 0; j < 26; j++) a[j] += w[i][j];
    }
  }
}

int main() {
  int i, j;
  char s[10];
  memset(a, 0, sizeof(a));
  memset(ans, 0, sizeof(ans));
  memset(w, 0, sizeof(w));
  n = 0;
  scanf("%s", s);
  for (i = 0; s[i] != 0; i++) {
    a[s[i] - 'a']++;
  }
  while (1) {
    scanf("%s", s);
    if (strcmp(s, ".") == 0) break;
    for (i = 0; s[i] != 0; i++) {
      w[n][s[i] - 'a']++;
    }
    n++;
  }
  for (i = 1; i < 3; i++) {
    dfs(0, 0, i);
  }
  printf("%d\n", max);
  return 0;
}