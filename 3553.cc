#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 50000 + 5;
int n, m;

struct node {
  int p;
  int d;
  int id;
} job[maxn];

vector<int> V[maxn];
bool vis[maxn];

bool cmp(node a, node b) { return a.d < b.d; }

void dfs(int cur) {
  if (vis[cur]) return;
  vis[cur] = true;
  int k = V[cur].size();
  for (int i = 0; i < k; i++) dfs(V[cur][i]);
  printf("%d\n", cur);
}

void init() {
  memset(vis, false, sizeof vis);
  for (int i = 1; i <= n; i++) V[i].clear();
}

int main() {
  int a, b;
  while (scanf("%d", &n) != EOF) {
    init();
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &job[i].p, &job[i].d);
      job[i].id = i;
    }
    sort(job + 1, job + n + 1, cmp);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &a, &b);
      V[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
      if (!vis[job[i].id]) dfs(job[i].id);
  }
  return 0;
}
