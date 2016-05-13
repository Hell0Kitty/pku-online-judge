#include <stdio.h>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 1000002
struct node {
  int x, y;
  int dis;
} base[10005], st, end;
int n, m;
int maps[1005][1005];
bool vis[1005][1005];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
struct que {
  struct node t[N];
  int head, tail;
  void init() { head = tail = 0; }
  bool empty() { return head == tail; }
  struct node top() {
    return t[head];
  }
  void push(struct node a) {
    t[tail] = a;
    tail++;
    if (tail >= N) tail -= N;
  }
  void pop() {
    head++;
    if (head >= N) head -= N;
  }
} q;
int maxn;
int leng;
bool isok(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void debug_map() {
  for (int i = 0; i < n; i++, puts(""))
    for (int j = 0; j < m; j++) printf("%3d", maps[i][j]);
}
void bfs() {
  node tt, tmp;
  while (!q.empty()) {
    tmp = q.top();
    for (int d = 0; d < 4; d++) {
      tt.x = tmp.x + dx[d];
      tt.y = tmp.y + dy[d];
      tt.dis = tmp.dis + 1;
      if (isok(tt.x, tt.y) && maps[tt.x][tt.y] == -1) {
        maps[tt.x][tt.y] = tt.dis;
        maxn = max(maxn, tt.dis);
        q.push(tt);
      }
    }
    q.pop();
  }
}
bool cal(int lim) {
  if (maps[st.x][st.y] < lim) return false;
  q.init();
  q.push(st);
  node tmp, tt;
  for (int i = 0; i <= n; i++) memset(vis[i], false, sizeof(bool) * (m + 1));

  while (!q.empty()) {
    tmp = q.top();
    for (int d = 0; d < 4; d++) {
      tt.x = tmp.x + dx[d];
      tt.y = tmp.y + dy[d];
      tt.dis = tmp.dis + 1;
      if (isok(tt.x, tt.y) && maps[tt.x][tt.y] >= lim && !vis[tt.x][tt.y]) {
        vis[tt.x][tt.y] = true;
        if (tt.x == end.x && tt.y == end.y) {
          leng = tt.dis;
          return true;
        }
        q.push(tt);
      }
    }
    q.pop();
  }
  return false;
}
int main() {
  int cas;
  scanf("%d", &cas);
  st.dis = 0;
  int tt;
  while (cas--) {
    q.init();
    maxn = 0;
    scanf("%d%d%d", &tt, &n, &m);
    scanf("%d%d%d%d", &st.x, &st.y, &end.x, &end.y);

    for (int i = 0; i < n; i++) memset(maps[i], -1, sizeof(int) * (m + 1));
    node t;
    t.dis = 0;
    for (int i = 0; i < tt; i++) {
      scanf("%d%d", &base[i].x, &base[i].y);
      maps[base[i].x][base[i].y] = 0;

      t.x = base[i].x;
      t.y = base[i].y;

      q.push(t);
    }
    bfs();
    int l = 0, r = n + m;
    int mid;
    int ans = 0;
    while (l <= r) {
      mid = (l + r) / 2;
      if (cal(mid)) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    printf("%d %d\n", ans, leng);
  }
  return 0;
}
