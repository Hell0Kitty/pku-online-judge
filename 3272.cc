#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5005;
typedef long long ll;
int head[2][N], nc[2];
ll tot[2][N];
bool flag[N];
struct Edge {
  int to, next;
} edge[2][N * 20];
void add(int a, int b, int k) {
  edge[k][nc[k]].to = b;
  edge[k][nc[k]].next = head[k][a];
  head[k][a] = nc[k]++;
}
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(head, -1, sizeof(head));
    memset(tot, 0, sizeof(tot));
    memset(flag, false, sizeof(flag));
    nc[0] = nc[1] = 0;
    for (int i = 0, a, b; i < m; i++) {
      scanf("%d%d", &a, &b);
      add(a, b, 0);
      add(b, a, 1);
      flag[b] = true;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      if (!flag[i]) tot[0][i] = 1;
      for (int j = head[0][i]; j != -1; j = edge[0][j].next)
        tot[0][edge[0][j].to] += tot[0][i];
    }
    tot[1][n] = 1;
    for (int i = n; i >= 1; i--) {
      for (int j = head[1][i]; j != -1; j = edge[1][j].next)
        tot[1][edge[1][j].to] += tot[1][i];
    }
    for (int i = 1; i <= n; i++)
      for (int j = head[0][i]; j != -1; j = edge[0][j].next)
        ans = max(ans, tot[0][i] * tot[1][edge[0][j].to]);
    printf("%lld\n", ans);
  }
  return 0;
}
