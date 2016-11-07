#include <cstdio>
#include <cstdlib>
#include <cstring>
#define M 1001000
using namespace std;
int to[M], head[M], len[M], next[M], top, cnt, n, dk, ans[M];
bool vis[M];
int fc[8] = {1, 10, 100, 1000, 10000, 100000, 1000000};
struct STACK {
  int x, p;
} stack[M];
void add(int u, int v, int w) {
  to[cnt] = v;
  len[cnt] = w;
  next[cnt] = head[u];
  head[u] = cnt++;
}
void create() {
  memset(head, -1, sizeof head);
  memset(vis, 0, sizeof vis);
  cnt = 0;
  for (int i = 0, tmp; i < fc[n - 1]; i++) {
    tmp = i % fc[n - 2];
    for (int j = 9; j >= 0; j--)  //字典序最小
      add(i, tmp * 10 + j, i * 10 + j);
  }
}
void euler() {
  int u, pos;
  top = 2;
  dk = 0;
  stack[1].x = 0;
  stack[1].p = head[0];
  while (top) {
    u = stack[top - 1].x;
    pos = stack[top - 1].p;
    for (; ~pos; pos = next[pos])
      if (!vis[pos]) {
        stack[top - 1].p = pos;
        vis[pos] = true;
        stack[top].p = head[to[pos]];
        stack[top].x = to[pos];
        ++top;
        break;
      }
    if (pos == -1)  //扫完u了，相当于递归完毕
    {
      ans[++dk] = stack[top - 1].p;
      top--;
    }
  }
}
void prt() {
  for (int i = 1; i < n; i++) printf("0");
  for (int i = dk - 1; i >= 2; i--) printf("%d", len[ans[i]] % 10);
  printf("\n");
}
void go() {
  create();
  euler();
  prt();
}
int main() {
  while (scanf("%d", &n), n) {
    if (n == 1)
      printf("0123456789\n");
    else
      go();
  }
  return 0;
}
