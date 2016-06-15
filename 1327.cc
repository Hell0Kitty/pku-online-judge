#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
char map[300][300];
int c, r;
void dfs(int i, int j, double &x, double &y, int &total) {
  if (i < 0 || i >= r || j < 0 || j > c || map[i][j] == '.') return;
  map[i][j] = '.';
  total++;
  x += (2 * i + 1) / 2.0;
  y += (2 * j + 1) / 2.0;
  dfs(i - 1, j, x, y, total);
  dfs(i + 1, j, x, y, total);
  dfs(i, j - 1, x, y, total);
  dfs(i, j + 1, x, y, total);
}
int main() {
  while (true) {
    vector<double> x, y;
    scanf("%d%d", &c, &r);
    if (!c && !r) break;
    while (true) {
      int maxnum = -1;
      double totalx = 0, totaly = 0;
      for (int i = 0; i < r; i++) scanf("%s", map[i]);
      for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
          if (map[i][j] == 'x') {
            double nowx = 0, nowy = 0;
            int total = 0;
            dfs(i, j, nowx, nowy, total);
            if (total > maxnum) {
              maxnum = total;
              totalx = nowx;
              totaly = nowy;
            }
          }
      x.push_back((totalx) / maxnum);
      y.push_back((totaly) / maxnum);
      scanf("%s", map[0]);
      if (map[0][0] == '=') break;
    }
    double resx = 0, resy = 0;
    int T = x.size() / 2;
    for (int i = 0; i < x.size() - T; i++) {
      resx += (x[i + T] - x[i]) / T;
      resy += (y[i + T] - y[i]) / T;
    }
    resx /= T;
    resy /= T;
    printf("%.2f %.2f\n", resy + 1e-6, resx + 1e-6);
  }
  return 0;
}
