#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
struct self {
  int x, y, side;
} s[10001];
int m, n, a, b, c;
double ans, z;
int side = -1;
int baizong, heizong, num;
int l[2], r[2];
int x, y;
void tongji() {
  if (l[0] > r[0] && l[1] > r[1]) {
    double k = min((double)l[0] / (m / 2 * n), (double)l[1] / (m / 2 * n));
    if (k > ans) {
      ans = k;
      side = 0;
    }
  }
  if (l[0] < r[0] && l[1] < r[1]) {
    double k = min((double)r[0] / (m / 2 * n), (double)r[1] / (m / 2 * n));
    if (k > ans) {
      ans = k;
      side = 1;
    }
  }
}

void exchange(int x, int y) {
  l[0] -= s[x].x;
  r[0] -= s[x].y;
  l[1] += s[x].x;
  r[1] += s[x].y;
  s[x].side = 1;

  l[1] -= s[y].x;
  r[1] -= s[y].y;
  l[0] += s[y].x;
  r[0] += s[y].y;
  s[y].side = 0;
}

int main() {
  srand(time(NULL));
  while (scanf("%d", &m) == 1) {
    scanf("%d", &n);
    num = 0;
    ans = 0;
    baizong = 0;
    heizong = 0;
    side = -1;
    l[0] = r[0] = l[1] = r[1] = 0;
    for (a = 1; a <= m; a++) {
      scanf("%d%d", &s[a].x, &s[a].y);
      baizong += s[a].x;
      heizong += s[a].y;
    }
    if (baizong > heizong)
      side = 0;
    else
      side = 1;

    for (a = 1; a <= m / 2; a++) {
      s[a].side = 0;
      l[0] += s[a].x;
      r[0] += s[a].y;
    }
    for (a = m / 2 + 1; a <= m; a++) {
      s[a].side = 1;
      l[1] += s[a].x;
      r[1] += s[a].y;
    }
    while (num <= 50000) {
      num++;
      x = rand() % m + 1;
      while (s[x].side != 0) x = rand() % m + 1;
      y = rand() % m + 1;
      while (s[y].side != 1) y = rand() % m + 1;
      z = ans;
      exchange(x, y);
      tongji();
      if (ans > z)
        if (rand() % 1000 + 1 <= 50)
          exchange(y, x);
        else
          ;
      else if (rand() % 1000 + 1 >= 50)
        exchange(y, x);
    }
    if (ans == 0)
      cout << "No solution" << '\n';
    else if (side == 0)
      cout << "W ";
    else
      cout << "B ";
    if (ans != 0) cout << fixed << setprecision(2) << ans * 100 << '\n';
  }
  return 0;
}
