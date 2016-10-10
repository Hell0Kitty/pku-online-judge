#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 10005
#define maxm 50005

struct Edge {
  int v, next;
} edge[maxm], opedge[maxm];
int n, m, head[maxn], ophead[maxn], ncount, nowtime, pos[maxn * 2], sig[maxn],
    signnum, in[maxn];
int pointnum[maxn];
bool flag[maxn];
void addedge(int a, int b) {
  edge[ncount].v = b;
  edge[ncount].next = head[a];
  head[a] = ncount;
  opedge[ncount].v = a;
  opedge[ncount].next = ophead[b];
  ophead[b] = ncount;
  ncount++;
}
void input() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    addedge(a, b);
  }
}
void dfs(int a) {
  flag[a] = true;
  pos[nowtime] = a;
  nowtime++;
  for (int i = head[a]; i != -1; i = edge[i].next)
    if (!flag[edge[i].v]) dfs(edge[i].v);
  pos[nowtime] = a;
  nowtime++;
}
void rdfs(int a) {
  flag[a] = true;
  sig[a] = signnum;
  pointnum[sig[a]]++;
  for (int i = ophead[a]; i != -1; i = opedge[i].next)
    if (!flag[opedge[i].v]) rdfs(opedge[i].v);
}

int main() {
  ncount = 0;
  memset(head, -1, sizeof(head));
  memset(ophead, -1, sizeof(ophead));
  memset(flag, 0, sizeof(flag));
  input();
  nowtime = 1;
  for (int i = 0; i < n; i++)
    if (!flag[i]) dfs(i);
  memset(flag, 0, sizeof(flag));
  memset(pointnum, 0, sizeof(pointnum));
  signnum = 0;
  for (int i = 2 * n; i > 0; i--)
    if (!flag[pos[i]]) {
      rdfs(pos[i]);
      signnum++;
    }
  memset(in, 0, sizeof(in));
  ncount = 0;
  for (int i = 0; i < n; i++)
    for (int j = head[i]; j != -1; j = edge[j].next)
      if (sig[i] != sig[edge[j].v]) in[sig[i]]++;
  int ans = -1;
  bool ok = true;
  for (int i = 0; i < signnum; i++)
    if (in[i] == 0) {
      if (ans != -1) {
        ok = false;
        break;
      }
      ans = i;
    }
  if (ok)
    printf("%d\n", pointnum[ans]);
  else
    printf("0\n");
  return 0;
}
