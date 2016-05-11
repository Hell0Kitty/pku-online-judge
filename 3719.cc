#include <iostream>
#include <cmath>
using namespace std;

struct node {
  int L, R, Lnum, Rnum, sumNum;
};

const double INF = 1000000000;
node a[105];
int n, m, w[20], C, p[66005];
double f[35][66005];
int V[18][15000];

void DFS(int u) {
  if (a[u].L == -1 && a[u].R == -1) {
    a[u].sumNum = 1;
    return;
  }
  DFS(a[u].L);
  a[u].Lnum = a[a[u].L].sumNum;
  DFS(a[u].R);
  a[u].Rnum = a[a[u].R].sumNum;
  a[u].sumNum = a[u].Lnum + a[u].Rnum;
}

void init() {
  int i, j, sum, num;
  for (i = 0; i < (1 << m); i++) {
    sum = 0;
    for (j = 0; j < m; j++)
      if (i & (1 << j)) sum += w[j];
    p[i] = sum;
  }
  for (i = 0; i <= 2 * m + 1; i++)
    for (j = 0; j < (1 << m); j++) f[i][j] = INF;
  for (i = 0; i <= m; i++) V[i][0] = 0;
  for (i = 0; i < (1 << m); i++) {
    num = 0;
    for (j = 0; j < m; j++)
      if (i & (1 << j)) num++;
    V[num][++V[num][0]] = i;
  }
}

void DFS1(int u) {
  int i, j, k, t, L = a[u].L, R = a[u].R;
  double temp;
  if (a[u].L == -1 && a[u].R == -1) {
    for (i = 0; i < m; i++) f[u][1 << i] = 0;
    return;
  }
  DFS1(a[u].L);
  DFS1(a[u].R);
  for (i = 1; i <= V[a[u].sumNum][0]; i++) {
    t = V[a[u].sumNum][i];
    for (j = 1; j <= V[a[L].sumNum][0]; j++) {
      k = V[a[L].sumNum][j];
      if (t - k < 0) continue;
      temp = f[L][k] + f[R][t - k] + fabs(1.0 * p[k] / p[t] - 0.5) * 1000;
      if (temp - f[u][t] < 1e-6) f[u][t] = temp;
    }
  }
}

int main() {
  for (scanf("%d", &C); C--;) {
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++) scanf("%d%d", &a[i].L, &a[i].R);
    scanf("%d", &m);
    for (i = 0; i < m; i++) scanf("%d", &w[i]);
    init();
    DFS(1);
    DFS1(1);
    double ans = INF;
    for (i = 0; i < (1 << m); i++)
      if (f[1][i] - ans < 1e-6) ans = f[1][i];
    printf("%.3lf\n", ans);
  }
  return 0;
}
