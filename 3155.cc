#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 100000000
using namespace std;

const int NN = 150;
const int MM = 20000;
const double eps = 1e-6;

int n, m, S, T, NV, en, head[NN], a[MM], b[MM], d[NN];
struct Edge {
  int u, v, next;
  double flow;
} e[MM];
void add(int u, int v, double flow) {
  e[en].u = u;
  e[en].v = v;
  e[en].flow = flow;
  e[en].next = head[u];
  head[u] = en++;
  e[en].u = v;
  e[en].v = u;
  e[en].flow = 0;
  e[en].next = head[v];
  head[v] = en++;
}

void build(double g) {
  en = 0;
  memset(head, -1, sizeof(head));

  S = 0;
  T = n + 1;
  NV = T + 1;
  for (int i = 1; i <= n; i++) {
    add(S, i, m);
    add(i, T, m + g * 2 - d[i]);
  }
  for (int i = 1; i <= m; i++) {
    add(a[i], b[i], 1);
    add(b[i], a[i], 1);
  }
}

int cur[NN], gap[NN], dis[NN], pre[NN];
double sap() {
  double maxflow = 0;
  for (int i = 0; i < NV; i++) {
    dis[i] = gap[i] = 0;
    cur[i] = head[i];
  }
  int u = pre[S] = S;
  double aug = INF;
  gap[0] = NV;
  while (dis[S] < NV) {
  loop:
    for (int &i = cur[u]; i != -1; i = e[i].next) {
      int v = e[i].v;
      if (e[i].flow > 0 && dis[u] == dis[v] + 1) {
        if (e[i].flow < aug) aug = e[i].flow;
        pre[v] = u;
        u = v;
        if (v == T) {
          maxflow += aug;
          for (u = pre[u]; v != S; v = u, u = pre[u]) {
            e[cur[u]].flow -= aug;
            e[cur[u] ^ 1].flow += aug;
          }
          aug = INF;
        }
        goto loop;
      }
    }
    int min_dis = NV;
    for (int i = head[u]; i != -1; i = e[i].next) {
      int v = e[i].v;
      if (e[i].flow > 0 && min_dis > dis[v]) {
        cur[u] = i;
        min_dis = dis[v];
      }
    }
    if (--gap[dis[u]] == 0) break;
    gap[dis[u] = min_dis + 1]++;
    u = pre[u];
  }
  return maxflow;
}

void bisearch() {
  double eps2 = 1.0 / n / n;
  double mid, l = 0, r = m;
  while (r - l >= eps2) {
    mid = (l + r) * 0.5;
    build(mid);
    double h = ((double)m * n - sap()) * 0.5;
    if (h >= eps)
      l = mid;
    else
      r = mid;
  }
  build(l);
  sap();
}

bool mark[NN];
int tot, ans[NN];
void dfs(int u) {
  mark[u] = true;
  if (u >= 1 && u <= n) ans[tot++] = u;
  for (int i = head[u]; i != -1; i = e[i].next) {
    int v = e[i].v;
    if (e[i].flow > 0 && !mark[v]) dfs(v);
  }
}

void output() {
  tot = 0;
  memset(mark, false, sizeof(mark));
  dfs(S);
  sort(ans, ans + tot);
  printf("%d\n", tot);
  for (int i = 0; i < tot; i++) printf("%d\n", ans[i]);
}

int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    if (m == 0) {
      printf("1\n1\n");
      continue;
    }
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &a[i], &b[i]);
      d[a[i]]++;
      d[b[i]]++;
    }
    bisearch();
    output();
  }
  return 0;
}
