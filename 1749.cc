#include <cstdio>
#include <string.h>
using namespace std;
int Abs(int a) { return a < 0 ? -a : a; }
struct Lnode {
  int key, data, d2;
  Lnode *next;
  Lnode() {
    next = NULL;
    data = d2 = 2100000000;
  }
};
#define MODULO 9101
struct HashTable {
  Lnode *head[MODULO];
  HashTable() { memset(head, 0, sizeof(head)); }
  Lnode *tIns(int k) {
    int w;
    Lnode *p;
    w = k % MODULO;
    p = head[w];
    while (p) {
      if (p->key == k) return p;
      p = p->next;
    }
    p = new Lnode;
    p->key = k;
    p->next = head[w];
    head[w] = p;
    return p;
  }
  Lnode *Find(int k) {
    int w;
    Lnode *p;
    w = k % MODULO;
    p = head[w];
    while (p) {
      if (p->key == k) return p;
      p = p->next;
    }
    return NULL;
  }
};
int main() {
  HashTable blocked, used;
  char cmd[10];
  Lnode *p;
  int tr, it;
  while (scanf("%s", cmd) != EOF && cmd[0] != '#') {
    scanf("%d %d", &tr, &it);
    p = blocked.Find(tr);
    if (p)
      puts("IGNORED");
    else {
      p = used.Find(it);
      if (p && ((Abs(p->data) != tr && (cmd[0] == 'X' || p->data < 0)) ||
                (p->d2 != 2100000000 && Abs(p->d2) != tr &&
                 (cmd[0] == 'X' || p->d2 < 0)))) {
        puts("DENIED");
        blocked.tIns(tr);
      } else {
        puts("GRANTED");
        p = used.tIns(it);
        if (p->data == 2100000000) {
          if (cmd[0] == 'X')
            p->data = -tr;
          else
            p->data = tr;
        } else {
          p->d2 = p->data;
          if (cmd[0] == 'X')
            p->data = -tr;
          else
            p->data = tr;
        }
      }
    }
  }
  return 0;
}