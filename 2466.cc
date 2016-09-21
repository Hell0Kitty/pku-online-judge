#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int a[50];
int x[15];
int flag[50];
bool cmp(int x, int y) { return x < y; }
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int m = n * (n - 1) / 2;
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + m, cmp);
    bool corr;
    for (int i = 3; i <= m; i++) {
      memset(flag, 0, sizeof(flag));
      x[1] = (a[1] + a[2] - a[i]) / 2;
      x[2] = (a[i] + a[1] - a[2]) / 2;
      x[3] = (a[2] + a[i] - a[1]) / 2;
      if ((a[1] + a[2] - a[i]) % 2 != 0 || (a[i] + a[1] - a[2]) % 2 != 0 ||
          (a[2] + a[i] - a[1]) % 2 != 0) {
        corr = false;
        continue;
      }
      flag[1] = flag[2] = flag[i] = 1;
      int k = 0;
      while (4 + k <= n) {
        for (int j = 1; j <= m; j++) {
          if (flag[j] == 0) {
            flag[j] = 1;
            x[4 + k] = a[j] - x[1];
            break;
          }
        }
        for (int j = 1; j < 4 + k; j++) {
          for (int l = 1; l <= m; l++) {
            if ((a[l] == x[4 + k] + x[j]) && flag[l] == 0) {
              flag[l] = 1;
              break;
            }
          }
        }
        k++;
      }
      corr = true;
      for (int j = 1; j <= m; j++) {
        if (flag[j] == 0) {
          corr = false;
          break;
        }
      }
      if (corr == true) break;
    }
    if (corr == false)
      printf("Impossible\n");
    else {
      for (int i = 1; i <= n; i++) printf("%d ", x[i]);
      printf("\n");
    }
  }
  return 0;
}
