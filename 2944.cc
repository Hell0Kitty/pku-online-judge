#include "cstdio"
#include "algorithm"
#define LL long long
using namespace std;

struct A {
  int ma, mi, cha, val, L, R, l, r, m;
  LL sum;
} a[200100];
void Build(int k, int l, int r) {
  a[k].l = l;
  a[k].r = r;
  a[k].m = (l + r) >> 1;
  a[k].L = k << 1;
  a[k].R = (k << 1) + 1;
  a[k].ma = a[k].mi = a[k].sum = a[k].cha = 0;
  if (l == r - 1) return;
  Build(a[k].L, l, a[k].m);
  Build(a[k].R, a[k].m, r);
}
void Change(int k, int s) {
  a[k].cha = 1;
  a[k].val = a[k].ma = a[k].mi = s;
  a[k].sum = (LL)s * (a[k].r - a[k].l);
}
void Down(int k) {
  if (a[k].cha) {
    Change(a[k].L, a[k].val);
    Change(a[k].R, a[k].val);
    a[k].cha = 0;
  }
}
int Query(int k, int x) {
  if (a[k].l == a[k].r - 1) return a[k].sum;
  Down(k);
  if (x < a[k].m) return Query(a[k].L, x);
  return Query(a[k].R, x);
}
int Find(int k, int x) {
  if (a[k].l == a[k].r - 1) return a[k].l;
  Down(k);
  if (a[a[k].L].mi < x) return Find(a[k].L, x);
  return Find(a[k].R, x);
}
void Update(int k, int x, int y, int s) {
  if (a[k].r <= x || y <= a[k].l) return;
  if (x <= a[k].l && a[k].r <= y) {
    Change(k, s);
    return;
  }
  Update(a[k].L, x, y, s);
  Update(a[k].R, x, y, s);
  // maintain
  a[k].ma = max(a[a[k].L].ma, a[a[k].R].ma);
  a[k].mi = min(a[a[k].L].mi, a[a[k].R].mi);
  a[k].sum = a[a[k].L].sum + a[a[k].R].sum;
}
struct B {
  int x, y, z;
} b[100100];
bool cmp(B a, B b) { return a.x < b.x; }

int main() {
  int n, m, t, v, s;
  LL ans;
  while (scanf("%d%d", &n, &m) && n && m) {
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].z);
    sort(b + 1, b + n + 1, cmp);

    s = n;
    ans = 0;
    Build(1, 1, m + 1);

    for (int i = m; i; i--) {
      for (; s && b[s].x == i; s--) {
        t = Query(1, b[s].y);
        if (t < b[s].z) {
          v = Find(1, b[s].z);
          Update(1, v, b[s].y + 1, b[s].z);
        }
      }
      ans += a[1].sum;
    }
    printf("%I64d\n", (LL)m * m * m - ans);
  }
  return 0;
}
