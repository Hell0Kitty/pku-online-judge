#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <fstream>
#include <utility>
#include <sstream>
#include <list>
#include <iomanip>
#include <functional>
#include <deque>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <complex>
#include <climits>
#include <cctype>
#include <cassert>
#include <bitset>
#include <limits>
#include <numeric>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

#define PI 3.1415926535
#define MS(x, r) memset(x, r, sizeof x)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define REP(i, start, end) for (int i = start; i >= end; i--)
#define FOREACH(it, x) for (it = (x.begin()); it != (x.end()); it++)
#define REPEACH(it, x) for (it = (x.end() - 1); it != (x.begin() - 1); it--)
#define SZ(x) ((int)x.size())
#define All(x) x.begin(), x.end()

struct point {
  int num;
  int x;
  int y;
};
int n;

string s;
point *l;
int ans_len, ans_b, ans_e;
char ans_d;

int cmp_x(const void *a, const void *b) {
  point *p1, *p2;
  p1 = (point *)a;
  p2 = (point *)b;
  if (p1->x != p2->x)
    return p1->x - p2->x;
  else
    return p1->y - p2->y;
}

void findShortcut(char d1, char d2) {
  int len, b, e, s, t;
  char d;

  s = 0;
  t = 1;
  while (s <= n) {
    while (t <= n && l[t].x == l[s].x) t++;
    if (t - s > 1) {
      while (s < t - 1) {
        if (abs(l[s].num - l[s + 1].num) > 1) {
          len = abs(l[s].y - l[s + 1].y);
          if (l[s].num < l[s + 1].num) {
            b = l[s].num;
            e = l[s + 1].num;
            if (l[s].y < l[s + 1].y)
              d = d1;
            else
              d = d2;
          } else {
            b = l[s + 1].num;
            e = l[s].num;
            if (l[s].y < l[s + 1].y)
              d = d2;
            else
              d = d1;
          }

          if (len < ans_len || (len == ans_len && b < ans_b) ||
              (len == ans_len && b == ans_b && e > ans_e)) {
            ans_len = len;
            ans_b = b;
            ans_e = e;
            ans_d = d;
          }
        }
        s++;
      }
    }
    s = t;
    t++;
  }
}

int main() {
  int i, x, y, temp, t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    l = new point[250001];

    l[0].num = 0;
    l[0].x = 0;
    l[0].y = 0;
    x = y = 0;

    for (i = 0; i < n; i++) {
      l[i + 1].num = i + 1;
      switch (s[i]) {
        case 'N':
          y++;
          break;
        case 'E':
          x++;
          break;
        case 'S':
          y--;
          break;
        case 'W':
          x--;
          break;
      }
      l[i + 1].x = x;
      l[i + 1].y = y;
    }

    ans_len = 250000;

    qsort(l, n + 1, sizeof(point), cmp_x);
    findShortcut('N', 'S');

    for (i = 0; i <= n; i++) {
      temp = l[i].x;
      l[i].x = l[i].y;
      l[i].y = temp;
    }
    qsort(l, n + 1, sizeof(point), cmp_x);
    findShortcut('E', 'W');

    printf("%d %d %d %c\n", ans_len, ans_b, ans_e, ans_d);
  }
  return 0;
}
