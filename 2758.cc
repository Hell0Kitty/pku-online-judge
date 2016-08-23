#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <queue>

#define MAXN (200000 + 5000)
#define MAXL (40 + 10)

#define mmst(a, b) memset(a, b, sizeof(a))
#define mmcya(a, b) memcpy(a, b, sizeof(a))
#define mmcyb(a, b) memcpy(a, b, sizeof(b))

using namespace std;

int n, m, Q;

int wa[MAXN], wb[MAXN], wv[MAXN], Ws[MAXN];

int sa[MAXN], rk[MAXN], ht[MAXN], rmq[MAXL][MAXN];

char s[MAXN];

inline bool cmp(int* r, int a, int b, int l) {
  return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int* sa, char* r, int n, int m) {
  int i, j, p, * x = wa, * y = wb;
  for (i = 0; i < m; i++) Ws[i] = 0;
  for (i = 0; i < n; i++) Ws[x[i] = r[i]]++;
  for (i = 1; i < m; i++) Ws[i] += Ws[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--Ws[x[i]]] = i;
  for (j = p = 1; p < n; j <<= 1, m = p) {
    for (p = 0, i = n - j; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < n; i++) wv[i] = x[y[i]];
    for (i = 0; i < m; i++) Ws[i] = 0;
    for (i = 0; i < n; i++) Ws[wv[i]]++;
    for (i = 1; i < m; i++) Ws[i] += Ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--Ws[wv[i]]] = y[i];
    for (swap(x, y), i = p = 1, x[sa[0]] = 0; i < n; i++)
      x[sa[i]] = cmp(y, sa[i], sa[i - 1], j) ? p - 1 : p++;
  }
}

void calcht(int* ht, int* sa, int* rk, char* r, int n) {
  int i, j;
  for (i = 0; i < n; i++) rk[sa[i]] = i;
  ht[0] = ht[n] = 0;
  for (i = j = 0; i < n; i++) {
    if (rk[i] == 0) continue;
    for (j = max(j - 1, 0); r[i + j] == r[sa[rk[i] - 1] + j]; j++)
      ;
    ht[rk[i]] = j;
  }
}

void calcrmq(int rmq[][MAXN], int* ht, int n) {
  int i, j;
  for (i = 1; i < n; i++) rmq[0][i] = ht[i];
  for (j = 1; (1 << j) < n; j++) {
    for (i = 1; i < n; i++) {
      rmq[j][i] = rmq[j - 1][i];
      if (i + (1 << (j - 1)) < n)
        rmq[j][i] = min(rmq[j][i], rmq[j - 1][i + (1 << (j - 1))]);
    }
  }
}

int AskRMQ(int rmq[][MAXN], int x, int y) {
  if (x > y) swap(x, y);
  int L = (int)floor(log((double)y - x) / log(2.0));
  return min(rmq[L][x + 1], rmq[L][y - (1 << L) + 1]);
}

void Init() {
  scanf("%s", s);
  scanf("%d\n", &Q);
  n = strlen(s);
  s[n++] = 0;
  da(sa, s, n, MAXN);
  calcht(ht, sa, rk, s, n);
  calcrmq(rmq, ht, n + 1);
}

struct BREAK {
  int p;
  char c;
} br[MAXN];

void Solve() {
  int i, j, p, q;
  m = 0;
  br[m++].p = 0;
  br[m++].p = n;
  for (; Q--;) {
    char ch;
    scanf("%c ", &ch);
    if (ch == 'I') {
      scanf("%c%d\n", &ch, &p);
      if (p > n + m - 2) p = n + m - 1;
      p--;
      for (i = 0; i < m; i++)
        if (br[i].p + i - 1 >= p) break;
      for (j = m; j > i; j--) swap(br[j], br[j - 1]);
      m++;
      br[i].c = ch;
      br[i].p = p - (i - 1);
    } else {
      scanf("%d%d\n", &p, &q);
      p--;
      q--;
      int s1, s2, t1, t2;
      for (s1 = 0; s1 < m; s1++)
        if (br[s1].p > p) break;
      for (s2 = 0; s2 < m; s2++)
        if (br[s2].p > q) break;
      if (p == q) {
        printf("%d\n", (n + m - 3) - (s1 + p - 1));
        continue;
      }
      int Ans = 0;
      for (; s1 < m || s2 < m;) {
        t1 = br[s1].p - p;
        t2 = br[s2].p - q;
        int L = AskRMQ(rmq, rk[p], rk[q]);
        if (t1 <= L || t2 <= L) {
          if (t1 < t2) {
            Ans += t1;
            p += t1;
            q += t1;
            if (br[s1].c == s[q])
              q++, Ans++;
            else
              break;
            s1++;
          } else if (t1 > t2) {
            Ans += t2;
            p += t2;
            q += t2;
            if (br[s2].c == s[p])
              p++, Ans++;
            else
              break;
            s2++;
          } else if (t1 == t2) {
            Ans += t1;
            p += t1;
            q += t1;
            if (br[s1].c == br[s2].c)
              Ans++;
            else
              break;
            s1++;
            s2++;
          }
        } else {
          Ans += L;
          break;
        }
      }
      printf("%d\n", Ans);
    }
  }
}

int main() {
  Init();
  Solve();
  return 0;
}
