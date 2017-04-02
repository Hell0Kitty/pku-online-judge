#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 10005

struct Interval {
  int s, e;
} interval[maxn];

int n, ar[maxn];

bool operator<(const Interval &a, const Interval &b) {
  if (a.e == b.e) return a.s < b.s;
  return a.e < b.e;
}

int lowb(int t) { return t & (-t); }

void add(int i, int v) {
  for (; i < maxn; ar[i] += v, i += lowb(i))
    ;
}

int sum(int i) {
  int s = 0;
  for (; i > 0; s += ar[i], i -= lowb(i))
    ;
  return s;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &interval[i].s, &interval[i].e);
    interval[i].s++;
    interval[i].e++;
  }
  sort(interval, interval + n);
  for (int i = 0; i < n; i++) {
    int num = sum(interval[i].e) - sum(interval[i].s - 1);
    // cout << interval[i].e << " " << num << endl;
    for (int j = 0; j < 2 - num; j++) add(interval[i].e - j, 1);
  }
  printf("%d\n", sum(interval[n - 1].e));
  return 0;
}
