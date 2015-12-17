#include <stdio.h>
struct node {
  int l, r;
  int st, mi, en;
  int id;
}; // 线段树简单一维
const int maxN = 50000002;
const int maxL = 10000020;
node segment_tree[maxN];
#define tree segment_tree
int root, ptr;
void insert(int cr, int start, int end, int color) {
  if (start >= end)
    return;
  if (tree[cr].st == start && tree[cr].en == end) {
    tree[cr].id = color;
    return;
  }
  int mid = (tree[cr].st + tree[cr].en) / 2;
  if (tree[cr].l == 0) {
    tree[cr].l = ptr++;
    tree[tree[cr].l].l = tree[tree[cr].l].r = 0;
    tree[tree[cr].l].id = -1;
    tree[tree[cr].l].st = tree[cr].st, tree[tree[cr].l].en = mid;
  }
  if (tree[cr].r == 0) {
    tree[cr].r = ptr++;
    tree[tree[cr].r].l = tree[tree[cr].r].r = 0;
    tree[tree[cr].r].id = -1;
    tree[tree[cr].r].st = mid, tree[tree[cr].r].en = tree[cr].en;
  }
  if (tree[cr].id != 0) {
    tree[tree[cr].l].id = tree[tree[cr].r].id = tree[cr].id;
    tree[cr].id = 0;
  }
  if (start >= mid) {
    insert(tree[cr].r, start, end, color);
    return;
  }
  if (end <= mid) {
    insert(tree[cr].l, start, end, color);
    return;
  }
  insert(tree[cr].l, start, mid, color);
  insert(tree[cr].r, mid, end, color);
}

char exist[10001];
void trail(int cr) {
  if (cr == 0 || tree[cr].id == -1)
    return;
  exist[tree[cr].id] = 1;
  if (tree[cr].id != 0)
    return;
  trail(tree[cr].l);
  trail(tree[cr].r);
}

void init() {
  root = 1;
  tree[root].l = tree[root].r = tree[root].id = 0;
  tree[root].st = 1, tree[root].en = maxL, tree[root].mi = (1 + maxL) / 2;
  ptr = 2;
}

int main() {
  int test, n, i, l, r;
  scanf("%d", &test);
  while (test--) {
    init();
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &l, &r);
      insert(1, l, r + 1, i);
    }
    for (i = 1; i <= n; i++)
      exist[i] = 0;
    trail(1);
    int ans = 0;
    for (i = 1; i <= n; i++)
      if (exist[i])
        ans++;
    printf("%d\n", ans);
  }
  scanf("\n");
  return 0;
}

