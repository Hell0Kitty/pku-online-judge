#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <ctime>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <queue>
#include <vector>
using namespace std;
struct A {
  int l, k;
} e;
bool operator<(const A &a, const A &b) {
  if (a.k == b.k) return a.l > b.l;
  return a.k < b.k;
}
priority_queue<A> qe;
int fa[1000006], s[1000005], nt[1000006];
char a[1000005];
int find(int k) {
  int fk = k, zk;
  while (fk != fa[fk]) fk = fa[fk];
  while (k != fa[k]) {
    zk = fa[k];
    fa[k] = fk;
    k = zk;
  }
  return fk;
}
char bj[1000006];
int from[1000006];
int main() {
  while (gets(a)) {
    while (!qe.empty()) qe.pop();
    int n;
    n = strlen(a);
    for (int i = 0; i < n; i++)
      bj[i] = 0, from[i] = i - 1, fa[i] = i, nt[i] = i + 1;
    for (int i = 0; i < n; i++) {
      int q = i + 1;
      while (a[i] == a[q]) {
        fa[q] = i;
        q++;
      }
      q--;
      s[i] = q - i + 1;
      e.k = q - i + 1;
      e.l = i;
      qe.push(e);
      i = q;
    }
    char z;
    int k, fk;
    while (!qe.empty()) {
      e = qe.top();
      qe.pop();
      if (e.k == 1) break;
      if (bj[find(e.l)]) continue;
      k = find(e.l);
      bj[k] = 1;
      printf("%c", a[k]);
      z = a[k];
      fk = from[k];
      while (a[nt[k]] == z) {
        printf(" %d", k + 1);
        k = nt[k];
      }
      printf(" %d", k + 1);
      k = nt[k];
      puts("");
      from[k] = fk;
      nt[fk] = k;
      if (a[fk] == a[k]) {
        int r = find(k), l = find(fk);
        fa[r] = l;
        s[l] += s[r];
        e.k = s[l];
        e.l = l;
        qe.push(e);
      }
    }
  }
}
