#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 101000
#define inf 0x3f3f3f3f
using namespace std;
struct Pool {
  long long w;
  int h, id;
  Pool(long long _w = 0, int _h = 0, int _id = 0) : w(_w), h(_h), id(_id) {}
} pool[N], stk[N];
int top, n;
long long ans[N], now;
int main() {
  //	freopen("test.in","r",stdin);
  int i, j, k;
  int temp = inf, id;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld%lld", &pool[i].w, &pool[i].h);
    pool[i].id = i;
    if (temp > pool[i].h) temp = pool[i].h, id = i;
  }
  stk[++top] = pool[id];
  stk[0].h = inf;
  int l = id, r = id, p;
  pool[0].h = pool[n + 1].h = inf;
  for (int rn = 1; rn <= n; rn++) {
    long long add = 0;
    if (pool[l - 1].h < pool[r + 1].h)
      p = --l;
    else
      p = ++r;

    while (pool[p].h > stk[top].h && top) {
      stk[top].w += add;
      ans[stk[top].id] = now + stk[top].w;
      now += stk[top].w * (min(pool[p].h, stk[top - 1].h) - stk[top].h);
      add = stk[top].w;
      top--;
    }

    pool[p].w += add;
    stk[++top] = pool[p];
  }
  for (i = 1; i <= n; i++) printf("%lld\n", ans[i]);
  return 0;
}
