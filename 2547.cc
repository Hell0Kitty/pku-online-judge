#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

double l, w, n;
bool visited[1 << 22];
struct P {
  double x;
  double wt;
  double lt, rt;
} pack[30];
int res[30];

bool solve(int dep, double l, double r, int state) {
  int i;
  if (dep == n) return true;
  if (visited[state]) return false;
  visited[state] = true;
  if (l < 0 || r > 0) return false;
  for (i = 0; i < n; i++) {
    int tmp = 1 << i;
    if ((tmp & state) != 0) continue;
    res[dep] = i;
    if (solve(dep + 1, l - pack[i].lt, r - pack[i].rt, (state | tmp)))
      return true;
  }
  return false;
}
int main() {
  double left, right;
  int t = 1;
  int i;
  while (scanf("%lf%lf%lf", &l, &w, &n) == 3) {
    if (l + w + n == 0) break;
    left = 1.5 * w;
    right = -left;
    for (i = 0; i < n; i++) {
      scanf("%lf%lf", &pack[i].x, &pack[i].wt);
      pack[i].lt = (pack[i].x + 1.5) * pack[i].wt;
      pack[i].rt = (pack[i].x - 1.5) * pack[i].wt;
      left += pack[i].lt;
      right += pack[i].rt;
    }
    memset(visited, false, sizeof(visited));
    printf("Case %d:\n", t++);
    if (solve(0, left, right, 0)) {
      for (i = 0; i < n; i++)
        printf("%.0lf %.0lf\n", pack[res[i]].x, pack[res[i]].wt);
    } else
      printf("Impossible\n");
  }
  return 0;
}
