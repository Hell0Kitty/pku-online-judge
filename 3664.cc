#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 50005;

struct Cow {
  int a, b, num;
} cow[maxn];

bool cmp1(const Cow &a, const Cow &b) { return a.a > b.a; }

bool cmp2(const Cow &a, const Cow &b) { return a.b > b.b; }

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &cow[i].a, &cow[i].b);
    cow[i].num = i;
  }
  sort(cow, cow + n, cmp1);
  sort(cow, cow + k, cmp2);
  printf("%d\n", cow[0].num + 1);
  return 0;
}
