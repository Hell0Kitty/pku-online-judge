#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
int n;
double ans;
int main() {
  int v, t;
  double time;
  while (scanf("%d", &n), n) {
    ans = INF;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &v, &t);
      if (t < 0) continue;
      time = t + 4.5 / v * 3600;
      ans = min(time, ans);
      // if(ans>time)
      // ans=time;
    }
    int res = ceil(ans);
    printf("%d\n", res);
  }
  return 0;
}
