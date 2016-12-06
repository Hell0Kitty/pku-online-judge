#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

double H, V, h, v;
int n;
double x, y;

int solve(int color, double x1, double y1, double x2, double y2, double x,
          double y) {
  double dx = (x2 - x1) * h + x1;
  double dy = (y2 - y1) * v + y1;
  if (x < dx && y > dy)
    return color;
  else if (x > dx && y < dy)
    return color;
  else if (x < dx && y < dy)
    return solve(color ^ 1, x1, y1, dx, dy, x, y);
  else
    return solve(color ^ 1, dx, dy, x2, y2, x, y);
}

int main() {
  int cases = 0;
  while (1) {
    cases++;
    cin >> H >> V >> h >> v;
    if (H == 0.0 && V == 0.0 && h == 0.0 && v == 0.0) break;
    printf("Case %d:\n", cases);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      int ans = solve(0, 0.0, 0.0, H, V, x, y);
      if (ans == 0)
        printf("black\n");
      else
        printf("white\n");
    }
  }
  return 0;
}
