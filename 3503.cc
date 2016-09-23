#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
#pragma comment(linker, "/STACK:102400000,102400000")

using std::priority_queue;
using std::vector;
using std::swap;
using std::stack;
using std::sort;
using std::max;
using std::min;
using std::pair;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::set;
using std::queue;
using std::string;
using std::istringstream;
using std::make_pair;
using std::getline;
using std::greater;
using std::endl;
using std::multimap;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PAIR;
typedef multimap<int, int> MMAP;

const int MAXN(510);
const int SIGMA_SIZE(82);
const int MAXM(110);
const int MAXE(200010);
const int MAXH(18);
const int INFI((INT_MAX - 1) >> 2);
const int BASE(131);
const int MOD(20071027);
const ULL LIM(1000000000000000ull);

struct NODE {
  int x, y, hei;
  friend bool operator<(const NODE &op1, const NODE &op2) {
    return op1.hei < op2.hei;
  }
};

int mp[MAXN][MAXN];
int vis[MAXN][MAXN];

int m_x[4] = {0, -1, 0, 1};
int m_y[4] = {-1, 0, 1, 0};

int ch, lim, count;
int h, w, d;
int qx[MAXN * MAXN], qy[MAXN * MAXN];
int front, back;
NODE arr[MAXN * MAXN];
int ind;

bool bfs(int cx, int cy) {
  front = back = 0;
  qx[back] = cx;
  qy[back++] = cy;
  vis[cx][cy] = ch;
  ++count;
  int tx, ty;
  bool ret(true);
  while (front < back) {
    cx = qx[front], cy = qy[front++];
    for (int i = 0; i < 4; ++i) {
      tx = cx + m_x[i];
      ty = cy + m_y[i];
      if (tx >= 1 && tx <= h && ty >= 1 && ty <= w) {
        if (mp[tx][ty] <= lim) continue;
        if (vis[tx][ty] > ch) {
          ret = false;
          continue;
        }
        if (vis[tx][ty] == ch) continue;
        if (mp[tx][ty] == ch) ++count;
        vis[tx][ty] = ch;
        qx[back] = tx;
        qy[back++] = ty;
      }
    }
  }
  return ret;
}

void solve() {
  int ans = 0;
  sort(arr, arr + ind);
  memset(vis, -1, sizeof(vis[0]) * (h + 1));
  for (int i = ind - 1; i >= 0; --i)
    if (vis[arr[i].x][arr[i].y] == -1) {
      ch = arr[i].hei;
      lim = ch - d;
      count = 0;
      if (bfs(arr[i].x, arr[i].y)) ans += count;
    }
  printf("%d\n", ans);
}

int main() {
  int TC;
  scanf("%d", &TC);
  while (TC--) {
    ind = 0;
    scanf("%d%d%d", &h, &w, &d);
    for (int i = 1; i <= h; ++i)
      for (int j = 1; j <= w; ++j) {
        scanf("%d", mp[i] + j);
        arr[ind].x = i;
        arr[ind].y = j;
        arr[ind++].hei = mp[i][j];
      }
    solve();
  }
  return 0;
}
