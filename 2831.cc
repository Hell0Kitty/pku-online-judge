#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1007
using namespace std;

struct Edge {
  int u, v, w;
  int id;
  int operator<(const Edge e) const {
    if (w != e.w) return w < e.w;
    return id > e.id;
  }
} edge[N << 8];

int n, m, q;
bool ans[N << 7];

struct uset {
  int p[N];
  uset(int n) {
    for (int i = 1; i <= n; i++) p[i] = i;
  }
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  void merge(Edge e) {
    int u = e.u, v = e.v, id = e.id;
    int fx = find(u), fy = find(v);
    if (fx != fy) {
      if (id)
        ans[id] = 1;
      else
        p[fx] = fy;
    }
  }
};

void Kruskal() {
  sort(edge + 1, edge + m + q + 1);
  uset us(n);
  for (int i = 1; i <= m + q; i++) us.merge(edge[i]);
}

int main() {
  int k, w;
  for (; cin >> n >> m >> q;) {
    for (int i = 1; i <= m; i++)
      scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w), edge[i].id = 0;
    for (int i = 1; i <= q; i++)
      scanf("%d%d", &k, &w), edge[m + i] = edge[k], edge[m + i].w = w,
                                      edge[m + i].id = i, ans[i] = 0;
    Kruskal();
    for (int i = 1; i <= q; i++) puts(ans[i] ? "Yes" : "No");
  }
  return 0;
}
