#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 10010
#define INF 1000000000
#define max(a, b) (a > b ? a : b)
int first[N], f[N], size[N], can[N], list[N], d[N];
int ans, cnt, tl, n, K, l1, l2, tot;
struct edge {
  int y, next, w;
} e[N << 1];
inline void addedge(int x, int y, int z) {
  e[++cnt].next = first[x];
  e[cnt].y = y;
  e[cnt].w = z;
  first[x] = cnt;
  e[++cnt].next = first[y];
  e[cnt].y = x;
  e[cnt].w = z;
  first[y] = cnt;
}
void clear() {
  memset(first, 0, sizeof first);
  memset(can, -1, sizeof can);
  cnt = 0;
  ans = 0;
}
void dfs1(int x, int fa) {
  size[x] = 1;
  list[++tl] = x;
  for (int i = first[x]; i; i = e[i].next)
    if (e[i].y != fa && can[e[i].y]) {
      dfs1(e[i].y, x);
      f[e[i].y] = x;
      size[x] += size[e[i].y];
    }
}
int getroot(int x, int fa) {
  tl = 0;
  dfs1(x, fa);
  int pos, tmp = INF, d, y;
  for (int i = 1; i <= tl; i++) {
    d = 0;
    y = list[i];
    for (int p = first[y]; p; p = e[p].next)
      if (e[p].y != f[y] && can[e[p].y]) d = max(d, size[e[p].y]);
    if (y != x) d = max(d, size[x] - size[y]);
    if (d < tmp) pos = y, tmp = d;
  }
  return pos;
}
void dfs2(int x, int fa, int dis) {
  list[++l1] = x;
  d[x] = dis;
  for (int i = first[x]; i; i = e[i].next)
    if (e[i].y != fa && can[e[i].y]) {
      dfs2(e[i].y, x, dis + e[i].w);
    }
}
int getans(int *a, int l, int r) {
  int j = r, ret = 0;
  for (int i = l; i <= r; i++) {
    while (d[a[i]] + d[a[j]] > K && j > i) j--;
    ret += j - i;
    if (j == i) break;
  }
  return ret;
}
inline int cmp(int i, int j) { return d[i] < d[j]; }
void work(int x, int fa) {
  int root;
  root = getroot(x, fa);
  l1 = l2 = 0;
  for (int i = first[root]; i; i = e[i].next)
    if (can[e[i].y]) {
      l2 = l1;
      dfs2(e[i].y, root, e[i].w);
      sort(list + l2 + 1, list + l1 + 1, cmp);
      ans -= getans(list, l2 + 1, l1);
    }
  list[++l1] = root;
  d[root] = 0;
  sort(list + 1, list + l1 + 1, cmp);
  ans += getans(list, 1, l1);
  can[root] = 0;
  for (int i = first[root]; i; i = e[i].next)
    if (can[e[i].y]) work(e[i].y, root);
}
char ch;
void read(int &x) {
  while (ch = getchar(), ch < '0' || ch > '9')
    ;
  x = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - '0';
}
int main() {
  while (scanf("%d%d", &n, &K), n || K) {
    clear();
    int x, y, z;
    for (int i = 1; i < n; i++) read(x), read(y), read(z), addedge(x, y, z);
    work(1, 0);
    printf("%d\n", ans);
  }
  return 0;
}