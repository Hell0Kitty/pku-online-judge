#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn 1005
#define maxl 25

struct Edge {
  int v, next;
  double w;
} edge[maxn * maxn];

int vis[maxn];
double lowc[maxn];
double len;
int n, m;
int head[maxn];
int ncount;
map<string, int> name;

void addedge(int a, int b, double w) {
  edge[ncount].v = b;
  edge[ncount].next = head[a];
  edge[ncount].w = w;
  head[a] = ncount++;
}

void input() {
  scanf("%lf%d", &len, &n);
  for (int i = 0; i < n; i++) {
    char ch[maxl];
    scanf("%s", ch);
    string st(ch);
    name[ch] = i;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    char ch1[maxl], ch2[maxl];
    double w;
    scanf("%s%s%lf", ch1, ch2, &w);
    string st1(ch1), st2(ch2);
    int a = name[st1];
    int b = name[st2];
    addedge(a, b, w);
    addedge(b, a, w);
  }
}

double prim() {
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) lowc[i] = inf;
  lowc[0] = 0;
  double ret = 0;
  lowc[n] = inf;
  while (true) {
    int u = n;
    for (int i = 0; i < n; i++)
      if (lowc[u] > lowc[i] && !vis[i]) u = i;
    if (u == n) break;
    vis[u] = true;
    ret += lowc[u];
    lowc[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].next) {
      int v = edge[i].v;
      lowc[v] = min(lowc[v], edge[i].w);
    }
  }
  return ret;
}

int main() {
  memset(head, -1, sizeof(head));
  ncount = 0;
  input();
  double ans = prim();
  if (ans > len)
    printf("Not enough cable\n");
  else
    printf("Need %.1f miles of cable\n", ans);
  return 0;
}
