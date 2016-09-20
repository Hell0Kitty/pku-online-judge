#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#define inf 1 << 30
using namespace std;
struct point {
  int x, y;
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}
} pos[11], s;
int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char str[9][10];
int x, y, n, sum, ret, dp[60000], p[15];
map<int, int> mm;
bool vis[9][9];
void dfs(int x, int y) {
  if (vis[x][y]) return;
  vis[x][y] = 1;
  sum++;
  for (int i = 0; i < 4; i++) {
    int a = x + move[i][0];
    int b = y + move[i][1];
    if (a >= 0 && a < n && b >= 0 && b < n && !vis[a][b] &&
        str[x][y] == str[a][b])
      dfs(a, b);
  }
}
int get_score() {
  memset(vis, 0, sizeof(vis));
  int t1 = 0, t2 = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (!vis[i][j]) {
        sum = 0;
        dfs(i, j);
        if (str[i][j] == '0')
          t1 = max(t1, sum);
        else
          t2 = max(t2, sum);
      }
    }
  return t1 - t2;
}
int minimax(int, int, int, int);
int maxmini(int state, int now, int d, int mi) {
  if (!state) return get_score();
  if (dp[now] != -inf) return dp[now];
  int ma = -inf, st = state, k, j;
  while (st) {       //枚举所有的1的情况，也就是'.'的情况
    k = st & (-st);  // 找到st倒数第一个1
    j = mm[k];       // 1的位置
    str[pos[j].x][pos[j].y] = '0';
    int t = minimax(state - k, now + p[j], d + 1, ma);
    str[pos[j].x][pos[j].y] = '.';
    ma = max(ma, t);
    if (ma >= mi) return ma;
    if (d == 0) {  //更新结果
      if (ret < ma || (ret == ma && (s.x > pos[j].x ||
                                     (s.x == pos[j].x && s.y > pos[j].y)))) {
        s = pos[j];
        ret = ma;
      }
    }
    st -= k;  //继续枚举下一个1
  }
  return dp[now] = ma;
}
int minimax(int state, int now, int d, int ma) {
  if (!state) return get_score();
  if (dp[now] != -inf) return dp[now];
  int mi = inf, k, st = state, j;
  while (st) {
    k = st & (-st);
    j = mm[k];
    str[pos[j].x][pos[j].y] = '1';
    int t = maxmini(state - k, now + 2 * p[j], d + 1, mi);
    str[pos[j].x][pos[j].y] = '.';
    mi = min(mi, t);
    if (mi <= ma) return mi;
    st -= k;
  }
  return dp[now] = mi;
}
int main() {
  //    freopen("1.txt","r",stdin);
  p[0] = 1;
  for (int i = 1; i <= 10; i++) p[i] = 3 * p[i - 1];
  for (int i = 0; i <= 11; i++) mm[(1 << i)] = i;
  while (scanf("%d", &n) && n) {
    int c1 = 0, c2 = 0, num = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", str[i]);
      for (int j = 0; j < n; j++) {
        if (str[i][j] == '0')
          c1++;
        else if (str[i][j] == '1')
          c2++;
        else
          pos[num++] = point(i, j);
      }
    }
    if (c1 > c2) {  //始终让0先走
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
          if (str[i][j] == '0')
            str[i][j] = '1';
          else if (str[i][j] == '1')
            str[i][j] = '0';
        }
    }
    for (int i = 0; i < p[num]; i++) dp[i] = -inf;
    ret = -inf;
    maxmini((1 << num) - 1, 0, 0, inf);
    printf("(%d,%d) %d\n", s.x, s.y, ret);
  }
  return 0;
}
