#include <stdio.h>
#define ll long long
#define MAX_N 1024
using namespace std;

struct queue_node {
  int y, x;
};

int set[MAX_N][MAX_N], cut[MAX_N][MAX_N];
int N, M;
int left, top, right, bottom;

struct queue_node queue[MAX_N * MAX_N];
int head, tail;

int find(int *arr, int idx) {
  static int stk[MAX_N * MAX_N], sp;
  for (sp = 0; arr[idx]; idx = arr[idx]) stk[sp++] = idx;
  for (sp--; sp >= 0; sp--) arr[stk[sp]] = idx;
  return idx;
}
void push(int y, int x) {
  if (x < left || x > right || y < top || y > bottom) return;
  if (cut[y][x]) return;

  cut[y][x] = 1;
  if (cut[y][x - 1] && cut[y][x + 1]) {
    set[y][x] = x + 1;
    set[y][x - 1] = x + 1;
  } else if (cut[y][x - 1])
    set[y][x - 1] = x;
  else if (cut[y][x + 1])
    set[y][x] = x + 1;

  queue[tail].y = y;
  queue[tail].x = x;
  tail++;
}
int bfs(int y, int x) {
  x = find(set[y], x);
  if (cut[y][x]) x++;
  if (x > right) return 0;

  head = tail = 0;
  push(y, x);
  while (head != tail) {
    y = queue[head].y;
    x = queue[head].x;
    head++;
    push(y - 1, x);
    push(y + 1, x);
    push(y, x - 1);
    push(y, x + 1);
  }

  return 1;
}
int main() {
  int i, j, ans;

  scanf("%d%d", &N, &M);
  while (M--) {
    scanf("%d%d%d%d", &left, &top, &right, &bottom);
    ans = 0;
    for (i = top; i <= bottom; i++)
      while (bfs(i, left)) ans++;
    printf("%d\n", ans);
  }
}
