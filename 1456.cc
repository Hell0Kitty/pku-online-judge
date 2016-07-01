#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 10005

struct Product {
  int p, d;
} prod[maxn];

int n;
int father[maxn];

bool operator<(const Product &a, const Product &b) { return a.p > b.p; }

int getanc(int a) {
  if (a < 0) return a;
  if (a == father[a]) return a;
  return father[a] = getanc(father[a]);
}

bool ins(Product &a) {
  int temp = getanc(a.d - 1);
  if (temp >= 0) {
    father[temp] = getanc(temp - 1);
    return true;
  }
  return false;
}

int main() {
  while (scanf("%d", &n) != EOF) {
    int t = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &prod[i].p, &prod[i].d);
      if (t < prod[i].d) t = prod[i].d;
    }
    sort(prod, prod + n);
    for (int i = 0; i < t; i++) father[i] = i;
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (ins(prod[i])) ans += prod[i].p;
    printf("%d\n", ans);
  }
  return 0;
}
