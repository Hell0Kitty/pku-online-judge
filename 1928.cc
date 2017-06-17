#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 55

struct Peanut {
  int x, y, num;
} peanut[maxn * maxn];

int n, m, t, pcount;

bool operator<(const Peanut &a, const Peanut &b) { return a.num > b.num; }

void input() {
  pcount = 0;
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int a;
      scanf("%d", &a);
      if (a) {
        peanut[pcount].x = i + 1;
        peanut[pcount].y = j + 1;
        peanut[pcount].num = a;
        pcount++;
      }
    }
}

void work() {
  int nowtime = peanut[0].x + 1;
  if (nowtime + peanut[0].x > t) {
    printf("0\n");
    return;
  }
  int ans = peanut[0].num;
  for (int i = 1; i < pcount; i++) {
    nowtime += abs(peanut[i].x - peanut[i - 1].x) +
               abs(peanut[i].y - peanut[i - 1].y) + 1;
    if (nowtime + peanut[i].x > t) break;
    ans += peanut[i].num;
  }
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    sort(peanut, peanut + pcount);
    work();
  }
  return 0;
}
