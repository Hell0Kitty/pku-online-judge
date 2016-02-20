#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int n, m, fa[1010], ans;

int find(int x) {
  int temp = x;
  while (fa[x] != x) {
    x = fa[x];
  }
  fa[temp] = x;
  return x;
}

struct Edge {
  int len, u, v;
} edge[20010];

int cmp(const void *a, const void *b) {
  return (*(Edge *)b).len - (*(Edge *)a).len;
}

int Kruskal() {
  int num = 0, canfind = 0;
  ;
  ans = 0;
  for (int i = 0; i < n; i++) fa[i] = i;
  qsort(edge, m, sizeof(edge[0]), cmp);
  for (int i = 0; i < m; i++) {
    int x = find(edge[i].u), y = find(edge[i].v);
    if (x != y) {
      ans += edge[i].len;
      num++;
      fa[x] = y;
      if (num == n - 1) {
        canfind = 1;
        break;
      }
    }
  }
  return canfind;
}

int main() {
  int s, e, c;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &s, &e, &c);
      edge[i].len = c;
      edge[i].u = s;
      edge[i].v = e;
    }
    if (Kruskal()) {
      printf("%d\n", ans);
    } else
      printf("-1\n");
  }

  return 0;
}
