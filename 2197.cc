#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <bitset>
#include <queue>
#include <vector>
using namespace std;

const int BORDER = (1 << 20) - 1;
const int MAXSIZE = 37;
const int MAXN = 30;
const int INF = 0x4ffffff;

#define CLR(x, y) memset(x, y, sizeof(x))
#define ADD(x) x = ((x + 1) & BORDER)
#define IN(x) scanf("%d", &x)
#define OUT(x) printf("%d\n", x)
#define MIN(m, v) (m) < (v) ? (m) : (v)
#define MAX(m, v) (m) > (v) ? (m) : (v)
#define ABS(x) ((x) > 0 ? (x) : -(x))

int n, m, ans;
int start, end, limit;
int index, net[MAXN];
int g[MAXN][MAXN];
bool visit[MAXN];
int route[MAXN];
int deep;
int case_id;

typedef struct { int v, val, next; } EDGE;
typedef struct {
  int len, num;
  int city[MAXN];
} NODE;
EDGE edge[MAXN * MAXN];
NODE node[MAXN * MAXN * MAXN * MAXN];

int init() {
  CLR(net, -1);
  CLR(visit, 0);
  CLR(g, 0);
  index = 0;
  ans = 0;
  deep = 0;
  return 0;
}
void add_edge(const int &u, const int &v, const int &val) {
  edge[index].next = net[u];
  edge[index].v = v;
  edge[index].val = val;
  net[u] = index;
  ++index;
}
bool cmp(const NODE &a, const NODE &b) { return a.len < b.len; }

int input() {
  int i, j, tmp;
  int a, b;
  scanf("%d", &m);
  for (i = 1; i <= m; ++i) {
    scanf("%d%d%d", &a, &b, &tmp);
    g[a][b] = g[b][a] = tmp;
  }
  scanf("%d%d", &start, &end);
  scanf("%d", &limit);
  return 0;
}
int make_graph() {
  int i, j, tmp;
  for (i = 1; i <= n; ++i)
    for (j = n; j >= 1; --j)
      if (g[i][j])
        add_edge(i, j, g[i][j]);
  return 0;
}
void dfs(const int &u, const int &dist) {
  if (dist > limit)
    return;
  route[deep] = u;
  ++deep;
  if (u == end) {
    memcpy(node[ans].city, route, deep * sizeof(route[0]));
    node[ans].len = dist;
    node[ans].num = deep;
    ++ans;
    --deep;
    return;
  }
  for (int i = net[u]; i != -1; i = edge[i].next)
    if (!visit[edge[i].v]) {
      visit[edge[i].v] = true;
      dfs(edge[i].v, dist + edge[i].val);
      visit[edge[i].v] = false;
    }
  --deep;
}
int output() {
  int i, j, tmp;
  printf("Case %d:\n", case_id);
  if (ans == 0) {
    printf(" NO ACCEPTABLE TOURS\n\n");
    return 0;
  }
  for (i = 0; i < ans; ++i) {
    printf(" %d:", node[i].len);
    for (j = 0; j < node[i].num; ++j)
      printf(" %d", node[i].city[j]);
    printf("\n");
  }
  printf("\n");
  return 0;
}
int work() {
  make_graph();
  visit[start] = true;
  dfs(start, 0);
  sort(node, node + ans, cmp);
  return 0;
}
int main() {
  case_id = 1;
  while (scanf("%d", &n) != EOF) {
    if (n == -1)
      break;
    init();
    input();
    work();
    output();
    ++case_id;
  }
  return 0;
}