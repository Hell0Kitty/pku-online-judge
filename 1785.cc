#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 100005

struct Node {
  char c[100];
  int v;
  int l, r, fa;
} tree[maxn];

int n;

bool operator<(const Node &a, const Node &b) { return strcmp(a.c, b.c) < 0; }

void input() {
  for (int i = 1; i <= n; i++) scanf("%*[ ]%[^/]/%d", tree[i].c, &tree[i].v);
}

void ins(int i) {
  int j = i - 1;

  while (tree[j].v < tree[i].v) j = tree[j].fa;
  tree[i].l = tree[j].r;
  tree[tree[i].l].fa = i;
  tree[j].r = i;
  tree[i].fa = j;
}

void dfs(int i) {
  if (!i) return;
  printf("(");
  dfs(tree[i].l);
  printf("%s/%d", tree[i].c, tree[i].v);
  dfs(tree[i].r);
  printf(")");
}

int main() {
  while (scanf("%d", &n), n) {
    input();
    tree[0].l = tree[0].r = tree[0].fa = 0;
    tree[0].v = 0x3f3f3f3f;
    sort(tree + 1, tree + n + 1);
    for (int i = 1; i <= n; i++) {
      tree[i].l = tree[i].r = tree[i].fa = 0;
      ins(i);
    }
    dfs(tree[0].r);
    printf("\n");
  }
  return 0;
}
