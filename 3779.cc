#include <iostream>
#include <cstdio>

using namespace std;

const int maxx = 105;

double da[maxx];
double time[maxx];

int main() {
  int T, n, temp;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) {
    printf("Case %d:\n", cas);
    double ans = 0;
    int zh = 0;
    double minn;
    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; i++) {
      scanf("%lf", &da[i]);
    }
    for (i = 0; i < n; i++) {
      minn = 1e10;
      for (j = 0; j < n; j++) {
        if (da[j] <= 0) continue;
        zh = (int)da[j];
        if ((double)zh == da[j]) zh--;
        if (zh < minn) minn = zh;
      }
      for (j = 0; j < n; j++) {
        if (da[j] <= 0) continue;
        da[j] -= minn;
        ans += minn;
      }
      for (j = 0; j < n; j++) {
        if (da[j] <= 0) continue;
        if (da[j] <= 1.0) {
          ans += da[j];
          da[j] = 0;
          time[j] = ans;
          continue;
        } else {
          da[j] -= 1.0;
          ans += 1.0;
        }
      }
    }
    for (i = 0; i < n; i++) {
      printf("%.2lf\n", time[i]);
    }
  }
  return 0;
}
