#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXEDGE = 20400;
const int MAXN = 400;
const int inf = 0x3fffffff / 1000;
struct edges {
  int cap, to, next, flow;
} edge[MAXEDGE];
struct nodes {
  int head, label, pre, cur;
} node[MAXN];
int L, N;
int gap[MAXN];
int in[MAXN], out[MAXN];
void init(int n) {
  L = 0;
  N = n;
  for (int i = 0; i < N; i++) node[i].head = -1;
  memset(in, -1, 4 * n);
  memset(out, -1, 4 * n);
}
void add_edge(int x, int y, int z, int w) {
  edge[L].cap = z;
  edge[L].flow = 0;
  edge[L].to = y;
  edge[L].next = node[x].head;
  node[x].head = L++;
  edge[L].cap = w;
  edge[L].flow = 0;
  edge[L].to = x;
  edge[L].next = node[y].head;
  node[y].head = L++;
}
int maxflow(int s, int t) {
  memset(gap, 0, sizeof(gap));
  gap[0] = N;
  int u, ans = 0;
  for (int i = 0; i < N; i++) {
    node[i].cur = node[i].head;
    node[i].label = 0;
  }
  u = s;
  node[u].pre = -1;
  while (node[s].label < N) {
    if (u == t) {
      int min = inf;
      for (int i = node[u].pre; i != -1; i = node[edge[i ^ 1].to].pre)
        if (min > edge[i].cap - edge[i].flow) min = edge[i].cap - edge[i].flow;
      for (int i = node[u].pre; i != -1; i = node[edge[i ^ 1].to].pre) {
        edge[i].flow += min;
        edge[i ^ 1].flow -= min;
      }
      u = s;
      ans += min;
      continue;
    }
    bool flag = false;
    int v;
    for (int i = node[u].cur; i != -1; i = edge[i].next) {
      v = edge[i].to;
      if (edge[i].cap - edge[i].flow && node[v].label + 1 == node[u].label) {
        flag = true;
        node[u].cur = node[v].pre = i;
        break;
      }
    }
    if (flag) {
      u = v;
      continue;
    }
    node[u].cur = node[u].head;
    int min = N;
    for (int i = node[u].head; i != -1; i = edge[i].next)
      if (edge[i].cap - edge[i].flow && node[edge[i].to].label < min)
        min = node[edge[i].to].label;
    gap[node[u].label]--;
    if (!gap[node[u].label]) return ans;
    node[u].label = min + 1;
    gap[node[u].label]++;
    if (u != s) u = edge[node[u].pre ^ 1].to;
  }
  return ans;
}
vector<int> outs;
void dfs(int u) {
  if (u == N - 3) return;
  outs.push_back(u);
  for (int i = node[u].head; i != -1; i = edge[i].next)
    if (edge[i].cap == inf && edge[i].flow && edge[i].to < N - 2) {
      edge[i].flow--;
      dfs(edge[i].to);
      return;
    }
  return;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    init(n + 4);
    add_edge(n + 1, 0, inf, 0);
    for (int i = 1; i <= n; i++) {
      add_edge(0, i, inf, 0);
      add_edge(i, n + 1, inf, 0);
      int k;
      scanf("%d", &k);
      out[i] += k;
      for (int j = 0; j < k; j++) {
        int x;
        scanf("%d", &x);
        add_edge(i, x, inf, 0);
        in[x]++;
      }
    }
    for (int i = 1; i <= n; i++)
      if (out[i] > in[i])
        add_edge(i, n + 3, out[i] - in[i], 0);
      else
        add_edge(n + 2, i, in[i] - out[i], 0);
    maxflow(n + 2, n + 3);
    int ans;
    for (int i = node[n + 1].head; i != -1; i = edge[i].next)
      if (edge[i].to == 0) {
        ans = edge[i].flow;
        edge[i].cap = edge[i].flow;
        edge[i ^ 1].cap = edge[i ^ 1].flow;
      }
    ans -= maxflow(n + 1, 0);
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
      for (int j = node[i].head; j != -1; j = edge[j].next)
        if (edge[j].to >= 1 && edge[j].to <= n && edge[j].cap == inf)
          edge[j].flow++;
    for (int i = node[0].head; i != -1; i = edge[i].next)
      while (edge[i].cap == inf && edge[i].flow--) {
        outs.clear();
        dfs(edge[i].to);
        for (int j = 0; j < outs.size(); j++) printf("%d ", outs[j]);
        puts("");
      }
  }
  return 0;
}
