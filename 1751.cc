#include <cstdio>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;
const int MAXN = 800;
const int MAXE = 500000;
const int INF = 0x7fffffff;
int nv, ne, index, set[MAXN], pos[MAXE];
struct Edge {
  int u, v;
  int val;
} edge[MAXE];
struct Node {
  int x, y;
} node[MAXN];
int cmp(const Edge& a, const Edge& b) { return a.val < b.val; }
int find_set(int x) {
  int root = x, tmp;
  while (set[root] >= 0) root = set[root];
  while (x != root) {
    tmp = set[x];
    set[x] = root;
    x = tmp;
  }
  return root;
}
void union_set(const int& root1, const int& root2) {
  int a = set[root1];
  int b = set[root1];
  if (a > b) {
    set[root1] = root2;
    set[root2] += a;
  } else {
    set[root2] = root1;
    set[root1] += b;
  }
}
int kruskal() {
  index = 0;
  int sum = 0, root1, root2, tmp, i;
  for (i = 0; i < ne; ++i) {
    root1 = find_set(edge[i].u);
    root2 = find_set(edge[i].v);
    if (root1 != root2) {
      pos[index] = i;
      ++index;
      union_set(root1, root2);
    }
  }
  return sum;
}
int main() {
  int i, j, k, a, b, tmp, val, n, m, root1, root2;
  while (scanf("%d", &nv) != EOF) {
    memset(set, -1, sizeof(set));
    for (i = 1; i <= nv; ++i) scanf("%d%d", &(node[i]).x, &(node[i].y));
    index = 0;
    for (i = 1; i <= nv; ++i)
      for (j = i + 1; j <= nv; ++j) {
        edge[index].u = i;
        edge[index].v = j;
        edge[index].val = (node[i].x - node[j].x) * (node[i].x - node[j].x) +
                          (node[i].y - node[j].y) * (node[i].y - node[j].y);
        ++index;
      }
    ne = index;
    sort(edge, edge + ne, cmp);
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
      scanf("%d%d", &a, &b);
      root1 = find_set(a);
      root2 = find_set(b);
      if (root1 != root2) union_set(root1, root2);
    }
    kruskal();
    for (i = 0; i < index; ++i)
      printf("%d %d\n", edge[pos[i]].u, edge[pos[i]].v);
  }
  return 0;
}