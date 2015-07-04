#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cctype>
#include <map>
using namespace std;
#define For(i, n) for (int i = 1; i <= n; i++)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define Fork(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i; i--)
#define Forp(x) for (int p = pre[x]; p; p = next[p])
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MAXN (200000 + 10)
#define MAXM (200000 + 10)
int n, m, a[MAXN], a2[MAXN];
struct node {
  node *ch[2];
  int a, siz;
  node() {
    ch[0] = ch[1] = NULL;
    siz = a = 0;
  }
  void update() {
    siz = a;
    if (ch[0]) siz += ch[0]->siz;
    if (ch[1]) siz += ch[1]->siz;
  }
} *null = new node(), *root[MAXN] = {NULL}, q[MAXN * 9];
int q_s;
void make_node(node *&y, node *&x, int l, int r, int t) {
  if (x == NULL) x = null;
  y = &q[++q_s];
  *y = node();
  int m = (l + r) >> 1;
  if (l == r) {
    *y = *x;
    y->siz++;
    y->a++;
    return;
  }
  if (t <= a2[m]) {
    make_node(y->ch[0], x->ch[0], l, m, t);
    y->ch[1] = x->ch[1];
    y->update();
  } else {
    make_node(y->ch[1], x->ch[1], m + 1, r, t);
    y->ch[0] = x->ch[0];
    y->update();
  }
}
void find(node *&x1, node *&x2, int l, int r, int k) {
  if (x1 == NULL) x1 = null;
  if (x2 == NULL) x2 = null;
  if (l == r) {
    printf("%d\n", a2[l]);
    return;
  }
  int m = (l + r) >> 1;
  int ls = 0;
  if (x2->ch[0]) ls += x2->ch[0]->siz;
  if (x1->ch[0]) ls -= x1->ch[0]->siz;
  if (ls >= k)
    find(x1->ch[0], x2->ch[0], l, m, k);
  else
    find(x1->ch[1], x2->ch[1], m + 1, r, k - ls);
}
int main() {
  // freopen("hdu2665.in","r",stdin);
  null->ch[0] = null;
  null->ch[1] = null;
  q_s = 0;
  scanf("%d%d", &n, &m);
  For(i, n) scanf("%d", &a[i]), a2[i] = a[i];
  sort(a2 + 1, a2 + 1 + n);
  int size = unique(a2 + 1, a2 + 1 + n) - (a2 + 1);
  For(i, n) { make_node(root[i], root[i - 1], 1, size, a[i]); }
  For(i, m) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    find(root[l - 1], root[r], 1, size, k);
  }
  return 0;
}