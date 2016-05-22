#include <stdio.h>
#include <string.h>
#define N 20005
struct edge {
  int y, next;
} e[100005 << 1];
int first[N], dfn[N], order = 0;
int n, m, top;
void add(int x, int y) {
  e[top].y = y;
  e[top].next = first[x];
  first[x] = top++;
}
int dfs(int x) {
  int i, y, w, v = -1;
  dfn[x] = ++order;
  for (i = first[x]; i != -1; i = e[i].next) {
    y = e[i].y;
    if (!dfn[y]) {
      w = dfs(y);
      if (w != -1)
        printf("%d %d %d\n", x, y, w);
      else {
        if (v != -1) {
          printf("%d %d %d\n", v, x, y);
          v = -1;
        } else
          v = y;
      }
    } else if (dfn[x] < dfn[y]) {
      if (v != -1) {
        printf("%d %d %d\n", v, x, y);
        v = -1;
      } else
        v = y;
    }
  }
  return v;
}
int main() {
  int i, a, b;
  top = 0;
  memset(dfn, 0, sizeof(dfn));
  memset(first, -1, sizeof(first));
  scanf("%d %d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    add(a, b);
    add(b, a);
  }
  dfs(1);
  return 0;
}
