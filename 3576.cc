#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long hash_t;
const int MAX_N = 5000, MAX_L = 30, SON = 26, MAX_NODE_CNT = MAX_N * MAX_L + 1,
          SEED = 99991;
char pat[MAX_L + 1];
int n, dep[MAX_NODE_CNT], seq[MAX_NODE_CNT];

struct disjoint_set_t {
  int root[MAX_NODE_CNT];
  int n;
  void set(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) root[i] = i;
  }
  int get_root(int x) { return x == root[x] ? x : root[x] = get_root(root[x]); }
  void set_union(int u, int v) {
    u = get_root(u);
    v = get_root(v);
    root[u] = v;
  }
} ds;

struct node_t {
  int son[SON], sc;
  hash_t hash;
  bool end;
} node[MAX_NODE_CNT];

int node_idx, root;

int node_alloc() {
  int ret = node_idx++;
  memset(node[ret].son, -1, sizeof(int) * SON);
  node[ret].sc = 0;
  node[ret].end = 0;
  return ret;
}

void init() {
  node_idx = 0;
  root = node_alloc();
}

void ins(char *str) {
  int pos = root;
  while (*str) {
    int t = *(str++) - 'a';
    if (node[pos].son[t] < 0) {
      node[pos].son[t] = node_alloc();
      node[pos].sc++;
    }
    pos = node[pos].son[t];
  }
  node[pos].end = 1;
}

void dfs(int u) {
  dep[u] = 0;
  for (int i = 0; i < SON; i++)
    if (node[u].son[i] >= 0) {
      dfs(node[u].son[i]);
      dep[u] = max(dep[u], dep[node[u].son[i]]);
    }
  dep[u]++;
}

bool cmp(const int &a, const int &b) { return dep[a] < dep[b]; }

bool cmp_s(const int &a, const int &b) {
  if (node[a].sc != node[b].sc) return node[a].sc < node[b].sc;
  return node[a].hash < node[b].hash;
}

int main() {
  while (scanf("%d", &n) != EOF && n) {
    init();
    for (int i = 0; i < n; i++) {
      scanf("%s", pat);
      ins(pat);
    }

    dfs(root);
    for (int i = 0; i < node_idx; i++) seq[i] = i;
    sort(seq, seq + node_idx, cmp);
    int ans = node_idx;
    ds.set(node_idx);

    for (int i = 0, j = 0; i < node_idx; i = j) {
      while (j < node_idx && dep[seq[j]] == dep[seq[i]]) j++;
      for (int k = i; k < j; k++) {
        node[seq[k]].hash = 0ULL;
        for (int s = 0; s < SON; s++) {
          int ss = node[seq[k]].son[s] >= 0
                       ? ds.get_root(node[seq[k]].son[s]) + 2
                       : 1;
          node[seq[k]].hash = node[seq[k]].hash * SEED + ss;
        }
        node[seq[k]].hash = node[seq[k]].hash * SEED + node[seq[k]].end + 1;
      }
      sort(seq + i, seq + j, cmp_s);
      for (int k = i, l = i; k < j; k = l) {
        while (l < j && node[seq[k]].sc == node[seq[l]].sc &&
               node[seq[k]].hash == node[seq[l]].hash)
          l++;
        ans -= (l - k - 1);
        for (int t = k + 1; t < l; t++) ds.set_union(seq[k], seq[t]);
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}
