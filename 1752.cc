#include <iostream>
#include <queue>
using namespace std;
#define MAXV 20000
#define INF 0xfffffff
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a < b ? b : a)

typedef struct { int t, w, next; } Edge;

Edge edge[8 * MAXV];
int k, n;
int d[2 * MAXV];
bool vis[2 * MAXV];
int headlist[2 * MAXV], edge_sum;
int start, end;

void swap(int &a, int &b) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void addedge(int s, int t, int w) {
  edge[edge_sum].t = t;
  edge[edge_sum].w = w;
  edge[edge_sum].next = headlist[s];
  headlist[s] = edge_sum++;
}

void spfa() {
  int i, v, t;
  queue<int> q;
  for (i = start; i <= end; i++) {
    d[i] = -INF;
    vis[i] = 0;
  }

  d[start] = 0;
  vis[start] = 1;
  q.push(start);
  while (!q.empty()) {
    v = q.front();
    q.pop();
    vis[v] = 0;

    for (i = headlist[v]; i != -1; i = edge[i].next) {
      t = edge[i].t;
      if (d[v] + edge[i].w > d[t]) {
        d[t] = d[v] + edge[i].w;
        if (!vis[t]) {
          q.push(t);
          vis[t] = 1;
        }
      }
    }
  }
}

int main() {
  int i, a, b, c;
  while (~scanf("%d%d", &k, &n)) {
    edge_sum = 0;
    start = INF;
    end = -1;
    memset(headlist, -1, sizeof(headlist));
    for (i = 0; i < n; i++) {
      scanf("%d%d", &a, &b);
      if (a > b) swap(a, b);
      a += MAXV - 1;
      b += MAXV;
      start = min(start, a);
      end = max(end, b);
      c = b - a;
      if (c < k) {
        addedge(a, b, c);
        addedge(b, a, -c);
      } else
        addedge(a, b, k);
    }

    for (i = start; i <= end; i++) {
      addedge(i, i + 1, 0);
      addedge(i + 1, i, -1);
    }

    spfa();

    printf("%d\n", d[end]);
    for (i = start; i <= end; i++) {
      if (d[i] - d[i - 1] == 1) printf("%d\n", i - MAXV);
    }
  }
  return 0;
}