#include& lt; cstdio & gt;
#include& lt; cstring & gt;
#include& lt; algorithm & gt;
using namespace std;

const int N = 4000 + 5;
const int M = 200000 + 4000;
struct EDGE {
  int v, next;
} edge[M];
int first[N], low[N], dfn[N], sta[M], belong[N], ans[N];
bool instack[N];
int g, cnt, top, scc;

void AddEdge(int u, int v) {
  edge[g].v = v;
  edge[g].next = first[u];
  first[u] = g++;
}
int min(int a, int b) {
  return a & lt;
  b ? a : b;
}
void Tarjan(int u)  //求强连通分量
{
  int i, v;
  low[u] = dfn[u] = ++cnt;
  sta[++top] = u;
  instack[u] = true;
  for (i = first[u]; i != -1; i = edge[i].next) {
    v = edge[i].v;
    if (!dfn[v]) {
      Tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (instack[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (low[u] == dfn[u]) {
    scc++;
    while (1) {
      v = sta[top--];
      instack[v] = false;
      belong[v] = scc;  //缩点
      if (u == v) break;
    }
  }
}
int Scan()  //输入外挂
{
  int res = 0, ch, flag = 0;
  if ((ch = getchar()) == '-')
    flag = 1;
  else if (ch & gt; = '0' & amp; &amp; ch & lt; = '9')
    res = ch - '0';
  while ((ch = getchar()) & gt; = '0' & amp; &amp; ch & lt; = '9')
    res = res * 10 + ch - '0';
  return flag ? -res : res;
}
void Out(int a)  //输出外挂
{
  if (a & gt; 9) Out(a / 10);
  putchar(a % 10 + '0');
}
int main() {
  int n, i, u, v, k;
  while (scanf("%d", &amp; n) != EOF) {
    g = cnt = top = scc = 0;
    memset(first, -1, sizeof(first));
    memset(dfn, 0, sizeof(dfn));
    memset(instack, false, sizeof(instack));
    for (i = 1; i & lt; = n; i++) {
      k = Scan();
      while (k--) {
        v = Scan();
        AddEdge(i, v + n);
      }
    }
    for (i = 1; i & lt; = n; i++) {
      v = Scan();
      AddEdge(v + n, i);  //王子i可以和妹子v结婚
    }

    for (i = 1; i & lt; = 2 * n; i++)  //求强连通分量
      if (!dfn[i]) Tarjan(i);

    for (u = 1; u & lt; = n; u++) {
      int count = 0;
      for (i = first[u]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (belong[u] == belong[v])  //同一个强连通分量
          ans[count++] = v - n;
      }
      sort(ans, ans + count);
      Out(count);
      for (i = 0; i & lt; count; i++) {
        putchar(' ');
        Out(ans[i]);
      }

      putchar('\n');
    }
  }
  return 0;
}
