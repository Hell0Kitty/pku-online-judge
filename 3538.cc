#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 1010
struct edge {
  int id;
  int s, e;
  int dis;
};

struct sel {
  int id;
  int dis;
} l[MAXN];

edge e[12000];
int set[MAXN];
int n, m;
int p1, p2, q1, q2;
int top;

bool cmp(edge a, edge b) { return a.dis < b.dis; }

void init(int n) {
  for (int i = 0; i <= n; i++) set[i] = i;
}

int find(int a) {
  int root = a;
  int temp;
  while (set[root] != root) root = set[root];
  while (set[a] != root) {
    temp = a;
    a = set[a];
    set[temp] = root;
  }
  return root;
}

bool merge(int a, int b) {
  int x = find(a);
  int y = find(b);
  if (x == y) return false;
  set[x] = y;
  return true;
}

int kruscal() {
  int num = 0, sum = 0;
  top = 0;
  for (int i = 0; i < m && num < n - 1; i++) {
    if (merge(e[i].s, e[i].e)) {
      sum += e[i].dis;
      l[top].id = e[i].id;
      l[top++].dis = e[i].dis;
      num++;
    }
  }
  if (num != n - 1) return -1;
  return sum;
}

long long dp[2][10105];
int path[MAXN][10105];

void dfs(int cnt, int y) {
  if (!cnt) return;
  if (path[cnt][y] != y) {
    dfs(cnt - 1, path[cnt][y]);
    printf("%d 5\n", l[cnt - 1].id);
  } else {
    dfs(cnt - 1, y);
    printf("%d 6\n", l[cnt - 1].id);
  }
}

bool cmp2(sel a, sel b) { return a.id < b.id; }
int main() {
  while (~scanf("%d%d", &n, &m)) {
    init(n);
    int dis;
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &e[i].s, &e[i].e, &e[i].dis);
      e[i].id = i + 1;
    }
    sort(e, e + m, cmp);
    scanf("%d%d%d%d", &p1, &q1, &p2, &q2);
    if ((dis = kruscal()) == -1 || dis > q1 + q2)
      printf("Impossible\n");
    else {
      int total = 0;
      sort(l, l + top, cmp2);
      for (int i = 0; i <= q1; i++) dp[0][i] = dp[1][i] = INF;
      dp[0][0] = 0;
      int cur = 0;
      for (int i = 1; i <= top; i++) {
        total += l[i - 1].dis;
        int c = l[i - 1].dis;
        for (int j = q1; (j >= c || total - j <= q2) && j >= 0; j--) {
          if (total - j <= q2 && dp[cur][j] != INF &&
              dp[cur][j] + c * p2 < dp[cur ^ 1][j]) {
            dp[cur ^ 1][j] = dp[cur][j] + c * p2;
            path[i][j] = j;
          }
          if (j >= c && dp[cur][j - c] != INF &&
              dp[cur][j - c] + c * p1 < dp[cur ^ 1][j]) {
            dp[cur ^ 1][j] = dp[cur][j - c] + c * p1;
            path[i][j] = j - c;
          }
        }
        for (int j = q1; j >= 0; j--) dp[cur][j] = INF;
        cur = cur ^ 1;
      }
      long long ans = INF, y = -1;
      for (int i = 0; i <= q1; i++) {
        if (ans > dp[cur][i]) {
          ans = dp[cur][i];
          y = i;
        }
      }
      if (ans == INF)
        printf("Impossible\n");
      else {
        printf("%lld\n", ans);
        dfs(top, y);
      }
    }
  }
}
