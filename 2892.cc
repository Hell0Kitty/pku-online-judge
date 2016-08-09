#include <cstdio>
#include <cstring>
#define ele int
using namespace std;
#define maxn 50010
inline ele lowbit(ele x) { return x & (-x); }
ele n;
struct BIT {
  BIT() { memset(c, 0, sizeof(c)); }
  inline ele prefix(ele i) {
    ele ans = 0;
    while (i > 0) {
      ans += c[i];
      i -= lowbit(i);
    }
    return ans;
  }
  inline void add(ele i, ele x) {
    while (i <= n) {
      c[i] += x;
      i += lowbit(i);
    }
  }
  ele c[maxn];
};
struct seg {
  inline ele get(ele i) { return a.prefix(i); }
  inline void add(ele l, ele r, ele c) {
    if (l > r) return;
    a.add(l, c);
    a.add(r + 1, -c);
  }
  BIT a;
};
ele m, q[maxn], cnt;
seg tl, tr;
inline void init() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) tl.add(i + 1, i + 1, i + 1);
  for (int i = 0; i < n; ++i) tr.add(i + 1, i + 1, n - i);
  cnt = 0;
}
inline void solve() {
  char s[10];
  ele x, a, b, c, d, last, k;
  while (m--) {
    scanf("%s", s);
    if (s[0] != 'R') scanf("%d", &x);
    if (s[0] == 'D') {
      a = tl.get(x);
      b = tr.get(x);
      tr.add(x - a + 1, x - 1, -b);
      tl.add(x + 1, x + b - 1, -a);
      tl.add(x, x, -a);
      tr.add(x, x, -b);
      q[cnt++] = x;
    } else if (s[0] == 'Q') {
      k = tl.get(x) + tr.get(x);
      if (k > 0) --k;
      printf("%d\n", k);
    } else if (s[0] == 'R') {
      x = q[--cnt];
      a = tl.get(x - 1);
      b = tr.get(x + 1);
      tr.add(x - a, x - 1, b + 1);
      tl.add(x + 1, x + b, a + 1);
      tl.add(x, x, a + 1);
      tr.add(x, x, b + 1);
    }
  }
}
int main() {
  init();
  solve();
  return 0;
}
