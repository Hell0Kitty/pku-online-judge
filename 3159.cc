#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 30010;
const int MAXE = 150010;
const int INF = 0x3f3f3f3f;
int head[MAXN];
int vis[MAXN];

int Q[MAXN];
int dist[MAXN];

struct Edge {
  int to;
  int v;
  int next;
} edge[MAXE];
int tol;
void add(int a, int b, int v) {
  edge[tol].to = b;
  edge[tol].v = v;
  edge[tol].next = head[a];
  head[a] = tol++;
}
void SPFA(int start, int n) {
  int top = 0;
  for (int v = 1; v <= n; v++) {
    if (v == start) {
      Q[top++] = v;
      vis[v] = true;
      dist[v] = 0;
    } else {
      vis[v] = false;
      dist[v] = INF;
    }
  }
  while (top != 0) {
    int u = Q[--top];
    vis[u] = false;
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (dist[v] > dist[u] + edge[i].v) {
        dist[v] = dist[u] + edge[i].v;
        if (!vis[v]) {
          vis[v] = true;
          Q[top++] = v;
        }
      }
    }
  }
}
int main() {
  int n;
  int M;
  int a, b, c;
  while (scanf("%d%d", &n, &M) != EOF) {
    tol = 0;
    memset(head, -1, sizeof(head));
    while (M--) {
      scanf("%d%d%d", &a, &b, &c);
      add(a, b, c);
    }
    SPFA(1, n);
    printf("%d\n", dist[n]);
  }
  return 0;
}
