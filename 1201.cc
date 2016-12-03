#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAXV 50002
#define INF INT_MAX
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a < b ? b : a)

typedef struct { int s, t, w; } Edge;

Edge edge[MAXV];
int n, d[MAXV], mi, ma;

void bellman_ford() {
  int i;
  bool flag = true;
  while (flag) {
    flag = false;
    for (i = 1; i <= n; i++) {  //要使所有的点满足s[ai-1]-s[bi] <= -ci
      if (d[edge[i].t] > d[edge[i].s] - edge[i].w) {
        d[edge[i].t] = d[edge[i].s] - edge[i].w;
        flag = true;
      }
    }

    for (i = mi; i <= ma; i++) {  //要使所有点满足s[i]-s[i-1] <= 1
      if (d[i] > d[i - 1] + 1) {
        d[i] = d[i - 1] + 1;
        flag = true;
      }
    }

    for (i = ma; i >= mi; i--) {  //要使所有点满足s[i-1]-s[i] <= 0
      if (d[i - 1] > d[i]) {
        d[i - 1] = d[i];
        flag = true;
      }
    }
  }
}

int main() {
  int i;
  while (~scanf("%d", &n)) {
    mi = INF, ma = -1;
    for (i = 1; i <= n; i++) {
      scanf("%d%d%d", &edge[i].t, &edge[i].s, &edge[i].w);
      mi = min(mi, edge[i].t);  //找出源点与终点
      ma = max(ma, edge[i].s);
      d[i] = 0;     //初始化
      edge[i].t--;  //使得ai-1
    }
    bellman_ford();
    printf("%d\n",
           d[ma] - d[mi - 1]);  //这里要包括最小点，所以是mi-1，否则会出错
  }
  return 0;
}
