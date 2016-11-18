#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 4400

struct node {
  int to, next;
};

node edge[90000100];
int head[MAXN], en, n, m;

void add(int a, int b) {
  edge[en].to = b;
  edge[en].next = head[a];
  head[a] = en++;
}

int low[MAXN], dfn[MAXN];
int stack[MAXN], top, set[MAXN], col, num;
bool vis[MAXN], instack[MAXN];

void tarjan(int u) {
  vis[u] = 1;
  dfn[u] = low[u] = ++num;
  instack[u] = true;
  stack[++top] = u;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (!vis[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (instack[v])
      low[u] = min(dfn[v], low[u]);
  }
  if (dfn[u] == low[u]) {
    int j;
    col++;
    do {
      j = stack[top--];
      instack[j] = false;
      set[j] = col;
    } while (j != u);
  }
}

void solve() {
  int i;
  top = col = num = 0;
  memset(instack, 0, sizeof(instack));
  memset(vis, 0, sizeof(vis));
  memset(set, -1, sizeof(set));
  for (i = 1; i <= 2 * n; i++)
    if (!vis[i]) tarjan(i);
}

bool twosat() {
  solve();
  for (int i = 1; i <= n; i++)
    if (set[i] == set[i + n]) return false;
  return true;
}

int main() {
  int s1, s2;
  while (~scanf("%d%d", &n, &m)) {
    memset(head, -1, sizeof(head));
    en = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &s1, &s2);
      int a = abs(s1);
      int b = abs(s2);

      if (s1 > 0 && s2 > 0) {
        add(a + n, b);
        add(b + n, a);
      }
      if (s1 < 0 && s2 < 0) {
        add(a, b + n);
        add(b, a + n);
      }
      if (s1 > 0 && s2 < 0) {
        add(a + n, b + n);
        add(b, a);
      }
      if (s1 < 0 && s2 > 0) {
        add(a, b);
        add(b + n, a + n);
      }
    }
    if (twosat())
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}
