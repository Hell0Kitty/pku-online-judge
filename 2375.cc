#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define snuke(it, x) \
  for (vector<int>::iterator it = (x).begin(); it != (x).end(); it++)

const int N = 255555;
int dfn[N], low[N], belong[N], stack[N], instack[N], tot, top, tim, n, m, in[N],
    out[N];
struct edge {
  int v, next;
} g[2001000];
int head[N], etot;
void add_edge(int u, int v) {
  g[etot].v = v;
  g[etot].next = head[u];
  head[u] = etot++;
}

void tarjan(int u) {
  dfn[u] = low[u] = ++tim;
  stack[top++] = u;
  instack[u] = 1;
  for (int i = head[u]; i != -1; i = g[i].next) {
    int v = g[i].v;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (instack[v]) {
      low[u] = min(low[u], low[v]);
    }
  }
  if (dfn[u] == low[u]) {
    while (true) {
      int v = stack[--top];
      instack[v] = 0;
      belong[v] = tot;
      if (v == u) break;
    }
    tot++;
  }
}

void scc() {
  tot = tim = top = 0;
  memset(instack, 0, sizeof(instack));
  memset(dfn, 0, sizeof(dfn));
  for (int i = 0; i < n * m; i++)
    if (!dfn[i]) tarjan(i);
}

int mat[555][555];

int main() {
  while (scanf("%d%d", &m, &n) == 2) {
    for (int i = 0; i < n * m; i++) {
      head[i] = -1;
      in[i] = out[i] = 0;
    }
    etot = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &mat[i][j]);
        if (i) {
          int val = mat[i - 1][j];
          int u = i * m + j, v = (i - 1) * m + j;
          if (val >= mat[i][j]) add_edge(v, u);
          if (val <= mat[i][j]) add_edge(u, v);
        }
        if (j) {
          int val = mat[i][j - 1];
          int u = i * m + j, v = i * m + j - 1;
          if (val >= mat[i][j]) add_edge(v, u);
          if (val <= mat[i][j]) add_edge(u, v);
        }
      }
    }

    scc();

    if (tot == 1) {
      puts("0");
      continue;
    }

    for (int i = 0; i < n * m; i++) {
      for (int j = head[i]; j != -1; j = g[j].next) {
        int v = g[j].v;
        if (belong[i] != belong[v]) {
          out[belong[i]]++;
          in[belong[v]]++;
        }
      }
    }
    int a = 0, b = 0;
    for (int i = 0; i < tot; i++) {
      a += in[i] == 0;
      b += out[i] == 0;
    }

    printf("%d\n", max(a, b));
  }
  return 0;
}
