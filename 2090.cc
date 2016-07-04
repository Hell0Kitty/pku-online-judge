#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 250

struct Edge {
  int v, next;
} edge[maxn * maxn];

int n;
int stock[maxn], f[maxn];
int head[maxn], ecount, color[maxn], q[maxn];
int out[maxn];
bool ok;
int stk1[maxn], stk2[maxn];
int top1, top2, step;

void input() {
  for (int i = 0; i < n; i++) {
    scanf("%d", &stock[i]);
    out[i] = stock[i];
  }
}

void addedge(int& a, int& b) {
  edge[ecount].next = head[a];
  edge[ecount].v = b;
  head[a] = ecount++;
}

void bfs(int& s) {
  int front = 0;
  int rear = 1;
  q[0] = s;
  color[s] = 1;
  while (front != rear) {
    int a = q[front++];
    for (int i = head[a]; i != -1; i = edge[i].next) {
      int b = edge[i].v;
      if (!color[b]) {
        q[rear++] = b;
        color[b] = 3 - color[a];
      } else if (color[a] == color[b]) {
        ok = false;
        return;
      }
    }
  }
}

void make(int i) {
  int a = stock[i];
  bool did = true;
  while (did) {
    did = false;
    if (top1 > 0 && stk1[top1 - 1] == out[step]) {
      top1--;
      printf("pop 1\n");
      step++;
      did = true;
    }
    if (top2 > 0 && stk2[top2 - 1] == out[step]) {
      top2--;
      printf("pop 2\n");
      step++;
      did = true;
    }
  }
  if (i < 0) return;
  if (color[i] == 1) {
    stk1[top1++] = a;
    printf("push 1\n");
  } else {
    stk2[top2++] = a;
    printf("push 2\n");
  }
}

void print() {
  top1 = top2 = 0;
  step = 0;
  for (int i = n - 1; i >= 0; i--) make(i);
  make(-1);
}

void work() {
  memset(head, -1, sizeof(head));
  f[0] = stock[0];
  for (int i = 1; i < n; i++) f[i] = min(f[i - 1], stock[i]);
  ecount = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (stock[j] >= stock[i]) continue;
      if (stock[j] > f[i - 1]) {
        addedge(i, j);
        addedge(j, i);
      }
    }
  }
  ok = true;
  memset(color, 0, sizeof(color));
  for (int i = 0; i < n; i++) {
    if (!color[i]) bfs(i);
    if (!ok) {
      printf("impossible\n");
      return;
    }
  }
  print();
}

int main() {
  int t = 0;
  while (scanf("%d", &n), n) {
    t++;
    printf("#%d\n", t);
    input();
    sort(out, out + n);
    work();
  }
  return 0;
}
