#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <math.h>
using namespace std;
typedef long long int64;
// typedef __int64 int64;
typedef pair<int64, int64> PII;
#define MP(a, b) make_pair((a), (b))
const int maxn = 55;
const double inf = 99999999;
const double pi = acos(-1.0);
const double eps = 1e-8;

struct Node {
  double x, y;
} pnt[maxn];
double dis[maxn];
bool vis[maxn];
double mat[maxn][maxn];
double dist(int a, int b) {
  return sqrt((pnt[a].x - pnt[b].x) * (pnt[a].x - pnt[b].x) +
              (pnt[a].y - pnt[b].y) * (pnt[a].y - pnt[b].y));
}

double Prim(int start, int aim, int n) {
  double ans = 0;
  memset(vis, false, sizeof(vis));
  vis[start] = true;
  vis[aim] = true;
  for (int i = 0; i < n; i++) {
    dis[i] = mat[start][i];
  }
  for (int i = 0; i < n; i++) {
    int id = -1;
    double M = inf;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && M > dis[j]) {
        M = dis[j];
        id = j;
      }
    }
    if (id == -1) break;
    vis[id] = true;
    ans += M;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && dis[j] > mat[id][j]) {
        dis[j] = mat[id][j];
      }
    }
  }
  return ans;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &pnt[i].x, &pnt[i].y);
    }
    if (n == 1) {
      puts("0");
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          mat[i][j] = 0.0;
        else
          mat[i][j] = dist(i, j);
      }
    }
    double res = inf;
    for (int i = 0; i < n; i++) {
      res = min(res, Prim((i + 1) % n, i, n));
    }
    printf("%.2lf\n", res);
  }
  return 0;
}
