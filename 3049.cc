#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
char c[20000], a[20000];
int n, m, v[20000];
void dfs(int i, int hi) {
  int x, y, j;
  char h;
  if (i == n) {
    x = 0;
    y = 0;
    for (j = 0; j < n; j++) {
      if (a[j] == 'a' || a[j] == 'e' || a[j] == 'i' || a[j] == 'o' ||
          a[j] == 'u')
        x++;
      else
        y++;
    }
    if (x >= 1 && y >= 2) {
      for (j = 0; j < n; j++) printf("%c", a[j]);
      printf("\n");
    }
    return;
  } else
    for (j = hi; j < m; j++) {
      if (!v[j]) {
        v[j] = 1;
        a[i] = c[j];
        dfs(i + 1, j + 1);  // printf("%d",i);
        v[j] = 0;
      }
    }
}
int main() {
  int i, j;
  while (scanf("%d%d", &n, &m) != EOF) {
    gets(c);
    j = 0;  // puts(c);
    for (i = 0; i < strlen(c); i++)
      if (c[i] >= 'a' && c[i] <= 'z') c[j++] = c[i];
    c[j] = '\0';
    sort(c, c + strlen(c));  // printf("%s",c);
    memset(v, 0, sizeof(v));
    dfs(0, 0);
  }
  return 0;
}
