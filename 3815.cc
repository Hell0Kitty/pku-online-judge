#include <iostream>
#include <map>
#include <cstdlib>
using namespace std;
#define MAXN 1005
#define INF 1e10
using namespace std;
struct edge {
  int v, w, next;
} E[3 * MAXN];
int head[MAXN], ecnt;
int Stack[MAXN], cnt[MAXN], dis[MAXN];
bool Instack[MAXN];
int N, D, scr, sink, top;
struct Tree {
  int h, id;
} Tnode[MAXN];
map<int, int> hash;
int cmp(const void *p1, const void *p2) {
  return ((Tree *)p1)->h - ((Tree *)p2)->h;
}
void Insert(int u, int v, int w) {
  E[ecnt].v = v;
  E[ecnt].w = w;
  E[ecnt].next = head[u];
  head[u] = ecnt++;
}
void Init() {
  int i, u, v;
  memset(head, -1, sizeof(head));
  ecnt = 0;
  for (i = 1; i <= N; i++) {
    scanf("%d", &Tnode[i].h);
    Tnode[i].id = i;
  }
  qsort(Tnode + 1, N, sizeof(Tnode[0]), cmp);
  scr = Tnode[1].id;
  sink = Tnode[N].id;
  for (i = 1; i <= N; i++) hash[Tnode[i].id] = i;
  for (i = 1; i < N; i++) Insert(hash[i + 1], hash[i], -1);
  for (i = 1; i < N; i++) {
    u = Tnode[i].id;
    v = Tnode[i + 1].id;
    if (u > v)  // d[i]-d[i+1]<=D
      Insert(i + 1, i, D);
    else
      Insert(i, i + 1, D);
  }
}
void SPFA(int scr, int sink) {
  int i, u, v, w;
  memset(Instack, false, sizeof(Instack));
  memset(cnt, 0, sizeof(cnt));
  for (i = 1; i <= N; i++) dis[i] = INF;
  top = 0;
  Stack[top++] = scr;
  Instack[scr] = true;
  dis[scr] = 0;
  while (top) {
    u = Stack[--top];
    Instack[u] = false;
    cnt[u]++;
    if (cnt[u] > N) {
      printf("-1\n");
      return;
    }
    for (i = head[u]; i != -1; i = E[i].next) {
      v = E[i].v;
      w = E[i].w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (!Instack[v]) {
          Instack[v] = true;
          Stack[top++] = v;
        }
      }
    }
  }
  printf("%d\n", dis[sink]);
}
int main() {
  while (scanf("%d%d", &N, &D) != EOF) {
    if (N == 0 && D == 0) break;
    Init();
    if (scr < sink)
      SPFA(1, N);
    else
      SPFA(N, 1);
  }
  return 0;
}
