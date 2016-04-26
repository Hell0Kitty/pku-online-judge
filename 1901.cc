#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())

const int maxn = 1000;
const int maxm = 1000 * 1000 / 2;

struct Point {
  int x, y, z, c[2], color;
} p[maxn + 5];

struct Edge {
  int b, v, dis;
  Edge() {}
  Edge(int _b, int _v, int _dis) : b(_b), v(_v), dis(_dis) {}
  bool operator<(const Edge &A) const { return dis < A.dis; }
} edge[maxm + 5];

int n, te, d, ansd, ansr;

int Dis(int u, int v) {
  return (p[u].x - p[v].x) * (p[u].x - p[v].x) +
         (p[u].y - p[v].y) * (p[u].y - p[v].y) +
         (p[u].z - p[v].z) * (p[u].z - p[v].z);
}

void update(int e) {
  int b = edge[e].b, v = edge[e].v;
  d -= (p[b].c[p[b].color] < p[b].c[p[b].color ^ 1]);
  d -= (p[v].c[p[v].color] < p[v].c[p[v].color ^ 1]);
  p[b].c[p[v].color]++;
  p[v].c[p[b].color]++;
  d += (p[b].c[p[b].color] < p[b].c[p[b].color ^ 1]);
  d += (p[v].c[p[v].color] < p[v].c[p[v].color ^ 1]);
}

int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d%d", &p[i].x, &p[i].y, &p[i].z, &p[i].color);
      p[i].c[0] = p[i].c[1] = 0;
      p[i].c[p[i].color] = 1;
    }
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        edge[++te] = Edge(i, j, Dis(i, j));
      }
    }
    sort(edge + 1, edge + 1 + te);
    edge[te + 1].dis = -1;
    for (int i = 1; i <= te; i++) {
      int low = i, high;
      while (edge[i + 1].dis == edge[i].dis) i++;
      high = i;
      for (int j = low; j <= high; j++) update(j);
      if (d > ansd) {
        ansd = d;
        ansr = edge[low].dis;
      }
    }
    printf("%d\n", ansd);
    printf("%.4lf\n", sqrt((double)ansr));
  }
  return 0;
}
