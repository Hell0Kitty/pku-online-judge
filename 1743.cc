#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define N 20004

int s[N], f[N];
int n, sa[N], height[N], rank[N], tmp[N], top[N];

void makesa() {
  int i, j, len, na;
  na = (n < 256 ? 256 : n);
  memset(top, 0, na * sizeof(int));
  for (i = 0; i < n; i++) top[rank[i] = s[i] & 0xff]++;
  for (i = 1; i < na; i++) top[i] += top[i - 1];
  for (i = 0; i < n; i++) sa[--top[rank[i]]] = i;
  for (len = 1; len < n; len <<= 1) {
    for (i = 0; i < n; i++) {
      j = sa[i] - len;
      if (j < 0) j += n;
      tmp[top[rank[j]]++] = j;
    }
    sa[tmp[top[0] = 0]] = j = 0;
    for (i = 1; i < n; i++) {
      if (rank[tmp[i]] != rank[tmp[i - 1]] ||
          rank[tmp[i] + len] != rank[tmp[i - 1] + len])
        top[++j] = i;
      sa[tmp[i]] = j;
    }
    memcpy(rank, sa, n * sizeof(int));
    memcpy(sa, tmp, n * sizeof(int));
    if (j >= n - 1) break;
  }
}

void lcp() {
  int i, j, k;
  for (j = rank[height[i = k = 0] = 0]; i < n - 1; i++, k++)
    while (k >= 0 && s[i] != s[sa[j - 1] + k])
      height[j] = (k--), j = rank[sa[j] + 1];
}

bool ok(int d) {
  int l = sa[0], r = sa[0];
  for (int i = 0; i < n; i++) {
    if (height[i] < d) {
      l = sa[i];
      r = sa[i];
      continue;
    }
    if (sa[i] < l) l = sa[i];
    if (sa[i] > r) r = sa[i];
    if (r - l > d) return true;
  }
  return false;
}

int binarysearch() {
  int l = 0;
  int r = n;
  while (l < r) {
    int mid = (l + r) / 2 + ((l + r) & 1);
    if (ok(mid))
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++) scanf("%d", &f[i]);
    for (int i = 0; i < n - 1; i++) s[i] = f[i + 1] - f[i];
    makesa();
    lcp();
    int ans = binarysearch();
    if (ans >= 4)
      printf("%d\n", ans + 1);
    else
      printf("0\n");
  }
  return 0;
}