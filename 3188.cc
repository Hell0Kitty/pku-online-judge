#include <stdio.h>
#include <string.h>

#define MAX_D 1024
#define HASH_SIZE 65536

struct node {
  struct node *next;
  int val, cnt;
};

int B, L, D;
int map[256], ans[256], best;
char dict[MAX_D][16];
struct node nodes[MAX_D], *hash[HASH_SIZE];
int nodes_cnt;
int vis[HASH_SIZE], tm;

inline void calc() {
  int i, h, val, uni;
  char *s;
  struct node *t;

  tm++;
  nodes_cnt = 0;
  for (i = 0; i < D; i++) {
    val = 0;
    for (s = dict[i]; *s; s++) val = val * 31 + map[*s] + 'a';
    h = val & (HASH_SIZE - 1);
    if (vis[h] != tm) {
      vis[h] = tm;
      hash[h] = NULL;
    }
    for (t = hash[h]; t; t = t->next)
      if (t->val == val) break;
    if (!t) {
      t = &nodes[nodes_cnt++];
      t->val = val;
      t->cnt = 0;
      t->next = hash[h];
      hash[h] = t;
    }
    t->cnt++;
  }

  uni = 0;
  for (i = 0; i < nodes_cnt; i++)
    if (nodes[i].cnt == 1) uni++;

  if (uni > best) {
    best = uni;
    memcpy(ans, map, sizeof(map));
  }
}

void dfs(int b, int l) {
  int i, cnt;

  cnt = L - l - (B - b) + 1;
  for (i = 0; i < cnt; i++) map[l + 'A' + i] = b;

  if (b == B - 1) {
    calc();
    return;
  }

  for (i = cnt; i >= 1; i--) dfs(b + 1, l + i);
}

int main() {
  int i;
  scanf("%d%d%d", &B, &L, &D);
  for (i = 0; i < D; i++) scanf("%s", dict[i]);
  dfs(0, 0);
  printf("%d\n", best);
  for (i = 'A'; i < 'A' + L; i++) {
    if (ans[i] != ans[i - 1]) putchar('\n');
    putchar(i);
  }
  putchar('\n');

  return 0;
}
