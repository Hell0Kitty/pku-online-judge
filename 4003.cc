#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxn 50003
int f1[maxn], f2[maxn];
int g1[maxn], g2[maxn];
int n, m;

struct E {
  int v, next, w;
} edge[maxn << 1];

int head[maxn], tot;

void init() {
  tot = 0;
  memset(head, -1, sizeof(int) * (n + 1));
}

void add(int s, int t, int w) {
  edge[tot].v = t;
  edge[tot].w = w;
  edge[tot].next = head[s];
  head[s] = tot++;
}

int maxz(int a, int b) { return a > b ? a : b; }
int minz(int a, int b) { return a < b ? a : b; }
void dfs1(int u, int pre) {
  int i;
  f1[u] = f2[u] = 0;
  for (i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == pre) continue;
    int w = edge[i].w;
    dfs1(v, u);
    if (f2[u] < f1[v] + w) {
      f2[u] = f1[v] + w;
      g2[u] = v;
      if (f2[u] > f1[u]) {
        swap(f2[u], f1[u]);
        swap(g2[u], g1[u]);
      }
    }
  }
}

void dfs2(int u, int pre) {
  int i;
  for (i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == pre) continue;
    int w = edge[i].w;
    if (g1[u] == v) {
      if (f2[v] < f2[u] + w) {
        f2[v] = f2[u] + w;
        g2[v] = u;
        if (f1[v] < f2[v]) {
          swap(f1[v], f2[v]);
          swap(g1[v], g2[v]);
        }
      }
    } else {
      if (f2[v] < f1[u] + w) {
        f2[v] = f1[u] + w;
        g2[v] = u;
        if (f1[v] < f2[v]) {
          swap(f1[v], f2[v]);
          swap(g1[v], g2[v]);
        }
      }
    }
    dfs2(v, u);
  }
}

struct DEQUE {
  int pos, val;
} que1[maxn], que2[maxn];
int main() {
  int i, j;
  int x, y, z;
  int Q;
  while (~scanf("%d%d", &n, &m)) {
    if (!n && !m) break;
    init();
    for (i = 2; i <= n; i++) {
      scanf("%d%d%d", &x, &y, &z);
      add(x, y, z);
      add(y, x, z);
    }
    dfs1(1, -1);

    dfs2(1, -1);

    int h1, h2, t1, t2;
    int ans;
    while (m--) {
      scanf("%d", &Q);
      h1 = h2 = 1;
      t1 = t2 = 0;
      ans = 1;
      for (i = 1; i <= n; i++) {
        while (h1 <= t1 && que1[t1].val >= f1[i]) t1--;
        que1[++t1].pos = i;
        que1[t1].val = f1[i];
        while (h1 <= t1 && abs(que1[t1].val - que1[h1].val) > Q) h1++;

        while (h2 <= t2 && que2[t2].val <= f1[i]) t2--;
        que2[++t2].pos = i;
        que2[t2].val = f1[i];
        while (h2 <= t2 && abs(que2[t2].val - que2[h2].val) > Q) h2++;
        ans = maxz(ans, i - maxz(que1[h1 - 1].pos, que2[h2 - 1].pos));
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
