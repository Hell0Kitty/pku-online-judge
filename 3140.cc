#include <stdio.h>
#include <cstring>
using namespace std;

struct node {
  int u;
  int next;
};

__int64 min(__int64 a, __int64 b) { return a > b ? b : a; }

node edge[100005 * 10];
int n, m;
__int64 stu[100005];
__int64 all = 0;
__int64 dp[100005];
__int64 ans;
int head[100005];
int visited[100005];
int count;
void addEdge(int c, int d) {
  edge[count].u = d;
  edge[count].next = head[c];
  head[c] = count++;

  edge[count].u = c;
  edge[count].next = head[d];
  head[d] = count++;
}

__int64 abs(__int64 a) { return a > 0 ? a : -a; }

void init() {
  memset(dp, 0, sizeof(dp));
  memset(visited, 0, sizeof(visited));
  all = 0;
  count = 0;
  memset(head, -1, sizeof(head));
  memset(edge, 0, sizeof(edge));
}

void dfs(int u) {
  visited[u] = 1;
  dp[u] = stu[u];
  for (int i = head[u]; i != -1;
       i = edge[i].next)  //其中i指的是边，v是边指向的点
  {
    int v = edge[i].u;
    if (visited[v] == 0) {
      dfs(v);
      dp[u] = dp[u] + dp[v];
    }
  }
}
int k = 1;
int main() {
  while (1) {
    scanf("%d%d", &n, &m);
    if (n + m == 0) {
      break;
    }
    init();
    for (int i = 1; i <= n; i++) {
      scanf("%I64d", &stu[i]);
      all += stu[i];
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      addEdge(a, b);
    }
    dfs(1);
    ans = abs(all - 2 * dp[1]);
    for (int i = 2; i <= n; i++) {
      ans = min(ans, abs(all - 2 * dp[i]));
    }
    printf("Case %d: %I64d\n", k++, ans);
  }
  return 0;
}
