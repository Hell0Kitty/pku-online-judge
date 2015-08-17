
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
  int id, h, s;
  int fa, sum;
} data[30001];
int map[1000000];
int stack[30001], top = 0;
int cmp(const void *a, const void *b) {
  struct node *aa = (struct node *)a;
  struct node *bb = (struct node *)b;
  return (aa->s) - (bb->s);
}
int main() {
  int testcase;
  scanf("%d", &testcase);
  while (testcase--) {
    int n, m, i;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
      scanf("%d%d%d", &data[i].id, &data[i].s, &data[i].h);
      map[data[i].id] = data[i].s;
      data[i].fa = 0;
      data[i].sum = 1;
    }
    qsort(data, n, sizeof(struct node), cmp);
    top = 0;
    for (i = 0; i < n; i++) {
      while (top && data[stack[top - 1]].h <= data[i].h) {
        data[stack[top - 1]].fa = data[i].id;
        data[i].sum += data[stack[top - 1]].sum;
        top--;
      }
      stack[top++] = i;
    }
    while (m--) {
      struct node t;
      scanf("%d", &t.id);
      t.s = map[t.id];
      struct node *ans = bsearch(&t, data, n, sizeof(struct node), cmp);
      printf("%d %d\n", ans->fa, ans->sum - 1);
    }
  }
  return 0;
}