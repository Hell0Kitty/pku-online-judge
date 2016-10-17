<pre class = "lang:c++ decode:true">
#include& lt; stdio.h & gt;
#include& lt; string.h & gt;
#include& lt; algorithm & gt;
    using namespace std;
const int N = 1005;
int head[N], nc;
struct Edge {
  int to, next;
} edge[N * 5];
int val[N], dp[N][2];
bool vis[N];
void add(int a, int b) {
  edge[nc].to = b;
  edge[nc].next = head[a];
  head[a] = nc++;
  edge[nc].to = a;
  edge[nc].next = head[b];
  head[b] = nc++;
}
void dfs(int now) {
  dp[now][1] = val[now];
  dp[now][0] = 0;
  vis[now] = true;
  for (int i = head[now]; i != -1; i = edge[i].next) {
    int to = edge[i].to;
    if (!vis[to]) {
      dfs(to);
      dp[now][1] += max(dp[to][1], 0);
      dp[now][0] = max(dp[now][0], max(dp[to][1], dp[to][0]));
    }
  }
}
int po[N][2];
int main() {
  int n;
  while (scanf("%d", &amp; n) != EOF) {
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    nc = 0;
    for (int i = 0; i & lt; n; i++) {
      scanf("%d%d%d", &amp; po[i][0], &amp; po[i][1], &amp; val[i]);
      for (int j = 0; j & lt; i; j++) {
        if (abs(po[i][0] - po[j][0]) + abs(po[i][1] - po[j][1]) == 1) add(i, j);
      }
    }
    dfs(0);
    printf("%d\n", max(dp[0][0], dp[0][1]));
  }
  return 0;
}
