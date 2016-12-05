#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 20000;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
struct v_seg {
  int s, t;
  int x;
} ss[maxn];
int cover[maxn << 2];
int Hash[maxn];
vector<int> V[maxn];
void pushdown(int rt) {
  if (cover[rt] != -1) {
    cover[rt << 1] = cover[rt << 1 | 1] = cover[rt];
    cover[rt] = -1;
  }
}
void update(int L, int R, int id, int l, int r, int rt) {
  if (L <= l && r <= R) {
    cover[rt] = id;
    return;
  }
  pushdown(rt);
  int m = (l + r) >> 1;
  if (L <= m) update(L, R, id, lson);
  if (R > m) update(L, R, id, rson);
}
void query(int L, int R, int id, int l, int r, int rt) {
  if (cover[rt] != -1) {
    if (Hash[cover[rt]] != id) {
      V[cover[rt]].push_back(id);
      Hash[cover[rt]] = id;
    }
    return;
  }
  if (l == r) return;
  pushdown(rt);
  int m = (l + r) >> 1;
  if (L <= m) query(L, R, id, lson);
  if (R > m) query(L, R, id, rson);
}
int cmp(v_seg a, v_seg b) { return a.x < b.x; }
int main() {
  int t, i, j, k, n, T, h;
  scanf("%d", &T);
  while (T--) {
    memset(cover, -1, sizeof(cover));
    memset(Hash, -1, sizeof(Hash));
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d%d%d", &ss[i].s, &ss[i].t, &ss[i].x);
      ss[i].s <<= 1;
      ss[i].t <<= 1;
      V[i].clear();
    }
    sort(ss, ss + n, cmp);
    for (i = 0; i < n; i++) {
      query(ss[i].s, ss[i].t, i, 0, 16000, 1);
      update(ss[i].s, ss[i].t, i, 0, 16000, 1);
    }
    int ans = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < V[i].size(); j++) {
        k = V[i][j];
        for (t = 0; t < V[i].size(); t++)
          for (int w = 0; w < V[k].size(); w++)
            if (V[i][t] == V[k][w]) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
