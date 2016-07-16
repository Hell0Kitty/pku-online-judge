#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
#define N 1200
#define M 50220
#define INF 0x3f3f3f3f

class MaxFlow {
 public:
  struct record {
    int v, f, next;
  } edge[M];
  int n, s, t;
  int pos[N], dis[N], vh[N], cl;
  int his[N], di[N], pre[N];

  void AddEdge(int a, int b, int f) {
    cl++;
    edge[cl].next = pos[a];
    edge[cl].v = b;
    edge[cl].f = f;
    pos[a] = cl;
    cl++;
    edge[cl].next = pos[b];
    edge[cl].v = a;
    edge[cl].f = 0;
    pos[b] = cl;
  }
  void Init() {
    cl = 1;
    memset(dis, 0, sizeof(dis));
    memset(vh, 0, sizeof(vh));
    memset(pos, 0, sizeof(pos));
  }
  int flow() {
    vh[0] = n;
    for (int i = 0; i < n; i++) di[i] = pos[i];
    int i = s, aug = INF, flow = 0;
    bool flag = false;
    while (dis[s] < n) {
      his[i] = aug;
      flag = false;
      for (int p = di[i]; p; p = edge[p].next)
        if ((edge[p].f > 0) && (dis[edge[p].v] + 1 == dis[i])) {
          flag = true;
          di[i] = p;
          aug = min(aug, edge[p].f);
          pre[edge[p].v] = p;
          i = edge[p].v;
          if (i == t) {
            flow += aug;
            while (i != s) {
              edge[pre[i]].f -= aug;
              edge[pre[i] ^ 1].f += aug;
              i = edge[pre[i] ^ 1].v;
            }
            aug = INF;
          }
          break;
        }
      if (flag) continue;
      int min = n - 1;
      for (int p = pos[i]; p; p = edge[p].next)
        if ((edge[p].f > 0) && (dis[edge[p].v] < min)) {
          di[i] = p;
          min = dis[edge[p].v];
        }

      --vh[dis[i]];
      if (vh[dis[i]] == 0) break;
      dis[i] = min + 1;
      ++vh[dis[i]];
      if (i != s) {
        i = edge[pre[i] ^ 1].v;
        aug = his[i];
      }
    }
    return flow;
  }
} net;

int n, b, g[1002][22], s[22];

void init(int x, int y) {
  net.Init();

  net.s = 0, net.t = n + b + 1, net.n = n + b + 2;
  for (int i = 1; i <= n; i++) net.AddEdge(0, i, 1);
  for (int i = 1; i <= n; i++)
    for (int j = x; j <= y; j++) net.AddEdge(i, g[i][j] + n, 1);
  for (int i = 1; i <= b; i++) net.AddEdge(n + i, net.t, s[i]);
}
int main() {
  scanf("%d%d", &n, &b);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= b; j++) scanf(" %d", &g[i][j]);
  for (int i = 1; i <= b; i++) scanf("%d", &s[i]);
  int ans = INF;

  for (int i = 1; i <= b; i++)
    for (int j = i; j <= b; j++) {
      init(i, j);
      if (net.flow() == n) ans = min(ans, j - i + 1);
    }
  printf("%d\n", ans);
  return 0;
}
