#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define MAXN 50000
char s[MAXN];
int rank[MAXN], sa[MAXN], wa[MAXN], wb[MAXN], high[MAXN], str[MAXN], wss[MAXN],
    wv[MAXN];
int n, m;

void calhigh(int *str, int *sa, int n) {
  int i, j, k = 0;
  for (i = 1; i <= n; i++) rank[sa[i]] = i;
  for (i = 0; i < n; high[rank[i++]] = k)
    for (k ? k-- : 0, j = sa[rank[i] - 1]; str[i + k] == str[j + k]; k++)
      ;
}

bool cmp(int *r, int a, int b, int l) {
  return (r[a] == r[b] && r[a + l] == r[b + l]);
}

void suffix(int *str, int *sa, int n, int m = 256) {
  int i, j, p, *x = wa, *y = wb;
  for (i = 0; i < m; i++) wss[i] = 0;
  for (i = 0; i < n; i++) wss[x[i] = str[i]]++;
  for (i = 1; i < m; i++) wss[i] += wss[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--wss[x[i]]] = i;
  for (j = 1, p = 1; p < n; m = p, j *= 2) {
    p = 0;
    for (i = n - j; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < n; i++) wv[i] = x[y[i]];
    for (i = 0; i < m; i++) wss[i] = 0;
    for (i = 0; i < n; i++) wss[wv[i]]++;
    for (i = 1; i < m; i++) wss[i] += wss[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--wss[wv[i]]] = y[i];
    for (swap(x, y), x[sa[0]] = 0, i = 1, p = 1; i < n; i++)
      x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
  }
  calhigh(str, sa, n - 1);
}

int check(int lth) {
  int cnt = 0, st = -1, tst = -1;
  for (int i = 2; i <= n; i++) {
    if (high[i] < lth) {
      if (cnt >= m - 1) {
        st = max(st, tst);
        tst = -1;
        cnt = 0;
      } else {
        cnt = 0;
        tst = -1;
      }
    } else {
      cnt++;
      tst = max(tst, max(sa[i - 1], sa[i]));
    }
  }
  if (cnt >= m - 1) st = max(st, tst);
  return st;
}

int main() {
  while (~scanf("%d", &m) && m) {
    scanf("%s", s);
    n = strlen(s);
    if (m == 1) {
      printf("%d 0\n", n);
      continue;
    }
    for (int i = 0; i < n; i++) str[i] = s[i];
    str[n] = 0;
    suffix(str, sa, n + 1);
    int ed, maxs = 0, tmp;
    int l = 0, r = n, mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if ((tmp = check(mid)) != -1) {
        l = mid + 1;
        maxs = mid;
        ed = tmp;
      } else
        r = mid;
    }
    if (maxs == 0)
      printf("none\n");
    else
      printf("%d %d\n", maxs, ed);
  }
  return 0;
}
