#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#define eps 1e-6
using namespace std;
struct Point {
  double x, y;
  int id;
};
Point a[100];
int vis[100];
int n;

double multi(Point p0, Point p1, Point p2) {
  return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}
double dis(Point p0, Point p1) {
  return (p0.x - p1.x) * (p0.x - p1.x) + (p0.y - p1.y) * (p0.y - p1.y);
}
int sig(double x) {
  if (fabs(x) < eps) return 0;
  if (x > eps) return 1;
  if (x < -eps) return -1;
}

int main() {
  int T;
  scanf("%d", &T);
  int i, j, k;
  while (T--) {
    scanf("%d", &n);
    double miny = 9999.0;
    vector<int> v;
    for (i = 1; i <= n; i++) {
      int u, v, w;
      scanf("%d %lf %lf", &a[i].id, &a[i].x, &a[i].y);
      vis[i] = 0;
      if (sig(miny - a[i].y) == 1) {
        miny = a[i].y;
        k = a[i].id;
      }
    }
    v.push_back(k);
    vis[k] = 1;
    int flag = 0;
    int k1, k2;
    while (1) {
      for (i = 1; i <= n; i++) {
        if (!vis[i]) {
          k1 = i;
          break;
        }
      }
      for (i = 1; i <= n; i++) {
        if (vis[i]) continue;

        if (sig(multi(a[k], a[k1], a[i])) == -1) {
          k1 = i;
        } else if (sig(multi(a[k], a[k1], a[i])) == 0) {
          if (sig(dis(a[i], a[k]) - dis(a[k1], a[k])) == 1) {
            k1 = i;
          }
        }
      }
      vis[k1] = 1;
      v.push_back(k1);
      k = k1;
      if (v.size() == n) {
        break;
      }
    }
    printf("%d", n);
    for (i = 0; i < v.size(); i++) {
      printf(" %d", v[i]);
    }
    printf("\n");
  }
  return 0;
}
