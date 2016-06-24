#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 300010, BLOCK_SIZE = 900;

int n, m;

int data[BLOCK_SIZE][BLOCK_SIZE];
int size[BLOCK_SIZE], next[BLOCK_SIZE];
int rec[BLOCK_SIZE], rec_sz, tot = 1;

void print() {
  for (int u = 1; u; u = next[u]) {
    printf("|");
    for (int i = 0; i < size[u]; i++) printf("%d ", data[u][i]);
    printf("|");
  }
  puts("");
}

int alloc() {
  int x = rec_sz ? rec[rec_sz--] : ++tot;
  size[x] = next[x] = 0;
  return x;
}

void dealloc(int x) { rec[++rec_sz] = x; }

void merge(int x) {
  int y = next[x];
  memcpy(data[x] + size[x], data[y], sizeof(int) * size[y]);
  size[x] += size[y];
  next[x] = next[y];
  dealloc(y);
}

void split(int x, int sz) {
  if (size[x] == sz) return;
  int y = alloc();
  size[y] = size[x] - sz;
  size[x] = sz;
  memcpy(data[y], data[x] + size[x], sizeof(int) * size[y]);
  next[y] = next[x];
  next[x] = y;
}

void maintain() {
  for (int u = 1; u; u = next[u])
    while (next[u] > 0 && size[u] + size[next[u]] <= BLOCK_SIZE) merge(u);
}

int locate(int cur) {
  for (int u = 1; u; u = next[u]) {
    if (cur > size[u])
      cur -= size[u];
    else {
      split(u, cur);
      return u;
    }
  }
}

void insert(int cur, int val, int sz) {
  int x = locate(cur);
  while (sz > BLOCK_SIZE) {
    int y = alloc();
    fill_n(data[y], BLOCK_SIZE, val);
    size[y] = BLOCK_SIZE;
    next[y] = next[x];
    next[x] = y;
    x = y;
    sz -= BLOCK_SIZE;
  }
  if (sz > 0) {
    int y = alloc();
    fill_n(data[y], sz, val);
    size[y] = sz;
    next[y] = next[x];
    next[x] = y;
  }
  maintain();
}
void erase(int cur, int sz) {
  int x = locate(cur);
  int y = locate(cur + sz);
  y = next[y];
  for (int u = next[x]; u != y; u = next[u]) dealloc(u);
  next[x] = y;
  maintain();
}

int Get(int cur) {
  int x = locate(cur);
  x = next[x];
  int res = data[x][0];
  maintain();
  return res;
}

int fa[N];
int find(int x) { return fa[x] ? fa[x] = find(fa[x]) : x; }

int cur_size;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int L;
    scanf("%d", &L);
    int x = find(L);
    if (cur_size < max(L, x)) {
      insert(cur_size, 0, max(L, x) - cur_size);
      cur_size = max(L, x);
    }
    erase(x - 1, 1);
    insert(L - 1, i, 1);
    fa[x] = x + 1;
    cur_size = max(cur_size, x);
  }
  printf("%d\n", cur_size);
  int u = 1, j = 0;
  for (int i = 1; i <= cur_size; i++) {
    printf("%d%c", data[u][j], i == cur_size ? '\n' : ' ');
    if (++j == size[u]) {
      j = 0;
      u = next[u];
    }
  }
  return 0;
}
