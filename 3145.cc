#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
const int N = 500000 + 10;
const int limt = 1000;
int minv[N << 2], n;
int ti[N], vi[N], sz;
void pushup(int rt) { minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]); }
void update(int L, int R, int v, int l, int r, int rt) {
  if (L <= l && r <= R) {
    minv[rt] = v;
    return;
  }
  int m = (l + r) >> 1;
  if (L <= m) update(L, R, v, lson);
  if (m < R) update(L, R, v, rson);
  pushup(rt);
}
void query1(int y) {
  int ret = -1, tmp = -1;
  for (int i = sz - 1; i >= 0; i--) {
    if (vi[i] % y == 0) {
      ret = i;
      break;
    }
    if (tmp == -1 || (vi[i] % y) < tmp) {
      tmp = vi[i] % y;
      ret = i;
    }
  }
  printf("%d\n", ret + (ret == -1 ? 0 : 1));
}
int query3(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return minv[rt];
  }
  int m = (l + r) >> 1;
  int t1, t2;
  t1 = t2 = N;
  if (L <= m) t1 = query3(L, R, lson);
  if (m < R) t2 = query3(L, R, rson);
  return min(t1, t2);
}
void query2(int y) {
  int t, ret = -1;
  for (int i = 0; i < N; i += y) {
    if (i + y - 1 > N)
      t = query3(i, N - 1, 0, N - 1, 1);
    else
      t = query3(i, i + y - 1, 0, N - 1, 1);
    if (t == N) continue;
    if (t % y < ret % y || ret == -1)
      ret = t;
    else if (t % y == ret % y && ti[t] > ti[ret])
      ret = t;
  }

  if (ret == -1)
    printf("-1\n");
  else
    printf("%d\n", ti[ret]);
}
int main() {
  int T, cas = 0;
  while (~scanf("%d", &n), n) {
    if (cas != 0 && n != 0) printf("\n");
    sz = 0;
    for (int i = 0; i < (N << 2); i++) minv[i] = N;
    printf("Case %d:\n", ++cas);
    for (int i = 0; i < n; i++) {
      char s[10];
      int x;
      scanf("%s%d", s, &x);
      if (s[0] == 'A') {
        if (x < limt)
          query1(x);
        else
          query2(x);
      } else if (s[0] == 'B') {
        vi[sz] = x;
        ti[x] = sz + 1;
        update(x, x, x, 0, N - 1, 1);
        sz++;
      }
    }
  }
  return 0;
}
