#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXINT = ~0u >> 1;

struct Node {
  Node *ls, *rs;
  long long v, add;
  void down() {
    if (add == 0) return;
    if (ls) {
      ls->v += add;
      ls->add += add;
    }
    if (rs) {
      rs->v += add;
      rs->add += add;
    }
    add = 0;
  }
  void repair() { v = min(ls->v, rs->v); }
};
Node segNode[100002], *bp, *root;
int left, right;
Node *makeTree(int l, int r) {
  Node *ans = bp++;
  if (l == r) {
    ans->v = ans->add = 0;
    ans->ls = ans->rs = NULL;
  } else {
    int t = (l + r) / 2;
    ans->ls = makeTree(l, t);
    ans->rs = makeTree(t + 1, r);
    ans->v = ans->add = 0;
  }
  return ans;
}
void clear(int l, int r) {
  bp = segNode;
  left = l;
  right = r;
  root = makeTree(l, r);
}
void set(int ll, int rr, long long x, Node *from = root, int l = left,
         int r = right) {
  if (l == ll && r == rr) {
    from->add += x;
    from->v += x;
  } else {
    int t = (l + r) / 2;
    from->down();
    if (rr <= t)
      set(ll, rr, x, from->ls, l, t);
    else if (ll > t)
      set(ll, rr, x, from->rs, t + 1, r);
    else {
      set(ll, t, x, from->ls, l, t);
      set(t + 1, rr, x, from->rs, t + 1, r);
    }
    from->repair();
  }
}
long long get(int ll, int rr, Node *from = root, int l = left, int r = right) {
  if (l == ll && r == rr) return from->v;
  int t = (l + r) / 2;
  from->down();
  if (rr <= t)
    return get(ll, rr, from->ls, l, t);
  else if (ll > t)
    return get(ll, rr, from->rs, t + 1, r);
  else
    return min(get(ll, t, from->ls, l, t), get(t + 1, rr, from->rs, t + 1, r));
}

int n, newn, limit;
int a[50000];
int b[50000];
int maxa[50001];
int minb[50000];
bool isR[50000];
int newa[50001];
int newb[50001];
int stka[50000];
int stkl[50000];

bool canGao(int ans, int a[], int b[], int n) {
  int sumb = 0, left = 1, p = 0;
  long long dpi = 0;
  clear(0, n);
  for (int i = 1; i <= n; i++) {
    sumb += b[i];
    while (sumb > ans) sumb -= b[left++];
    if (left > i) return false;
    set(i - 1, i - 1, (long long)dpi + a[i]);
    stkl[p] = i - 1;
    while (p > 0 && a[i] >= stka[p - 1]) {
      set(stkl[p - 1], stkl[p] - 1, (long long)a[i] - stka[p - 1]);
      p--;
    }
    stka[p++] = a[i];
    dpi = get(left - 1, i - 1);
    if (dpi > limit) return false;
  }
  return true;
}

int main() {
  int i;
  scanf("%d%d", &n, &limit);
  for (i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
  minb[0] = b[0];
  for (i = 1; i < n; i++) minb[i] = min(b[i], minb[i - 1]);
  maxa[n] = -1;
  for (i = n - 1; i >= 0; i--) maxa[i] = max(a[i], maxa[i + 1]);
  for (i = 0; i < n; i++)
    if (minb[i] > maxa[i + 1])
      isR[i] = true;
    else
      isR[i] = false;
  memset(newa, -1, sizeof(newa));
  memset(newb, 0, sizeof(newb));
  newn = 1;
  for (i = 0; i < n; i++) {
    newa[newn] = max(newa[newn], a[i]);
    newb[newn] += b[i];
    if (isR[i]) newn++;
  }
  newn--;
  newa[0] = 0;
  newb[0] = 0;
  int l = 0, r = MAXINT;
  while (l < r) {
    int t = ((long long)l + r) / 2;
    if (canGao(t, newa, newb, newn))
      r = t;
    else
      l = t + 1;
  }
  printf("%d\n", l);
  return 0;
}
