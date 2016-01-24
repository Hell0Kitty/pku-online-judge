#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int M = 1000007;
const int N = 1020;
struct node {
  int v;
  int next;
} edge[4 * M];
int head1[2 * N], head2[2 * N], num;
int id[2 * N], ord[2 * N];
bool vis[2 * N];
bool flag;
int n, m, cnt;

void init() {
  for (int i = 0; i <= 2 * n + 1; i++) {
    head1[i] = -1;
    head2[i] = -1;
    id[i] = 0;
  }
  num = 0;
  flag = true;
}

void addege1(int u, int v) {
  edge[num].v = v;
  edge[num].next = head1[u];
  head1[u] = num++;
}

void addege2(int u, int v) {
  edge[num].v = v;
  edge[num].next = head2[u];
  head2[u] = num++;
}

void build() {
  int a, b, w;
  char s[10];
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d%s", &a, &b, &w, s);
    if (strcmp(s, "AND") == 0) {
      if (w == 1) {
        addege1(a * 2 + 1, a * 2);
        addege1(b * 2 + 1, b * 2);
        addege2(a * 2, a * 2 + 1);
        addege2(b * 2, b * 2 + 1);
      } else {
        addege1(a * 2, b * 2 + 1);
        addege1(b * 2, a * 2 + 1);
        addege2(b * 2 + 1, a * 2);
        addege2(a * 2 + 1, b * 2);
      }
    } else if (strcmp(s, "OR") == 0) {
      if (w == 1) {
        addege1(a * 2 + 1, b * 2);
        addege1(b * 2 + 1, a * 2);
        addege2(b * 2, a * 2 + 1);
        addege2(a * 2, b * 2 + 1);
      } else {
        addege1(a * 2, a * 2 + 1);
        addege1(b * 2, b * 2 + 1);
        addege2(a * 2 + 1, a * 2);
        addege2(b * 2 + 1, b * 2);
      }
    } else if (strcmp(s, "XOR") == 0) {
      if (w == 1) {
        addege1(a * 2, b * 2 + 1);
        addege1(b * 2 + 1, a * 2);
        addege1(a * 2 + 1, b * 2);
        addege1(b * 2, a * 2 + 1);
        addege2(b * 2 + 1, a * 2);
        addege2(a * 2, b * 2 + 1);
        addege2(b * 2, a * 2 + 1);
        addege2(a * 2 + 1, b * 2);
      } else {
        addege1(a * 2, b * 2);
        addege1(b * 2, a * 2);
        addege1(a * 2 + 1, b * 2 + 1);
        addege1(b * 2 + 1, a * 2 + 1);
        addege2(b * 2, a * 2);
        addege2(a * 2, b * 2);
        addege2(b * 2 + 1, a * 2 + 1);
        addege2(a * 2 + 1, b * 2 + 1);
      }
    }
  }
}

void dfs1(int u) {
  vis[u] = 1;
  for (int i = head1[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (!vis[v]) dfs1(v);
  }
  ord[cnt++] = u;
}

void dfs2(int u) {
  vis[u] = 1;
  id[u] = cnt;
  for (int i = head2[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (!vis[v]) dfs2(v);
  }
}

void kosaraju() {
  cnt = 0;
  fill(vis, vis + 2 * n, false);
  for (int i = 0; i < 2 * n; i++) {
    if (!vis[i]) dfs1(i);
  }
  cnt = 0;
  fill(vis, vis + 2 * n, false);
  for (int i = 2 * n - 1; i >= 0; i--) {
    if (!vis[ord[i]]) {
      dfs2(ord[i]);
      ++cnt;
    }
  }
  --cnt;
  for (int i = 0; i < n; i++) {
    if (id[2 * i] == id[2 * i + 1]) {
      flag = false;
      return;
    }
  }
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    init();
    build();
    kosaraju();
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
