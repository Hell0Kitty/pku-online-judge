#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 50, MAX_P = 20, MAX_W = 1000, SON = 4, INF = 0x3f3f3f3f;
char t[MAX_P + 1], s[MAX_W + 1];
int n, idx[256];
int f[2][MAX_N * MAX_P + 1], now, pre;

struct node_t {
  node_t *son[SON], *fail;
  bool v;
} node_pool[MAX_N * MAX_P + 1], *node_idx, *root;

node_t *node_alloc() {
  node_t *ret = node_idx++;
  memset(ret->son, 0, sizeof(ret->son));
  ret->fail = NULL;
  ret->v = 0;
  return ret;
}

void init() {
  node_idx = node_pool;
  root = node_alloc();
}

void ins(char *str) {
  node_t *pos = root;
  while (*str) {
    int p = idx[*(str++)];
    if (!pos->son[p]) pos->son[p] = node_alloc();
    pos = pos->son[p];
  }
  pos->v = 1;
}

void build() {
  static queue<node_t *> q;
  for (int i = 0; i < SON; i++)
    if (root->son[i]) {
      root->son[i]->fail = root;
      q.push(root->son[i]);
    } else
      root->son[i] = root;
  while (q.size()) {
    node_t *u = q.front();
    q.pop();
    for (int i = 0; i < SON; i++)
      if (u->son[i]) {
        u->son[i]->fail = u->fail->son[i];
        u->son[i]->v |= u->fail->son[i]->v;
        q.push(u->son[i]);
      } else
        u->son[i] = u->fail->son[i];
  }
}

int main() {
  idx['A'] = 0, idx['G'] = 1, idx['C'] = 2, idx['T'] = 3;
  int cas = 0;
  while (scanf("%d", &n) != EOF && n) {
    init();
    for (int i = 0; i < n; i++) {
      scanf("%s", t);
      ins(t);
    }
    build();
    scanf("%s", s);
    int sz = strlen(s);
    int cnt = node_idx - node_pool;

    now = 0, pre = 1;
    memset(f[now], 0x3f, sizeof(f[now]));
    f[now][0] = 0;
    for (int i = 0; i < sz; i++) {
      now ^= 1, pre ^= 1;
      memset(f[now], 0x3f, sizeof(f[now]));
      for (int j = 0; j < cnt; j++)
        if (f[pre][j] < INF) {
          node_t *pos = node_pool + j;
          for (int k = 0; k < 4; k++)
            if (!pos->son[k]->v) {
              int t = pos->son[k] - node_pool;
              f[now][t] = min(f[now][t], f[pre][j] + (k != idx[s[i]]));
            }
        }
    }

    printf("Case %d: ", ++cas);
    int ans = INF;
    for (int i = 0; i < cnt; i++)
      if (!(node_pool + i)->v) ans = min(ans, f[now][i]);
    if (ans == INF)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
