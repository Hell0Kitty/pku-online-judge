#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <queue>
using namespace std;
const int MAXN = 10000;
int vis[MAXN];
double lowcost[MAXN];
double closeset[MAXN];
double mins[MAXN];
struct V {
  double x, y;
} v[MAXN];
double dis(V a, V b) {
  return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) +
              1.0 * (a.y - b.y) * (a.y - b.y));
}
int main() {
  int T;
  int s, p;
  cin >> T;
  while (T--) {
    int cnt = 1;
    memset(vis, 0, sizeof(vis));
    cin >> s >> p;
    for (int i = 0; i < p; i++) {
      cin >> v[i].x >> v[i].y;
    }
    vis[0] = 1;
    for (int i = 0; i < p; i++)
      if (!vis[i]) {
        lowcost[i] = dis(v[i], v[0]);
        closeset[i] = 0;
      }

    while (cnt < p) {
      double min1 = 10000000;
      int k;
      for (int i = 0; i < p; i++)
        if (!vis[i]) {
          if (min1 > lowcost[i]) {
            k = i;
            min1 = lowcost[i];
          }
        }
      vis[k] = 1;
      mins[cnt - 1] = min1;
      cnt++;
      for (int i = 0; i < p; i++)
        if (!vis[i]) {
          if (lowcost[i] > dis(v[k], v[i])) {
            lowcost[i] = dis(v[k], v[i]);
            closeset[i] = k;
          }
        }
    }
    sort(mins, mins + cnt - 1);
    printf("%.2lf\n", mins[cnt - 1 - s]);
  }
  return 0;
}
