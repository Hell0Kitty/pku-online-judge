#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 30003

struct Block {
  int father, tot, dis;
} block[maxn];

int n;

void init() {
  for (int i = 0; i < maxn; i++) {
    block[i].father = i;
    block[i].tot = 1;
    block[i].dis = 0;
  }
}

int getanc(int a) {
  int ret;
  if (block[a].father == a) return a;
  ret = getanc(block[a].father);
  block[a].dis += block[block[a].father].dis;
  block[a].father = ret;
  return ret;
}

void move() {
  int a, b;
  scanf("%d%d", &a, &b);
  int anc1 = getanc(a);
  int anc2 = getanc(b);
  block[anc2].dis = block[anc1].tot;
  block[anc2].father = anc1;
  block[anc1].tot = block[anc1].tot + block[anc2].tot;
}

void count() {
  int a;
  scanf("%d", &a);
  int anc = getanc(a);
  printf("%d\n", block[anc].tot - block[a].dis - 1);
}

int main() {
  scanf("%d", &n);
  init();
  for (int i = 0; i < n; i++) {
    char st[3];
    scanf("%s", st);
    if (strcmp(st, "M") == 0)
      move();
    else
      count();
  }
  return 0;
}
