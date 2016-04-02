#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int N = 50005;
const int M = 40000;

struct Node {
  int num;
  int size;
  struct Node *l, *r;
} * root, tree[M];

int a[M], u[M];
int tot;
int m, n;
int it;

void init() {
  tot = 0;
  it = 0;
  root = NULL;
}

int ls(Node *p) { return p->l ? p->l->size : 0; }

int rs(Node *p) { return p->r ? p->r->size : 0; }

void rotate_left(Node *&p) {
  Node *q = p->r;
  p->r = q->l;
  q->l = p;
  q->size = p->size;
  p->size = ls(p) + rs(p) + 1;
  p = q;
}

void rotate_right(Node *&p) {
  Node *q = p->l;
  p->l = q->r;
  q->r = p;
  q->size = p->size;
  p->size = ls(p) + rs(p) + 1;
  p = q;
}

void maintain(Node *&p, bool flag) {
  if (flag) {
    if (p->r && p->r->r && p->r->r->size > ls(p))
      rotate_left(p);
    else if (p->r && p->r->l && p->r->l->size > ls(p)) {
      rotate_right(p->r);
      rotate_left(p);
    }
  } else {
    if (p->l && p->l->l && p->l->l->size > rs(p))
      rotate_right(p);
    else if (p->l && p->l->r && p->l->r->size > rs(p)) {
      rotate_left(p->l);
      rotate_right(p);
    }
  }
}

void insert(int x, Node *&p) {
  if (!p) {
    p = &tree[tot++];
    p->l = NULL;
    p->r = NULL;
    p->size = 1;
    p->num = x;
  } else {
    p->size++;
    if (p->num > x)
      insert(x, p->l);
    else
      insert(x, p->r);
    maintain(p, x >= p->num);
  }
}

int getkth(int k, Node *p) {
  if (k <= 0 || k > p->size) return 0;
  int lc = ls(p);
  if (k == lc + 1)
    return p->num;
  else if (k <= lc)
    return getkth(k, p->l);
  else
    return getkth(k - 1 - lc, p->r);
}

int main() {
  while (scanf("%d%d", &m, &n) == 2) {
    init();
    int i, j;
    for (i = 1; i <= m; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) scanf("%d", &u[i]);
    int t = 1;
    for (i = 1; i <= m; i++) {
      if (tot != u[t]) {
        insert(a[i], root);
      } else {
        it++;
        printf("%d\n", getkth(it, root));
        t++;
        i--;
      }
    }
    while (t <= n) {
      it++;
      printf("%d\n", getkth(it, root));
      t++;
    }
  }
  return 0;
}
