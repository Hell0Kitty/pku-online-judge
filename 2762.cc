#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX 1301
#define MAXM 6301
using namespace std;

int n, m, Sum, Count;
int l[MAXM], r[MAXM];
int fa[MAX], Du[MAX], DU_R[MAX];
vector<int> f[MAX];
int DNF[MAX], LOW[MAX];
int Stack[MAX], Top = 0;
bool b[MAX], vis[MAX];

int find(int x) {
  if (fa[x] != x) fa[x] = find(fa[x]);
  return fa[x];
}
void tarjan(int x);
bool DFS(int x, int y);
void init() {
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= Sum; i++) {
    Du[i] = DU_R[i] = 0;
    b[i] = false;
    f[i].clear();
  }
}

void readin();
void work();

int main() {
  int T;
  scanf("%d", &T);
  while (T) {
    readin();
    work();
    init();
    T--;
  }
  return 0;
}

void readin() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &l[i], &r[i]);
    Du[l[i]]++;
    f[l[i]].push_back(r[i]);
  }
}
void work() {
  int x, y;
  Sum = 0;
  Count = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) tarjan(i);
  for (int i = 1; i <= m; i++) {
    x = fa[l[i]];
    y = fa[r[i]];
    if (x == y) continue;
    Du[x]++;
    DU_R[y]++;
    f[x].push_back(y);
  }
  memset(b, 0, sizeof(b));
  for (int i = 1; i <= Sum; i++)
    if (!DU_R[i]) {
      if (DFS(i, 1))
        printf("Yes\n");
      else
        printf("No\n");
      return;
    }
}

void tarjan(int x) {
  int X;
  DNF[x] = LOW[x] = ++Count;
  Stack[++Top] = x;
  b[x] = true;
  for (int i = 0; i < Du[x]; i++) {
    X = f[x][i];
    if (b[X])
      LOW[x] = MIN(LOW[x], DNF[X]);
    else if (!vis[X]) {
      tarjan(X);
      LOW[x] = MIN(LOW[x], LOW[X]);
    }
  }
  Du[x] = 0;
  f[x].clear();
  vis[x] = true;
  if (DNF[x] != LOW[x]) return;
  Sum++;
  while (1) {
    X = Stack[Top--];
    fa[X] = Sum;
    b[X] = false;
    if (X == x) return;
  }
}
bool DFS(int x, int y) {
  b[x] = true;
  if (y == Sum) return true;
  for (int i = 0; i < Du[x]; i++) {
    int X = f[x][i];
    if (b[X]) continue;
    if (DFS(X, y + 1)) return true;
  }
  return false;
}
