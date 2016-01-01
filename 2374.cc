#include <stdio.h>

#define MAX_N 50032
#define MAX_R 100032

struct {
  int a, b;
} dp[MAX_N], fences[MAX_N];
int N, S, tree[MAX_R * 16];

__inline int max(int a, int b) { return a > b ? a : b; }

__inline int abs(int a) { return a > 0 ? a : -a; }

__inline int min(int a, int b) { return a < b ? a : b; }

void insert(int idx, int start, int end, int left, int right, int val) {
  int mid;

  if (start == left && right == end) {
    tree[idx] = val;
    return;
  }
  mid = (start + end) / 2;
  if (right <= mid)
    insert(idx * 2, start, mid, left, right, val);
  else if (left > mid)
    insert(idx * 2 + 1, mid + 1, end, left, right, val);
  else {
    insert(idx * 2, start, mid, left, mid, val);
    insert(idx * 2 + 1, mid + 1, end, mid + 1, right, val);
  }
}

int query(int idx, int start, int end, int pos) {
  int val, mid;

  if (start == pos && end == pos) return tree[idx];
  mid = (start + end) / 2;
  if (pos <= mid)
    val = query(idx * 2, start, mid, pos);
  else
    val = query(idx * 2 + 1, mid + 1, end, pos);
  return max(val, tree[idx]);
}

__inline int calc_min(int i, int pos) {
  if (!i) return abs(pos - MAX_R);
  return min(pos - fences[i].a + dp[i].a, fences[i].b - pos + dp[i].b);
}

int main() {
  int i;
  scanf("%d%d", &N, &S);
  S += MAX_R;
  for (i = 1; i <= N; i++) {
    scanf("%d%d", &fences[i].a, &fences[i].b);
    fences[i].a += MAX_R;
    fences[i].b += MAX_R;
    dp[i].a = calc_min(query(1, 0, MAX_R * 2, fences[i].a), fences[i].a);
    dp[i].b = calc_min(query(1, 0, MAX_R * 2, fences[i].b), fences[i].b);
    insert(1, 0, MAX_R * 2, fences[i].a, fences[i].b, i);
  }
  printf("%d\n", min(S - fences[N].a + dp[N].a, fences[N].b - S + dp[N].b));

  return 0;
}
