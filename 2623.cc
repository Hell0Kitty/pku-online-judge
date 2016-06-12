#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <utility>
#include <cstring>
#include <list>
#include <stack>
#include <cstdio>
using namespace std;

#define ft first
#define sd second

typedef long long LL;
typedef unsigned int UI;

const int MAXN = 511111;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const LL MAXL = (0x7fffffffffffffffLL);
const int MAXI = 0x7fffffff;

long long a[1111111];

int partition(int l, int r) {
  int i = rand() % (r - l + 1) + l;
  swap(a[l], a[i]);
  int s = l, e = r;
  LL pivot = a[l];
  while (s < e) {
    while (s < e && a[e] > pivot) e--;
    if (s < e) a[s++] = a[e];
    while (s < e && a[s] < pivot) s++;
    if (s < e) a[e--] = a[s];
  }
  a[s] = pivot;
  return s;
}

LL solve(int l, int r, int k) {
  int p = partition(l, r);

  if (p == k) {
    return a[p];
  }

  if (k > r || k < 0) {
    return -1;
  }

  if (k < p) {
    return solve(l, p - 1, k);
  }

  if (k > p) {
    return solve(p + 1, r, k);
  }
  return 0;
}

int main() {
  int n, k;
  while (cin >> n) {
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    if (n & 1)
      printf("%.1f\n", a[(n + 1) / 2] * 1.0);
    else
      printf("%.1f\n", (a[n / 2] * 1.0 + a[n / 2 + 1] * 1.0) / 2);
  }
}
