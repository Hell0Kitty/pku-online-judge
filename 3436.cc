#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxp 11
#define maxn 55
#define inf 0x3f3f3f3f

struct edge {
  int x, y, nxt;
  int c;
} bf[maxn * maxn * maxn];

struct Machine {
  int q, s[maxp], d[maxp];
} machine[maxn];

int p, n, s, t, ans;
int ne, head[maxn], cur[maxn], ps[maxn], dep[maxn];

void addedge(int x, int y, int c) {
  bf[ne].x = x;
  bf[ne].y = y;
  bf[ne].c = c;
  bf[ne].nxt = head[x];
  head[x] = ne++;
  bf[ne].x = y;
  bf[ne].y = x;
  bf[ne].c = 0;
  bf[ne].nxt = head[y];
  head[y] = ne++;
}

int flow(int n, int s, int t) {
  int tr, res = 0;
  int i, j, k, f, r, top;
  while (1) {
    memset(dep, -1, n * sizeof(int));
    for (f = dep[ps[0] = s] = 0, r = 1; f != r;)
      for (i = ps[f++], j = head[i]; j; j = bf[j].nxt) {
        if (bf[j].c && -1 == dep[k = bf[j].y]) {
          dep[k] = dep[i] + 1;
          ps[r++] = k;
          if (k == t) {
            f = r;
            break;
          }
        }
      }
    if (-1 == dep[t]) break;

    memcpy(cur, head, n * sizeof(int));
    for (i = s, top = 0;;) {
      if (i == t) {
        for (k = 0, tr = inf; k < top; ++k)
          if (bf[ps[k]].c < tr) tr = bf[ps[f = k]].c;
        for (k = 0; k < top; ++k) bf[ps[k]].c -= tr, bf[ps[k] ^ 1].c += tr;
        res += tr;
        i = bf[ps[top = f]].x;
      }
      for (j = cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
        if (bf[j].c && dep[i] + 1 == dep[bf[j].y]) break;
      if (cur[i]) {
        ps[top++] = cur[i];
        i = bf[cur[i]].y;
      } else {
        if (0 == top) break;
        dep[i] = -1;
        i = bf[ps[--top]].x;
      }
    }
  }
  return res;
}

bool ok(int a, int b) {
  if (a == b) return false;
  for (int i = 0; i < p; i++)
    if (machine[a].d[i] + machine[b].s[i] == 1) return false;
  return true;
}

void input() {
  for (int i = 1; i <= 2 * n; i += 2) {
    scanf("%d", &machine[i / 2].q);
    for (int j = 0; j < p; j++) scanf("%d", &machine[i / 2].s[j]);
    for (int j = 0; j < p; j++) scanf("%d", &machine[i / 2].d[j]);
    addedge(i, i + 1, machine[i / 2].q);
  }
  s = 0;
  t = 2 * n + 1;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < p; j++)
      if (machine[i].s[j] == 1) {
        ok = false;
        break;
      }
    if (ok) addedge(s, i * 2 + 1, inf);
  }
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < p; j++)
      if (machine[i].d[j] != 1) {
        ok = false;
        break;
      }
    if (ok) addedge(i * 2 + 2, t, inf);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (ok(i, j)) addedge(i * 2 + 2, j * 2 + 1, inf);
}

bool ok(edge &a) {
  if (!(a.c > 0 && a.x != s && a.y != s && a.x != t && a.y != t)) return false;
  if ((a.y & 1) && !(a.x & 1) && (a.y + 1 == a.x)) return false;
  return true;
}

void output() {
  printf("%d ", ans);
  int ecount = 0;
  for (int i = 2; i < ne; i++)
    if ((i & 1) && ok(bf[i])) ecount++;
  printf("%d\n", ecount);
  for (int i = 2; i < ne; i++)
    if ((i & 1) && ok(bf[i]))
      printf("%d %d %d\n", bf[i].y / 2, (bf[i].x + 1) / 2, bf[i].c);
}

int main() {
  scanf("%d%d", &p, &n);
  ne = 2;
  memset(head, 0, sizeof(head));
  input();
  ans = flow(n * 2 + 2, s, t);
  output();
  return 0;
}
