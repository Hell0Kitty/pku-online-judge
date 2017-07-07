#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct nodes {
  int u, next;
};

const int maxn = 20010;

int t, e, num, node[maxn], n, parent[maxn], balance[maxn], degree[maxn],
    head[maxn];
nodes edge[maxn * 10];
queue<int> q;

void addEdge(int u, int v);
void dfs(int u, int pre);

int main() {
  scanf("%d", &t);
  while (t-- != 0) {
    memset(node, 0, sizeof(node));
    memset(balance, 0, sizeof(balance));
    memset(degree, 0, sizeof(degree));
    memset(head, -1, sizeof(head));
    e = 0;
    while (!q.empty()) q.pop();
    scanf("%d", &num);
    for (int i = 0; i < num - 1; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      addEdge(u, v);
    }
    int ans = 0x7fffffff, tnode;
    dfs(1, -1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (ans > balance[u]) {
        ans = balance[u];
        tnode = u;
      } else if (ans == balance[u])
        tnode = min(tnode, u);
      if (parent[u] != -1) {
        balance[parent[u]] = max(balance[parent[u]], node[u]);
        degree[parent[u]]--;
        if (degree[parent[u]] == 0) q.push(parent[u]);
      }
    }

    printf("%d %d\n", tnode, ans);
  }

  return 0;
}

void addEdge(int u, int v) {
  edge[e].u = v;
  edge[e].next = head[u];
  head[u] = e++;

  edge[e].u = u;
  edge[e].next = head[v];
  head[v] = e++;
}

void dfs(int u, int pre) {
  parent[u] = pre;
  node[u] = 1;
  if (pre != -1) degree[pre]++;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].u;
    if (v != pre) {
      dfs(v, u);
      node[u] += node[v];
    }
  }
  balance[u] = num - node[u];
  if (degree[u] == 0) q.push(u);
}
