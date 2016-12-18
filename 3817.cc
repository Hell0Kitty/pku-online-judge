#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
struct node {
  double x, y;
  double val;
};
double pt[1010];
int main() {
  int n, i, k, j;

  while (cin >> n && n) {
    node *tar = new node[n + 3];
    double *dp = new double[n + 3];

    for (i = 1; i <= n; i++) {
      cin >> tar[i].x >> tar[i].y >> tar[i].val;
    }
    tar[0].x = 0;
    tar[0].y = 0;
    tar[0].val = 0;
    tar[n + 1].x = 100;
    tar[n + 1].y = 100;
    dp[0] = 0;
    memset(pt, 0, sizeof(pt));

    for (i = 1; i <= n + 1; i++) {
      pt[i] = pt[i - 1] + tar[i].val;
      double min1 = 10000000;
      for (j = 0; j < i; j++) {
        double d = dp[j];
        d += pt[i - 1] - pt[j];
        if (d > min1) continue;
        d += (sqrt((double)(tar[i].x - tar[j].x) * (tar[i].x - tar[j].x) +
                   (tar[i].y - tar[j].y) * (tar[i].y - tar[j].y)));
        if (d < min1) min1 = d;
      }
      dp[i] = min1 + 1;
    }

    printf("%.3lf\n", dp[n + 1]);
    delete[] tar;
    delete[] dp;
  }
  return 0;
}
