#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define maxn 100005

bool is[maxn];
long long prm[maxn];
int n, a, b, m, p, q;

int getprm(int n) {
  int i, j, k = 0;
  int s, e = (int)(sqrt(0.0 + n) + 1);
  memset(is, 1, sizeof(is));
  prm[k++] = 2;
  is[0] = is[1] = 0;
  for (i = 4; i < n; i += 2) is[i] = 0;
  for (i = 3; i < e; i += 2)
    if (is[i]) {
      prm[k++] = i;
      for (s = i * 2, j = i * i; j < n; j += s) is[j] = 0;
    }
  for (; i < n; i += 2)
    if (is[i]) prm[k++] = i;
  return k;
}

int binarysearch() {
  int l = 0;
  int r = n;
  while (l < r) {
    int mid = (l + r) / 2 + ((l + r) & 1);
    if (((long long)prm[mid]) * prm[mid] <= m)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

void work(int l, int r) {
  int ans = prm[l] * prm[r];
  q = p = prm[l];
  while (l >= 0) {
    if (prm[l] * b < a * prm[r]) break;
    while (r < n - 1 && prm[l] * b >= a * prm[r + 1] &&
           prm[l] * prm[r + 1] <= m)
      r++;
    if (ans < prm[l] * prm[r]) {
      p = prm[l];
      q = prm[r];
      ans = prm[l] * prm[r];
    }
    l--;
  }
  printf("%d %d\n", p, q);
}

int main() {
  n = getprm(maxn - 1);
  while (scanf("%d%d%d", &m, &a, &b), m | a | b) {
    int l, r;
    l = r = binarysearch();
    work(l, r);
  }
  return 0;
}
