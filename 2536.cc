#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, s, v;
int match[110];
bool use[110];

struct gopher {
  double x, y;
} g[110];

struct hole {
  double x, y;
} h[110];

double dis(gopher g, hole h) {
  return sqrt(((g.x - h.x) * (g.x - h.x) + (g.y - h.y) * (g.y - h.y)));
}

bool find(int u) //地鼠找洞
{
  for (int i = 1; i <= m; ++i) {
    if (!use[i] && dis(g[u], h[i]) <= (double)(s * v)) {
      use[i] = true;
      if (match[i] == -1 || find(match[i])) {
        match[i] = u;
        return true;
      }
    }
  }
  return false;
}

int sum() {
  int sumall = 0;
  for (int i = 1; i <= n; ++i) {
    memset(use, false, sizeof(use));
    if (find(i))
      sumall++;
  }
  return sumall;
}

int main() {
  double x, y;
  int ans;
  while (scanf("%d%d%d%d", &n, &m, &s, &v) != EOF) {
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= n; ++i) //地鼠坐标
      scanf("%lf%lf", &g[i].x, &g[i].y);
    for (int i = 1; i <= m; ++i) //洞的坐标
      scanf("%lf%lf", &h[i].x, &h[i].y);
    ans = sum();
    printf("%d\n", n - ans);
  }
  return 0;
}