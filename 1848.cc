#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 1000, N = 105;
int dp[N][3], head[N], nc;
bool vis[N];
struct Edge {
  int to, next;
} edge[N * 4];
void add(int a, int b) {
  edge[nc].to = b;
  edge[nc].next = head[a];
  head[a] = nc++;
  edge[nc].to = a;
  edge[nc].next = head[b];
  head[b] = nc++;
}
void dfs(int now) {
  vis[now] = true;
  int t, stk[N], top = 0, sumc = 0, v;
  dp[now][1] = 0;
  for (int i = head[now]; i != -1; i = edge[i].next) {
    t = edge[i].to;
    if (vis[t]) continue;
    stk[top++] = t;
    dfs(t);
    sumc += dp[t][0];
  }
  if (top == 0) {
    dp[now][0] = dp[now][2] = inf;
    dp[now][1] = 0;
    return;
  }
  dp[now][1] = sumc;
  v = inf;
  for (int i = 0; i < top; i++) {
    t = stk[i];
    v = min(v, sumc - dp[t][0] + min(dp[t][1], dp[t][2]));
  }
  dp[now][2] = v;
  v = inf;
  for (int i = 0; i < top; i++) {
    int t1 = stk[i];
    v = min(sumc - dp[t1][0] + dp[t1][2] + 1, v);
    for (int j = i + 1; j < top; j++) {
      int t2 = stk[j];
      v = min(sumc - dp[t1][0] - dp[t2][0] + min(dp[t2][1], dp[t2][2]) +
                  min(dp[t1][1], dp[t1][2]) + 1,
              v);
    }
  }
  dp[now][0] = v;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(head, -1, sizeof(head));
    nc = 0;
    memset(vis, false, sizeof(vis));
    for (int i = 1, a, b; i < n; i++) {
      scanf("%d%d", &a, &b);
      add(a, b);
    }
    dfs(1);
    if (dp[1][0] < inf)
      printf("%d\n", dp[1][0]);
    else
      printf("-1\n");
  }
  return 0;
}
