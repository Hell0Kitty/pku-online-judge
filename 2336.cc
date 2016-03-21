#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX 1500
int tt[MAX];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, d, m;
    scanf("%d%d%d", &n, &d, &m);
    int i;
    for (i = 1; i <= m; i++) {
      scanf("%d", &tt[i]);
    }
    if (m <= n) {
      printf("%d %d\n", tt[m] + d, 1);
      continue;
    }
    int cur = n;
    int cost = 0;
    int num;
    int most;
    if (m % n == 0)
      num = m / n;
    else
      num = m / n + 1;
    if (m >= 2 * n)  // note
    {
      while (cur + n <= m) {
        most = cost > tt[cur] ? cost : tt[cur];
        cost = most + 2 * d;
        cur += n;
      }
    }
    if (m % n) {
      most = cost > tt[m - n] ? cost : tt[m - n];
      cost = most + 2 * d;
    }
    most = cost > tt[m] ? cost : tt[m];
    printf("%d %d\n", most + d, num);
  }
}
