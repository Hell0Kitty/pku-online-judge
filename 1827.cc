#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 50001;
struct Node {
  int d, s;
} mons[N];
int n, m, p[N];
int cmp(Node a, Node b) {
  if (a.s != b.s) {
    return a.s > b.s;
  }

  return a.d > b.d;
}
int find(int x) {
  if (x != p[x]) {
    p[x] = find(p[x]);
  }

  return p[x];
}
void Un_set(int x, int y) {
  int rx = find(x), ry = find(y);
  p[ry] = p[rx];
}
int main() {
  while (~scanf("%d%d", &n, &m) && (n + m)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &mons[i].d);
    }

    for (int i = 1; i <= n; i++) {
      scanf("%d", &mons[i].s);
    }

    sort(mons + 1, mons + n + 1, cmp);

    for (int i = 0; i <= m; i++) {
      p[i] = i;
    }

    int sum = 0;

    for (int i = 1; i <= n; i++) {
      int rd = find(mons[i].d);

      if (rd == 0) {
        sum += mons[i].s;
        continue;
      }

      Un_set(rd - 1, mons[i].d);
    }

    printf("%d\n", sum);
  }

  return 0;
}
