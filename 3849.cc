#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define clr(x, a) memset(x, a, sizeof(x));
const int maxn = 1000;
const int inf = 1012345678;
int rd() {
  int x;
  scanf("%d", &x);
  return x;
}
int dir[6][2] = {{-1, -1}, {0, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0}};
int mx = 300, my = 300;
int g[maxn][maxn], a[maxn][maxn], ans[100000];
struct node {
  int x, y;
  node() {}
  node(int aa, int bb) {
    x = aa;
    y = bb;
  }
} to[100000];
int b[10], vis[10];
void add(int& i, int& x, int& y, int num) {
  i++;
  x += dir[num][0];
  y += dir[num][1];
  g[x][y] = i;
  to[i] = node(x, y);
}
void init() {
  int num, i, j, k, x, y, nx, ny;
  x = mx, y = my;
  k = 0;
  num = 5;
  i = 1;
  j = 0, k = 1;
  g[x][y] = i;
  to[i] = node(mx, my);
  while (i <= 10001) {
    if (num == 5) {
      if (j == 0) {
        add(i, x, y, num);
        num = 0;
        k++;
        j = k - 2;
      } else {
        j--;
        add(i, x, y, num);
      }
    } else {
      if (j == 0) {
        num++;
        j = k - 1;
      } else {
        j--;
        add(i, x, y, num);
      }
    }
  }
  clr(a, 0);
  clr(b, 0);
  for (i = 1; i <= 10000; i++) {
    int now = inf, id = 0;
    clr(vis, 0);
    x = to[i].x, y = to[i].y;
    for (j = 0; j < 6; j++) {
      nx = x + dir[j][0];
      ny = y + dir[j][1];
      vis[a[nx][ny]] = 1;
    }
    for (j = 1; j <= 5; j++) {
      if (!vis[j] && b[j] < now) {
        now = b[j];
        id = j;
      }
    }
    ans[i] = id;
    a[x][y] = id;
    b[id]++;
  }
}
int main() {
  int i, j, k;
  init();
  int n;
  n = rd();
  for (i = 0; i < n; i++) {
    j = rd();
    printf("%d\n", ans[j]);
  }
}
