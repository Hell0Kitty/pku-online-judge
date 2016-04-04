#include <stdio.h>
#include <stdlib.h>

struct node {
  int u, v, dis;
};

node a[1005];
int C, n, e, p[1005], num = 0;

void Add(int u, int v, int dis) {
  if (u < v)
    a[e].u = u, a[e].v = v;
  else
    a[e].u = v, a[e].v = u;
  a[e++].dis = dis;
}

int cmp(const void *a, const void *b) {
  node aa = *(node *)a;
  node bb = *(node *)b;
  if (aa.dis == bb.dis) {
    if (aa.u == bb.u) return aa.v - bb.v;
    return aa.u - bb.u;
  }
  return aa.dis - bb.dis;
}

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

void Union(int u, int v) {
  u = find(u);
  v = find(v);
  if (u != v) p[u] = v;
}

int main() {
  for (scanf("%d", &C); C--;) {
    scanf("%d", &n);
    int i, j, dis, u, v;
    for (e = 0, i = 1; i <= n; i++) {
      for (j = 1; j < n; j++) {
        scanf("%d,", &dis);
        if (j < i && dis) Add(i, j, dis);
      }
      scanf("%d", &dis);
    }
    qsort(a, e, sizeof(a[0]), cmp);
    for (i = 1; i <= n; i++) p[i] = i;
    printf("Case %d:\n", ++num);
    for (i = 0; i < e; i++) {
      u = a[i].u;
      v = a[i].v;
      dis = a[i].dis;
      if (find(u) != find(v)) {
        printf("%c-%c %d\n", u - 1 + 'A', v - 1 + 'A', dis);
        Union(u, v);
      }
    }
  }
  return 0;
}
