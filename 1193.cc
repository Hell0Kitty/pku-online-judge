#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define SWAP(a, b) (tmp = a, a = b, b = tmp)

int T[10010], M[10010], P[10010];
int type[10010];
int ans1, ans2;

int msgQueue[10010], mqlen;

int wait_rear, wait_front;
int wait_list[10010];

int mem[10010];

int cmp(int a, int b) {
  if (T[a] != T[b]) return T[a] - T[b];
  if (type[b] != type[a]) return type[b] - type[a];
  return a - b;
}

void imq(int x, int t) {
  int p = mqlen, q = p / 2, tmp;
  type[x] = t;
  msgQueue[mqlen++] = x;
  while (q)
    if (cmp(msgQueue[p], msgQueue[q]) < 0)
      SWAP(msgQueue[p], msgQueue[q]), p = q, q /= 2;
    else
      break;
}

void mqheapify(int x) {
  int p = x, q, tmp;
  q = x * 2;
  if (q < mqlen && cmp(msgQueue[q], msgQueue[p]) < 0) p = q;
  q = x * 2 + 1;
  if (q < mqlen && cmp(msgQueue[q], msgQueue[p]) < 0) p = q;
  if (p != x) {
    SWAP(msgQueue[p], msgQueue[x]);
    mqheapify(p);
  }
}

int dmq() {
  int rtn = msgQueue[1], tmp;
  mqlen--;
  SWAP(msgQueue[1], msgQueue[mqlen]);
  mqheapify(1);
  return rtn;
}

typedef struct MEM_NODE {
  int hi, lo;
  MEM_NODE *prev, *next;
} MEM_NODE;

MEM_NODE head;

void mem_init(int size) {
  MEM_NODE *p = (MEM_NODE *)malloc(sizeof(MEM_NODE));
  p->hi = size - 1, p->lo = 0, p->prev = &head, p->next = NULL;
  head.next = p;
}

void mem_delete(MEM_NODE *p) {
  if (p->next != NULL) {
    mem_delete(p->next);
    p->next = NULL;
  }
  free(p);
}

int mem_find(int size) {
  MEM_NODE *p = NULL;
  for (p = head.next; p; p = p->next) {
    if (p->hi - p->lo + 1 >= size) return p->lo;
  }
  return -1;
}

void mem_delete_node(MEM_NODE *p) {
  MEM_NODE *prev = p->prev, *next = p->next;
  // if (prev != &head)
  prev->next = next;
  if (next != NULL) next->prev = prev;
  free(p);
}

void mem_alloc(int lo, int size) {
  MEM_NODE *p = NULL;
  for (p = head.next; p; p = p->next)
    if (p->lo == lo) {
      p->lo += size;
      break;
    }
  if (p->lo > p->hi) mem_delete_node(p);
}

MEM_NODE *mem_merge(MEM_NODE *p) {
  MEM_NODE *q = p->next;
  if (q == NULL) return p;
  if (p->hi + 1 != q->lo) return q;
  p->hi = q->hi;
  mem_delete_node(q);
  return p;
}

void mem_release(int lo, int size) {
  MEM_NODE *p = NULL, *q = NULL;

  q = &head, p = q->next;
  while (p != NULL && p->hi < lo) q = p, p = p->next;
  p = (MEM_NODE *)malloc(sizeof(MEM_NODE));
  p->lo = lo, p->hi = lo + size - 1;
  p->next = q->next;
  q->next = p;
  p->prev = q;
  if (p->next != NULL) p->next->prev = p;
  if (q != &head) p = mem_merge(q);
  mem_merge(p);
}

int try_alloc(int x) {
  int mem_num = mem_find(M[x]);
  if (mem_num == -1) return 0;
  mem[x] = mem_num;
  mem_alloc(mem_num, M[x]);
  T[x] += P[x];
  imq(x, 1);
  return 1;
}

void alloc(int x) {
  if (!try_alloc(x)) {
    wait_list[wait_rear++] = x;
    if (wait_rear > ans2) ans2 = wait_rear;
  }
}

void release(int x) {
  int tt = T[x];
  if (tt > ans1) ans1 = tt;
  while (1) {
    mem_release(mem[x], M[x]);
    if (mqlen == 1) break;
    if (type[msgQueue[1]] == 0) break;
    if (T[msgQueue[1]] != tt) break;
    x = dmq();
  }
  while (wait_front != wait_rear) {
    x = wait_list[wait_front];
    T[x] = tt;
    if (try_alloc(x))
      wait_front++;
    else
      break;
  }
}

int main() {
  int n, m, i, x;

  while (~scanf("%d", &n)) {
    m = 0;
    wait_rear = wait_front = 0;
    mem_init(n);
    ans1 = ans2 = 0;
    mqlen = 1;
    while (~scanf("%d%d%d", &T[m], &M[m], &P[m]) && (T[m] || M[m] || P[m])) m++;
    for (i = 0; i < m; i++) imq(i, 0);
    while (mqlen != 1) {
      if (type[x = dmq()] == 0)
        alloc(x);
      else
        release(x);
    }
    mem_delete(head.next);
    printf("%d\n%d\n", ans1, ans2);
  }
  return 0;
}
