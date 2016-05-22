#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

struct Order {
  int s;
  int e;
  int p;
} ord[23];
int n, NumB, NumOrd;
int MaxEarn, CurEarn, off[8];  // off记录每一站的应下车人数

int cmp(const void *aa, const void *bb) {
  struct Order *a = (Order *)aa;
  struct Order *b = (Order *)bb;
  if (a->s != b->s)
    return a->s - b->s;
  else
    return a->e - a->e;
}

//参数num是order的编号，tolp是车上总人数
void DFS(int num, int tolp) {
  // order由零开始编号，故此时已搜索所有order，回溯
  if (num == NumOrd) {
    if (MaxEarn < CurEarn) MaxEarn = CurEarn;
    return;
  } else {
    //减去下车人数,注意无论当前order是否accepted，都要执行
    if (num > 0)
      for (int i = ord[num - 1].s + 1; i <= ord[num].s; i++) {
        tolp -= off[i];
      }
    //加上当前order的上车人数不超载就搜索下一张order
    tolp += ord[num].p;
    if (tolp <= n) {
      CurEarn += (ord[num].e - ord[num].s) * ord[num].p;
      off[ord[num].e] += ord[num].p;
      DFS(num + 1, tolp);
      //以下两条指令必须在当前的if中，因为上面的“CurEarn+= ...”和“off+=”
      //是满足if 的条件时才执行的。
      CurEarn -= (ord[num].e - ord[num].s) * ord[num].p;
      off[ord[num].e] -= ord[num].p;
    }
    tolp -= ord[num].p;  //还原现场
    DFS(num + 1, tolp);
  }
  return;
}

int main() {
  while (scanf("%d %d %d", &n, &NumB, &NumOrd) && (n || NumB || NumOrd)) {
    memset(off, 0, sizeof(off));
    MaxEarn = 0;
    CurEarn = 0;
    for (int i = 0; i < NumOrd; i++) {
      scanf("%d %d %d", &ord[i].s, &ord[i].e, &ord[i].p);
    }
    qsort(ord, NumOrd, sizeof(ord[0]), cmp);
    DFS(0, 0);
    printf("%d\n", MaxEarn);
  }
  return 0;
}
