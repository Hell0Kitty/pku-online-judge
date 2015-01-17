#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 55;
struct node {
  int d;
  node* next;
};
node cards[maxn];
node* head;
void makelist(int n) {
  node* cur;
  node* tp;
  tp = new node;
  tp->d = -1;
  tp->next = NULL;
  head = tp;
  cur = head;
  for (int i = 1; i <= n; i++) {
    tp = new node;
    tp->d = n - i + 1;
    tp->next = NULL;
    cur->next = tp;
    cur = tp;
  }
}
void cutting(int p, int c) {
  node* st;
  node* ed;
  node* lk;
  st = head;
  lk = head;
  for (int i = 0; i < p; i++) {
    st = st->next;
    if (i) lk = lk->next;
  }
  ed = st;
  for (int i = 0; i < c - 1; i++) ed = ed->next;
  lk->next = ed->next;
  ed->next = head->next;
  head->next = st;
}
int main() {
  int n, r;
  while (scanf("%d%d", &n, &r), n + r) {
    makelist(n);
    int p, c;
    for (int i = 0; i < r; i++) {
      scanf("%d%d", &p, &c);
      cutting(p, c);
    }
    printf("%d\n", head->next->d);
  }
  return 0;
}
