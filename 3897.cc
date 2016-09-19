#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <cctype>
#define eps 0.000001  //注意精度
using namespace std;
struct node {
  int x, y;
  double step;
  bool operator<(const node &a) const { return step > a.step; }
} st, ed;

double dis;
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool vis[205][205];
char map[205][205];
double d[205][205];

double BFS(double p) {
  priority_queue<node> myque;
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) d[i][j] = 100000000;

  st.step = 0;
  myque.push(st);
  vis[st.x][st.y] = 1;

  while (!myque.empty()) {
    node t = myque.top();
    myque.pop();

    vis[t.x][t.y] = 1;
    if (t.x == ed.x && t.y == ed.y) {
      return t.step;  // p小了
    }

    for (int i = 0; i < 4; i++) {
      node now = t;
      now.x = t.x + dx[i];
      now.y = t.y + dy[i];

      if (map[now.x][now.y] == '#' || now.x < 1 || now.y < 1 || now.x > n ||
          now.y > m)
        continue;
      if (vis[now.x][now.y]) continue;

      if (i <= 1)
        now.step = t.step + p;
      else
        now.step = t.step + 1;
      if (d[now.x][now.y] > now.step)
        d[now.x][now.y] =
            now.step;  //走到当前点的距离要小于之前走过来的距离才能更新，没有dis的剪枝会超时
      else
        continue;

      myque.push(now);
    }
  }
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  int cnt = 0;
  while (T--) {
    memset(map, 0, sizeof map);
    n = 0;
    m = 0;
    dis = 0;
    ed.x = 0;
    ed.y = 0;
    st.x = 0;
    st.y = 0;
    scanf("%lf%d", &dis, &n);
    for (int i = 1; i <= n; i++) {
      getchar();
      gets(map[i] + 1);
    }
    m = strlen(map[1] + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (map[i][j] == 'S') {
          st.x = i;
          st.y = j;
        }
        if (map[i][j] == 'E') {
          ed.x = i;
          ed.y = j;
        }
        if (ed.x && ed.y && st.x && st.y) break;
      }
      if (ed.x && ed.y && st.x && st.y) break;
    }

    double left = 0;
    double right = 10.0;
    double mid = 0;
    while (right - left > eps) {
      mid = (left + right) / 2.0;
      if (BFS(mid) < dis + eps)
        left = mid;  // mid小了
      else
        right = mid;
    }
    printf("Case #%d: %.3f%%\n", ++cnt, mid * 100.0);
  }
}
