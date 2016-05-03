#include <iostream>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct point {
  int x, y;
};
int g[101][101][5], cas, n, m, k, x1[1010], x2[1010], y1[1010], y2[1010];
int a[101][101], b[101][101], x, y;
bool ans, v[101][101];
string s;
void bfs1(int x, int y) {
  int c, d, cc, dd, key;
  point tmp;
  queue<point> q;
  while (!q.empty()) q.pop();
  a[x][y] = 0;
  tmp.x = x;
  tmp.y = y;
  q.push(tmp);
  while (!q.empty()) {
    cc = q.front().x;
    dd = q.front().y;
    key = a[cc][dd];
    q.pop();
    for (int k = 0; k < 4; k++) {
      c = cc;
      d = dd;
      if (g[c][d][k]) {
        if (k == 0) c++;
        if (k == 1) d++;
        if (k == 2) c--;
        if (k == 3) d--;
        if (a[c][d] == -1) {
          a[c][d] = key + 1;
          tmp.x = c;
          tmp.y = d;
          q.push(tmp);
        }
      }
    }
  }
}
void bfs2(int x, int y) {
  int c, d, cc, dd, key;
  point tmp;
  queue<point> q;
  while (!q.empty()) q.pop();
  b[x][y] = 0;
  tmp.x = x;
  tmp.y = y;
  q.push(tmp);
  while (!q.empty()) {
    cc = q.front().x;
    dd = q.front().y;
    key = b[cc][dd];
    q.pop();
    for (int k = 0; k < 4; k++) {
      c = cc;
      d = dd;
      if (g[c][d][k]) {
        if (k == 0) c++;
        if (k == 1) d++;
        if (k == 2) c--;
        if (k == 3) d--;
        if (b[c][d] == -1) {
          b[c][d] = key + 1;
          tmp.x = c;
          tmp.y = d;
          q.push(tmp);
        }
      }
    }
  }
}
int main() {
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d%d", &n, &m);
    cin >> s;
    memset(g, 1, sizeof(g));
    for (int i = 0; i < n; i++) g[i][0][3] = g[i][m - 1][1] = 0;
    for (int i = 0; i < m; i++) g[0][i][2] = g[n - 1][i][0] = 0;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
      scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
      if (x1[i] == x2[i]) {
        if (y1[i] < y2[i]) {
          g[x1[i]][y1[i]][1] = 0;
          g[x2[i]][y2[i]][3] = 0;
        } else {
          g[x1[i]][y1[i]][3] = 0;
          g[x2[i]][y2[i]][1] = 0;
        }
      } else {
        if (x1[i] < x2[i]) {
          g[x1[i]][y1[i]][0] = 0;
          g[x2[i]][y2[i]][2] = 0;
        } else {
          g[x1[i]][y1[i]][2] = 0;
          g[x2[i]][y2[i]][0] = 0;
        }
      }
    }
    memset(v, 0, sizeof(v));
    x = 0;
    y = 0;
    v[x][y] = 1;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'R') x++;
      if (s[i] == 'L') x--;
      if (s[i] == 'U') y++;
      if (s[i] == 'D') y--;
      v[x][y] = 1;
    }
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));
    bfs1(0, 0);
    bfs2(x, y);
    ans = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (v[i][j] == 0 && a[i][j] + b[i][j] == s.length()) ans = false;
    if (ans) {
      for (int i = 1; i <= k; i++)
        if (a[x1[i]][y1[i]] + b[x2[i]][y2[i]] > s.length() &&
            a[x2[i]][y2[i]] + b[x1[i]][y1[i]] > s.length()) {
          ans = false;
          break;
        }
    }
    for (int j = m - 1; j >= 0; j--)  //全围起来！！
      for (int i = 0; i < n; i++)
        if (a[i][j] == -1) {
          ans = false;
          break;
        }

    if (ans)
      printf("CORRECT\n");
    else
      printf("INCORRECT\n");
  }
  return 0;
}
