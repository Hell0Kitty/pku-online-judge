#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 111117
int dfs(int u);
int hash[MAXN];
int c, t, k;
int ans;
int cy[MAXN], mk[MAXN];
int cnts[1100], cw[1100][40], piz[1100];

int query(int k) {
  int p;
  p = k % MAXN;
  while (hash[p] != -1 && hash[p] != k) p = (p + 10) % MAXN;
  return p;
}

bool hashit(int k) {
  int p;
  p = k % MAXN;
  while (hash[p] != -1 && hash[p] != k) p = (p + 10) % MAXN;
  if (hash[p] == -1)
    hash[p] = k;
  else
    return false;
  return true;
}

int fail[MAXN], tp;

int coordinate(int u, int cnt, int id, int pz) {
  if (cnts[u] - id + cnt < k) return 0;
  if (cnt == k) {
    int p = query(pz);
    if (mk[p] != -1) return 0;
    int x = cy[p];
    mk[p] = 1;
    if (dfs(x)) {
      cy[p] = u;
      return 1;
    }
    return 0;
  } else {
    if (coordinate(u, cnt, id + 1, pz))
      return 1;
    else {
      pz |= (1 << (cw[u][id] - 1));
      if (coordinate(u, cnt + 1, id + 1, pz)) return 1;
      return 0;
    }
  }
  return 0;
}

int newPiz(int u, int cnt, int id, int pz) {
  if (cnts[u] - id + cnt < k) return 0;
  if (cnt == k) {
    if (!hashit(pz)) return 0;
    int p = query(pz);
    cy[p] = u;
    return 1;
  } else {
    if (newPiz(u, cnt, id + 1, pz))
      return 1;
    else {
      pz |= (1 << (cw[u][id] - 1));
      if (newPiz(u, cnt + 1, id + 1, pz)) return 1;
      return 0;
    }
  }
  return 0;
}

int dfs(int u) {
  if (cnts[u] < k) return 0;
  for (int i = 0; i < tp; i++)
    if ((piz[u] & (~fail[i])) == 0) return 0;
  if (newPiz(u, 0, 0, 0))
    return 1;
  else if (coordinate(u, 0, 0, 0))
    return 1;
  else
    fail[tp++] = piz[u];
  return 0;
}

int main() {
  while (~scanf("%d%d%d", &c, &t, &k)) {
    for (int i = 1; i <= c; i++) {
      piz[i] = 0;
      scanf("%d", &cnts[i]);
      for (int j = 0; j < cnts[i]; j++) {
        scanf("%d", &cw[i][j]);
        piz[i] |= (1 << (cw[i][j] - 1));
      }
    }
    tp = 0;
    ans = 0;
    memset(hash, -1, sizeof(hash));
    memset(cy, -1, sizeof(cy));
    for (int i = 1; i <= c; i++) {
      memset(mk, -1, sizeof(mk));
      if (dfs(i)) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
