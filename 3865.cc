#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
struct Node {
  char s[90];
  int r, c;
} p[100005];
char s[20000], t[290];
int n, m, id;
void gao(int a) {
  int len = strlen(s), last = 0, fi = 0;
  for (int i = 0; i <= len; i++)
    if (i == len || s[i] == ',') {
      int sz = 0;
      for (int j = last; j < i; j++) t[sz++] = s[j];
      t[sz] = '\0';
      strcpy(p[id].s, t);
      p[id].r = a;
      p[id++].c = fi++;
      last = i + 1;
    }
}
bool cmp(const Node &p1, const Node &p2) { return strcmp(p1.s, p2.s) < 0; }
int rk[21005][11], c1, c2, g[20010];
bool cmp2(const int &a, const int &b) {
  if (rk[a][c1] != rk[b][c1]) return rk[a][c1] < rk[b][c1];
  return rk[a][c2] < rk[b][c2];
}
int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    getchar();
    id = 0;
    for (int i = 0; i < n; i++) {
      gets(s);
      gao(i);
    }
    sort(p, p + id, cmp);
    int M = 1;
    rk[p[0].r][p[0].c] = 1;
    for (int i = 1; i < id; i++)
      if (strcmp(p[i].s, p[i - 1].s) != 0)
        rk[p[i].r][p[i].c] = ++M;
      else
        rk[p[i].r][p[i].c] = M;
    for (int i = 0; i < n; i++) g[i] = i;
    bool ans = 1;
    for (c1 = 0; c1 < m && ans; c1++)
      for (c2 = c1 + 1; c2 < m; c2++) {
        sort(g, g + n, cmp2);
        for (int i = 1; i < n; i++)
          if (rk[g[i]][c1] == rk[g[i - 1]][c1] &&
              rk[g[i]][c2] == rk[g[i - 1]][c2]) {
            printf("NO\n%d %d\n%d %d\n", g[i] + 1, g[i - 1] + 1, c1 + 1,
                   c2 + 1);
            ans = 0;
            break;
          }
      }
    if (ans) puts("YES");
  }
  return 0;
}
