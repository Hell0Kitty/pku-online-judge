#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int Minstring(char *s, int n) {
  int i, j, x, y, u, v;
  for (x = 0, y = 1; y < n; y++)
    if (s[y] <= s[x]) {
      i = u = x;
      j = v = y;
      while (s[i] == s[j]) {
        ++u;
        if (++i == n) j = 0;
        ++v;
        if (++j == n) j = 0;
        if (i == x) break;
      }
      if (s[i] <= s[j])
        y = v;
      else {
        x = y;
        if (u > y) y = u;
      }
    }
  return x;
}

char s[111];

int nbs[111], eu[5555], next[5555], ev[5555], now;

void add(int u, int v) {
  ++now;
  eu[now] = u;
  next[now] = nbs[u];
  nbs[u] = now;
  ev[now] = v;
}

int pre[111];

void dfs(int u) {
  int i, v, j;
  for (i = nbs[u]; i; i = next[i]) {
    v = ev[i];
    if (u == 0) {
      pre[v] = u;
      dfs(v);
    } else {
      char t[101];
      int l = 0;
      string x1, x2;
      for (j = pre[u]; j < u; j++) t[l++] = s[j], x1 += s[j];
      for (j = u; j < v; j++) t[l++] = s[j], x2 += s[j];
      t[l] = '\n';
      if (x1 > x2 && Minstring(t, l)) {
        pre[v] = u;
        dfs(v);
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int cnt1 = 0, cnt2 = 0;
    // cout<<s<<endl;
    memset(nbs, 0, sizeof(nbs));
    now = 0;
    int i, j, k, len = strlen(s);
    for (i = 0; i < len; i++) {
      if (s[i] == '0')
        cnt1++;
      else
        cnt2++;
    }
    if (cnt1 == len || cnt2 == len) {
      printf("(%s)\n", s);
      continue;
    }
    for (i = 0; i < len; i++) {
      char t[111];
      int l = 0;
      for (j = i; j < len; j++) {
        t[l++] = s[j];
        t[l] = '\0';
        int pos = Minstring(t, l);
        if (pos == 0) {
          add(i, j + 1);
          // printf("%d %d\n",i,j);
        }
      }
    }
    dfs(0);
    int stk[111], tot = 0;
    k = len;
    while (k) {
      // printf("%d  ",k);
      stk[++tot] = k;
      k = pre[k];
    }

    printf("(");

    j = tot;
    for (i = 0; i < len; i++) {
      if (i == stk[j]) {
        printf(")(");
        j--;
      }
      printf("%c", s[i]);
    }
    printf(")\n");
  }
  return 0;
}
