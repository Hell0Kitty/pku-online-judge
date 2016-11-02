#include <cstdio>
using namespace std;
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <utility>
#include <functional>
#define N 55
#define eps 1e-8
#define equ(a, b) (fabs((a) - (b)) < eps)
#define gt(a, b) (!equ(a, b) && (a) > (b))
int h[N][N], len[N][N];
bool used[N][N];
int n, m, num, sr, sc, er, ec;
struct node {
  int r, c, h;
  bool operator<(const node &pos) const { return h > pos.h; }
} sta[105];
int bfs() {
  used[er][ec] = true;
  if (!used[sr][sc] || !used[er][ec]) return -1;
  queue<pair<int, int> > q;
  memset(len, -1, sizeof(len));
  len[sr][sc] = 0;
  q.push(make_pair<int, int>(sr, sc));
  while (!q.empty()) {
    pair<int, int> top = q.front();
    q.pop();
    if (top.first - 1 >= 0 && used[top.first - 1][top.second] &&
        len[top.first - 1][top.second] == -1) {
      len[top.first - 1][top.second] = len[top.first][top.second] + 1;
      q.push(make_pair<int, int>(top.first - 1, top.second));
    }
    if (top.first + 1 <= n && used[top.first + 1][top.second] &&
        len[top.first + 1][top.second] == -1) {
      len[top.first + 1][top.second] = len[top.first][top.second] + 1;
      q.push(make_pair<int, int>(top.first + 1, top.second));
    }
    if (top.second - 1 >= 0 && used[top.first][top.second - 1] &&
        len[top.first][top.second - 1] == -1) {
      len[top.first][top.second - 1] = len[top.first][top.second] + 1;
      q.push(make_pair<int, int>(top.first, top.second - 1));
    }
    if (top.second + 1 <= m && used[top.first][top.second + 1] &&
        len[top.first][top.second + 1] == -1) {
      len[top.first][top.second + 1] = len[top.first][top.second] + 1;
      q.push(make_pair<int, int>(top.first, top.second + 1));
    }
  }
  return len[er][ec] == -1 ? -1 : len[er][ec] * 10;
}
bool detect(int r, int c, int pos) {
  if (sta[pos].r == r || sta[pos].c == c) return true;
  double dr = 10 * (r - sta[pos].r), dc = 10 * (c - sta[pos].c),
         dh = -sta[pos].h;
  bool f1 = r > sta[pos].r, f2 = c > sta[pos].c;

  for (int i = f1 ? sta[pos].r + 1 : sta[pos].r - 1; f1 ? i <= r : i >= r;
       f1 ? i++ : i--) {
    double k = 10 * (i - sta[pos].r) / dr, nc = sta[pos].c * 10 + k * dc,
           nh = sta[pos].h + k * dh;
    int t1 = f1 ? i - 1 : i,
        t2 = f2 ? ceil(nc / 10 - eps) - 1 + eps : nc / 10 + eps;
    if (gt(h[t1][t2], nh)) return false;
  }
  for (int i = f2 ? sta[pos].c + 1 : sta[pos].c - 1; f2 ? i <= c : i >= c;
       f2 ? i++ : i--) {
    double k = 10 * (i - sta[pos].c) / dc, nr = sta[pos].r * 10 + k * dr,
           nh = sta[pos].h + k * dh;
    int t1 = f1 ? ceil(nr / 10 - eps) - 1 + eps : nr / 10 + eps,
        t2 = f2 ? i - 1 : i;
    if (gt(h[t1][t2], nh)) return false;
  }
  return true;
}
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%d", &h[i][j]);
    scanf("%d%d%d%d%d", &sr, &sc, &er, &ec, &num);
    for (int i = 0; i < num; i++)
      scanf("%d%d%d", &sta[i].r, &sta[i].c, &sta[i].h);
    sort(sta, sta + num);
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++) {
        used[i][j] = false;
        for (int k = 0; k < num && !used[i][j]; k++)
          if (detect(i, j, k)) used[i][j] = true;
      }

    printf("%d\n", bfs());
  }
  return 0;
}
