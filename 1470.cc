#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 909

int n, root;
bool g[maxn][maxn], hasroot[maxn];
int id[maxn], lcs[maxn][maxn];
int sum[maxn];

void input() {
  int a, b, m;
  char st[100];
  memset(g, 0, sizeof(g));
  memset(hasroot, 0, sizeof(hasroot));
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    a--;
    scanf("%[^0-9]", st);
    scanf("%d", &m);
    scanf("%[^0-9]", st);
    for (int i = 0; i < m; i++) {
      scanf("%d", &b);
      b--;
      hasroot[b] = true;
      g[a][b] = g[b][a] = true;
    }
  }
  for (int i = 0; i < n; i++)
    if (!hasroot[i]) {
      root = i;
      break;
    }
}

int get(int i) {
  if ((id[i] == i)) return i;
  return id[i] = get(id[i]);
}

void unin(int i, int j) { id[get(i)] = get(j); }

void dfs(int rt) {
  int i;
  id[rt] = rt;
  for (i = 0; i < n; ++i)
    if (g[rt][i] && -1 == id[i]) {
      dfs(i);
      unin(i, rt);
    }
  for (i = 0; i < n; ++i)
    if (-1 != id[i]) lcs[rt][i] = lcs[i][rt] = get(i);
}

void work() {
  int m;
  char st[100];
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%[^0-9]", st);
    scanf("%d", &a);
    scanf("%[^0-9]", st);
    scanf("%d", &b);
    a--;
    b--;
    sum[lcs[a][b]]++;
  }
  for (int i = 0; i < n; i++)
    if (sum[i]) printf("%d:%d\n", i + 1, sum[i]);
}

int main() {
  char st[100];
  while (scanf("%d", &n) != EOF) {
    input();
    memset(id, -1, sizeof(id));
    memset(sum, 0, sizeof(sum));
    dfs(root);
    work();
    scanf("%[^0-9]", st);
  }
  return 0;
}
