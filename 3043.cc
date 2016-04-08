#include <stdio.h>

#define SIZE 64
#define QUEUE_SIZE 4096

struct tree_node {
  int end, dp[SIZE];
  struct tree_node *child[26], *next;
};

struct queue_node {
  int idx;
  struct tree_node *ptr;
};

int H, W;
char map[SIZE][SIZE];
struct tree_node nodes[QUEUE_SIZE], root, *hash[26];
int nodes_cnt;
struct queue_node queue[QUEUE_SIZE];
int tail, head;

inline void bfs() {
  struct tree_node *t;
  int i;

  head = tail = 0;
  queue[tail++].ptr = &root;
  while (head != tail) {
    t = queue[head++].ptr;
    for (i = 0; i < 26; i++) {
      if (!t->child[i]) continue;
      queue[tail].ptr = t->child[i];
      queue[tail].idx = i;
      tail++;
    }
  }
  for (tail--; tail >= 1; tail--) {
    t = queue[tail].ptr;
    i = queue[tail].idx;
    t->next = hash[i];
    hash[i] = t;
  }
}

inline void calc(int y, int x) {
  struct tree_node *t, *c;
  int i, j, sum;

  for (t = hash[map[y][x] - 'A']; t; t = t->next) {
    sum = t->end;
    for (i = 0; i < 26; i++) {
      c = t->child[i];
      if (!c) continue;
      for (j = W - 1; j >= x; j--) sum += c->dp[j];
    }
    t->dp[x] += sum;
  }
}

int main() {
  int i, j, sum;
  char str[64], *s;
  struct tree_node *t, **p;
  scanf("%d%d", &H, &W);
  for (i = 0; i < H; i++) scanf("%s", map[i]);
  while (scanf("%s", str) != EOF) {
    t = &root;
    for (s = str; *s; s++) {
      p = &t->child[*s - 'A'];
      if (!*p) *p = &nodes[nodes_cnt++];
      t = *p;
    }
    t->end++;
  }
  bfs();

  for (i = 0; i < H; i++)
    for (j = W - 1; j >= 0; j--) calc(i, j);

  sum = 0;
  for (i = 0; i < 26; i++) {
    t = root.child[i];
    if (!t) continue;
    for (j = 0; j < W; j++) sum += t->dp[j];
  }
  printf("%d\n", sum);

  return 0;
}
