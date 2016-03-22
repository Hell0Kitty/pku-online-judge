#include <stdio.h>
#include <stdlib.h>

#ifndef INT_MAX
#define INT_MAX 0x7fffffff
#endif

struct tree_node {
  int cnt, min;
};
struct seg_node {
  int a, b, s;
};
int N, M, E;
struct tree_node tree[86432 * 4];
struct seg_node in[10032];

int cmp(const void *a, const void *b) {
  return ((struct seg_node *)a)->a - ((struct seg_node *)b)->a;
}

__inline int max(int a, int b) { return a > b ? a : b; }

__inline int min(int a, int b) { return a < b ? a : b; }

void tree_op(const int ins, int idx, int left, int right, int start, int end,
             int *val) {
  int mid;

  if (ins) {
    if (!tree[idx].cnt || *val < tree[idx].min) tree[idx].min = *val;
    tree[idx].cnt++;
  }

  if (left == start && right == end) {
    if (!ins && tree[idx].cnt && tree[idx].min < *val) *val = tree[idx].min;
    return;
  }

  mid = (left + right) / 2;
  if (end <= mid)
    tree_op(ins, idx * 2, left, mid, start, end, val);
  else if (start > mid)
    tree_op(ins, idx * 2 + 1, mid + 1, right, start, end, val);
  else {
    tree_op(ins, idx * 2, left, mid, start, mid, val);
    tree_op(ins, idx * 2 + 1, mid + 1, right, mid + 1, end, val);
  }
}

int main() {
  int i, val, start, end;

  scanf("%d%d%d", &N, &M, &E);
  for (i = 0; i < N; i++) scanf("%d%d%d", &in[i].a, &in[i].b, &in[i].s);
  qsort(in, N, sizeof(in[0]), cmp);

  for (i = 0; i < N; i++) {
    if (in[i].b < M) continue;
    if (in[i].a > E) break;
    start = max(M, in[i].a - 1);
    end = min(E, in[i].b);
    if (in[i].a == M) {
      tree_op(1, 1, M, E, end, end, &in[i].s);
      continue;
    }
    val = INT_MAX;
    tree_op(0, 1, M, E, start, end, &val);
    if (val == INT_MAX) continue;
    val += in[i].s;
    tree_op(1, 1, M, E, end, end, &val);
  }

  val = INT_MAX;
  tree_op(0, 1, M, E, E, E, &val);
  printf("%d\n", val == INT_MAX ? -1 : val);

  return 0;
}
